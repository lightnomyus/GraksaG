#ifndef TESTER_SCATTER3D_H
#define TESTER_SCATTER3D_H

#include <QObject>
#include <type_definition.h>

class Tester_Scatter3D : public QObject
{
    Q_OBJECT
public:
    explicit Tester_Scatter3D(QObject *parent = nullptr);
    Q_INVOKABLE void send_Data(float xPos, float yPos, float zPos);

signals:
    void incoming_Data(position3D_t xPos, position3D_t yPos, position3D_t zPos);

public slots:
};

#endif // TESTER_SCATTER3D_H
