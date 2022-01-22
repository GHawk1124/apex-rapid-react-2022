#pragma once

#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

class HangarSubsystem : public frc2::SubsystemBase {
public:
  HangarSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

private:
  rev::CANSparkMax m_hangar;
};
