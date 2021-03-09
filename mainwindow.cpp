#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QProcess>
#include <QDebug>
#include <QTranslator>
#include <QApplication>
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
	QTranslator qtLanguageTranslator;
	QVBoxLayout *main = new QVBoxLayout;setLayout(main);main->setAlignment(Qt::AlignTop);
	setMinimumWidth(200);
	bak = new QLabel();
	save = new QPushButton(tr("save"));
	restore = new QPushButton(tr("restore"));
	del = new QPushButton(tr("del"));
	main->addWidget(save);
	main->addWidget(restore);
	main->addWidget(del);
	main->addWidget(bak);
	source_files();
	bak_file();
	connect(save, &QPushButton::clicked , this , &MainWindow::save_slot);
	connect(restore, &QPushButton::clicked , this , &MainWindow::restore_slot);
	connect(del, &QPushButton::clicked , this , &MainWindow::del_slot);
}

MainWindow::~MainWindow()
{
}

void MainWindow::save_slot(){
	QString home = QDir::homePath();QProcess tar;
	tar.setWorkingDirectory(home + "/.local/share/FasterThanLight");
	QStringList arg;arg << "--use-compress-program=lz4 --favor-decSpeed --best" << "-cf" << "save.tlz4";
	if(QFile(home + "/.local/share/FasterThanLight/continue.sav").exists()){
		arg.append("continue.sav");
	}else{
		bak->setText(tr("mainmenu_return"));
		return;
	}
	if(QFile(home + "/.local/share/FasterThanLight/ae_prof.sav").exists()){
		arg.append("ae_prof.sav");
	}
	tar.start("tar",arg);
	tar.waitForStarted(-1);
	tar.waitForFinished(-1);
	bak_file();
}
void MainWindow::restore_slot(){
	QString home = QDir::homePath();
	QFile(home + "/.local/share/FasterThanLight/ae_prof.sav").remove();
	QFile(home + "/.local/share/FasterThanLight/continue.sav").remove();
	QProcess tar;tar.setWorkingDirectory(home + "/.local/share/FasterThanLight");
	tar.start("tar",QStringList() << "--use-compress-program=lz4" << "-xf" << "save.tlz4" );
	tar.waitForStarted(-1);
	tar.waitForFinished(-1);
}
void MainWindow::del_slot(){
	QFile(QDir::homePath() + "/.local/share/FasterThanLight/save.tlz4").remove();
	restore->setEnabled(false);
	del->setEnabled(false);
	bak->setHidden(true);
}
void MainWindow::source_files(){
	QString home = QDir::homePath();
	if(!QDir(home + "/.local/share/FasterThanLight").exists()){save->setEnabled(false);restore->setEnabled(false);del->setEnabled(false);return;}
	if(QFile(home + "/.local/share/FasterThanLight/ae_prof.sav").exists()){save->setEnabled(true);return;}
	if(QFile(home + "/.local/share/FasterThanLight/continue.sav").exists()){save->setEnabled(true);return;}
}
void MainWindow::bak_file(){
	if(QFile(QDir::homePath() + "/.local/share/FasterThanLight/save.tlz4").exists()){
		restore->setEnabled(true);
		del->setEnabled(true);
		bak->setHidden(false);
		bak->setText(QFileInfo(QDir::homePath() + "/.local/share/FasterThanLight/save.tlz4").lastModified().toString());
	}else{
		bak->setHidden(true);
		restore->setEnabled(false);
		del->setEnabled(false);
	}
}
