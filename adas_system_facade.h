#pragma once
#include "sensordatamodel.h"
#include "SensorData.h"

class adas_system_facade
{
public:
    adas_system_facade();
    void initSystem();
    SensorData getLiveData();
    void handleError(int code);
    SensorDataModel* getModel() const;


private:
    SensorDataModel* sensorModel;

};


