#include "patcheditdialog.h"
//
patchEditDialog::patchEditDialog(QWidget * parent, QStringList * patchs, bool * ok) : QDialog(parent)
{
	setupUi(this);
	globalpatchs = patchs;
	globalOk = ok;
	*globalOk = true;
	fillTable();
	resizeTimer = new QTimer(this);
	connect(resizeTimer,SIGNAL(timeout()),this,SLOT(slot_resizeTimerTimeout()));
	resizeTimer->start(250);
}

void patchEditDialog::fillTable(){
QStringList temppatchs = *globalpatchs;
QStringListIterator it(temppatchs);
QStringList headerString;
int index = 0;
	headerString << tr("Patches");
	patchTableWidget->clear();
	patchTableWidget->setHorizontalHeaderLabels(headerString);
	while (it.hasNext()){
		patchTableWidget->insertRow(index);
		patchTableWidget->setItem(index,0,new QTableWidgetItem(it.next()));
		patchTableWidget->setColumnWidth(0,560);
		index++;		
	}
}

void patchEditDialog::resizeEvent(QResizeEvent * e){
	e = e; // just to keep the compiler happy ....
	patchTableWidget->setColumnWidth(0,patchTableWidget->width()-10);
}

void patchEditDialog::slot_browseButtonClicked(){
	patchLineEdit->setText(QFileDialog::getOpenFileName(this, tr("Select patch File"),"/",tr("All (*)")));
}

void patchEditDialog::slot_addButtonClicked(){
bool found = false;

	for (int i = 0; i < patchTableWidget->rowCount(); i++){
		if (patchTableWidget->item(i,0)->text() == patchLineEdit->text()) found = true;
	}
	if (!found){
		patchTableWidget->insertRow(patchTableWidget->rowCount());
		patchTableWidget->setItem(patchTableWidget->rowCount()-1,0,new QTableWidgetItem(patchLineEdit->text()));
		*globalOk = false;
	}
}

void patchEditDialog::slot_delButtonClicked(){
	if (patchLineEdit->text() != ""){
		if ((patchTableWidget->rowCount() != 0) && (patchTableWidget->currentItem()->text() == patchLineEdit->text())){
			patchTableWidget->removeRow(patchTableWidget->currentRow());
			*globalOk = false;
		}
	}
}

void patchEditDialog::slot_submitButtonClicked(){
QStringList tempList;

	for (int i = 0; i < patchTableWidget->rowCount(); i++){
		tempList << patchTableWidget->item(i,0)->text();
	}
	*globalpatchs = tempList;
	this->done(true);
}

void patchEditDialog::slot_discardButtonClicked(){
	*globalOk = true;
	this->done(false);
}

void patchEditDialog::slot_tableClicked(){
	patchLineEdit->setText(patchTableWidget->item(patchTableWidget->currentRow(),0)->text());
}

void patchEditDialog::slot_resizeTimerTimeout(){
	patchTableWidget->setColumnWidth(0,patchTableWidget->width()-10);
}
//
