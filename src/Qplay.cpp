
#include "Qplay.hpp"

#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QDesktopServices>

Qplay::Qplay()
{
  player = new Player();
  
  // Componentes gráficos
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
  QString fichero = QFileDialog::getOpenFileName( 
	  this,
	  "Abrir archivos de audio",
	  QDesktopServices::storageLocation(QDesktopServices::HomeLocation),
	  tr("MP3 (*.mp3)"));  
  qDebug() << "Archivo seleccionado: " << fichero << endl;
  iniciarPlayer(fichero);
}

void Qplay::iniciarPlayer(const QString &fichero)
{
  player->iniciarPlayer(fichero);
}

Qplay::~Qplay()
{
  delete player;
}
