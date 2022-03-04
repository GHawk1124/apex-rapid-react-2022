// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakePneumaticCommand.h"

IntakePneumaticCommand::IntakePneumaticCommand(IntakeSubsystem* subsystem)
    : m_subsystem{subsystem} {
  AddRequirements({subsystem});
}

void IntakePneumaticCommand::Execute() {
  m_subsystem->toggleSolenoid();
}

bool IntakePneumaticCommand::IsFinished() {
    return true;
}
