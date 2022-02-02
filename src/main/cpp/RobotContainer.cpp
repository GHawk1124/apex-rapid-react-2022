// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer()
    : m_shootCommand(&m_shooter_subsystem),
      m_hangCommand(&m_hangar_subsystem),
      m_intakeCommand(&m_intake_subsystem) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -m_controller.GetY(); },
      [this] { return m_controller.GetZ(); }));
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

// frc2::Command *RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomousCommand;
// }
