import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "LaneSense - ADAS Dashboard"

    Rectangle {
        anchors.fill: parent
        anchors.margins: 20
        color: "#121212"

        RowLayout {
            anchors.fill: parent
            spacing: 20

            // 🔷 Left Column: Speedometer + Warning
            ColumnLayout {
                Layout.preferredWidth: parent.width * 0.6
                Layout.fillHeight: true
                spacing: 20

                Rectangle {
                    Layout.preferredHeight: 400
                    Layout.fillWidth: true
                    color: "#1e1e1e"
                    radius: 12

                    Speedometer {
                        anchors.centerIn: parent
                        speed: presenter.speed
                        width: 250
                        height: 250
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100
                    color: "#292929"
                    radius: 8

                    Row {
                        anchors.centerIn: parent
                        spacing: 10
                        Text {
                            text: "System Status: " + presenter.status
                            color: "white"
                            font.pixelSize: 18
                        }

                        Button {
                            text: "Show Warning"
                            onClicked: warningDialog.open()
                        }
                    }
                }
            }

            // 🔷 Right Column: LaneOffsetSymbol + Info Blocks
            ColumnLayout {
                Layout.preferredWidth: parent.width * 0.4
                Layout.fillHeight: true
                spacing: 20

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 120
                    color: "#1e1e1e"
                    radius: 8

                    LaneOffsetSymbol {
                        offset: presenter.laneOffset
                        width: 200
                        height: 100
                        anchors.centerIn: parent
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100
                    color: "#1e1e1e"
                    radius: 8

                    Text {
                        anchors.centerIn: parent
                        text: "Traffic Sign: " + presenter.trafficSign
                        color: "white"
                        font.pixelSize: 20
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 100
                    color: "#1e1e1e"
                    radius: 8

                    Text {
                        anchors.centerIn: parent
                        text: "Acceleration: " + Number(presenter.acceleration).toFixed(2)
                        color: "white"
                        font.pixelSize: 20
                    }
                }
            }
        }

        // 🔔 Warning Dialog (overlay)
        WarningDialogue {
            id: warningDialog
            warningText: presenter.status
        }
    }
}
