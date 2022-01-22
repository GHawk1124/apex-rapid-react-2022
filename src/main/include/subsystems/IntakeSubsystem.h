#pragma once

#include "Constants.h"
#include "ctre/Phoenix.h"
#include <frc2/command/SubsystemBase.h>

class IntakeSubsystem : public frc2::SubsystemBase {
public:
  IntakeSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

private:
  VictorSPX m_intake;
};
