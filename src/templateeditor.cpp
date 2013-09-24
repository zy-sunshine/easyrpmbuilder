#include "templateeditor.h"
//
templateEditor::templateEditor(QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	loadTemplates();
}

void templateEditor::resizeEvent(QResizeEvent * e){
	e = e; // just to keep the compiler happy .....
	templateTable->setColumnWidth(0,templateTable->width()-25);
}

void templateEditor::loadTemplates(){
QDir templates((QString)getenv("HOME")+"/.easyrpmbuilder","*.tpl");
QStringListIterator iterator(templates.entryList());
QString entry;
int lineCount = 0;
	templateTable->clear();
	templateTable->setRowCount(0);
	templateTable->setColumnCount(1);
	templateTable->setHorizontalHeaderLabels(QStringList("Template Name"));
	while (iterator.hasNext()){
		entry = iterator.next();
		templateTable->insertRow(lineCount);
		templateTable->setItem(lineCount,0,new QTableWidgetItem(entry));
		lineCount++;
	}
        QDir tempDir("/usr/share/easyrpmbuilder/");
        QStringList distros = tempDir.entryList((QStringList)"*.grp");
	QStringListIterator it(distros);
	if (it.hasNext()) distributionComboBox->clear();
	QString distro;
	while (it.hasNext()){
		distro = it.next();
		distro = distro.mid(0,distro.indexOf(".grp"));
		distributionComboBox->addItem(distro);
	}
}

void templateEditor::slot_delTemplateButtonClicked(){
	int rc = QMessageBox::warning(this,tr("WARNING"),tr("You are about to delete the template\n\n------------------------------\n") + templateTable->currentItem()->text() + tr("\n------------------------------\n\nDo you realy want to proceed?"),QMessageBox::Yes,QMessageBox::No);
	if (rc == QMessageBox::Yes){
		QString filename = templateTable->currentItem()->text();
		QFile::remove((QString)getenv("HOME")+"/.easyrpmbuilder/" + filename);
		loadTemplates();
	}
}

void templateEditor::slot_submitButtonClicked(){
	if (templatenameLineEdit->text() != ""){
		QFile templateFile((QString)getenv("HOME")+"/.easyrpmbuilder/"+templatenameLineEdit->text()+".tpl");
		if (templateFile.open(QIODevice::WriteOnly|QIODevice::Text)){
			QTextStream stream(&templateFile);
                        //stream.setCodec(QTextCodec::codecForName("UTF-8"));
			stream << ">" << templatenameLineEdit->text() << "<-" << endl;
			stream << ">" << versionLineEdit->text() << "<-" << endl;
			stream << ">" << licenseLineEdit->text() << "<-" << endl;
			stream << ">" << groupComboBox->currentText() << "<-" << endl;
			stream << ">" << distributionComboBox->currentText() << "<-" << endl;
			stream << ">" << buildCommandsPlainTextEdit->toPlainText() << "<-" << endl;
			stream << ">" << installCommandsPlainTextEdit->toPlainText() << "<-" << endl;
			templateFile.close();
                        QMessageBox::information(this, tr("info"), tr("Saved Success"));
		}
	}
        //loadTemplates();
}

void templateEditor::slot_templateTableClicked(){
QString filename = templateTable->currentItem()->text();
QString line;
QString container;
QString groupString;
int index = 0;

	if (filename != ""){
		QFile templateFile((QString)getenv("HOME")+"/.easyrpmbuilder/"+filename);
		if (templateFile.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream stream(&templateFile);
			do {
				line = stream.readLine();
				if (line.contains("<-")){
					container = container + line + "\n";
					container = container.mid(1,container.length()-4);
					switch (index){
					case 0 : templatenameLineEdit->setText(container);
								break;
					case 1 : versionLineEdit->setText(container);
								break;
					case 2 : licenseLineEdit->setText(container);
								break;
					case 3 : groupString = container;
							 groupComboBox->setCurrentIndex(groupComboBox->findText(groupString));
								break;
					case 4 : distributionComboBox->setCurrentIndex(distributionComboBox->findText(container));
							 groupComboBox->setCurrentIndex(groupComboBox->findText(groupString));
								break;
					case 5 : buildCommandsPlainTextEdit->setPlainText(container);
								break;
					case 6 : installCommandsPlainTextEdit->setPlainText(container);
								break;
					}
					container = "";
					index++;

				} else {
					container = container + line + "\n";
				}
			} while (!stream.atEnd());
			templateFile.close();
		}
	}
}

void templateEditor::slot_distroComboBoxValueChanged(){
QString line;
QString filename = "/usr/share/easyrpmbuilder/" + distributionComboBox->currentText() + ".grp";
if (!QFile::exists(filename)) filename = "/usr/share/easyrpmbuilder/groups.grp";
QFile file(filename);
	if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
		groupComboBox->clear();
		QTextStream stream(&file);
		while (!stream.atEnd()){
			line = stream.readLine();
			groupComboBox->addItem(line);
		}
		file.close();
	}
}
//
