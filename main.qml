import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

Window {
    id: w
    property int timerTime: 10
    property bool contr: true
    minimumWidth: 600
    maximumWidth: 600
    width: 600

    minimumHeight: cl.height
    maximumHeight: cl.height
    height: cl.height

    visible: true
    title: qsTr("Line it")

    ColumnLayout{
        id: cl
        anchors.centerIn: w.contentItem
        spacing: 2

        Gameplay {
        id: gameplay

        }
        Toolbar{
        id: toolbar
        onNewGame: gameplay.newGame()
        onQuitApp: Qt.quit()
        }
    }
}
