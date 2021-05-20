import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml 2.12
import QtQuick.Dialogs 1.2
RowLayout{
    id: rLay
    signal newGame()
    signal quitApp()

    function endGame(){
        if (timerTime == 0){
            contr = false
            diag.open()
        }
    }

    function pauseGame(){
        if (contr ==false)
                timerTime++
    }



    Button{
        id: newGameButton
        text: "New Game"
        onClicked:{
            timerTime = 120
            newGame()
        }
    }


    TextField{
        id: timerField
        Layout.fillWidth: true

        Timer {
            id: fTimer
            interval: 1000; running: true; repeat: true

            onTriggered:{
               // fTimer.running = contr
                pauseGame()
                timerTime--
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
            newGame()
        }
    }
    Shortcut{
        context: Qt.ApplicationShortcut
        sequences: [StandardKey.Close, "Ctrl+Q"]
        onActivated: quitApp()
    }


    Dialog{
        id: diag
        title: "Game over. Start new game?"
        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {newGame()
            timerTime = 120
            contr = true
        }
        onNo: Qt.quit()
    }
}
