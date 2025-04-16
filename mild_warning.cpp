#include "mild_warning.h"

QString mild_warning::getWarningLevel(const SensorData &data)
{
     if(data.speed > 120.0 || data.lane_offset > 1.5){
         return "MILD WARNING";
     }
     return "SAFE";
}
