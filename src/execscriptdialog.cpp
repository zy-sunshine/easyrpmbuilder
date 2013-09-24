#include "execscriptdialog.h"
//
execScriptDialog::execScriptDialog( QWidget * parent, QString script, QString name, QString version ) : QDialog(parent)
{
	setupUi(this);
	documentHighlighter = new highlighter(systemOutput->document());
process = new QProcess(this);
QFile file("/tmp/easyrpmtempscript.sh");

	connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_readyReadStandardOutput()));
	connect(process,SIGNAL(readyReadStandardError()),this,SLOT(slot_readyReadStandardError()));
	connect(process,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(slot_processFinished()));
	doneButton->setEnabled(false);
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream stream(&file);
		stream << script << endl;
		file.close();
		file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadUser|QFile::WriteUser|QFile::ExeUser|QFile::ReadGroup|QFile::WriteGroup|QFile::ExeGroup|QFile::ReadOther|QFile::WriteOther|QFile::ExeOther);
		process->start("/tmp/easyrpmtempscript.sh " + name + " " + version);
	}
}

void execScriptDialog::slot_readyReadStandardOutput(){
	QString rc=process->readAll();
	systemOutput->appendPlainText(rc.trimmed());
	systemOutput->moveCursor(QTextCursor::End);
}

void execScriptDialog::slot_readyReadStandardError(){
	QString rc=process->readAllStandardError();
	systemOutput->appendPlainText(rc.trimmed());
	systemOutput->moveCursor(QTextCursor::End);
}

void execScriptDialog::slot_processFinished(){
	doneButton->setEnabled(true);
}
