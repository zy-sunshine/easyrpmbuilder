#include "editprivatemacrofile.h"
//
editPrivateMacroFile::editPrivateMacroFile(QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	myHighLighter = new highlighter(macroPlainTextEdit->document());
	slot_discardButtonClicked();
}

void editPrivateMacroFile::slot_submitButtonClicked(){
QString path = (QString)getenv("HOME") + "/.rpmmacros";
QFile file(path);
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream stream(&file);
		stream << macroPlainTextEdit->toPlainText();
		file.close();
		QMessageBox::information(this,"DEBUG",tr("Changes saved!"));
	}
}

void editPrivateMacroFile::slot_discardButtonClicked(){
QString path = (QString)getenv("HOME") + "/.rpmmacros";
QFile file(path);
QString content;
	if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			content = content + stream.readLine() + "\n";
		}
		macroPlainTextEdit->setPlainText(content);
		file.close();
	}
}

//
