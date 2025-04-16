// WarningDialogue.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Dialog {
    id: dialog
    property string warningText: ""

    title: "Warning!"
    modal: true
    standardButtons: Dialog.Ok

    contentItem: Text {
        text: warningText
        wrapMode: Text.Wrap
        color: "red"
        font.pixelSize: 20
    }
}
