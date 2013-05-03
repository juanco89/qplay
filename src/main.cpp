#include <QtGui/QApplication>
#include "Qplay.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Qplay foo;
    foo.show();
    return app.exec();
}
