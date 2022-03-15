// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ShooterSubsystem.h"

#include <rev/CANSparkMax.h>

#include "Constants.h"

ShooterSubsystem::ShooterSubsystem()
    : m_shooter_left{constants::shooter::kShooterLeftPort,
                     rev::CANSparkMax::MotorType::kBrushless},
      m_shooter_right{constants::shooter::kShooterRightPort,
                      rev::CANSparkMax::MotorType::kBrushless} {
  m_shooter_right.Follow(m_shooter_left, true);
}

void ShooterSubsystem::startShoot() {
  m_shooter_left.Set(0.6f);
  // right follows...
}

void ShooterSubsystem::stopShoot() {
  m_shooter_left.Set(0.0f);
  // right follows...
}

void ShooterSubsystem::Periodic() {}

void ShooterSubsystem::SimulationPeriodic() {}
