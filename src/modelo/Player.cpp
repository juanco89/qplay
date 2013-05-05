
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

void Player::reproducir(const QString &ruta)
{
  if(!player)
  {
    // Se crea el media player si no está creado aún.
    player = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(ruta));
  }
  else
  {
    // Si existe, se detiene la actual reproducción
    player->stop();
    // Se asigna una nueva fuente (canción)
    player->setCurrentSource(Phonon::MediaSource(ruta));
  }
  // Inicia la reproducción de la actual fuente
  player->play();
}

/** 
 * \Brief Destructor.
 */
Player::~Player()
{
  delete player;
}
