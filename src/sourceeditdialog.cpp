#include "sourceeditdialog.h"
//
sourceEditDialog::sourceEditDialog(QWidget * parent, QStringList * sources, bool * ok) : QDialog(parent)
{
	setupUi(this);
	globalSources = sources;
	globalOk = ok;
	*globalOk = true;
	fillTable();
	resizeTimer = new QTimer(this);
	connect(resizeTimer,SIGNAL(timeout()),this,SLOT(slot_resizeTimerTimeout()));
	resizeTimer->start(250);
}

void sourceEditDialog::fillTable(){
QStringList tempSources = *globalSources;
QStringListIterator it(tempSources);
QStringList headerString;
QString entry;
int index = 0;
	headerString << tr("Sources");
	sourceTableWidget->clear();
	sourceTableWidget->setHorizontalHeaderLabels(headerString);
	while (it.hasNext()){
		sourceTableWidget->insertRow(index);
		entry = it.next();
		sourceTableWidget->setItem(index,0,new QTableWidgetItem(entry));
		sourceTableWidget->setColumnWidth(0,560);
		index++;		
	}
}

void sourceEditDialog::resizeEvent(QResizeEvent * e){
	e = e; // just to keep the compiler happy ....
	sourceTableWidget->setColumnWidth(0,sourceTableWidget->width()-10);
}

void sourceEditDialog::slot_browseButtonClicked(){
	sourceLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Select Source File"),"/",tr("All (*)")));
}

void sourceEditDialog::slot_addButtonClicked(){
bool found = false;

	for (int i = 0; i < sourceTableWidget->rowCount(); i++){
		if (sourceTableWidget->item(i,0)->text() == sourceLineEdit->text()) found = true;
	}
	if (!found){
		sourceTableWidget->insertRow(sourceTableWidget->rowCount());
		sourceTableWidget->setItem(sourceTableWidget->rowCount()-1,0,new QTableWidgetItem(sourceLineEdit->text()));
		*globalOk = false;
	}
}

void sourceEditDialog::slot_delButtonClicked(){
	if (sourceLineEdit->text() != ""){
		if ((sourceTableWidget->rowCount() != 0) && (sourceTableWidget->currentItem()->text() == sourceLineEdit->text())){
			sourceTableWidget->removeRow(sourceTableWidget->currentRow());
			*globalOk = false;
		}
	}
}

void sourceEditDialog::slot_submitButtonClicked(){
QStringListIterator it(*globalSources);
QStringList tempList;

	for (int i = 0; i < sourceTableWidget->rowCount(); i++){
		tempList << sourceTableWidget->item(i,0)->text();
	}
	*globalSources = tempList;
	this->done(true);
}

void sourceEditDialog::slot_discardButtonClicked(){
	*globalOk = true;
	this->done(false);
}

void sourceEditDialog::slot_tableClicked(){
	sourceLineEdit->setText(sourceTableWidget->item(sourceTableWidget->currentRow(),0)->text());
}

void sourceEditDialog::slot_resizeTimerTimeout(){
	sourceTableWidget->setColumnWidth(0,sourceTableWidget->width()-10);
}
//
