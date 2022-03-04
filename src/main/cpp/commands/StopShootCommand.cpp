// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/StopShootCommand.h"

StopShootCommand::StopShootCommand(ShooterSubsystem* subsystem)
    : m_subsystem{subsystem} {}

void StopShootCommand::Execute() {
    m_subsystem->stopShoot();
}

bool StopShootCommand::IsFinished() {
    return true;
}
