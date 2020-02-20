
import QtQuick 2.0
import QtQuick.Controls 2.4
import ChessSignals 1.0

Dialog {
    id: transform

    property size appWindowSize;

    title: qsTr( "Choose figure..." )
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape
    x: appWindowSize.width / 2 - width / 2
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

        RadioButton {
            checked: true
            text: qsTr( "Queen" )

            onClicked: {
                column.figure = Chess.Queen
            }
        }

        RadioButton {
            text: qsTr( "Castle" )

            onClicked: {
                column.figure = Chess.Castle
            }
        }

        RadioButton {
            text: qsTr( "Knight" )

            onClicked: {
                column.figure = Chess.Knight
            }
        }

        RadioButton {
            text: qsTr( "Bishop" )

            onClicked: {
                column.figure = Chess.Bishop
            }
        }

        Rectangle {
            height: 25
            width: column.width
        }

        Button {
            text: qsTr( "OK" )
            anchors.right: column.right

            onClicked: {
                close()
            }
        }
    }
}
