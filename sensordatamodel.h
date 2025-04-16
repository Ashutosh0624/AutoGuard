#ifndef SENSORDATAMODEL_H
#define SENSORDATAMODEL_H

#include <QObject>
#include <QTimer>
#include "qt_grpc_client.h"

// FS-REQ ID: FS-REQ-001 for initialization logging
// FS-REQ ID: FS-REQ-002 for periodic data polling
// FS-REQ ID: FS-REQ-003 for error monitoring

class SensorDataModel : public QObject
{
    Q_OBJECT

public:
    explicit SensorDataModel(QObject* parent = nullptr);
    ~SensorDataModel();

    Q_PROPERTY(float speed READ speed NOTIFY speedChanged)
    Q_PROPERTY(float acceleration READ acceleration NOTIFY accelerationChanged)
    Q_PROPERTY(float steering READ steering NOTIFY steeringChanged)
    Q_PROPERTY(float brake READ brake NOTIFY brakeChanged)
    Q_PROPERTY(float throttle READ throttle NOTIFY throttleChanged)
    Q_PROPERTY(float laneOffset READ laneOffset NOTIFY laneOffsetChanged)
    Q_PROPERTY(QString trafficSign READ trafficSign NOTIFY trafficSignChanged)
    Q_PROPERTY(QString status READ status NOTIFY statusChanged)

    float speed() const;
    float acceleration() const;
    float steering() const;
    float brake() const;
    float throttle() const;
    float laneOffset() const;
    QString trafficSign() const;
    QString status() const;

    SensorData fetchSensorData();
signals:
        void speedChanged();
        void accelerationChanged();
        void steeringChanged();
        void brakeChanged();
        void throttleChanged();
        void laneOffsetChanged();
        void trafficSignChanged();
        void statusChanged();
        void errorOccurred(const QString &errorMessage);

private slots:
    void pollSensorData();

private:
    QTimer* m_timer;
    QtGrpcClient m_client;
    SensorData m_data;

    void handleErrors(const QString& context, const QString& fsReqId);
};

#endif // SENSORDATAMODEL_H
