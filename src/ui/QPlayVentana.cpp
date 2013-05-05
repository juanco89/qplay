
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

#include "QPlayVentana.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QDesktopServices>
#include <QDesktopWidget>

QPlayVentana::QPlayVentana()
{
  player = new Player();
  
  inicializarComponentes();
  
  this->setBaseSize(QSize(600, 400));
  
  // Mover la ventana al centro
  QRect geometry = this->geometry();
  QDesktopWidget *desktop = new QDesktopWidget();
  geometry.moveCenter(desktop->geometry().center());
  this->setGeometry(geometry);
  delete desktop;
}

/**
 * \Brief Inicializa los componentes gráficos de la ventana.
 */ 
void QPlayVentana::inicializarComponentes()
{
  QWidget * wCentral = new QWidget(this);
  QVBoxLayout *lyPrincipal = new QVBoxLayout(wCentral);
  QHBoxLayout * lyBotones = new QHBoxLayout();
  
  QPushButton * bSalir = new QPushButton("Salir", wCentral);
  QObject::connect(bSalir, SIGNAL(clicked()), this, SLOT(close()));
  
  QPushButton * bAbrir = new QPushButton("Abrir", wCentral);
  QObject::connect(bAbrir, SIGNAL(clicked()),this, SLOT(buscarArchivos()));
  
  lyBotones->addWidget(bSalir);
  lyBotones->addWidget(bAbrir);
  
  tablaMusical = new QTableWidget(wCentral);
  
  QStringList encabezados;
  encabezados.append("Canción");
  tablaMusical->setHorizontalHeaderLabels(encabezados);
  tablaMusical->setColumnCount(encabezados.size());
  QObject::connect(tablaMusical, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(reproducirSeleccion(int,int)));
  
  lyPrincipal->addWidget(tablaMusical, 1);
  lyPrincipal->addLayout(lyBotones);
  
  wCentral->setLayout(lyPrincipal);
  setCentralWidget(wCentral);
}

/***  SLOTS ****/

void QPlayVentana::buscarArchivos()
{
  QStringList ficheros = QFileDialog::getOpenFileNames( 
	  this,
	  "Abrir archivos de audio",
	  QDesktopServices::storageLocation(QDesktopServices::HomeLocation),
	  tr("MP3 (*.mp3)"));

  int numFilas = ficheros.size();
  tablaMusical->setRowCount(numFilas);
  QTableWidgetItem *nuevoItem;
  for(int i = 0; i < numFilas; i++)
  {
    nuevoItem = new QTableWidgetItem(ficheros.at(i));	// Revisar
    tablaMusical->setItem(i, 0, nuevoItem);
  }
}

void QPlayVentana::reproducirSeleccion(int row, int col)
{
  QString ruta = tablaMusical->item(row, col)->text();
  
  qDebug() << ruta << endl;
  
  player->reproducir(ruta);
}


/**
 * \Brief Destructor
 */ 
QPlayVentana::~QPlayVentana()
{
  delete player;
}