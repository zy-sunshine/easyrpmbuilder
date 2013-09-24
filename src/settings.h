#ifndef SETTINGS_H
#define SETTINGS_H
//
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "ui_settings.h"
//
class settings : public QDialog, public Ui::settings
{
Q_OBJECT
public:
	settings(QWidget * parent);
private:
	QString			  homePath;
	QString			  language;
	void load();
private slots:
	void slot_okButtonClicked();
	void slot_browseButtonClicked();
};
#endif
