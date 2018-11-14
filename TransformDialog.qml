
import QtQuick 2.0
import QtQuick.Controls 2.4
import ChessSignals 1.0
import QtQuick.Layouts 1.11

Dialog {
    id: transform

    property size appWindowSize;

    title: qsTr( "Choose figure..." )
    standardButtons: Dialog.Ok
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape
    x: appWindowSize.width / 2 - width / 2
    y: appWindowSize.height / 2 - height / 2
    width: column.width * 2

    property int color: Chess.White
    property int fx: -1
    property int fy: -1
    property int figure: Chess.Queen

    ColumnLayout {
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
    }
}
