#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ShooterSubsystem.h"

class ShootCommand
    : public frc2::CommandHelper<frc2::CommandBase, ShootCommand> {
public:
  /**
   * Creates a new ExampleCommand.
   *
   * @param subsystem The subsystem used by this command.
   */
  explicit ShootCommand(ShooterSubsystem *subsystem);

private:
  ShooterSubsystem *m_subsystem;
};
