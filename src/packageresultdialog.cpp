#include "packageresultdialog.h"
//
packageResultDialog::packageResultDialog( QWidget * parent, QStringList * files ) : QDialog(parent)
{
	setupUi(this);
	packageFiles = files;
	packageInfoProcess = new QProcess(this);
	connect(packageInfoProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_readyReadStandardOutput()));
	connect(packageInfoProcess,SIGNAL(readyReadStandardError()),this,SLOT(slot_readyReadStandardError()));
	connect(packageInfoProcess,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(slot_processFinished()));
	fillTable();
	if (tableWidget->rowCount() > 0){
		tableWidget->setCurrentCell(0,0);
		slot_tableClicked();
	}
}

void packageResultDialog::slot_tableClicked(){
int currentItem = tableWidget->currentRow();
QString filename = packageFiles->at(currentItem);
	tableWidget->setEnabled(false);
	packageInfoProcess->start("rpm -qip " + filename);
}

void packageResultDialog::fillTable(){
QStringList entryList = *packageFiles;
QStringListIterator it(entryList);
QStringList headerString;
QString entry;
int index = 0;
	headerString << tr("File");
	tableWidget->clear();
	tableWidget->setHorizontalHeaderLabels(headerString);
	while (it.hasNext()){
		entry = it.next();
		entry = entry.mid(entry.lastIndexOf("/")+1);
		tableWidget->insertRow(index);
		tableWidget->setItem(index,0,new QTableWidgetItem(entry));
		tableWidget->setColumnWidth(0,250);
		index++;		
	}
}

void packageResultDialog::slot_readyReadStandardOutput(){
QString rc = packageInfoProcess->readAll();
	packageView->setPlainText(rc.trimmed());
	packageView->moveCursor(QTextCursor::End);
}

void packageResultDialog::slot_readyReadStandardError(){
QString rc = packageInfoProcess->readAllStandardError();
	packageView->setPlainText(rc.trimmed());
	packageView->moveCursor(QTextCursor::End);
}

void packageResultDialog::slot_processFinished(){
	tableWidget->setEnabled(true);
}
//
