#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>


int main(int argc, char *argv[])      
{
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
