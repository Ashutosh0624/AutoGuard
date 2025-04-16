#pragma once
#include <string>

#define ERROR_NONE 0
#define ERROR_GRPC_FAILURE 101
#define ERROR_SENSOR_OFFLINE 102


struct SensorData {
    float speed = 0.0f;
    float acceleration = 0.0f;
    float steering = 0.0f;
    float brake = 0.0f;
    float throttle = 0.0f;
    float lane_offset = 0.0f;
    std::string traffic_sign = "None";
    std::string status = "Unknown";
    bool sensor_ok = false;
    int errorCode = 0;
};
