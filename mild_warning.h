#ifndef MILD_WARNING_H
#define MILD_WARNING_H
#include "warning_strategy.h"

class mild_warning: public WarningStrategy
{
public:
    mild_warning() = default;
    QString getWarningLevel(const SensorData& data) override;

};

#endif // MILD_WARNING_H
