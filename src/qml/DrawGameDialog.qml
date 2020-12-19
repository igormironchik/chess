
import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Window 2.15

Dialog {
    property size appWindowSize;
    property real radioSize: Screen.pixelDensity * 4

    title: qsTr( "Draw Game..." )
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    width: appWindowSize.width
    height: Math.max( appWindowSize.height / 2, column.height + implicitHeaderHeight + 10 )
    x: 0
    y: appWindowSize.height / 2 - height / 2

    Column {
        anchors.centerIn: parent
        id: column

        Text {
            font.pointSize: 30
            font.bold: true
            text: qsTr( "Draw Game!!!" )
        }

        Rectangle {
            height: 25
            width: column.width
        }

        Button {
            text: qsTr( "OK" )
            anchors.right: column.right
            implicitHeight: radioSize * 2.5
            implicitWidth: radioSize * 5

            onClicked: {
                close()
            }
        }
    }
}
