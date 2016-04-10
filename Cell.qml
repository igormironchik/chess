
import QtQuick 2.0

Item {
    id: cell

    width: 50
    height: 50

    property alias cellColor: rectangle.color
    property int chessX
    property int chessY

    signal clicked( int x, int y )
    signal hovered( int x, int y )

    function clearColor() {
        blue.visible = false
        red.visible = false
    }

    function markBlue() {
        blue.visible = true
    }

    function markRed() {
        red.visible = true
    }

    Rectangle {
        id: rectangle
        anchors.fill: parent
    }

    Rectangle {
        id: blue
        visible: false
        anchors.fill: parent
        color: "#880000FF"
    }

    Rectangle {
        id: red
        visible: false
        anchors.fill: parent
        color: "#88FF0000"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

        onClicked: cell.clicked( chessX, chessY )
        onEntered: cell.hovered( chessX, chessY )
    }
}
