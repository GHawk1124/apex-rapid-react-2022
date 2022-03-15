// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ShootCommand.h"

ShootCommand::ShootCommand(ShooterSubsystem* subsystem)
    : m_subsystem{subsystem} {}

void ShootCommand::Execute() {
  m_subsystem->startShoot();
}

bool ShootCommand::IsFinished() {
  return true;
}
