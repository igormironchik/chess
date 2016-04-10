
import QtQuick 2.5

Rectangle {
    id: rect
    width: 50
    height: 50
    color: "transparent"

    property alias source: image.source

    Image {
        width: 45
        height: 45
        id: image
        anchors.horizontalCenter: rect.horizontalCenter
        anchors.verticalCenter: rect.verticalCenter
        fillMode: Image.PreserveAspectFit
        horizontalAlignment: Image.AlignHCenter
        verticalAlignment: Image.AlignVCenter
    }
}
