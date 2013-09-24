#ifndef MACROVIEWCONTAINER_H
#define MACROVIEWCONTAINER_H
//
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include "ui_macroViewContainer.h"
#include "showmacros.h"
#include "editprivatemacrofile.h"
//
class macroViewContainer : public QDialog, public Ui::macroViewContainer
{
Q_OBJECT
public:
	macroViewContainer(QWidget * parent = 0);
private:
	QStringList		folders;
	void loadTabs();
	void makeTabs();
	void saveTabs();
private slots:
	void slot_addFolderButtonClicked();
	void slot_delFolderButtonClicked();
	void slot_tabCloseRequest(int);
};
#endif
