// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"
#include "Constants.h"

#include <rev/CANSparkMax.h>

ShooterSubsystem::ShooterSubsystem() : leftMotor{constants::shooter::kShooterLeftPort, rev::CANSparkMax::MotorType::kBrushless},
 rightMotor{constants::shooter::kShooterRightPort, rev::CANSparkMax::MotorType::kBrushless} {
  // Implementation of subsystem constructor goes here.
  rightMotor.Follow(leftMotor);
}

void ShooterSubsystem::startShoot() {
    leftMotor.Set(1.0);
}

void ShooterSubsystem::stopShoot() {
    leftMotor.Set(0.0);
}

void ShooterSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ShooterSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
