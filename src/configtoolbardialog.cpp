#include "configtoolbardialog.h"
//
configToolBarDialog::configToolBarDialog(QWidget * parent, long int * mask) : QDialog(parent)
{
	setupUi(this);
	toolbarMask = mask;
	initCheckBoxes();
}

void configToolBarDialog::slot_closeButtonClicked(){
long int filter = 1;
long int newFilter = 0;
	while (filter < 65536){
		switch (filter){
		case      1 : if (checkBox->isChecked()) newFilter = newFilter | filter;
						break;
		case      2 : if (checkBox_2->isChecked()) newFilter = newFilter | filter;
						break;
		case      4 : if (checkBox_3->isChecked()) newFilter = newFilter | filter;
						break;
		case      8 : if (checkBox_4->isChecked()) newFilter = newFilter | filter;
						break;
		case     16 : if (checkBox_5->isChecked()) newFilter = newFilter | filter;
						break;
		case     32 : if (checkBox_6->isChecked()) newFilter = newFilter | filter;
						break;
		case     64 : if (checkBox_7->isChecked()) newFilter = newFilter | filter;
						break;
		case    128 : if (checkBox_8->isChecked()) newFilter = newFilter | filter;
						break;
		case    256 : if (checkBox_9->isChecked()) newFilter = newFilter | filter;
						break;
		case    512 : if (checkBox_10->isChecked()) newFilter = newFilter | filter;
						break;
		case   1024 : if (checkBox_11->isChecked()) newFilter = newFilter | filter;
						break;
		case   2048 : if (checkBox_12->isChecked()) newFilter = newFilter | filter;
						break;
		case   4096 : if (checkBox_13->isChecked()) newFilter = newFilter | filter;
						break;
		case   8192 : if (checkBox_14->isChecked()) newFilter = newFilter | filter;
						break;
		case  16384 : if (checkBox_15->isChecked()) newFilter = newFilter | filter;
						break;
		case  32768 : if (checkBox_16->isChecked()) newFilter = newFilter | filter;
						break;
		}
		filter*=2;
	}
	*toolbarMask = newFilter;
	this->accept();
}

void configToolBarDialog::initCheckBoxes(){
long int filter = 1;
long int tempMask = *toolbarMask;

	while (filter < 65536){
		switch (filter){
		case      1 : ((filter&tempMask) == filter)?checkBox->setChecked(true):checkBox->setChecked(false);
						break;
		case      2 : ((filter&tempMask) == filter)?checkBox_2->setChecked(true):checkBox_2->setChecked(false);
						break;
		case      4 : ((filter&tempMask) == filter)?checkBox_3->setChecked(true):checkBox_3->setChecked(false);
						break;
		case      8 : ((filter&tempMask) == filter)?checkBox_4->setChecked(true):checkBox_4->setChecked(false);
						break;
		case     16 : ((filter&tempMask) == filter)?checkBox_5->setChecked(true):checkBox_5->setChecked(false);
						break;
		case     32 : ((filter&tempMask) == filter)?checkBox_6->setChecked(true):checkBox_6->setChecked(false);
						break;
		case     64 : ((filter&tempMask) == filter)?checkBox_7->setChecked(true):checkBox_7->setChecked(false);
						break;
		case    128 : ((filter&tempMask) == filter)?checkBox_8->setChecked(true):checkBox_8->setChecked(false);
						break;
		case    256 : ((filter&tempMask) == filter)?checkBox_9->setChecked(true):checkBox_9->setChecked(false);
						break;
		case    512 : ((filter&tempMask) == filter)?checkBox_10->setChecked(true):checkBox_10->setChecked(false);
						break;
		case   1024 : ((filter&tempMask) == filter)?checkBox_11->setChecked(true):checkBox_11->setChecked(false);
						break;
		case   2048 : ((filter&tempMask) == filter)?checkBox_12->setChecked(true):checkBox_12->setChecked(false);
						break;
		case   4096 : ((filter&tempMask) == filter)?checkBox_13->setChecked(true):checkBox_13->setChecked(false);
						break;
		case   8192 : ((filter&tempMask) == filter)?checkBox_14->setChecked(true):checkBox_14->setChecked(false);
						break;
		case  16384 : ((filter&tempMask) == filter)?checkBox_15->setChecked(true):checkBox_15->setChecked(false);
						break;
		case  32768 : ((filter&tempMask) == filter)?checkBox_16->setChecked(true):checkBox_16->setChecked(false);
						break;
		}
		filter*=2;
	}
}
//
