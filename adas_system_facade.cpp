#include "adas_system_facade.h"
#include "logger.h"
#include "configparser.h"
#include "errormanager.h"

adas_system_facade::adas_system_facade()
{
    sensorModel = new SensorDataModel();
}

void adas_system_facade::initSystem()
{
     // logger setup
    logger::getInstance()->log("ADAS system initialization started ...",
                               Level::INFO,
                               "ADASSystem Facade",
                               "ADAS - INIT");

    QString mode = ConfigParser::getInstance()->getValue("Warning", "mode", "mild").toString();

    logger::getInstance()->log("Configuration warning strategy mode: "+ mode,
                               Level::INFO,
                               "ADASSystemFacade",
                               "ADAS-INIT");

    // log path confirmation
    QString logPath = ConfigParser::getInstance()->getValue("Logging",
                                                            "log_path",
                                                            "app.log").toString();

    logger::getInstance()->log("logging to file path : "+ logPath,
                               Level::DEBUG,
                               "ADASSystemFacade",
                               "ADAS-INIT");

    logger::getInstance()->log("ADAS system initialization completed",
                               Level::INFO,
                               "ADASSystemFacade",
                               "ADAS-INIT");

}

SensorData adas_system_facade::getLiveData()
{
      SensorData data = sensorModel->fetchSensorData();

      if(!data.sensor_ok){
          logger::getInstance()->log("Sensor error detected. Code: " + QString::number(data.errorCode),
                                     Level::ERROR,
                                     "ADASSystemFacade",
                                     "ADAS-DATA");

      handleError(data.errorCode);
      }
      return data;

}

void adas_system_facade::handleError(int code)
{
  logger::getInstance()->log("Handling error code: " + QString::number(code),
                             Level::WARNING,
                             "ADASSystemFacade",
                             "ADAS - ERROR");

  errorManager::getInstance()->handleSensorFault("Sensor not working", "FS-REQ 302");
}

SensorDataModel *adas_system_facade::getModel() const
{
    return sensorModel;
}

