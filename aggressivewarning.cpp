#include "aggressivewarning.h"

QString aggressiveWarning::getWarningLevel(const SensorData& data) {
    if (data.speed >= 140.0f || data.lane_offset > 0.3f) {
        return "DANGEROUS WARNING";
    }
    return "SAFE";
}
