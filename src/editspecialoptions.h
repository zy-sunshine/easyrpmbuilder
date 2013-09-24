#ifndef EDITSPECIALOPTIONS_H
#define EDITSPECIALOPTIONS_H
//
#include <QDialog>
#include <QTimer>
#include <QMessageBox>
#include "ui_specialOptionDialog.h"
//
class editSpecialOptions : public QDialog, public Ui::specialOptionDialog
{
Q_OBJECT
public:
        editSpecialOptions(QWidget * parent = 0, QString optionName = "", QStringList * optionStringList = 0, bool * ok = 0);
	bool			* globalOk;
        QStringList		* globalOptionStringList;
	QTimer			* resizeTimer;
	void fillTable(); 
private slots:
	void slot_discardButtonClicked();
	void slot_submitButtonClicked();
	void slot_addButtonClicked();
	void slot_delButtonClicked();
	void slot_tableClicked();
	void slot_clearButtonClicked();
};
#endif
