#ifndef EXECSCRIPTDIALOG_H
#define EXECSCRIPTDIALOG_H
//
#include <QDialog>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include "ui_execScriptDialog.h"
#include "highlighter.h"
//
class execScriptDialog : public QDialog, public Ui::execScriptDialog
{
Q_OBJECT
public:
	execScriptDialog(QWidget * parent = 0, QString script = "", QString name = "", QString version = "");
private:
	QProcess			* process;
	highlighter			* documentHighlighter;
private slots:
	void slot_readyReadStandardOutput();
	void slot_readyReadStandardError();
	void slot_processFinished();
};
#endif
