import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1

ApplicationWindow {
    id: mainWindow
    width: 640
    height: 500
    visible: true
    title: "Выбор файла с ответами"
    signal mouseClicked()
    property int number: 0
    property int currentIndexClicked: -1

    function setPatternRecognitionArray(patternRecognitionMas) {
        console.log(patternRecognitionMas)
        patternRecognitionArrayViewModel.append({patternRecognitionText: "test2 answers"})
        for(var i = 0; i < patternRecognitionMas.length; i++)
            patternRecognitionArrayViewModel.append({patternRecognitionText: patternRecognitionMas[i]})
    }


    RowLayout {
        id: col
        width: 320
        height: 410
        ColumnLayout {
            width: 320
            height: 410
            Rectangle {
                id: textPatternReviewId
                width: parent.width
                height: 23
                Text {
                    id: textPatternReviewIdtext
                    text: qsTr("Очередь файлов ответов")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            Rectangle {
                width: 320
                height: 2
                color: "black"
            }
            Rectangle {
                id: prostRect
                width: parent.width
                height: parent.height
                ListView {
                    id: patternRecognitionArray
                    anchors.fill: parent
                    spacing: 15
                    clip: true
                    anchors.top: parent.bottom
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right

                    delegate: Item {
                        anchors.left: parent.left
                        anchors.right: parent.right
                        height: 35
                        Text {
                            text: patternRecognitionText
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 16
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                currentIndexClicked = index
                                patternRecognitionArray.currentIndex = index
                            }
                        }

                        Rectangle {
                            width: 300
                            height: 40
                            color: "transparent"
                            border{
                                color: {
                                    var colorM = "#ffbd00"
                                    if(patternRecognitionArray.currentIndex == index)
                                        colorM = "#157efb"
                                    return colorM
                                }
                                width: 2
                            }
                        }
                    }
                    ScrollBar.vertical: ScrollBar { visible: true }
                    model: ListModel {
                        id: patternRecognitionArrayViewModel
                    }

                    onCurrentItemChanged: {
                        currentIndexClicked = patternRecognitionArray.currentIndex
                    }
                }
            }

        }
    }

    Rectangle {
        id: borderId
        anchors.left: col.right
        height: 460
        width: 2
        color: "black"
    }


    Column {
        width: 318
        height: 410
        anchors.left: borderId.right
        //anchors.leftMargin: 10

        Rectangle {
            id: properiesId
            width: parent.width
            height: 30
            Text {
                id: properiesIdText
                text: qsTr("Свойства")
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

        Rectangle {
            width: 320
            height: 2
            color: "black"
        }

        Rectangle {
            height: 10
            width: 320
        }

        Column {
            spacing: 15

            Row {
                Label {
                    anchors.leftMargin: 10
                    text: qsTr("    Количество вопросов = ")
                }
                Label {
                    text: {
                        if(currentIndexClicked >= 0)
                            return "40"
                        else
                            return "62"
                    }
                }
            }

            Row {
                Label {
                    anchors.leftMargin: 10
                    text: qsTr("    Количество ответов = ")
                }
                Label {
                    text: {
                        if(currentIndexClicked >= 0)
                            return numbersOfReplies
                        else
                            return "1"
                    }
                }
            }

            // Row {
            //     Label {
            //         anchors.leftMargin: 10
            //         text: qsTr("    Количество  = ")
            //     }
            //     Label {
            //         text: {
            //             if(currentIndexClicked >= 0)
            //                 return numberOfRecognitionArea
            //             else
            //                 return "NULL"
            //         }
            //     }
            // }
        }
    }

    Button {
        anchors.topMargin: 50
        width: mainWindow.width
        height: 25
        text: qsTr("Выбрать")
        anchors.top: col.bottom
        color: "#c2cbc3"
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

