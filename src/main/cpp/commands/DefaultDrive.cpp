// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DefaultDrive.h"

#include <utility>

DefaultDrive::DefaultDrive(DriveSubsystem* subsystem,
                           std::function<double()> fwd,
                           std::function<double()> rot)
    : m_drive{subsystem}, m_fwd{std::move(fwd)}, m_rot{std::move(rot)} {
  AddRequirements({subsystem});
}

void DefaultDrive::Execute() {
  m_drive->ArcadeDrive(m_fwd(), m_rot());
}
