#include "sensordatamodel.h"
#include "logger.h"
#include "errormanager.h"
#include "configparser.h"

SensorDataModel::SensorDataModel(QObject* parent)
    : QObject(parent), m_timer(new QTimer(this))
{
    // FS-REQ-001: Initialization Logging
    logger::getInstance()->log("[INIT] SensorDataModel created.",
                               Level::INFO, "SensorDataModel", "FS-REQ-001");

    int pollingInterval = ConfigParser::getInstance()
                            ->getValue("ADAS", "polling_interval_ms", 500)
                            .toInt();

    connect(m_timer, &QTimer::timeout, this, &SensorDataModel::pollSensorData);
    m_timer->start(pollingInterval);
}

SensorDataModel::~SensorDataModel()
{
    if (m_timer != nullptr)
    {
        m_timer->stop();
    }
    logger::getInstance()->log("[DESTROY] SensorDataModel destroyed.",
                               Level::INFO, "SensorDataModel", "FS-REQ-001");
}

void SensorDataModel::pollSensorData()
{
    // FS-REQ-002: Periodic Sensor Data Polling
    try
    {
        SensorData newData = m_client.getSensorData();

        if (!newData.sensor_ok) {
            handleErrors("Sensor system not running", "FS-REQ-003");
            return;
        }

        // Compare old vs new, and emit signal if value changed
                if (m_data.speed != newData.speed) emit speedChanged();
                if (m_data.acceleration != newData.acceleration) emit accelerationChanged();
                if (m_data.steering != newData.steering) emit steeringChanged();
                if (m_data.brake != newData.brake) emit brakeChanged();
                if (m_data.throttle != newData.throttle) emit throttleChanged();
                if (m_data.lane_offset != newData.lane_offset) emit laneOffsetChanged();
                if (m_data.traffic_sign != newData.traffic_sign) emit trafficSignChanged();
                if (m_data.status != newData.status) emit statusChanged();

                m_data = newData; // finally update all data at once
    }
    catch (const std::exception& ex)
    {
        handleErrors(ex.what(), "FS-REQ-003");
    }
    catch (...)
    {
        handleErrors("Unknown error occurred while polling sensor data", "FS-REQ-003");
    }
}

void SensorDataModel::handleErrors(const QString& context, const QString& fsReqId)
{
    logger::getInstance()->log("[ERROR] " + context,
                               Level::ERROR, "SensorDataModel", fsReqId);
    errorManager::getInstance()->handleCriticalSystemError(context, fsReqId);
    emit errorOccurred(context);
}

// ----------------- Q_PROPERTY Getters -----------------

float SensorDataModel::speed() const
{
    return m_data.speed;
}

float SensorDataModel::acceleration() const
{
    return m_data.acceleration;
}

float SensorDataModel::steering() const
{
    return m_data.steering;
}

float SensorDataModel::brake() const
{
    return m_data.brake;
}

float SensorDataModel::throttle() const
{
    return m_data.throttle;
}

float SensorDataModel::laneOffset() const
{
    return m_data.lane_offset;
}

QString SensorDataModel::trafficSign() const
{
    return QString::fromStdString(m_data.traffic_sign);
}

QString SensorDataModel::status() const
{
    return QString::fromStdString(m_data.status);
}

SensorData SensorDataModel::fetchSensorData()
{
  m_data = m_client.getSensorData(); // gRPC call to the backend

  if(!m_data.sensor_ok){
      handleErrors("Sensor data fetching failed", "FS-REQ-003");
  }
  return m_data;
}
