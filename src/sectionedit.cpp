#include "sectionedit.h"
//
sectionEdit::sectionEdit(QWidget * parent, QString caption, QString * content, bool * ok) : QDialog(parent)
{
	globalOK = ok;
	setupUi(this);
	documentHighlighter = new highlighter(sectionContentPlainTextEdit->document());
	this->setWindowTitle("Section Editor - " + caption);
	sectionLabel->setText("Section Editor : " + caption);
	contentPointer = content;
	eventCounter = 0;
	sectionContentPlainTextEdit->setPlainText(*content);
	*globalOK = false;
}


void sectionEdit::slot_submitButtonClicked(){
	*contentPointer = sectionContentPlainTextEdit->toPlainText();
	this->done(true);
}

void sectionEdit::slot_discardButtonClicked(){
	this->done(false);
	*globalOK = false;
}

void sectionEdit::slot_contentChanged(){
	if (eventCounter == 0) eventCounter = 1; else *globalOK = true;
}

//
