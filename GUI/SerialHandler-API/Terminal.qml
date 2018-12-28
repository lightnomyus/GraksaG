import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root_terminal
    anchors.fill: parent

    ListView{
        id: view_terminal
        anchors.fill: parent
        model: model_terminal
        delegate: delegate_terminal
    }

    Component {
            id: delegate_terminal
            Row {
                spacing: 10
                Text { text: message }
            }
        }

    ListModel{
        id: model_terminal
        ListElement {
            message:""
        }
    }


    Connections{
        target: obj_SerialHandler
        onMessage_SerialHandler: {
            model_terminal.append({message:message});
        }
    }
}
