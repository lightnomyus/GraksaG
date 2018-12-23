#ifndef API_SCATTER3D_H
#define API_SCATTER3D_H

#include <QObject>
#include <type_definition.h>

class API_Scatter3D : public QObject
{
    Q_OBJECT
public:
    explicit API_Scatter3D(QObject *parent = nullptr);

signals:
    void update_UI(position3D_t xPos, position3D_t yPos, position3D_t zPos);

public slots:
    void receive_Data3DPosition(position3D_t xPos, position3D_t yPos, position3D_t zPos);
};

#endif // API_SCATTER3D_H
