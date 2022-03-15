// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

class IntakeSubsystem : public frc2::SubsystemBase {
 public:
  IntakeSubsystem();

  void toggleSolenoid();

  void toggleMotor();

  void Periodic() override;

  void SimulationPeriodic() override;

 private:
  frc::Compressor pcmCompressor;
  frc::DoubleSolenoid IntakeSolenoidPCM;
  rev::CANSparkMax m_intake;

  bool intakeOut = false;
  bool motorOn = false;
};
