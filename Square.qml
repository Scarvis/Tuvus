import QtQuick 2.5

Rectangle {
    id: squareId
    width: 56; height: 56
    signal clicked
    property string colorSquare: "red"
    property alias text: squareIdText.text

    color: colorSquare

    border.color: Qt.lighter(color)
    Text {
        id: squareIdText
        anchors.centerIn: parent
        color: "#f0f0f0"
        //text: "Cell " + index
    }
    MouseArea {
        anchors.fill: parent
        onClicked: squareId.clicked()
    }

    function colorChangeAfterClick(inputAttr){
        squareId.color = inputAttr
        colorSquare = inputAttr
    }
}
