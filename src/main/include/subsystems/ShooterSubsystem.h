#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "Constants.h"

class ShooterSubsystem : public frc2::SubsystemBase {
public:
  ShooterSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

private:
  TalonFX m_shooter;
};
