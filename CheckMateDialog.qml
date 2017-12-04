
import QtQuick 2.0
import QtQuick.Controls 2.2

Dialog {
    property size appWindowSize;
    property string turnText;

    title: qsTr( "Checkmate..." )
    standardButtons: Dialog.Ok
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    x: appWindowSize.width / 2 - width / 2
    y: appWindowSize.height / 2 - height / 2

    Text {
        anchors.centerIn: parent
        font.pixelSize: 30
        font.bold: true
        text: ( turnText === qsTr( "Black" ) ?
            qsTr( "White" ) : qsTr( "Black" ) ) + qsTr( " won!!!" )
    }
}
