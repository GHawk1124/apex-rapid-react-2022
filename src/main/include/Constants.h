// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <rev/CANSparkMax.h>

namespace constants {

namespace drive {
constexpr int kLeftFrontPort = 2;
constexpr int kLeftBackPort = 4;
constexpr int kRightFrontPort = 1;
constexpr int kRightBackPort = 3;
constexpr int kFalcon500TicksPerRotation = 2048;
constexpr double kGearRatio = 0;
constexpr double kTicksPerMeter = kFalcon500TicksPerRotation;
}  // namespace drive

namespace intake {
constexpr int kIntakePort = 4;
}  // namespace intake

namespace shooter {
constexpr int kShooterPort = 5;
}  // namespace shooter

namespace hang {
constexpr int kHangPort = 6;
constexpr auto kHangMotorType = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
}  // namespace hang

}  // namespace constants
