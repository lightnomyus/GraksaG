import QtQuick 2.0
import QtLocation 5.12
import QtPositioning 5.12
import QtQuick.Controls 1.6

Item {
    id: root_MapViewer

    Plugin{
        id: mapPlugin
        name: "esri"
    }

    Rectangle{
        id: placeholder_MapViewer
        anchors.fill: parent

        Rectangle{
            id: placeholder_Button
            width: parent.width
            height: 0.1 * parent.height
            anchors.top: parent.top

            Button{
                id: button_setHome
                height: parent.height
                width: 0.25 * parent.width
                anchors.left: parent.left
                text: qsTr("Set Home")
            }

            Button{
                id: button_clear
                height: parent.height
                width: 0.25 * parent.width
                anchors.left: button_setHome.right
                text: qsTr("Clear")
            }

            Button{
                id: button_zoomIn
                height: parent.height
                width: 0.25 * parent.width
                anchors.left: button_clear.right
                text: qsTr("Zoom In")
            }

            Button{
                id: button_zoomOut
                height: parent.height
                width: 0.25 * parent.width
                anchors.left: button_zoomIn.right
                text: qsTr("Zoom Out")
            }

        }

        Rectangle{
            id: placeholder_Map
            width: parent.width
            anchors.top: placeholder_Button.bottom
            anchors.bottom: placeholder_coordinate.top

            Map{
                id: id_map
                anchors.fill: parent
                plugin: mapPlugin
                center: QtPositioning.coordinate(59.91, 10.75) // Oslo

            }
        }

        Rectangle{
            id: placeholder_coordinate
            width: parent.width
            anchors.bottom: parent.bottom
            height: 0.1*parent.height
        }

    }

}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
