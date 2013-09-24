#include "changelogdialog.h"
//
changelogDialog::changelogDialog(QWidget * parent, QString * comment, bool * ok) : QDialog(parent)
{
	setupUi(this);
	m_ok = ok;
	m_comment = comment;
	disassemble(); 
	slot_contentChanged();
	submitButton->setFocus();
}

void changelogDialog::slot_submitButtonClicked(){
QString tempString = previewPlainTextEdit->toPlainText().trimmed();

	//tempString = tempString + "\n";
	*m_ok = true;
	//*m_comment = tempString + *m_comment;
	if (logPlainTextEdit->toPlainText() != ""){
		*m_comment = previewPlainTextEdit->toPlainText().trimmed();
	} else {
		QString tempString2 = *m_comment;
		tempString2 = tempString2.trimmed();
		*m_comment = tempString2;
	}
	this->done(true);
}

void changelogDialog::slot_discardButtonClicked(){
	*m_ok = false;
	this->done(false);
}

void changelogDialog::slot_contentChanged(){
QString preview = headerLabel->text();
QString content = logPlainTextEdit->toPlainText();
int end;
	if (logPlainTextEdit->toPlainText() != ""){
		preview = preview.mid(preview.indexOf(":") + 2) + "\n";
		while (content.indexOf("\n") != -1){
			end = content.indexOf("\n");
			preview = preview + "- " + content.mid(0,end+1);
			content = content.mid(end+1);
		}
		if (content.length() != 0) preview = preview + "- " + content;
		previewPlainTextEdit->setPlainText(preview.trimmed() + "\n" + *m_comment);
	} else {
		QString tempString = *m_comment;
		tempString = tempString.trimmed();
		previewPlainTextEdit->setPlainText(tempString);
	}
}


void changelogDialog::disassemble(){
QString comment = *m_comment;
QString line;
QString content;
int start = 0;
int end = comment.indexOf("\n");

	headerLabel->setText("Log-Entry : " + comment.mid(start,end-start));
	comment = comment.mid(end + 1);
	while (comment.left(1) == "-"){
		line = comment.mid(0,comment.indexOf("\n"));
		content = content + line.mid(2) + "\n";
		comment = comment.mid(line.length()+1);
	}
 	logPlainTextEdit->setPlainText(content);
	*m_comment = comment;
}

//
