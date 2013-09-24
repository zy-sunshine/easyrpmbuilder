#ifndef PACKAGERESULTDIALOG_H
#define PACKAGERESULTDIALOG_H
//
#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include "ui_packageResultDialog.h"
//
class packageResultDialog : public QDialog, public Ui::packageResultDialog
{
Q_OBJECT
public:
	packageResultDialog(QWidget * parent = 0, QStringList * files = 0);
private:
	QStringList		* packageFiles;
	QProcess		* packageInfoProcess;
	void fillTable();
private slots:
	void slot_tableClicked();
	void slot_readyReadStandardOutput();
	void slot_readyReadStandardError();
	void slot_processFinished();
};
#endif
