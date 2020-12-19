
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.15

RadioButton {
    id: control

    property real radioSize: Screen.pixelDensity * 4

    font.pointSize: 14

    indicator: Rectangle {
        implicitWidth: radioSize
        implicitHeight: radioSize

        x: control.leftPadding
        y: parent.height / 2 - height / 2
        radius: radioSize / 2
        border.color: control.visualFocus ? control.palette.highlight : control.palette.mid

        Rectangle {
            width: radioSize - 15
            height: radioSize - 15
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            radius: width / 2
            color: control.palette.text
            visible: control.checked
        }
    }

    contentItem: Text {
        text: control.text
        font: control.font
        opacity: enabled ? 1.0 : 0.3
        color: control.palette.windowText
        verticalAlignment: Text.AlignVCenter
        leftPadding: control.indicator.width + control.spacing
    }
}
