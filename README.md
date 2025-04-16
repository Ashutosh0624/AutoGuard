# AutoGuard
 AutoGrad:A real-time Advanced Driver Assistance System (ADAS) that uses CARLA simulator for sensor data, Python-based gRPC server for communication, and a modern Qt/QML frontend for visual lane and vehicle state awareness. Built with industrial-grade design patterns, IPC, and edge-ready architecture.


# AutoGrad: Real-Time ADAS System with CARLA + Qt + gRPC

**AutoGrad** is an industrial-grade, real-time **Advanced Driver Assistance System (ADAS)** designed to simulate and visualize driver warnings based on live sensor data from the **CARLA simulator**. The project demonstrates end-to-end system design using:

- 🧠 **CARLA simulator** for real-time driving environment data
- 🔄 **Python-based gRPC server** for high-performance communication
- 🖥️ **Qt/QML frontend** for animated visual dashboard and alerts
- 🛠️ **Design Patterns** (Strategy, Facade, Factory, Observer)
- 📦 **IPC with `multiprocessing.Manager().dict()`** for Python inter-process communication
- ⚙️ **Singleton Loggers, Config Parsers, and Error Managers** for modular development

---

## 🚀 Key Features

- Fetches real-time sensor data (speed, lane offset, brake, acceleration, etc.)
- Shows animated **speedometer**, **lane offset symbols**, and **visual alerts**
- Scalable **MVP architecture** using SOLID principles
- Designed for **Edge AI adaptation** and embedded deployment
- Full error handling, multithreading, and system logging implemented

---

## 🔧 Tech Stack

| Component | Tech Used |
|----------|-----------|
| Simulator | [CARLA 0.9.13](https://carla.org) |
| Backend | Python 3.10, gRPC, Protobuf |
| Frontend | Qt 6, QML, C++ |
| Communication | gRPC + IPC |
| Architecture | MVP + Design Patterns |
| Target | Embedded Linux, Edge Devices |

---

## 📁 Project Structure

AutoGrad/ ├── grpc_server/ # gRPC server handling sensor requests ├── carla_data_collector/ # Fetches real-time sensor data from CARLA ├── qt_qml_client/ # Qt/QML frontend with gRPC client ├── proto/ # Protobuf definitions ├── configs/ # App config files (.conf) ├── docs/ # Architecture diagrams and explanations ├── README.md └── LICENSE


---

## 🧪 Upcoming Features

- [ ] CAN Bus data simulation with SocketCAN
- [ ] Embedded deployment script (Yocto/Linux)
- [ ] Lane departure prediction using deep learning (optional)
- [ ] IEEE journal submission ready

---

## 🤝 Contributors

Made with passion by [Ashutosh Tiwari](https://github.com/Ashutosh0624)  
Let's build safer autonomous systems together!
