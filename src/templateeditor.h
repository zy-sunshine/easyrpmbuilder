#ifndef TEMPLATEEDITOR_H
#define TEMPLATEEDITOR_H
//
#include <QDialog>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QTextCodec>
#include "ui_templateeditor.h"
//
class templateEditor : public QDialog, public Ui::templateeditor
{
Q_OBJECT
public:
	templateEditor(QWidget * parent = 0);
private:
	void loadTemplates();
	void resizeEvent(QResizeEvent *);
private slots:
	void slot_delTemplateButtonClicked();
	void slot_submitButtonClicked();
	void slot_templateTableClicked();
	void slot_distroComboBoxValueChanged();	
};
#endif
