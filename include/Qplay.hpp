#ifndef Qplay_H
#define Qplay_H

#include <QtGui/QMainWindow>
#include <Phonon/MediaObject>

class Qplay : public QMainWindow
{
Q_OBJECT

public:
    Qplay();
    virtual ~Qplay();

private:
    void iniciarPlayer(const QString &fichero);
    Phonon::MediaObject * player;
    
private slots:
  void abrirMultimedia();
  
};

#endif // Qplay_H
