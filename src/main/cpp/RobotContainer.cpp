// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer()
    : m_shootCommand(&m_shooter),
      m_hangCommand(&m_hangar),
      m_intakeCommand(&m_intake) {
  // Initialize all of your commands and subsystems here

  fs::path deployDirectory = frc::filesystem::GetDeployDirectory();
  deployDirectory = deployDirectory / "output" / "curve.wpilib.json";
  m_trajectory =
      frc::TrajectoryUtil::FromPathweaverJson(deployDirectory.string());

  // Configure the button bindings
  ConfigureButtonBindings();
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -m_controller.GetY(); },
      [this] { return m_controller.GetZ(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  frc2::JoystickButton(&m_controller, 1).WhenHeld(m_intakeCommand, 1);
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Create a voltage constraint to ensure we don't accelerate too fast
  frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          constants::drive::ks, constants::drive::kv, constants::drive::ka),
      constants::drive::kDriveKinematics, constants::drive::kMaxVoltage);

  // Set up config for trajectory
  frc::TrajectoryConfig config(constants::Auto::kMaxSpeed,
                               constants::Auto::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(constants::drive::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

  // An example trajectory to follow.  All units in meters.
  // Start at the origin facing the +X direction
  // Pass through these two interior waypoints, making an 's' curve path
  // End 3 meters straight ahead of where we started, facing forward
  // Pass the config
  /*   auto trajectory = frc::TrajectoryGenerator::GenerateTrajectory(
        frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
        {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
        frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
        config); */

  frc2::RamseteCommand ramseteCommand(
      m_trajectory, [this]() { return m_drive.GetPose(); },
      frc::RamseteController(constants::Auto::kRamseteB,
                             constants::Auto::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          constants::drive::ks, constants::drive::kv, constants::drive::ka),
      constants::drive::kDriveKinematics,
      [this] { return m_drive.GetWheelSpeeds(); },
      frc2::PIDController(constants::drive::kPDriveVel, 0, 0),
      frc2::PIDController(constants::drive::kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_drive.TankDriveVolts(left, right); },
      {&m_drive});

  // Reset odometry to the starting pose of the trajectory.
  m_drive.ResetOdometry(m_trajectory.InitialPose());

  // no auto
  return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_drive.TankDriveVolts(0_V, 0_V); }, {}));
}
