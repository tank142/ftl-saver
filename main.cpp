#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	if(translator.load("ftl-saver_ru_RU","/home/tank/ftl-saver/ftl-saver/")){
		translator.load("ftl-saver_en_US","/home/tank/ftl-saver/ftl-saver/");
	}
	a.installTranslator(&translator);
	MainWindow w;
	w.show();
	return a.exec();
}
