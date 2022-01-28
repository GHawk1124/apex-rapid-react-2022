// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>
#include <frc2/command/InstantCommand.h>

#include "commands/DefaultDrive.h"
#include "commands/HangCommand.h"
#include "commands/IntakeCommand.h"
#include "commands/ShootCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/HangarSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubsystem.h"

class RobotContainer {
 public:
  RobotContainer();

  // frc2::Command *GetAutonomousCommand();

 private:
  // frc::Joystick m_controller{0};
  frc::XboxController m_controller{0};
  ShooterSubsystem m_shooter_subsystem;
  HangarSubsystem m_hangar_subsystem;
  IntakeSubsystem m_intake_subsystem;
  DriveSubsystem m_drive;

  ShootCommand m_shootCommand;
  HangCommand m_hangCommand;
  IntakeCommand m_intakeCommand;

  void ConfigureButtonBindings();
};
