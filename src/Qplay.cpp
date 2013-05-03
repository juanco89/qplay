#include "Qplay.h"

#include <QHBoxLayout>
#include <QPushButton>

#include <Phonon/MediaSource>
#include <qcoreapplication.h>

#include <QFileDialog>

Qplay::Qplay()
{
  QWidget * wCentral = new QWidget(this);
  QHBoxLayout * layout = new QHBoxLayout(wCentral);
  
  QPushButton * bSalir = new QPushButton(wCentral);
  bSalir->setText("Salir");
  QObject::connect(bSalir, SIGNAL(clicked()), this, SLOT(close()));

  QPushButton * bAbrir = new QPushButton("Abrir", wCentral);
  QObject::connect(bAbrir, SIGNAL(clicked()),this, SLOT(abrirMultimedia()));
  
  layout->addWidget(bSalir);
  layout->addWidget(bAbrir);
  
  wCentral->setLayout(layout);
  setCentralWidget(wCentral);
}

void Qplay::abrirMultimedia()
{
  QFileDialog * dialog = new QFileDialog(this);
  dialog->open();
  QString fichero = dialog->getOpenFileName();
  qDebug() << fichero << endl ;
  delete dialog;
  iniciarPlayer(fichero);
}

void Qplay::iniciarPlayer(const QString &fichero)
{
  if(!player)
  {
    player = Phonon::createPlayer(Phonon::MusicCategory, Phonon::MediaSource(fichero));
  }
  else 
  {
    player->stop();
    player->setCurrentSource(Phonon::MediaSource(fichero));
  }
  player->play();
}

Qplay::~Qplay()
{
  delete player;
}

