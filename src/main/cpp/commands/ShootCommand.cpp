// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(ShooterSubsystem* subsystem,
                           std::function<double()> throttle)
    : m_subsystem{subsystem}, m_throttle{std::move(throttle)} {}

void ShootCommand::Execute() {
  m_subsystem->startShoot(m_throttle());
}

bool ShootCommand::IsFinished() {
  return true;
}
