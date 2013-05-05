
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

#ifndef QPlayVentana_H
#define QPlayVentana_H

#include "Player.hpp"

#include <QtGui/QMainWindow>
#include <QTableWidget>

class QPlayVentana : public QMainWindow
{
Q_OBJECT

public:
    explicit QPlayVentana();
    virtual ~QPlayVentana();

private:
    void inicializarComponentes();
    
    QTableWidget *tablaMusical;
    Player * player;
    
private slots:
  void buscarArchivos();
  void reproducirSeleccion(int row, int col);
  
};

#endif // QPlayVentana
