#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QStandardPaths>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTranslator translator;
	if(!translator.load("ftl-saver_" + QLocale::system().name(),QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(2))){
		translator.load("ftl-saver_en_US",QStandardPaths::standardLocations(QStandardPaths::AppLocalDataLocation).at(2));
	}
	a.installTranslator(&translator);
	MainWindow w;
	w.show();
	return a.exec();
}
