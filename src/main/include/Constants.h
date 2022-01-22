#pragma once

#include <rev/CANSparkMax.h>

namespace hang {
constexpr int kHangPort = 1;
constexpr auto kHangMotorType = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
} // namespace hang

namespace intake {
constexpr int kIntakePort = 3;
} // namespace intake

namespace shooter {
constexpr int kShooterPort = 2;
} // namespace shooter