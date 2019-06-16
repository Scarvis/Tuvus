import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.2
import QtQml.Models 2.2
import QtQuick.Dialogs 1.2

import io.qt.examples.backend 1.0
import DocumentsList 1.0
import io.qt.docHandler 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    height: 1000
    width: 1920
    title: "Tuvus Reader"
    property color menuBackgroundColor: "#3C3C3C"
    property color menuBorderColor: "#282828"
    property int number: 0
    property string closeUpDocumentImagePath: ""
    property int documentsListIndexCurrent: 0
    property int currentQuestionCrop: 0
    property var objectsArray: []
    property int indexCroppedQuestionImage: 1
    property int maxIndexCroppedQuestionImage: 1
    property int toolButtonIconSizeGeneral: 16
    property var recognizeIssuesArrayFromCode: []
    property var rightAnswersArrayFromCode: []
    property var prostoBuf: []
    property bool recognizeDocumentsBool: false
    property var blyat: []
    property int currentIndexPatternRecognition: 0
    property var arrayPatternRecognition: []
    property var arrayFileAnswers: []
    property bool isChangeCurrentRecognizeText: false
    property bool testForVideo: false
    Loader {
       id: loaderId;
       anchors.fill: parent;
       onLoaded: {
           console.log("mainqml: ",arrayPatternRecognition)
           loaderId.item.setPatternRecognitionArray(arrayPatternRecognition)
       }
    }
    Connections {
        target: loaderId.item
        onMouseClicked: selectPatternId()
    }

    Loader {
       id: loaderSelectFileAnswers;
       anchors.fill: parent;
       onLoaded: {
           console.log("mainqml: ",arrayFileAnswers)
           loaderSelectFileAnswers.item.setPatternRecognitionArray(arrayFileAnswers)
       }
    }
    // Connections {
    //     target: loaderSelectFileAnswers.item
    //     onMouseClicked: selectPatternId()
    // }
    
    Loader {
       id: loaderCreatePatternRecognition;
       anchors.fill: parent;
    }
    Connections {
        target: loaderCreatePatternRecognition.item
        onMouseClicked: getCropImage()
    }

    Loader {
        id: loaderGenerateFileReport
        anchors.fill: parent
    }

    Connections {
        target: loaderGenerateFileReport.item
        onMouseClicked: saveFileReport()
    }

    function selectPatternId() {
        console.log(loaderId.item.currentIndexClicked)
        currentIndexPatternRecognition = loaderId.item.currentIndexClicked
        inspectionSystem.setPatternRecognition()
    }
    
    function getCropImage() {
        var buf = loaderCreatePatternRecognition.item.currentIndexClicked
        if(loaderCreatePatternRecognition.item.saveClicked){
            saveDialog.open()
            return
        }
        var str = inspectionSystem.getCropImage(
            loaderCreatePatternRecognition.item.pathImageConst,
            loaderCreatePatternRecognition.item.xArray[buf],
            loaderCreatePatternRecognition.item.yArray[buf],
            loaderCreatePatternRecognition.item.widthArray[buf],
            loaderCreatePatternRecognition.item.heightArray[buf]
        )
        loaderCreatePatternRecognition.item.pathImage = str
    }

    function saveFileReport() {

    }

    header: MenuBar {
        id: menuBar
        width: parent.width

        Menu {
            id: menuItemFile
            title: qsTr("Файл")

            Action {
                text: qsTr("Открыть файл")
                shortcut: "Ctrl+O"
                onTriggered: {
                    openDialog.open()
                }
            }
            Action {
                text: qsTr("Открыть папку")
            }

            Action {
                text: qsTr("Сохранить")
                shortcut: "Ctrl+S"
            }
            Action {
                text: qsTr("Сохранить как")
            }



            topPadding: 2
            bottomPadding: 2

            delegate: MenuItem {
                id: menuItem
                implicitWidth: 200
                implicitHeight: 25

                //eto text v itemah sub menu
                contentItem: Text {
                    leftPadding: menuItem.indicator.width
                    rightPadding: menuItem.arrow.width
                    text: menuItem.text
                    font.pixelSize: 16
                    font.family: ("Times New Roman")
                    opacity: enabled ? 1.0 : 0.3
                    //color: menuItem.highlighted ? "#ffffff" : "#010000"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                    scale: {
                        x: "1.0001"
                        y: "1.0001"
                    }
                }

                //eto itemi sub menu
                background: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 25
                    opacity: enabled ? 1 : 0.3
                    //color: "#010000"
                    color: menuItem.highlighted ? "#70AEFE" : "transparent"
                }
            }
            //ETO border color sub menu
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 25
                color: "#ffffff"
                border.color: "#010000"
                radius: 1
            }
        }

        Menu {
            title: qsTr("Правка")
            Action{
                text: qsTr("Отменить")
                shortcut: qsTr("Ctrl+Z")
            }

            topPadding: 2
            bottomPadding: 2

            delegate: MenuItem {
                id: menuItem2
                implicitWidth: 200
                implicitHeight: 25

                //eto text v itemah sub menu
                contentItem: Text {
                    leftPadding: menuItem2.indicator.width
                    rightPadding: menuItem2.arrow.width
                    text: menuItem2.text
                    font.pixelSize: 16
                    font.family: ("Times New Roman")
                    opacity: enabled ? 1.0 : 0.3
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                    scale: {
                        x: "1.0001"
                        y: "1.0001"
                    }
                }

                //eto itemi sub menu
                background: Rectangle {
                    implicitWidth: 200
                    implicitHeight: 25
                    opacity: enabled ? 1 : 0.3
                    //color: "#010000"
                    color: menuItem2.highlighted ? "#70AEFE" : "transparent"
                }
            }
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 25
                color: "#ffffff"
                border.color: "#010000"
                radius: 1
            }


        }
        Menu {
            title: qsTr("Вид")
            Action {
                text: qsTr("save")
                onTriggered: {
                    //inspectionSystem.saveImageCrop()
                }
            }
        }
        Menu {
            title: qsTr("Распознавание")
            
            Action {
                text: qsTr("Выбор шаблона распознавания")
                onTriggered: {
                    if(loaderId.source == "file:C://Users//Mikhail//Documents//QMLTestApp//SelectPatternRecognition.qml"){
                        loaderId.source = ""
                    }
                    arrayPatternRecognition = inspectionSystem.getArrayPatternRecognition()
                    loaderId.source = "file:C://Users//Mikhail//Documents//QMLTestApp//SelectPatternRecognition.qml"
                }
            }
            Action {
                text: qsTr("Выбор файла с ответами")
                onTriggered: {
                    if(loaderSelectFileAnswers.source == "file:C://Users//Mikhail//Documents//QMLTestApp//SelectAnswersFile.qml"){
                        loaderSelectFileAnswers.source = ""
                    }
                    arrayFileAnswers = inspectionSystem.getArrayFileAnswers()
                    loaderSelectFileAnswers.source = "file:C://Users//Mikhail//Documents//QMLTestApp//SelectAnswersFile.qml"
                }
            }
            Action {
                text: qsTr("Создание шаблона распознавания")
                onTriggered: {
                    if(loaderCreatePatternRecognition.source == "file:C://Users//Mikhail//Documents//QMLTestApp//CreatePatternRecognition.qml"){
                        loaderCreatePatternRecognition.source = ""
                    }
                    loaderCreatePatternRecognition.source = "file:C://Users//Mikhail//Documents//QMLTestApp//CreatePatternRecognition.qml"
                }

            }
        }
        Menu {
            title: qsTr("Справка")
        }


        delegate: MenuBarItem {
            id: menuBarItem

            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                opacity: enabled ? 1.0 : 0.3
                color: "#ffffff"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitHeight: 35
                color: menuBarItem.highlighted ? "#858687" : menuBackgroundColor
            }
        }

        background: Rectangle {
            implicitHeight: 35
            color: menuBackgroundColor
            border.color: menuBorderColor
            //нижняя полоска
            Rectangle {
                color: "grey"
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
            }
        }
    }

    ToolBar {
        id: toolBarHeader
        leftPadding: 8
        anchors.top: menuBar.bottom
        width: parent.width
        //height: 100
        Flow {
            id: flow

            Row {
                id: fileRow
                height: 100
                ToolButton {
                    id: openButton
                    text: "\uF115 Загрузить файл" // icon-folder-open-empty
                    font.family: "fontello"
                    font.pixelSize: toolButtonIconSizeGeneral
                    onClicked: openDialog.open()
                }

                ToolButton {
                    id: recognizeFolderDocumentsToolButton
                    text: "\uF289 Распознать всю очередь" // icon-folder-open-empty
                    font.family: "fontello"
                    font.pixelSize: toolButtonIconSizeGeneral
                    onClicked: {
                        documentsListFromDB.startRecognition()
                        objectsArray = documentsListFromDB.currentStatusDocument()
                        blyat = documentsListFromDB.getPathFilesItems()
                        console.log(blyat, blyat.length)
                        inspectionSystem.setDocumentsList(blyat, documentsListIndexCurrent)
                        inspectionSystem.recognizeCurrentFolder()
                        maxIndexCroppedQuestionImage = inspectionSystem.getMaxIndexCroppedQuestionImage()
                        recognizeDocumentsBool = true
                        recognizeIssuesArrayFromCode = inspectionSystem.getRecognizedIssuesList()
                        for(var i = 0; i < recognizeIssuesArrayFromCode.length; i++)
                            recognizedIssuesListViewModel.append({recognizedIssues: "Вопрос №" + (i+1) + ": " + recognizeIssuesArrayFromCode[i]})
                        rightAnswersArrayFromCode = inspectionSystem.getRightAnswersList()
                        for(var k = 0; k < recognizeIssuesArrayFromCode.length; k++)
                            rightAnswersListViewModel.append({rightAnswer: "Вопрос №" + (k+1) + ": " + rightAnswersArrayFromCode[k]})
                        curentDocumentInfoText.text = inspectionSystem.getCurrentDocumentName()      
                    } 
                }

                ToolButton {
                    id: recognizeFileDocumentToolButton
                    text: "\uF289\uE800 Распознать файл" // icon-folder-open-empty
                    font.family: "fontello"
                    font.pixelSize: toolButtonIconSizeGeneral
                }

                ToolButton {
                    id: generateReportToolButton
                    text: "Генерация отчета"
                    font.family: "fontello"
                    font.pixelSize: toolButtonIconSizeGeneral
                    onClicked: {
                        if(loaderGenerateFileReport.source == "file:C://Users//Mikhail//Documents//QMLTestApp//FileReport.qml"){
                            loaderGenerateFileReport.source = ""
                        }
                        //arrayPatternRecognition = inspectionSystem.getArrayPatternRecognition()
                        loaderGenerateFileReport.source = "file:C://Users//Mikhail//Documents//QMLTestApp//FileReport.qml"
                    }
                }

            }
        }
    }




    

    QInspectionSystem {
        id: inspectionSystem
    }



    Row {
        y: 35

        Rectangle {
            id: testButtonsRectangle
            width: 40
            height: mainWindow.height
            //Layout.minimumHeight: 200
            color: "#2C57A2"

            Button {
                id: testButton
                width: 40
                height: 40
                text: qsTr("test")
                onClicked: {
                    console.log("button clicked " + (++number))
                    inspectionSystem.loadFolder("bsl")
                }
            }

            ToolButton {
                id: testButton1
                anchors.top: testButton.bottom
                text: "\uF115"
                font.family: "fontello"
                checked: true
                background: Rectangle {
                    implicitWidth: 40
                    implicitHeight: 40
                    color: "#EDF3FE"
                    opacity: enabled ? 1 : 0.3
                }
                onClicked: {
                    console.log("openFolderButton")
                }
            }
            ToolButton {
                id: testButton2
                anchors.top: testButton1.bottom
                text: "\uF177"
                font.family: "fontello"
                font.pixelSize: 28
                background: Rectangle {
                    implicitWidth: 40
                    implicitHeight: 40
                    color: "#EDF3FE"
                    opacity: enabled ? 1 : 0.3
                }
                onClicked: {
                    if(indexCroppedQuestionImage > 1)
                        indexCroppedQuestionImage--
                }
            }
            ToolButton {
                id: testButton3
                anchors.top: testButton2.bottom
                text: "\uF178"
                font.family: "fontello"
                font.pixelSize: 28
                background: Rectangle {
                    implicitWidth: 40
                    implicitHeight: 40
                    color: "#EDF3FE"
                    opacity: enabled ? 1 : 0.3
                }
                onClicked: {
                    if(indexCroppedQuestionImage < 10)
                        indexCroppedQuestionImage++
                }
            }

        }

        Rectangle {
            id: documents
            width: 210
            height: mainWindow.height
            color: "#EDF3FE"
            border.color: "#D6E5FE"
            Text {
                id: pagesTextId
                height: 25
                width: 210
                text: "ДОКУМЕНТЫ"
                font.pixelSize: 20
                font.family: "Times New Roman"
                color: "black"
                anchors.top: documents.top
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: documents.horizontalCenter
                topPadding: 10
            }

            Rectangle {
                anchors.top: pagesTextId.bottom
                anchors.topMargin: 10
                ToolBar {
                    leftPadding: 15
                    //topPadding: 40
                    background: Rectangle {
                        implicitHeight: 30
                        implicitWidth: documents.width
                        color: "#EDF3FE"
                        Rectangle {
                            width: parent.width
                            height: 2
                            anchors.top: parent.bottom
                            color: "transparent"
                            border.color: "#D6E5FE"
                        }
                    }
                    Flow {
                        width: documents.width
                        Row {

                            ToolButton {
                                id: openFolderButton
                                text: "\uF115"
                                font.family: "fontello"
                                font.pixelSize: toolButtonIconSizeGeneral
                                background: Rectangle {
                                    implicitWidth: 40
                                    implicitHeight: 40
                                    color: "#EDF3FE"
                                    opacity: enabled ? 1 : 0.3
                                }
                                onClicked: {
                                    openDialog.open()
                                    console.log("openFolderButton")
                                }
                            }

                            ToolButton {
                                id: openFileButton
                                text: "\uE800"
                                font.family: "fontello"
                                font.pixelSize: toolButtonIconSizeGeneral
                                background: Rectangle {
                                    implicitWidth: 40
                                    implicitHeight: 40
                                    color: "#EDF3FE"
                                    opacity: enabled ? 1 : 0.3
                                }
                                onClicked: openDialog.open()
                            }

                            ToolButton {
                                id: recognizeDocumentsButton
                                text: "\uF289"
                                font.family: "fontello"
                                font.pixelSize: toolButtonIconSizeGeneral
                                background: Rectangle {
                                    implicitWidth: 40
                                    implicitHeight: 40
                                    color: "#EDF3FE"
                                    opacity: enabled ? 1 : 0.3
                                }
                                onClicked: {
                                    documentsListFromDB.startRecognition()
                                    objectsArray = documentsListFromDB.currentStatusDocument()
                                    blyat = documentsListFromDB.getPathFilesItems()
                                    console.log(blyat, blyat.length)
                                    inspectionSystem.setDocumentsList(blyat, documentsListIndexCurrent)
                                    inspectionSystem.recognizeCurrentFolder()
                                    
                                    
                                    maxIndexCroppedQuestionImage = inspectionSystem.getMaxIndexCroppedQuestionImage()
                                    recognizeDocumentsBool = true
                                }
                            }

                            ToolButton {
                                id: closeFolderButton
                                text: "\uE803"
                                font.family: "fontello"
                                font.pixelSize: toolButtonIconSizeGeneral
                                background: Rectangle {
                                    implicitWidth: 40
                                    implicitHeight: 40
                                    color: "#EDF3FE"
                                    opacity: enabled ? 1 : 0.3
                                }
                            }
                        }
                    }
                }
            }

            Rectangle {
                anchors.bottom: mainWindow.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.fill: parent
                anchors.topMargin: 90
                color: "#EDF3FE"
                ListView {
                    id: documentsList
                    anchors.bottom: mainWindow.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.fill: parent
                    leftMargin: 25
                    spacing: 135
                    visible: testForVideo

                    width: parent.width
                    focus: true
                    clip: true

                    ScrollBar.vertical: ScrollBar { visible: true }

                    model: DocumentsListModel {
                        id: modelList
                        list: documentsListFromDB
                    }

                    delegate: Component {
                        id: delegateItem
                        Item {

                            Rectangle {
                                width: parent.width
                                height: 120

                                Image {
                                    id: imageItem
                                    width: 150
                                    height: 105
                                    source: pathFile
                                    MouseArea {
                                        anchors.fill: parent
                                        onClicked: {
                                            modelList.list.setIndexClicked(index)
                                            documentsList.currentIndex = index
                                            closeUpDocumentImagePath = pathFile
                                            documentsListIndexCurrent = index
                                            console.log(closeUpDocumentImagePath)
                                        }
                                    }
                                }

                                Text {
                                    id: itexItem
                                    anchors.top: imageItem.bottom
                                    font.family: "Alias"
                                    anchors.horizontalCenter: imageItem.horizontalCenter
                                    anchors.topMargin: 5

                                    font.pixelSize: 14
                                    text: nameFile
                                    scale: {
                                        x: "1.0001"
                                        y: "1.0001"
                                    }
                                }

                                Rectangle {
                                    width: 17
                                    height: 17
                                    anchors.left: imageItem.right
                                    anchors.verticalCenter: imageItem.verticalCenter
                                    anchors.right: documents.right
                                    anchors.leftMargin: 5
                                    color: "#EDF3FE"
                                    //color: "blue"
                                    Text {
                                        text: {
                                            var cstd = objectsArray
                                            console.log(cstd)
                                            if(cstd[index] === 1)
                                                return "\uE802";
                                            else if(cstd[index] === 2)
                                                return "\uE803";
                                            else
                                                return "\uF128";
                                        }
                                        font.pixelSize: 20
                                        font.family: "fontello"
                                        color: {
                                            var cstd = objectsArray
                                            if(cstd[index] === 1)
                                                return "green";
                                            else if(cstd[index] === 2)
                                                return "red";
                                            else
                                                return "blue";
                                        }
                                    }
                                }

                                Rectangle {
                                    width: 150
                                    height: 105
                                    color: "transparent"
                                    border {
                                        color: {
                                            var colorM = "transparent"
                                            if(documentsList.currentIndex == index)
                                                colorM = "#157efb"
                                            return colorM
                                        }
                                        width: 2
                                    }
                                }

                            }
                        }

                    }

                    onCurrentItemChanged: {
                        modelList.list.setIndexClicked(documentsList.currentIndex)
                        closeUpDocumentImagePath = modelList.list.getItem()
                        documentsListIndexCurrent = documentsList.currentIndex
                        recognizeIssuesArrayFromCode = modelList.list.getRecognizeIssuesResults()
                        recognizedIssuesListViewModel.clear()
                        for(var i = 0; i < recognizeIssuesArrayFromCode.length; i++)
                            recognizedIssuesListViewModel.append({recognizedIssues: "Вопрос №" + (i+1) + ": " + recognizeIssuesArrayFromCode[i]})
                        console.log("weq ", number++, modelList.list.currentIndexClicked())
                    }
                }
            }
        }
//                    text: {
//                        return modelList.list[documentsListIndexCurrent].pathFile
//                    }

        Column {
            Row {
                Rectangle {
                    id: curentDocumentInfo
                    width: 1110
                    height: 40
                    Text {
                        id: curentDocumentInfoText
                        text: {
                            var str = inspectionSystem.getCurrentDocumentName()
                            return str;
                        }


                        font.pixelSize: 20
                        anchors.verticalCenter: parent.verticalCenter
                        leftPadding: 15
                }
                Rectangle {
                    width: parent.width
                    height: 1
                    anchors.top: parent.bottom
                    color: "#D6E5FE"
                }
                border {
                    color: "#D6E5FE"
                    width: 2
                }
            }

                Rectangle {
                    id: recognizedIssuesText
                    width: 300
                    height: 40
                    // ComboBox {
                    //     width: parent.width
                    //     height: parent.height
                    //     model: ListModel {
                    //         id: recognizedIssuesModel
                    //     }
                    //     Component.onCompleted: {
                    //         arrayPatternRecognition = inspectionSystem.getArrayPatternRecognition()
                    //         for(var i = 0; i < arrayPatternRecognition.length; i++){
                    //             recognizedIssuesModel.append(arrayPatternRecognition[i])
                    //         }

                    //     }
                    // }
                    Text {
                        text: "Распознанные ответы"
                        font.pixelSize: 14
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }

                Rectangle {
                    id: rightAnswersText
                    width: 300
                    height: 40
                    Text {
                        text: qsTr("Правильные ответы")
                        font.pixelSize: 14
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }

            Row {
                Column {
                    Rectangle {
                        id: closeUpDocumentRecognizeResult
                        width: 1100
                        height: 148
                        ToolButton {
                            id: closeUpDocumentRecognizeResultChangeToolButton
                            text: !isChangeCurrentRecognizeText ? "Исправить" : "Принять"
                            font.pixelSize: 22
                            anchors.top: closeUpDocumentRecognizeResultText.bottom
                            anchors.horizontalCenter: closeUpDocumentRecognizeResult.horizontalCenter
                            anchors.topMargin: 15
                            onClicked: {
                                console.log(x)
                                if(!isChangeCurrentRecognizeText)
                                    isChangeCurrentRecognizeText = true;
                                else if(isChangeCurrentRecognizeText){
                                    inspectionSystem.changeCurrentCloseUpDocumentRecognizeResult(
                                        indexCroppedQuestionImage, 
                                        closeUpDocumentRecognizeResultTextInput.text
                                    )
                                    isChangeCurrentRecognizeText = false;
                                    recognizedIssuesListViewModel.set(
                                        indexCroppedQuestionImage - 1, 
                                        { recognizedIssues: "Вопрос №" + indexCroppedQuestionImage + ": " + closeUpDocumentRecognizeResultTextInput.text}
                                        )
                                    var bf = indexCroppedQuestionImage
                                    indexCroppedQuestionImage = 0
                                    indexCroppedQuestionImage = bf
                                }
                            }
                        }
                        Rectangle {
                            width: 100
                            height: 30
                            anchors.horizontalCenter: closeUpDocumentRecognizeResult.horizontalCenter
                            anchors.verticalCenter: closeUpDocumentRecognizeResult.verticalCenter
                            anchors.topMargin: 15
                            visible: isChangeCurrentRecognizeText
                            border {
                                color: "black"
                                width: 1
                            }
                            TextInput {
                                width: 100
                                height: 30
                                visible: isChangeCurrentRecognizeText
                                id: closeUpDocumentRecognizeResultTextInput
                                font.pixelSize: 22
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }

                        Row {
                            anchors.fill: parent

                            ToolButton {
                                text: "\uF177"
                                font.family: "fontello"
                                font.pixelSize: 22
                                anchors.right: closeUpDocumentRecognizeResultRectangle.left
                                anchors.rightMargin: 25
                                visible: !isChangeCurrentRecognizeText
                                anchors.verticalCenter: closeUpDocumentRecognizeResult.verticalCenter
                                y: 50
                                onClicked: {
                                    if(indexCroppedQuestionImage > 1)
                                        indexCroppedQuestionImage--
                                    console.log("Left tb. ", "x = ", x, "y = ", y)
                                }
                            }

                            Rectangle {
                                id: closeUpDocumentRecognizeResultRectangle
                                width: 100
                                height: 50
                                x: 491
                                y: 50
                                visible: !isChangeCurrentRecognizeText
                                //anchors.horizontalCenter: closeUpDocumentRecognizeResult.horizontalCenter
                                anchors.verticalCenter: closeUpDocumentRecognizeResult.verticalCenter
                                Text {
                                    id: closeUpDocumentRecognizeResultText
                                    width: 100
                                    height: 50
                                    text: {
                                        if(!recognizeDocumentsBool) return "nil"
                                        var pf = inspectionSystem.getCurrentCloseUpDocumentRecognizeResult(indexCroppedQuestionImage)
                                        if(pf.length < 1)
                                            pf = "nothing"
                                        else 
                                            var retPf = "Вопрос #" + indexCroppedQuestionImage + "\n" + pf
                                        console.log("Text. ", "x = ", x, "y = ", y)
                                        return retPf
                                    }
                                    //anchors.horizontalCenter: parent.horizontalCenter
                                    visible: !isChangeCurrentRecognizeText
                                    //y: 55
                                    //x: 550 - (closeUpDocumentRecognizeResultText.text.length)
                                    //anchors.horizontalCenter: closeUpDocumentRecognizeResult.horizontalCenter
                                    font.pixelSize: 22
                                    
                                }
                            }
                            
                            ToolButton {
                                text: "\uF178"
                                font.family: "fontello"
                                font.pixelSize: 22
                                visible: !isChangeCurrentRecognizeText
                                anchors.left: closeUpDocumentRecognizeResultRectangle.right
                                anchors.leftMargin: 25
                                anchors.verticalCenter: closeUpDocumentRecognizeResult.verticalCenter
                                y: 50
                                onClicked: {
                                    if(indexCroppedQuestionImage < maxIndexCroppedQuestionImage)
                                        indexCroppedQuestionImage++
                                    console.log("Right tb. ", "x = ", x, "y = ", y)
                                }
                            }
                            
                        }
                        
                    }
                    Rectangle {
                        anchors.top: closeUpDocumentRecognizeResult.top
                        height: 2
                        color: "black"
                    }

                    Rectangle {
                        id: closeUpDocument
                        width: 1100
                        height: 700
                        anchors.topMargin: 5
                        antialiasing: true
                        Image {
                            width: parent.width
                            height: parent.height
                            anchors.verticalCenter: closeUpDocument.verticalCenter
                            anchors.horizontalCenter: closeUpDocument.horizontalCenter
                            anchors.leftMargin: 5
                            anchors.rightMargin: 5
                            mipmap: true
                            antialiasing: true
                            smooth: true
                            fillMode: Image.PreserveAspectFit
                            visible: testForVideo
                            source: {
                                if(recognizeDocumentsBool){
                                    var pf = inspectionSystem.getCurrentCropQuestion(indexCroppedQuestionImage - 1)
                                    if(pf.length == 0)
                                        pf = documentsListFromDB.getCurrentCropQuestion(indexCroppedQuestionImage)
                                    
                                    return pf
                                }
                                else {
                                    return closeUpDocumentImagePath
                                }

                            }
                        }
                        Rectangle {
                            x: 190
                            y: 120
                            width: 75
                            height: 60 
                            visible: false
                            border {
                                color: "green"
                                width: 2
                            }
                        }
                    }
                }


                Rectangle {
                    id: recognizedIssuesArea
                    width: 300
                    height: 870
                    //color: "green"
                    ListView {
                        id: recognizedIssuesListView
                        anchors.fill: parent
                        spacing: 15
                        clip: true
                        delegate: Item {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            height: 30
                            anchors.leftMargin: 10
                            Text {
                                anchors.fill: parent
                                anchors.margins: 5
                                text: recognizedIssues
                            }
                            Rectangle {
                                width: 290
                                height: 30
                                color: "transparent"
                                border{
                                    color: {
                                        var colorM = "#ff423e"
                                        if (recognizedIssuesListViewModel.get(index).recognizedIssues == rightAnswersListViewModel.get(index).rightAnswer)
                                            colorM = "#1cff16"
                                        return colorM
                                    }
                                    width: 1
                                }
                            }
                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    indexCroppedQuestionImage = index + 1
                                    console.log("see thiss", recognizedIssues)
                                }
                            }
                        }
                        model: ListModel {
                            id: recognizedIssuesListViewModel
                        }

                    }

                }

                Rectangle {
                    id: rightAnswersArea
                    width: 300
                    height: 870
                    ListView {
                        id: rightAnswersListView
                        anchors.fill: parent
                        spacing: 15
                        clip: true
                        delegate: Item {
                            anchors.left: parent.left
                            anchors.right: parent.right
                            height: 30
                            anchors.leftMargin: 10
                            Text {
                                anchors.fill: parent
                                anchors.margins: 5
                                text: rightAnswer
                            }
                            // Rectangle {
                            //     width: 300
                            //     height: 20
                            //     color: "transparent"
                            //     border{
                            //         color: {
                            //             var colorM = "#ffbd00"
                            //             if(recognizeAreaId.currentIndex == index)
                            //                 colorM = "#157efb"
                            //             return colorM
                            //         }
                            //         width: 2
                            //     }
                            // }
                        }
                        model: ListModel {
                            id: rightAnswersListViewModel
                        }

                    }

                }

            }

        }
    }



    FileDialog {
        id: openDialog
        title: "Выберите файл"

        onAccepted: {
            console.log("You choose: " + openDialog.fileUrls)
            testForVideo = true
            //inspectionSystem.loadFile(file)
            //Qt.quit()
        }
        onRejected: {
            console.log("Canceled")
           //Qt.quit()
        }
        nameFilters: [ "Image files (*.png *.jpg)", "Json Files (*.json)"]
        //selectedNameFilter.index: 0
        selectedNameFilter: "Image files (*.png *.jpg)"
    }

    FileDialog {
        id: saveDialog
        //fileMode: FileDialog.SaveFile
        title: "Save file"
        //defaultSuffix: document.fileType
        nameFilters: openDialog.nameFilters
        //selectedNameFilter.index: 1
        //folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
        onAccepted: {
            if(loaderCreatePatternRecognition.item.saveClicked){
                inspectionSystem.savePatternRecognition(
                    fileUrl,
                    loaderCreatePatternRecognition.item.xArray, 
                    loaderCreatePatternRecognition.item.yArray,
                    loaderCreatePatternRecognition.item.widthArray,
                    loaderCreatePatternRecognition.item.heightArray
                )
                loaderCreatePatternRecognition.item.saveClicked = false
            }
        }
    }

    MessageDialog {
        id: errorDialog
    }


}
