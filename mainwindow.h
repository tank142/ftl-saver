#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFile>
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
private:
	QLabel *bak;
	QPushButton *save;
	QPushButton *restore;
	QPushButton *del;
	void bak_file();
	void source_files();
private slots:
	void save_slot();
	void restore_slot();
	void del_slot();
};
#endif // MAINWINDOW_H
