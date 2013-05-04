#include <QtGui/QApplication>
#include "Qplay.hpp"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    Qplay foo;
    foo.show();
    return app.exec();
}
