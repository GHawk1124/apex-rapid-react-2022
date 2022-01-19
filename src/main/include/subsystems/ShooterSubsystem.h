#pragma once

#include <frc2/command/SubsystemBase.h>

class ShooterSubsystem : public frc2::SubsystemBase {
public:
  ShooterSubsystem();

  void Periodic() override;

  void SimulationPeriodic() override;

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
