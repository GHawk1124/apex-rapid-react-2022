#pragma once

#include <frc2/command/SubsystemBase.h>

class HangarSubsystem : public frc2::SubsystemBase {
public:
  HangarSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
