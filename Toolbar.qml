import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12
RowLayout{
    id: rLay
    signal newGame()
    signal quitApp()

    function endGame(){
        if (timerTime > 80){
            time.text ="Time is out. Goodbay"
            flag = false
        }
    }




    Button{
        id: newGameButton
        text: "New Game"
        onClicked:{
            rLay.timerTime = 0
            newGame()
        }
    }
        property int timerTime: 75
    property bool  flag: true

    TextField{
        id: timerField
        Layout.fillWidth: true

        Timer {
            id: fTimer
            interval: 1000; running: true; repeat: true

            onTriggered:{
                timerTime++
                console.log(flag)
                time.text = timerTime

                endGame()

            }
       }

        Text {
            font.pointSize: 25
            anchors.centerIn: timerField
            id: time }
    }


    Button {
        id: quitButton
        text: "Quit"
        onClicked: {
            quitApp()
        }
    }
    Shortcut {
        context: Qt.ApplicationShortcut
        sequences: ["Ctrl+N"]
        onActivated: {
            rLay.timerTime = 0
            newGame()
        }
    }
    Shortcut{
        context: Qt.ApplicationShortcut
        sequences: [StandardKey.Close, "Ctrl+Q"]
        onActivated: quitApp()
    }
}

