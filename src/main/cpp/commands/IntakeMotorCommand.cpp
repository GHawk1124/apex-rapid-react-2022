// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/IntakeMotorCommand.h"

IntakeMotorCommand::IntakeMotorCommand(IntakeSubsystem* subsystem)
    : m_subsystem{subsystem} {
  AddRequirements({subsystem});
}

void IntakeMotorCommand::Initialize() {
  m_subsystem->toggleMotor();
}

bool IntakeMotorCommand::IsFinished() {
  return true;
}
