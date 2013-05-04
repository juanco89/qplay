
#include "Player.hpp"

Player::Player() : QObject()
{
  player = 0;
}

void Player::iniciarPlayer(const QString &ruta)
{
  if(!player)
  {
    player = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(ruta));
    QObject::connect(player, SIGNAL(finished()), this, SLOT(siguiente()));
  }
  else 
  {
    player->stop();
    player->setCurrentSource(Phonon::MediaSource(ruta));
  }
  player->play();
}


/** SLOTS **/

void Player::siguiente()
{
  qDebug() << "Finalizó la reproducción" << endl;
}

/** Destructor  */
Player::~Player()
{
  delete player;
}
