
/*!
    \file

    \author Igor Mironchik (igor.mironchik at gmail dot com).

    Copyright (c) 2016 Igor Mironchik

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.7

Image {
    property bool enabled: false
    source: "qrc:/img/undo_disabled.png"

    MouseArea {
        anchors.fill: parent

        onPressed: {
            if( undoBtn.enabled )
                undoBtn.source = "qrc:/img/undo_clicked.png"
        }

        onReleased: {
            if( undoBtn.enabled )
                undoBtn.source = "qrc:/img/undo.png"
        }

        onClicked: {
            board.undo()
            disable()
        }
    }

    Connections {
        target: board

        onRotationStarted: {
            disable()
        }

        onRotationDone: {
            if( gameImpl.turnsCount() > 1 )
                enable()
        }
    }

    function disable() {
        enabled = false
        source = "qrc:/img/undo_disabled.png"
    }

    function enable() {
        enabled = true
        source = "qrc:/img/undo.png"
    }
}
