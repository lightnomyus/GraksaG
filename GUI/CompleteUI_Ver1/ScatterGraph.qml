import QtQuick 2.0
import QtDataVisualization 1.2
import QtQuick.Controls 1.4


Item {
    id: scatterGraph_root
    property alias scatter_element: data1_model

    Rectangle{
        id: placeholder_setting
        width: scatterGraph_root.width
        height: 0.1*scatterGraph_root.height

        Button{
            anchors.left: parent.left
            id: button_shadow
            height: parent.height
            width: 1/4 * parent.width
            text: "Shadow Toggle"
            onClicked: {
                if(scatter3D_id.shadowQuality == AbstractGraph3D.ShadowQualityNone){
                    scatter3D_id.shadowQuality = AbstractGraph3D.ShadowQualitySoftHigh
                }else{
                    scatter3D_id.shadowQuality = AbstractGraph3D.ShadowQualityNone
                }
            }
        }

        Button{
            anchors.left: button_shadow.right
            id: button_view
            height: parent.height
            width: 1/4 * parent.width
            text: "View Toggle"
            onClicked: {
                if (scatter3D_id.scene.activeCamera.cameraPreset === Camera3D.CameraPresetFront) {
                    scatter3D_id.scene.activeCamera.cameraPreset = Camera3D.CameraPresetFrontHigh;
                } else if (scatter3D_id.scene.activeCamera.cameraPreset === Camera3D.CameraPresetFrontHigh) {
                    scatter3D_id.scene.activeCamera.cameraPreset = Camera3D.CameraPresetIsometricRightHigh;
                } else {
                    scatter3D_id.scene.activeCamera.cameraPreset = Camera3D.CameraPresetFront;
                }
            }
        }

        Button{
            anchors.left: button_view.right
            id: button_theme
            height: parent.height
            width: 1/4 * parent.width
            text: "Theme Toggle"
            onClicked: {
                if (scatter3D_id.theme.type === Theme3D.ThemeRetro) {
                    scatter3D_id.theme.type = Theme3D.ThemeArmyBlue
                } else if (scatter3D_id.theme.type === Theme3D.ThemeArmyBlue) {
                    scatter3D_id.theme.type = Theme3D.ThemeDigia
                } else {
                    scatter3D_id.theme.type = Theme3D.ThemeRetro
                }
            }
        }

        Button{
            anchors.left: button_theme.right
            id: button_clear
            height: parent.height
            width: 1/4 * parent.width
            text: "Clear Scatter"
            onClicked: data1_model.clear()
        }


    }

    Rectangle{
        id: placeholder_graph
        width: scatterGraph_root.width
        anchors.top: placeholder_setting.bottom
        anchors.bottom: parent.bottom

        Scatter3D {
            id: scatter3D_id
            width: parent.width
            height: parent.height
//            scene.activeCamera: Camera3D{cameraPreset: Camera3D.CameraPresetFront}
            axisX: ValueAxis3D{autoAdjustRange: true}
            axisY: ValueAxis3D{autoAdjustRange: true}
            axisZ: ValueAxis3D{autoAdjustRange: true}
            shadowQuality: AbstractGraph3D.ShadowQualityNone
//            theme.type: Theme3D.ThemeRetro
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

        Connections{
            target: obj_Scatter3D
            onUpdate_UI: data1_model.append({"xPos": xPos, "yPos": yPos, "zPos": zPos})
        }

    }

}
