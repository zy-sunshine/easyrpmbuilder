#ifndef CONFIGTOOLBARDIALOG_H
#define CONFIGTOOLBARDIALOG_H
//
#include <QDialog>
#include <QMessageBox>
#include "ui_configToolBarDialog.h"
//
class configToolBarDialog : public QDialog, public Ui::configToolBarDialog
{
Q_OBJECT
public:
	configToolBarDialog(QWidget * parent = 0, long int * mask = 0);
private:
	long int 	* toolbarMask;
	void initCheckBoxes();
private slots:
	void slot_closeButtonClicked();
};
#endif
