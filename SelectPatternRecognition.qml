import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.1

ApplicationWindow {
    id: mainWindow
    title: qsTr("Выбор шаблона распознавания")
    width: 640
    height: 500
    visible: true
    signal mouseClicked()
    property string idPatternRecognition: "0"
    property string numberQuestion: "60"
    property string numbersOfReplies: "6"
    property string numberOfRecognitionArea: "65"
    property int number: 0
    property int currentIndexClicked: -1

    function setPatternRecognitionArray(patternRecognitionMas) {
        console.log(patternRecognitionMas)
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
                    text: qsTr("Очередь шаблонов проектирования")
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
                            return numberQuestion
                        else
                            return "NULL"
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
                            return "NULL"
                    }
                }
            }

            Row {
                Label {
                    anchors.leftMargin: 10
                    text: qsTr("    Количество распознаваемых областей = ")
                }
                Label {
                    text: {
                        if(currentIndexClicked >= 0)
                            return numberOfRecognitionArea
                        else
                            return "NULL"
                    }
                }
            }
        }
    }

    Button {
        id: control
        anchors.topMargin: 50
        width: mainWindow.width
        height: 25
        text: qsTr("Выбрать")
        anchors.top: col.bottom
        color: "gray"

        // contentItem: Text {
        //     text: control.text
        //     font: control.font
        //     opacity: enabled ? 1.0 : 0.3
        //     color: control.down ? "#c2cbc3" : "black"
        //     horizontalAlignment: Text.AlignHCenter
        //     verticalAlignment: Text.AlignVCenter
        //     elide: Text.ElideRight
        // }

        // background: Rectangle {
        //     implicitWidth: parent.width
        //     implicitHeight: parent.height
        //     opacity: enabled ? 1 : 0.3
        //     border.color: control.down ? "black" : "#808080"
        //     border.width: 1
        //     radius: 2
        // }

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

