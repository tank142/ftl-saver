#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QStandardPaths>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	if(translator.load("ftl-saver_ru_RU",QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(2))){
		translator.load("ftl-saver_en_US",QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation).at(2));
	}
	a.installTranslator(&translator);
	MainWindow w;
	w.show();
	return a.exec();
}
