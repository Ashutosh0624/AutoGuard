#include "sensorpresenter.h"
#include "strategy_factory.h"
#include "logger.h"
#include "configparser.h"

sensorPresenter::sensorPresenter(QObject *parent)
    : QObject{parent}, system{new adas_system_facade()}
{
     // Initialize ADAS system and model
     system->initSystem();

     //connect internal model's signal to this presenter's notifier
     //QObject::connect(system->getModel(), &SensorDataModel::speedChanged, this, &sensorPresenter::SensorDataUpdated);
     // Connect all individual property signals (optional but good)
     connect(system->getModel(), &SensorDataModel::speedChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::accelerationChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::steeringChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::brakeChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::throttleChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::laneOffsetChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::trafficSignChanged, this, &sensorPresenter::SensorDataUpdated);
     connect(system->getModel(), &SensorDataModel::statusChanged, this, &sensorPresenter::SensorDataUpdated);


     //Initialize strategy from config
     QString mode = ConfigParser::getInstance()->getValue("Warning", "mode", "mild").toString();
     strategy = StrategyFactory::createStrategy(mode);

     logger::getInstance()->log("SensorPresenter initialized successfully.",
                                Level::INFO,
                                "sensorPresenter",
                                "FS-PRESENTER-INIT");
}

sensorPresenter::~sensorPresenter()
{
    delete strategy;
    delete system;
}

void sensorPresenter::updateSensorData()
{
    SensorData data = system->getLiveData();

    emit SensorDataUpdated();

    if(strategy){
        QString warning = strategy->getWarningLevel(data);
        emit warningLevelChanged(warning);
    }
}

void sensorPresenter::setStrategy(WarningStrategy *newstrategy)
{
   if(strategy) delete strategy;
   strategy = newstrategy;
}

// *****************Getter function************************************
float sensorPresenter::speed() const {
    return system->getModel()->speed();
}

float sensorPresenter::acceleration() const {
    return system->getModel()->acceleration();
}

float sensorPresenter::steering() const {
    return system->getModel()->steering();
}

float sensorPresenter::brake() const {
    return system->getModel()->brake();
}

float sensorPresenter::throttle() const {
    return system->getModel()->throttle();
}

float sensorPresenter::laneOffset() const {
    return system->getModel()->laneOffset();
}

QString sensorPresenter::trafficSign() const {
    return system->getModel()->trafficSign();
}

QString sensorPresenter::status() const {
    return system->getModel()->status();
}

