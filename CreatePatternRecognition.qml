import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: mainWindow
    width: 1440;
    height: 870
    visible: true
    title: qsTr("Создание шаблона распознавания")
    signal mouseClicked()
    property int currentIndexClicked: -1
    property int number: 0
    property string defaultColorButton: "#c2cbc3"
    property var xArray: []
    property var yArray: []
    property var widthArray: []
    property var heightArray: []
    property string pathImage: ""
    property string pathImageConst: "Scan1.png"
    property bool closeUpImage: false
    property bool saveClicked: false
    Row {
        id: rowMain
        width: 1440;
        height: 800

        Rectangle {
            id: documentClose
            width: 798
            height: 800
            Image {
                id: documentCloseImage
                width: 798
                height: 800
                fillMode: Image.PreserveAspectFit
                source: {
                    if(closeUpImage){
                        return pathImage
                    }
                    else {
                        return pathImageConst
                    }
                }
            }
        }

        Rectangle {
            width: 2
            height: 800
            color: "black"
        }

        Column {
            width: 640
            height: 800

            Rectangle {
                id: satychka
                height: 15
                width: 640
                //color: "yellow"
            }

            Row {
                width: 640
                height: 72
                spacing: 150

                Rectangle{
                    width: 15
                    height: 800
                    //color: "green"
                }

                Label {
                    width: 50
                    height: 72
                    text: "X"
                    font.pixelSize: 48
                }

                Label {
                    width: 50
                    height: 72
                    text: "Y"
                    font.pixelSize: 48
                }
            }

            Row {
                width: 640
                height: 72
                spacing: 75
                Rectangle{
                    width: 15
                    height: 800
                    //color: "pink"
                }

                Rectangle {
                    width: 150
                    height: 72
                    color: "#d3f5dc"
                    TextInput {
                        id: xArea
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 36
                        anchors.fill: parent
                    }
                    border {
                        color: "black"
                        width: 2
                    }
                }

                Rectangle {
                    width: 150
                    height: 72
                    color: "#d3f5dc"
                    TextInput {
                        id: yArea
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 36
                        anchors.fill: parent
                    }
                    border {
                        color: "black"
                        width: 2
                    }
                }
            }

            Row {
                width: 640
                height: 72
                spacing: 100

                Rectangle{
                    width: 15
                    height: 800
                    //color: "green"
                }

                Label {
                    width: 50
                    height: 72
                    text: "Width"
                    font.pixelSize: 48
                    //color: "black"
                }

                Label {
                    width: 50
                    height: 72
                    text: "    Height"
                    font.pixelSize: 48
                }
            }

            Row {
                width: 640
                height: 72
                spacing: 75
                Rectangle{
                    width: 15
                    height: 800
                    //color: "pink"
                }

                Rectangle {
                    width: 150
                    height: 72
                    color: "#d3f5dc"
                    TextInput {
                        id: widthArea
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 36
                        anchors.fill: parent
                    }
                    border {
                        color: "black"
                        width: 2
                    }
                }

                Rectangle {
                    width: 150
                    height: 72
                    color: "#d3f5dc"
                    TextInput {
                        id: heightArea
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 36
                        anchors.fill: parent
                    }
                    border {
                        color: "black"
                        width: 2
                    }
                }
            }

            Rectangle {
                width: 640
                height: 50
            }

            Row {
                spacing: 15
                Button {
                    width: 203
                    height: 48
                    color: "#c2cbc3"

                    Text {
                        text: "Добавить область"
                        font.pixelSize: 22
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    onClicked: {
                        xArray.push(xArea.text)
                        yArray.push(yArea.text)
                        widthArray.push(widthArea.text)
                        heightArray.push(heightArea.text)
                        console.log(
                            xArray[xArray.length - 1],
                            yArray[xArray.length - 1],
                            widthArray[xArray.length - 1],
                            heightArray[xArray.length - 1]
                        )
                        patternRecognitionArrayViewModel.append({recognizeAreaName: "Область распознавания " + number++})
                        recognizeAreaId.currentIndex++
                        currentIndexClicked = recognizeAreaId.currentIndex
                    }
                }

                Button {
                    width: 203
                    height: 48
                    color: "#c2cbc3"

                    Text {
                        text: "Удалить область"
                        font.pixelSize: 22
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    onClicked: {
                        if(xArray.length > 0){
                            xArray.splice(currentIndexClicked)
                            yArray.splice(currentIndexClicked)
                            widthArray.splice(currentIndexClicked)
                            heightArray.splice(currentIndexClicked)
                            patternRecognitionArrayViewModel.remove(recognizeAreaId.currentIndex)
                        }
                    }
                }

                Button {
                    width: 203
                    height: 48
                    color: "#c2cbc3"

                    Text {
                        text: "Показать область"
                        font.pixelSize: 22
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                    }

                    onClicked: {
                        mainWindow.mouseClicked()
                    }
                }
            }

            Rectangle {
                width: 640
                height: 10
            }

            Rectangle {
                width: 640
                height: 36
                Text {
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Области распознавания"
                    font.pixelSize: 24
                }
            }

            Rectangle {
                width: 640
                height: 2
                color: "black"
            }

            Rectangle {
                width: 640
                height: 400
                //color: "pink"

                ListView {
                    id: recognizeAreaId
                    anchors.fill: parent
                    spacing: 10
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
                            text: recognizeAreaName
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.verticalCenter: parent.verticalCenter
                            font.pixelSize: 16
                        }
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                currentIndexClicked = index
                                recognizeAreaId.currentIndex = index
                                closeUpImage = true
                            }
                        }

                        Rectangle {
                            width: 640
                            height: 35
                            color: "transparent"
                            border{
                                color: {
                                    var colorM = "#ffbd00"
                                    if(recognizeAreaId.currentIndex == index)
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
                        currentIndexClicked = recognizeAreaId.currentIndex
                        mainWindow.mouseClicked()
                        closeUpImage = true
                        console.log("delete elem")
                        
                    }
                }



            }

        }
    }
    Row {
        anchors.top: rowMain.bottom
        anchors.topMargin: 15
        width: parent.width
        height: 70
        Button {
            width: 480
            height: 40
            text: "Загрузить изображение"
            color: defaultColorButton
        }

        Rectangle {
            width: 40
            height: 70
            color: "transparent"
        }

        Button {
            width: 480
            height: 40
            text: "Оригинал"
            color: defaultColorButton
            onClicked: closeUpImage = false
        }

        Rectangle {
            width: 40
            height: 70
            color: "transparent"
        }

        Button {
            width: 480
            height: 40
            text: "Сохранить шаблон"
            color: defaultColorButton
            onClicked: {
                saveClicked = true
                mainWindow.mouseClicked()
                //saveClicked = false
                mainWindow.close()
            }
        }
    }
    
}
