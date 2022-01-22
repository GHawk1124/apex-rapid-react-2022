#include "subsystems/ShooterSubsystem.h"

ShooterSubsystem::ShooterSubsystem() : m_shooter{shooter::kShooterPort} {
  // Implementation of subsystem constructor goes here.
}

void ShooterSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ShooterSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}
