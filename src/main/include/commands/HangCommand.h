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
  explicit HangCommand(HangarSubsystem *subsystem);

private:
  HangarSubsystem *m_subsystem;
};
