// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
#include <iostream>

DriveSubsystem::DriveSubsystem()
    : m_LF{constants::drive::kLeftFrontPort},
      m_LB{constants::drive::kLeftBackPort},
      m_RF{constants::drive::kRightFrontPort},
      m_RB{constants::drive::kRightBackPort} {
  m_LB.Follow(m_LF);
  m_RB.Follow(m_RF);
  m_RF.SetInverted(true);
  m_RB.SetInverted(ctre::phoenix::motorcontrol::InvertType::FollowMaster);
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
  
  m_LF.Set(ControlMode::PercentOutput, left);
  m_LB.Set(ControlMode::PercentOutput, left);
  m_RF.Set(ControlMode::PercentOutput, right);
  m_RB.Set(ControlMode::PercentOutput, right);
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  // double leftSpeed = fwd - rot;
  // double rightSpeed = fwd + rot;
  // m_LF.Set(ControlMode::PercentOutput, leftSpeed);
  // m_LB.Set(ControlMode::PercentOutput, leftSpeed);
  // m_RF.Set(ControlMode::PercentOutput, rightSpeed);
  // m_RB.Set(ControlMode::PercentOutput, rightSpeed);
  m_DiffDrive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::ResetEncoders() {}
