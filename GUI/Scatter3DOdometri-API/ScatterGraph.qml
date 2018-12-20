import QtQuick 2.0
import QtDataVisualization 1.2

Item {

    Scatter3D {
        width: parent.width
        height: parent.height
        scene.activeCamera: Camera3D{cameraPreset: Camera3D.CameraPresetIsometricRightHigh}
        axisX: ValueAxis3D{max: 10}
        axisY: ValueAxis3D{max: 10}
        axisZ: ValueAxis3D{max: 10}

        Scatter3DSeries{
            id: data1_series
            ItemModelScatterDataProxy{
                itemModel: data1_model
                xPosRole: "xpos"
                yPosRole: "ypos"
                zPosRole: "zpos"
            }
        }

    }

    ListModel{
        id: data1_model
    }




}
