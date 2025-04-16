#ifndef AGGRESSIVEWARNING_H
#define AGGRESSIVEWARNING_H

#include "warning_strategy.h"

class aggressiveWarning: public WarningStrategy
{
public:
    aggressiveWarning() = default;
    QString getWarningLevel(const SensorData& data) override;
};

#endif // AGGRESSIVEWARNING_H
