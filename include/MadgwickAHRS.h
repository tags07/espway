//=====================================================================================================
// MadgwickAHRS.h
//=====================================================================================================
//
// Implementation of Madgwick's IMU and AHRS algorithms.
// See: http://www.x-io.co.uk/node/8#open_source_ahrs_and_imu_algorithms
//
// Date			Author          Notes
// 29/09/2011	SOH Madgwick    Initial release
// 02/10/2011	SOH Madgwick	Optimised for reduced CPU load
// 15/11/2016   Sakari Kapanen  Additions and adaptation to ESP8266: gravity, pitch and roll calculation
//
//=====================================================================================================
#pragma once

typedef struct {
    float q0;
    float q1;
    float q2;
    float q3;
} quaternion;

typedef struct {
    float x;
    float y;
    float z;
} vector3;

void MadgwickAHRSupdateIMU(float beta, float sfreq, float gx, float gy, float gz, float ax, float ay, float az, quaternion * const q);

void gravityVector(const quaternion * const q, vector3 * const g);
double pitchAngle(const vector3 * const g);
double rollAngle(const vector3 * const g);

