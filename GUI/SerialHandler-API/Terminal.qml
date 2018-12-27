import QtQuick 2.0

Item {
    id: root_terminal
    anchors.fill: parent

    ListModel{
        id: model_terminal
    }

    ListView{
        anchors.fill: parent
        model: model_terminal
    }

    Connections{
        target: obj_SerialHandler
        onMessage_SerialHandler: model_terminal.append({"message " : message})
    }
}
