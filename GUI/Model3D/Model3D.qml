import QtQuick 2.10
import Qt3D.Render 2.0
import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import QtQuick.Controls.Universal 2.1
import QtQuick.Controls 1.4

Entity{
    id: root_entity_id

    Camera {
        id: camera
        position: Qt.vector3d( 0.0, 13.40, -50.0 ) //15 degree camera
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )     //horizon vector; (0,-1,0) for downwards
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 ) //coordinate of object seen
    }

    components:[
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                camera: camera
                clearColor: Universal.color(Universal.Cyan) //sky blue color
            }
        }
    ]

    Mesh{
        id: vehicle_mesh
        source: "3D/garuda.stl"
    }

    GoochMaterial {
        id: vehicle_material
    }

    Transform {
            id: vehicle_transform
            rotationX: 0
            rotationY: 0
            rotationZ: 0

//            Connections{
//                target: backendObj
//                onUpdate_current_yaw: vehicle_transform.rotationY = yaw;
//                onUpdate_current_pitch: vehicle_transform.rotationX = pitch;
//                onUpdate_current_roll: vehicle_transform.rotationZ = roll;
//            }
    }

    Entity {
            id: vehicle_entity
            components: [vehicle_mesh, vehicle_material, vehicle_transform]
    }




}

