#ifndef EDITPRIVATEMACROFILE_H
#define EDITPRIVATEMACROFILE_H
//
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include "highlighter.h"
#include "ui_editPrivateMacroFileDialog.h"
//
class editPrivateMacroFile : public QDialog, Ui::editPrivateMacroFileDialog
{
Q_OBJECT
public:
	editPrivateMacroFile(QWidget * parent = 0);
private:
	highlighter		* myHighLighter;
private slots:
	void slot_submitButtonClicked();
	void slot_discardButtonClicked();
};
#endif
