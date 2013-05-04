#ifndef Qplay_H
#define Qplay_H

#include "Player.hpp"

#include <QtGui/QMainWindow>

class Qplay : public QMainWindow
{
Q_OBJECT

public:
    Qplay();
    virtual ~Qplay();

private:
    void iniciarPlayer(const QString &fichero);
    Player * player;
    
private slots:
  void abrirMultimedia();
  
};

#endif // Qplay_H
