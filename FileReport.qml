import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1
import QtQml 2.4

ApplicationWindow {
    id: mainWindow
    title: qsTr("Выбор файла с ответами")
    width: 640
    height: 600
    visible: true
    signal mouseClicked()
    property string idPatternRecognition: "0"
    property string numberQuestion: "60"
    property string numbersOfReplies: "6"
    property string numberOfRecognitionArea: "65"
    property var patternRecognitionMas: []
    property int number: 0
    property int currentIndexClicked: -1
    property bool singleReport: false
    color: "#c4cad1"


    Rectangle {
        id: bufRect
        width: parent.width
        height: 20
        color: "#c4cad1"
    }

    Row {
        id: rowE
        anchors.top: bufRect.bottom
        width: parent.width
        height: 540


        ColumnLayout {
            spacing: 15
            width: 350
            height: parent.height
            Rectangle {
                id: lbl1
                height: 20
                Text {
                    text: qsTr("    Дата создания отчета  = ")
                    font.pixelSize: 18
                }
            }
            Rectangle {
                id: lbl2
                height: 20
                //anchors.top: lbl1.bottom
                Text {
                    text: qsTr("    Дата проведения тестирования  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl3
                height: 20
                //anchors.top: lbl2.bottom
                Text {
                    text: qsTr("    Создан  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl4
                height: 20
                //anchors.top: lbl3.bottom
                Text {
                    text: qsTr("    Количество файлов  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl5
                height: 20
                visible: singleReport
                //anchors.top: lbl4.bottom
                Text {
                    text: qsTr("    Количество вопросов  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl6
                height: 20
                visible: singleReport
                //anchors.top: lbl5.bottom
                Text {
                    text: qsTr("    Количество правильных ответов  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl7
                height: 20
                //anchors.top: lbl6.bottom
                Text {
                    text: qsTr("    Шаблон распознавания  = ")
                    font.pixelSize: 18
                }
            }

            Rectangle {
                id: lbl8
                height: 20
                //anchors.top: lbl7.bottom
                Text {
                    text: qsTr("    Файл с ответами  = ")
                    font.pixelSize: 18
                }
            }

        }

        Rectangle {
            height: parent.height
            width: 2
            color: "black"
        }

        ColumnLayout {
            spacing: 15
            width: 286
            height: parent.height

            Rectangle {
                width: 200
                height: 28
                color: "white"
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16
                    text: new Date().toLocaleDateString(Qt.locale("ru_RU"), Locale.ShortFormat)
                }
            }
            Rectangle {
                height: 28
                width: 200
                color: "white"
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16
                    text: new Date().toLocaleDateString(Qt.locale("ru_RU"), Locale.ShortFormat)
                }
            }
            Rectangle {
                height: 28
                width: 200
                color: "white"
                TextInput{
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16
                    text: "people"

                }
            }
            Rectangle {
                height: 28
                width: 200
                color: "white"
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    text: "qw"
                    font.pixelSize: 16

                }
            }
            Rectangle {
                height: 28
                width: 200
                color: "white"
                visible: singleReport
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16

                }
            }
            Rectangle {
                height: 28
                width: 200
                color: "white"
                visible: singleReport
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16

                }
            }

            Rectangle {
                height: 28
                width: 200
                color: "white"
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16

                }
            }

            Rectangle {
                height: 28
                width: 200
                color: "white"
                TextInput {
                    anchors.leftMargin: 5
                    anchors.fill: parent
                    font.pixelSize: 16

                }
            }
        }

    }

    Button {
        anchors.top: rowE.bottom
        width: parent.width
        height: 24
        Text {
            text: "Сохранить"
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 18
        }
        onClicked: {
            msgDialog.open()
        }
    }


    MessageDialog {
        id: msgDialog
        title: "Выбор"
        icon: StandardIcon.Question
        text: "Вы уверены?"
        standardButtons: StandardButton.Yes | StandardButton.No
        onYes: procClick()
    }
    function procClick() {
        mainWindow.mouseClicked()
        mainWindow.close()
    }
}

