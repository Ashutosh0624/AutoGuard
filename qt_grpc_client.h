#ifndef QT_GRPC_CLIENT_H
#define QT_GRPC_CLIENT_H

#include <string>
#include "carla.grpc.pb.h"
#include "carla.pb.h"
#include <grpcpp/grpcpp.h>
#include "SensorData.h"


class QtGrpcClient {
public:
    QtGrpcClient(const std::string& server_address = "localhost:50051");
    SensorData getSensorData();

private:
    std::unique_ptr<carla::CarlaDataService::Stub> stub_;
};

#endif // QT_GRPC_CLIENT_H
