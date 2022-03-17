// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/IntakeSubsystem.h"

#include <frc/Timer.h>
#include <units/time.h>

IntakeSubsystem::IntakeSubsystem()
    : pcmCompressor{constants::intake::kPcmPort,
                    frc::PneumaticsModuleType::CTREPCM},
      IntakeSolenoidPCM{frc::PneumaticsModuleType::CTREPCM, 1, 2},
      m_intake{constants::intake::kIntakePort,
               rev::CANSparkMax::MotorType::kBrushless} {
  // Implementation of subsystem constructor goes here.
  // pcmCompressor.Disable();
  // IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kForward);
}

void IntakeSubsystem::toggleSolenoid() {
  if (intakeOut) {
    // pull back in pistons with full force
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kForward);
  } else {
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kReverse);
    frc::Wait(0.1_s);  // Wait for .1 seconds then turn off the air
    IntakeSolenoidPCM.Set(frc::DoubleSolenoid::Value::kOff);
  }
  intakeOut = !intakeOut;
}

void IntakeSubsystem::toggleMotor() {
  motorOn = !motorOn;
  if (motorOn) {
    m_intake.Set(0.9f);
  } else {
    m_intake.Set(0.0f);
  }
}

void IntakeSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void IntakeSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
