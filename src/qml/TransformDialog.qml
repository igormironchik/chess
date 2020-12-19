
import QtQuick 2.0
import QtQuick.Controls 2.4
import ChessSignals 1.0
import QtQuick.Window 2.15

Dialog {
    id: transform

    property size appWindowSize;
    property real radioSize: Screen.pixelDensity * 4

    title: qsTr( "Choose figure..." )
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape
    width: appWindowSize.width
    height: Math.max( appWindowSize.height / 2, column.height + implicitHeaderHeight + 10 )
    x: 0
    y: appWindowSize.height / 2 - height / 2

    property int color: Chess.White
    property int fx: -1
    property int fy: -1
    property int figure: Chess.Queen

    Column {
        anchors.centerIn: parent
        id: column

        ButtonGroup {
            buttons: column.children
        }

        property alias figure: transform.figure

        TransformRadioButton {
            checked: true
            text: qsTr( "Queen" )

            onClicked: {
                column.figure = Chess.Queen
            }
        }

        TransformRadioButton {
            text: qsTr( "Castle" )

            onClicked: {
                column.figure = Chess.Castle
            }
        }

        TransformRadioButton {
            text: qsTr( "Knight" )

            onClicked: {
                column.figure = Chess.Knight
            }
        }

        TransformRadioButton {
            text: qsTr( "Bishop" )

            onClicked: {
                column.figure = Chess.Bishop
            }
        }

        Rectangle {
            height: radioSize * 1.5
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
