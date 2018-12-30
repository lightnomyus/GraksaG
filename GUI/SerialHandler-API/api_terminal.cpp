#include "api_terminal.h"

API_Terminal::API_Terminal(QObject *parent) : QObject(parent)
{

}

void API_Terminal::receive_Message(QString message)
{
    emit update_UI(message);
}
