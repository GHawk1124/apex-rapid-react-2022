#pragma once

#include <frc2/command/Command.h>

#include "commands/HangCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/ShootCommand.h"
#include "subsystems/HangarSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubsystem.h"

class RobotContainer {
public:
  RobotContainer();

  // frc2::Command *GetAutonomousCommand();

private:
  ShooterSubsystem m_shooter_subsystem;
  HangarSubsystem m_hangar_subsystem;
  IntakeSubsystem m_intake_subsystem;
  ShootCommand m_shootCommand;
  HangCommand m_hangCommand;
  IntakeCommand m_intakeCommand;

  void ConfigureButtonBindings();
};
