#ifndef CHANGELOGDIALOG_H
#define CHANGELOGDIALOG_H
//
#include <QDialog>
#include <QMessageBox>
#include "ui_changelogDialog.h"
//
class changelogDialog : public QDialog, public Ui::changelogDialog
{
Q_OBJECT
public:
	changelogDialog(QWidget * parent = 0, QString * comment = 0, bool * ok = 0);
private:
	bool		* m_ok;
	QString		* m_comment;
	void disassemble();
	
private slots:
	void slot_contentChanged();
	void slot_submitButtonClicked();
	void slot_discardButtonClicked();
	
};
#endif
