// LaneOffsetSymbol.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 220
    height: 100
    property real offset: 0.0  // Actual offset from backend (can be -36 to +36)

    // Normalized for UI (-1 to +1 range)
    property real normalizedOffset: Math.max(-1, Math.min(1, offset / 40))

    Rectangle {
        id: lane
        anchors.fill: parent
        radius: 10
        color: "#1e1e1e"
        border.color: "#444"
        border.width: 1
        clip: true

        // Offset value in center
        Text {
            anchors.centerIn: parent
            text: "Lane Offset: " + Number(offset).toFixed(2)
            color: offset >= 1 ? "red" : offset >= 0.5 ? "orange" :
                   offset <= -1 ? "red" : offset <= -0.5 ? "orange" : "lightgreen"
            font.pixelSize: 18
            font.bold: true
        }

        // Horizontal scale bar
        Rectangle {
            id: scaleBar
            width: parent.width * 0.9
            height: 10
            radius: 5
            color: "#333"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 15

            // Moving indicator bar
            Rectangle {
                id: indicator
                width: 8
                height: 20
                radius: 2
                color: offset >= 1 ? "red" : offset >= 0.5 ? "orange" :
                       offset <= -1 ? "red" : offset <= -0.5 ? "orange" : "green"

                y: -5
                x: (scaleBar.width / 2) + normalizedOffset * (scaleBar.width / 2) - width / 2

                Behavior on x {
                    NumberAnimation { duration: 250; easing.type: Easing.InOutQuad }
                }
            }
        }
    }
}
