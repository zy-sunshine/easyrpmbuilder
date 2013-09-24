#include "settings.h"
//
settings::settings(QWidget * parent ) 	: QDialog(parent)
{
	setupUi(this);
	homePath = getenv("HOME");
	language = "auto";
	load();
}

void settings::load(){
int index = 0;

	if (QFile::exists(homePath + "/.easyrpmbuilder/settings")){
		QFile tempFile(homePath + "/.easyrpmbuilder/settings");
		if (tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream stream(&tempFile);
			while (!stream.atEnd()){
				switch (index){
				case 0 : rpmRootPathEdit->setText(stream.readLine());
							break;
				case 1 : vendorLineEdit->setText(stream.readLine());
							break;
				case 2 : packagerLineEdit->setText(stream.readLine());
							break;
				case 3 : homepageLineEdit->setText(stream.readLine());
							break;
                                case 4 : sourceLineEdit->setText(stream.readLine());
                                                        break;
                                case 5 : source1LineEdit->setText(stream.readLine());
                                                        break;
                                case 6 : buildrootLineEdit->setText(stream.readLine());
                                                        break;
                                case 7 : language = stream.readLine();
							break;
				}
				index++;
			}
			tempFile.close();
		}
	}
	QDir dir("/usr/share/qt4/translations");
	QStringListIterator it(dir.entryList(QStringList("easyrpmbuilder*.qm")));
	languageComboBox->addItem("auto");
	while (it.hasNext()){
		languageComboBox->addItem(it.next());
	}
	languageComboBox->setCurrentIndex(languageComboBox->findText(language));
}

void settings::slot_browseButtonClicked(){
QString rc = QFileDialog::getExistingDirectory(0,tr("Select RPM Root Dir"),rpmRootPathEdit->text());
	if (rc != "") rpmRootPathEdit->setText(rc);
}

void settings::slot_okButtonClicked(){
	QFile tempFile(homePath + "/.easyrpmbuilder/settings");
	if (tempFile.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream stream(&tempFile);
		stream << rpmRootPathEdit->text() << endl;
		stream << vendorLineEdit->text() << endl;
		stream << packagerLineEdit->text() << endl;
		stream << homepageLineEdit->text() << endl;
                stream << sourceLineEdit->text() << endl;
                stream << source1LineEdit->text() << endl;
                stream << buildrootLineEdit->text() << endl;
		stream << languageComboBox->currentText();
		tempFile.close();
	}
	this->done(0);
}
//
