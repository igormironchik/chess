
import QtQuick 2.0
import QtQuick.Controls 2.2

Dialog {
    property size appWindowSize;
    property string turnText;

    title: qsTr( "Checkmate..." )
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    x: appWindowSize.width / 2 - width / 2
    y: appWindowSize.height / 2 - height / 2

    Column {
        anchors.centerIn: parent
        id: column

        Text {
            font.pixelSize: 30
            font.bold: true
            text: ( turnText === qsTr( "Black" ) ?
                qsTr( "White" ) : qsTr( "Black" ) ) + qsTr( " won!!!" )
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
