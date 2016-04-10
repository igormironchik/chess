
import QtQuick.Window 2.2
import QtQuick 2.0

Window {
    id: appWindow
    visible: true

    width: 16 * 2 + 50 * 8
    height: 16 * 2 + 50 * 8

    Rectangle {
        id: rect
        anchors.fill: parent

        Board {
            id: board
            anchors.horizontalCenter: rect.horizontalCenter
            anchors.verticalCenter: rect.verticalCenter

            objectName: "board"
        }
    }
}
