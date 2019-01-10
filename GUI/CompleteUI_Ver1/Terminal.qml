import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root_terminal
    anchors.fill: parent

    Rectangle{
        id: holder_terminal
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: clear_id.top
        color: "blue"

        ListView{
            id: view_terminal
            anchors.fill: parent
            model: model_terminal
            delegate: delegate_terminal
            ScrollBar.vertical: ScrollBar {}
            onCountChanged: view_terminal.currentIndex = count-1

        }
    }

    Button{
        id: clear_id
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 0.1 * parent.height
        text: qsTr("Clear")
        font.pointSize: 12
        onPressed: model_terminal.clear()
    }

    Component {
        id: delegate_terminal
            Row {
                spacing: 10
                Text {
                    text: message
                    color: "black"
                }
            }
        }

    ListModel{
        id: model_terminal
        dynamicRoles: true
    }


//    Connections{
//        target: obj_Terminal
//        onUpdate_UI: {
//            model_terminal.append({message:message});
//        }
//    }
}
