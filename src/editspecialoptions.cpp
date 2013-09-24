#include "editspecialoptions.h"
//
editSpecialOptions::editSpecialOptions( QWidget * parent, QString optionName, QStringList * optionStringList, bool * ok) : QDialog(parent)
{
	setupUi(this);
	globalOk = ok;
	*globalOk = true;
	headerLabel->setText(optionName);
        globalOptionStringList = optionStringList;
	fillTable();
}

void editSpecialOptions::fillTable(){
QStringList tempStringList = *globalOptionStringList;
QStringList headerString;
//QString entry;
//int end;
int index = 0;

	headerString << tr("Values");
	valueTable->clear();
	valueTable->setHorizontalHeaderLabels(headerString);
        /*
        while (!tempStringList.empty() ){
                if (tempStringList.contains(" ")){
                        end = tempStringList.indexOf(" ");
		} else {
			end = tempString.length();
		}
                entry = tempStringList.left(end);
                tempString = tempStringList.mid(end + 1);
                */
        QStringList::iterator it;
        for(it = tempStringList.begin(); it != tempStringList.end(); ++it){
		valueTable->insertRow(index);
                valueTable->setItem(index,0,new QTableWidgetItem(*it));
		valueTable->setColumnWidth(0,560);
		index++;
	}
}

void editSpecialOptions::slot_addButtonClicked(){
bool found = false;

	for (int i = 0; i < valueTable->rowCount(); i++){
		if (valueTable->item(i,0)->text() == valueLineEdit->text()) found = true;
	}
	if (!found){
		valueTable->insertRow(valueTable->rowCount());
		valueTable->setItem(valueTable->rowCount()-1,0,new QTableWidgetItem(valueLineEdit->text()));
		*globalOk = false;
	}
}

void editSpecialOptions::slot_delButtonClicked(){
	if (valueLineEdit->text() != ""){
		if ((valueTable->rowCount() != 0) && (valueTable->currentItem()->text() == valueLineEdit->text())){
			valueTable->removeRow(valueTable->currentRow());
			*globalOk = false;
		}
	}
}

void editSpecialOptions::slot_submitButtonClicked(){
QStringList tempStringList;

	for (int i = 0; i < valueTable->rowCount(); i++){
            tempStringList << valueTable->item(i,0)->text();
            //tempStringList = tempStringList + valueTable->item(i,0)->text() + " ";
	}
        *globalOptionStringList = tempStringList;
	this->done(true);
	
}

void editSpecialOptions::slot_discardButtonClicked(){
	*globalOk = true;
	this->done(false);
}

void editSpecialOptions::slot_tableClicked(){
	valueLineEdit->setText(valueTable->item(valueTable->currentRow(),0)->text());
}

void editSpecialOptions::slot_clearButtonClicked(){
	if (QMessageBox::question(this,tr("Clear List"),tr("Do you really want to clear the list?"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
		int count = valueTable->rowCount();
		for (int row=0;row < count; row++) valueTable->removeRow(0);
	}
	*globalOk = false;
}
//
