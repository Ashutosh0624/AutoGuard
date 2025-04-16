#pragma once

#include <QString>
#include "SensorData.h"

class WarningStrategy{
public:
    virtual QString getWarningLevel(const SensorData& data) = 0;
    virtual ~WarningStrategy() = default;
};
