import QtQuick 2.0
import QtDataVisualization 1.2
import QtQuick.Controls 1.4


Item {
    id: root
    property alias scatter_element: data1_model

    Rectangle{
        id: placeholder_setting
        width: root.width
        height: 0.1*root.height

        Button{
            anchors.left: parent.left
            id: button_shadow
            height: parent.height
            width: 1/3 * parent.width
            text: "Shadow Toggle"
        }

        Button{
            anchors.left: button_shadow.right
            id: button_view
            height: parent.height
            width: 1/3 * parent.width
            text: "View Toggle"
        }

        Button{
            anchors.left: button_view.right
            id: button_theme
            height: parent.height
            width: 1/3 * parent.width
            text: "Theme Toggle"
        }


    }

    Rectangle{
        id: placeholder_graph
        width: root.width
        anchors.top: placeholder_setting.bottom
        anchors.topMargin: 10
        anchors.bottom: parent.bottom

        Scatter3D {
            width: parent.width
            height: parent.height
            scene.activeCamera: Camera3D{cameraPreset: Camera3D.CameraPresetFront}
            axisX: ValueAxis3D{autoAdjustRange: true}
            axisY: ValueAxis3D{autoAdjustRange: true}
            axisZ: ValueAxis3D{autoAdjustRange: true}
            shadowQuality: AbstractGraph3D.ShadowQualityNone
            theme.type: Theme3D.ThemeRetro
            measureFps: true

            Scatter3DSeries{
                id: data1_series
                mesh: Abstract3DSeries.MeshSphere
                ItemModelScatterDataProxy{
                    itemModel: data1_model
                    xPosRole: "xPos"
                    yPosRole: "yPos"
                    zPosRole: "zPos"
                }
            }

        }

        ListModel{
            id: data1_model
        }

    }

}
