// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

IntakeSubsystem::IntakeSubsystem()
    : pcmCompressor{constants::intake::kPcmPort,
                    frc::PneumaticsModuleType::CTREPCM},
      IntakeSolenoidPCM{frc::PneumaticsModuleType::CTREPCM, 1, 2} {
  // Implementation of subsystem constructor goes here.
  pcmCompressor.EnableDigital();
  IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kReverse);
}

void IntakeSubsystem::toggleSolonoid() {
  IntakeSolenoidPCM.Toggle();
}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void IntakeSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
