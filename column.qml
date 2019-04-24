import QtQuick 2.0

Square {
    id: root
    width: 120
    height: 240

    Column {
        id: row
        anchors.centerIn: parent
        spacing: 8
        Square { color: Red }
        Square { color: Green
            width: 96 }
        Square { color: Blue }
    }
}
