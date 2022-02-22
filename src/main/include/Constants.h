// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <rev/CANSparkMax.h>
#include <units/acceleration.h>
#include <units/length.h>

namespace constants {

namespace drive {
constexpr int kLeftFrontPort = 2;
constexpr int kLeftBackPort = 4;
constexpr int kRightFrontPort = 1;
constexpr int kRightBackPort = 3;
constexpr int kFalcon500TicksPerRotation = 2048;
constexpr double kGearRatio = 10.71;
constexpr auto kWheelDiameter = 6_in;
constexpr auto kTrackWidth = 0.94297_m;
constexpr double kTicksPerMeter = kFalcon500TicksPerRotation;
constexpr auto kDistancePerPulse = kWheelDiameter *
                                   units::constants::detail::PI_VAL /
                                   kGearRatio / kFalcon500TicksPerRotation;
constexpr auto ks = 0.64768_V;
constexpr auto kv = 2.5441 * 1_V * 1_s / 1_m;
constexpr auto ka = 0.1141 * 1_V * 1_s * 1_s / 1_m;
constexpr double kPDriveVel = 0.000075;
extern const frc::DifferentialDriveKinematics kDriveKinematics;
constexpr auto kMaxSpeed = 3_mps;
constexpr auto kMaxAcceleration = 3_mps_sq;
constexpr auto kMaxVoltage = 10_V;
}  // namespace drive

namespace Auto {
constexpr auto kMaxSpeed = 1_mps;
constexpr auto kMaxAcceleration = 1_mps_sq;
constexpr auto kRamseteB = 2.0 * 1_rad * 1_rad / (1_m * 1_m);
constexpr auto kRamseteZeta = 0.7 / 1_rad;
}  // namespace Auto

namespace intake {
constexpr int kIntakePort = 4;
constexpr int kPcmPort = 6;
}  // namespace intake

namespace shooter {
constexpr int kShooterPort = 5;
}  // namespace shooter

namespace hang {
constexpr int kHangPort = 6;
constexpr auto kHangMotorType = rev::CANSparkMaxLowLevel::MotorType::kBrushless;
}  // namespace hang

}  // namespace constants
