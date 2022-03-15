// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Filesystem.h>
#include <frc/Joystick.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/RamseteController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/RamseteCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>
#include <wpi/fs.h>

#include "commands/DefaultDrive.h"
#include "commands/IntakeMotorCommand.h"
#include "commands/IntakePneumaticCommand.h"
#include "commands/ShootCommand.h"
#include "commands/StopShootCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  frc::Joystick m_controller{0};
  ShooterSubsystem m_shooter;
  IntakeSubsystem m_intake;
  DriveSubsystem m_drive;

  ShootCommand m_shootCommand;
  StopShootCommand m_stopShootCommand;
  IntakePneumaticCommand m_intakePneumaticCommand;
  IntakeMotorCommand m_intakeMotorCommand;

  frc::Trajectory m_trajectory;

  frc::SendableChooser<frc2::Command*> m_chooser;

  void ConfigureButtonBindings();
};
