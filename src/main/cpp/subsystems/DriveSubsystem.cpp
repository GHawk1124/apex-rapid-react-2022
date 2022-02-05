// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include <iostream>

DriveSubsystem::DriveSubsystem()
    : m_LF{constants::drive::kLeftFrontPort},
      m_LB{constants::drive::kLeftBackPort},
      m_RF{constants::drive::kRightFrontPort},
      m_RB{constants::drive::kRightBackPort},
      m_odometry{m_gyro.GetRotation2d()} {
  m_LB.Follow(m_LF);
  m_RB.Follow(m_RF);
  m_RF.SetInverted(true);
  m_RB.SetInverted(ctre::phoenix::motorcontrol::InvertType::FollowMaster);
  m_gyro.Calibrate();
  ResetEncoders();
}

void DriveSubsystem::Periodic() {
  frc::SmartDashboard::PutNumber("Gyro Angle X", m_gyro.GetAngle());
  frc::SmartDashboard::PutNumber("Gyro Angle Y", m_gyro.GetAngle());
  frc::SmartDashboard::PutNumber("Gyro Angle Z", m_gyro.GetAngle());
  m_odometry.Update(
      m_gyro.GetRotation2d(),
      units::meter_t(
          m_LF.GetSelectedSensorPosition() *
          units::meter_t(constants::drive::kDistancePerPulse).value()),
      units::meter_t(
          m_RF.GetSelectedSensorPosition() *
          units::meter_t(constants::drive::kDistancePerPulse).value()));
}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right) {
  m_LF.SetVoltage(left);
  m_RF.SetVoltage(right);
  m_DiffDrive.Feed();
}

void DriveSubsystem::TankDrive(double left, double right) {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_DiffDrive.ArcadeDrive(fwd, rot);
}

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds() {
  return {units::meters_per_second_t(
              m_LF.GetSelectedSensorVelocity() *
              units::meter_t(constants::drive::kDistancePerPulse).value()),
          units::meters_per_second_t(
              m_RF.GetSelectedSensorVelocity() *
              units::meter_t(constants::drive::kDistancePerPulse).value())};
}

units::degree_t DriveSubsystem::GetHeading() const {
  return m_gyro.GetRotation2d().Degrees();
}

frc::Pose2d DriveSubsystem::GetPose() {
  return m_odometry.GetPose();
}

void DriveSubsystem::ResetEncoders() {
  m_RF.SetSelectedSensorPosition(0);
  m_RB.SetSelectedSensorPosition(0);
  m_LF.SetSelectedSensorPosition(0);
  m_LB.SetSelectedSensorPosition(0);
}

void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
  ResetEncoders();
  m_odometry.ResetPosition(pose, m_gyro.GetRotation2d());
}
