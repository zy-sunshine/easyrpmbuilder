#ifndef SOURCEEDITDIALOG_H
#define SOURCEEDITDIALOG_H
//
#include <QDialog>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>

#include "ui_sourceEditDialog.h"
//
class sourceEditDialog : public QDialog, public Ui::sourceEditDialog
{
Q_OBJECT
public:
	sourceEditDialog(QWidget * parent = 0, QStringList * sources = 0, bool * ok = 0);
private:
	QStringList		* globalSources;
	bool			* globalOk;
	QTimer			* resizeTimer;
	void fillTable();
	void resizeEvent(QResizeEvent *);
private slots:
	void slot_resizeTimerTimeout();
	void slot_browseButtonClicked();
	void slot_addButtonClicked();
	void slot_delButtonClicked();
	void slot_discardButtonClicked();
	void slot_submitButtonClicked();
	void slot_tableClicked();
};
#endif
