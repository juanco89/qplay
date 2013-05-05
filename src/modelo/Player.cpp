
/*************************************************************************
    Copyright (C) <2013>  <Juan C. Orozco>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

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
