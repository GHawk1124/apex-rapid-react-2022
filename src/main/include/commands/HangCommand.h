// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/HangarSubsystem.h"

class HangCommand : public frc2::CommandHelper<frc2::CommandBase, HangCommand> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit HangCommand(HangarSubsystem* subsystem);

 private:
  HangarSubsystem* m_subsystem;
};
