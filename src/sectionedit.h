#ifndef SECTIONEDIT_H
#define SECTIONEDIT_H
//
#include <QDialog>
#include "ui_sectionedit.h"
#include "highlighter.h"
//
class sectionEdit : public QDialog, public Ui::sectionedit
{
Q_OBJECT
public:
	sectionEdit(QWidget * parent = 0, QString caption = "", QString * content = 0, bool * ok = 0);
private:
	int				  eventCounter;
	QString			* contentPointer;
	bool			* globalOK;
	highlighter		* documentHighlighter;
private slots:
	void slot_submitButtonClicked();
	void slot_discardButtonClicked();
	void slot_contentChanged();
};
#endif
