#include "logview.h"
//
logview::logview(QWidget * parent, QString content) : QDialog(parent)
{
	setupUi(this);
	contentView->setPlainText(content);
	connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
}
//
