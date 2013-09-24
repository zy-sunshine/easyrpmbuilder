#ifndef SHOWMACROS_H
#define SHOWMACROS_H
//
#include <QDialog>
#include <QDir>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "highlighter.h"
#include "ui_showMacrosDialog.h"
//
class showMacros : public QDialog, public Ui::showMacrosDialog
{
Q_OBJECT
public:
	showMacros(QWidget * parent = 0, QString path = "");
	QDir		* sourceDir;
private:
	highlighter		* macroViewHighlighter;
	QString			  directory;
	void fillTable();
private slots:
	void slot_tableClicked();
	
};
#endif
