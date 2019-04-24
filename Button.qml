import QtQuick 2.12

Rectangle {
    id: mybutton

    //Добавляем к кнопке свойство text,
    //в которое можно будет что-нибудь записать.
    //Это будет текст нашей кнопки
    property string text
    signal clicked
//    radius: 5

//    //Ширина и высота кнопки по умолчанию
//    implicitWidth: buttonText.width + radius
//    implicitHeight: buttonText.height + radius

    //Непосредственно элемент, рисующий текст кнопки
    Text {
        id: buttonText
        //По центру кнопки
        anchors.centerIn: parent
        text: mybutton.text
    }
    MouseArea{
        anchors.fill: parent
        onClicked: mybutton.clicked()
    }
}
