#ifndef PATCHEDITDIALOG_H
#define PATCHEDITDIALOG_H
//
#include <QDialog>
#include <QTimer>
#include <QFileDialog>

#include "ui_patchEditDialog.h"
//
class patchEditDialog : public QDialog, public Ui::patchEditDialog
{
Q_OBJECT
public:
	patchEditDialog(QWidget * parent = 0, QStringList * patchs = 0, bool * ok = 0);
private:
	QStringList		* globalpatchs;
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
