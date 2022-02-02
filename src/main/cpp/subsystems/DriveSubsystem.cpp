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

void DriveSubsystem::Periodic() {}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right) {}

void DriveSubsystem::TankDrive(double left, double right) {}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_DiffDrive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::ResetEncoders() {}
