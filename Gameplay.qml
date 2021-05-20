import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
GridLayout {
    id: gl
    width: 600
    height: 600

    columns: 10
    rows: 10

    columnSpacing: 0
    rowSpacing: 0

signal unpauseGame()

    function newGame(){
        var newGameConfigs = helper.newGame()
        for (var i = 0; i < newGameConfigs.length; i++)
            bricks.itemAt(i).config = newGameConfigs[i]
        gl.light()
    }

    function light(){
        var count = 0
        var brickConfigs = []
        for (var i = 0; i < 100; i++)
            brickConfigs.push(bricks.itemAt(i).config)
        var brickLights = helper.light(brickConfigs)
        for (var i = 0; i < brickLights.length; i++)
            bricks.itemAt(i).light = brickLights[i]
        for (var h = 0; h < brickLights.length; h++)
        {
            if (bricks.itemAt(h).light === true)
                count++
        }
        if (count === 100){
            contr = false
            ope.open()
        }
    }

    Repeater {
        model: 100
        id: bricks

        Brick{
            onRotated: gl.light() ;
        }
    }
    Component.onCompleted: {
        newGame()
    }
    Dialog{
        id: ope

        title: "You win!. Start new game?"
        standardButtons: StandardButton.Yes | StandardButton.No

        onYes: {
            newGame()
            contr = true
            timerTime = 120
        }
        onNo: Qt.quit()
    }
}
