#ifndef LOGVIEW_H
#define LOGVIEW_H
//
#include <QDialog>
#include "ui_logview.h"
//
class logview : public QDialog, public Ui::logview
{
Q_OBJECT
public:
	logview(QWidget * parent = 0, QString content = "");
};
#endif
