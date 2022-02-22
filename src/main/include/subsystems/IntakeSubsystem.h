// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "ctre/Phoenix.h"

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  void toggleSolonoid();

  void Periodic() override;

  void SimulationPeriodic() override;

 private:
  // WPI_VictorSPX m_intake;
  frc::Compressor pcmCompressor;
  frc::DoubleSolenoid IntakeSolenoidPCM;

  bool solonoid = false;
};
