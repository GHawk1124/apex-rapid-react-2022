// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultDrive.h"

#include <iostream>
#include <utility>

DefaultDrive::DefaultDrive(DriveSubsystem* subsystem,
                           std::function<double()> left,
                           std::function<double()> right)
    : m_drive{subsystem}, m_left{std::move(left)}, m_right{std::move(right)} {
  AddRequirements({subsystem});
}

void DefaultDrive::Execute() {
  m_drive->TankDrive(m_left(), m_right());
}
