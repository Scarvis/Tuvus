import QtQuick 2.0

Component {
    id: delegateItem
    Item{
        Rectangle {
            width: parent.width
            height: 120
            Image {
                id: imageItem
                width: 150
                height: 105
                source: pathFile
            }
            Text {
                id: itexItem
                anchors.top: imageItem.bottom
                font.family: "Alias"
                //anchors.centerIn: imageItem.anchors.centerIn
                anchors.horizontalCenter: imageItem.anchors.horizontalCenter
                anchors.topMargin: 5
                //anchors.leftMargin: 50
//                anchors.verticalCenter: parent.verticalCenter
//                anchors.horizontalCenter: parent.horizontalCenter

                font.pixelSize: 14
                // delegate can directly use ListElement role name
                text: nameFile
                scale: {
                    x: "1.0001"
                    y: "1.0001"
                }
            }
        }
    }
}

