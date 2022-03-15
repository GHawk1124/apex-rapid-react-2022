// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"
#include "ctre/Phoenix.h"

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem();

  void startShoot();

  void stopShoot();

  void Periodic() override;

  void SimulationPeriodic() override;

 private:
  rev::CANSparkMax m_shooter_left;
  rev::CANSparkMax m_shooter_right;
};
