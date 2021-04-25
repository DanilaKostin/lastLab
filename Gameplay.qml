import QtQuick 2.12
import QtQuick.Layouts 1.12

GridLayout {
    id: gl
    width: 600
    height: 600

    columns: 10
    rows: 10

    columnSpacing: 0
    rowSpacing: 0


    function newGame(){
        var newGameConfigs = helper.newGame()
        for (var i = 0; i < newGameConfigs.length; i++)
            bricks.itemAt(i).config = newGameConfigs[i]

    }

    function light(){
        var brickConfigs = []
        for (var i = 0; i < bricks.count; i++)
           brickConfigs.push(bricks.itemAt(i).config)
        var brickLights = helper.light(brickConfigs)
        for (var i = 0; i < brickLights.length; i++)
            bricks.itemAt(i).light = brickLights[i]
    }

    Repeater {
        model: 100
        id: bricks

    Brick{
           onRotated: gl.light() ;
        }
    }
    Component.onCompleted: {
        newGame();
    }
}
