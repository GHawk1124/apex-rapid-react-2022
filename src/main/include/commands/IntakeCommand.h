// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/IntakeSubsystem.h"

class IntakeCommand
    : public frc2::CommandHelper<frc2::CommandBase, IntakeCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit IntakeCommand(IntakeSubsystem* subsystem);

  void Execute() override;

 private:
  IntakeSubsystem* m_subsystem;
};
