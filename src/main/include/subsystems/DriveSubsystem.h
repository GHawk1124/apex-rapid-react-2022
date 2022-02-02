// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  void Periodic() override;

  void TankDriveVolts(units::volt_t left, units::volt_t right);

  void TankDrive(double left, double right);

  void ArcadeDrive(double fwd, double rot);

  void ResetEncoders();

 private:
  WPI_TalonFX m_LF;
  WPI_TalonFX m_LB;
  WPI_TalonFX m_RF;
  WPI_TalonFX m_RB;

  frc::DifferentialDrive m_DiffDrive{m_LF, m_RF};
};
