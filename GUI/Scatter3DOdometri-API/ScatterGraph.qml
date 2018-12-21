import QtQuick 2.0
import QtDataVisualization 1.2

Item {
    property alias scatter_element: data1_model

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
