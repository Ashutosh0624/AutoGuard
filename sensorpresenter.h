#pragma once
#include <QObject>
#include "adas_system_facade.h"
#include "warning_strategy.h"

class sensorPresenter : public QObject
{
    Q_OBJECT

    //QML accessible properties
    Q_PROPERTY(float speed READ speed NOTIFY SensorDataUpdated)
    Q_PROPERTY(float brake READ brake NOTIFY SensorDataUpdated)
    Q_PROPERTY(float throttle READ throttle NOTIFY SensorDataUpdated)
    Q_PROPERTY(float laneOffset READ laneOffset NOTIFY SensorDataUpdated)
    Q_PROPERTY(float acceleration READ acceleration NOTIFY SensorDataUpdated)
    Q_PROPERTY(float steering READ steering NOTIFY SensorDataUpdated)
    Q_PROPERTY(QString trafficSign READ trafficSign NOTIFY SensorDataUpdated)
    Q_PROPERTY(QString status READ status NOTIFY SensorDataUpdated)

public:
    explicit sensorPresenter(QObject *parent = nullptr);
    ~sensorPresenter();

    // Exposed getters
            float speed() const;
            float acceleration() const;
            float steering() const;
            float brake() const;
            float throttle() const;
            float laneOffset() const;
            QString trafficSign() const;
            QString status() const;


    void updateSensorData(); // called by timer or external trigger
    void setStrategy(WarningStrategy* newstrategy); // set at runtime (via factory);

signals:
    void SensorDataUpdated();
    void warningLevelChanged(const QString& level);


private:
    adas_system_facade *system;
    WarningStrategy *strategy;

};


