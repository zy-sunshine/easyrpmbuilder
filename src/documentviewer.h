#ifndef DOCUMENTVIEWER_H
#define DOCUMENTVIEWER_H
//
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPushButton>
#include <QTextBrowser>
#include <QFrame>
#include <QFont>
//
class documentViewer : public QDialog
{
Q_OBJECT
public:
	documentViewer(QWidget * parent = 0, QString Url = "");
private:
	QFrame					* mainFrame;
	QTextBrowser			* document;
	QPushButton				* closeButton;
	QPushButton				* backButton;
	QPushButton				* forwardButton;
	QPushButton				* goHomeButton;
	QString					  globalUrl;
	void resizeEvent(QResizeEvent *);
private slots:
	void slot_backButtonClicked();
	void slot_forwardButtonClicked();
	void slot_goHomeButtonClicked();
	void slot_backwardAvailable(bool);
	void slot_forwardAvailable(bool);
};
#endif
