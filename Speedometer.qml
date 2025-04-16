// Speedometer.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 300
    height: 300
    property real speed: 0

    Rectangle {
        id: dial
        anchors.fill: parent
        radius: width / 2
        color: "#1e1e1e"
        border.color: "#ffffff"
        border.width: 2
        clip: false  // 🔥 disable this to avoid clipping ticks
    }

    // ✅ Tick marks placed manually using trig, NO rotation
    Repeater {
        model: 9  // 0 to 240 km/h
        delegate: Rectangle {
            width: 2
            height: 12
            color: "white"
            radius: 1

            property real angle: index * 30 * Math.PI / 180
            property real r: (root.width / 2) - 10

            x: root.width / 2 + Math.cos(angle) * r - width / 2
            y: root.height / 2 + Math.sin(angle) * r - height / 2
        }
    }

    // ✅ Speed text in center
    Text {
        anchors.centerIn: parent
        text: Number(speed).toFixed(2) + " km/h"
        color: "white"
        font.pixelSize: 22
        font.bold: true
    }

    // ✅ Animated Needle
    Rectangle {
        id: needle
        width: 4
        height: root.height / 2 - 20
        color: "red"
        radius: 2
        anchors.centerIn: parent

        transform: [
            Rotation {
                id: needleRotation
                origin.x: needle.width / 2
                origin.y: needle.height
                angle: speed * 1.5
            }
        ]

        Behavior on transform {
            NumberAnimation { duration: 300; easing.type: Easing.InOutQuad }
        }
    }
}
