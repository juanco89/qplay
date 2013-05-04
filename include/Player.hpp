#ifndef Player_H
#define Player_H

#include <QObject>
#include <Phonon/MediaObject>

class Player : QObject
{
  Q_OBJECT
  
public:
    Player();
    virtual ~Player();
    void iniciarPlayer(const QString &ruta);

private:
    Phonon::MediaObject * player;
    
private slots:
    void siguiente();
};

#endif
