import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Scene3D 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Scene3D{
        anchors.fill: parent
        Model3D{

        }
    }
}
