// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class IntakeMotorCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeMotorCommand> {
 public:
  explicit IntakeMotorCommand(IntakeSubsystem* subsystem);

  void Initialize() override;
  bool IsFinished() override;

 private:
  IntakeSubsystem* m_subsystem;
};
