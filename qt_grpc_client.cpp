#include "qt_grpc_client.h"
#include <QDebug>

QtGrpcClient::QtGrpcClient(const std::string& server_address) {
    auto channel = grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials());
    stub_ = carla::CarlaDataService::NewStub(channel);
}

SensorData QtGrpcClient::getSensorData() {
    SensorData data;
    carla::EmptyRequest request;
    carla::SensorResponse response;
    grpc::ClientContext context;

    grpc::Status status = stub_->GetSensorData(&context, request, &response);



    if (status.ok()) {
        qDebug() << "[✔] gRPC call successful";
        data.speed = response.speed();
        data.acceleration = response.acceleration();
        data.steering = response.steering();
        data.brake = response.brake();
        data.throttle = response.throttle();
        data.lane_offset = response.lane_offset();
        data.traffic_sign = response.traffic_sign();
        data.status = response.status();
        data.sensor_ok = response.sensor_ok();  // ✅ Directly use from gRPC message
        data.errorCode = 0; // no error

    } else {
        qDebug() << "[❌] gRPC call failed:" << QString::fromStdString(status.error_message());
        data.status = "Error: " + status.error_message();
        data.sensor_ok = false;
        data.errorCode = 101; // custom error code for gRPC failure
    }

    qDebug() << "Fetched Sensor Data:"
                 << "Speed:" << data.speed
                 << "Steering:" << data.steering
                 << "SensorOK:" << data.sensor_ok;


    return data;
}
