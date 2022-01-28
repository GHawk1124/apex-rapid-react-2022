// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem()
    : m_LF{constants::drive::kLeftFrontPort},
      m_LB{constants::drive::kLeftBackPort},
      m_RF{constants::drive::kRightFrontPort},
      m_RB{constants::drive::kRightBackPort} {
  // m_rightMotors.SetInverted(true);
  ResetEncoders();
}

void DriveSubsystem::Periodic() {
  // m_odometry.Update(m_gyro.GetRotation2d(),
  // units::meter_t(m_LF.GetSelectedSensorPosition(0) * kTicksPerInch),
  //                   units::meter_t(m_RF.GetSelectedSensorPosition(0) *
  //                   kTicksPerInch));
}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right) {
  // m_leftMotors.SetVoltage(left);
  // m_rightMotors.SetVoltage(right);
  // m_drive.Feed();
}

void DriveSubsystem::TankDrive(double left, double right) {
  m_LF.Set(ControlMode::PercentOutput, left * 12.0f);
  m_LB.Set(ControlMode::PercentOutput, left * 12.0f);
  m_RF.Set(ControlMode::PercentOutput, right * 12.0f);
  m_RB.Set(ControlMode::PercentOutput, right * 12.0f);
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  double leftSpeed = fwd - rot;
  double rightSpeed = fwd + rot;
  m_LF.Set(ControlMode::PercentOutput, leftSpeed);
  m_LB.Set(ControlMode::PercentOutput, leftSpeed);
  m_RF.Set(ControlMode::PercentOutput, rightSpeed);
  m_RB.Set(ControlMode::PercentOutput, rightSpeed);
}

void DriveSubsystem::ResetEncoders() {}
