#include "macroviewcontainer.h"
//
macroViewContainer::macroViewContainer(QWidget * parent) : QDialog(parent)
{
	setupUi(this);
	QPushButton * addFolderButton = new QPushButton(QIcon(":/icon/icons/add.png"),tr("add"),this);
	tabWidget->setCornerWidget(addFolderButton,Qt::TopRightCorner);
	this->showMaximized();
	tabWidget->removeTab(0);
	loadTabs();
	makeTabs();
	tabWidget->setTabsClosable(true);
	connect(addFolderButton,SIGNAL(clicked()),this,SLOT(slot_addFolderButtonClicked()));
	connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(slot_tabCloseRequest(int)));
}

void macroViewContainer::loadTabs(){
QString path = (QString)getenv("HOME");
QFile file(path + "/.easyrpmbuilder/macrofolders.txt");
	folders.clear();
	folders << path + "/.rpmmacros";
	if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			folders << stream.readLine();
		}
		file.close();
	} else {
		folders << "/usr/lib/rpm" << "/etc/rpm"; 
	}
}

void macroViewContainer::makeTabs(){
QStringListIterator it(folders);
QString entry;
int index = 0;

	tabWidget->clear();
	while (it.hasNext()){
		entry = it.next();
		if (index == 0){
			tabWidget->addTab(new editPrivateMacroFile(this), entry);
		} else {
			tabWidget->addTab(new showMacros(this, entry), entry);
		}
		index++;
	}
}

void macroViewContainer::slot_addFolderButtonClicked(){
QString foldername = QFileDialog::getExistingDirectory(this, tr("Get Macro Folder"), "/home", QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
	if (foldername != ""){
		folders << foldername;
		makeTabs();
		saveTabs();
	}
}

void macroViewContainer::slot_delFolderButtonClicked(){
int index = tabWidget->currentIndex();
QString tabName = tabWidget->tabText(index);
int rc;
	if (index == 0){
		QMessageBox::information(this,tr("ATTENTION"),tr("Your can not remove your private macro file!"));
	} else {
		rc = QMessageBox::question(this,tr("ATTENTION"),tr("You are about to remove the tab: ") + tabName + tr("\nDo you want to proceed?"),QMessageBox::Yes,QMessageBox::No);
		if (rc == QMessageBox::Yes){
			tabWidget->removeTab(index);
			folders.removeAt(index);
			saveTabs();
		}
	}
}

void macroViewContainer::saveTabs(){
QString path = (QString)getenv("HOME");
QStringListIterator it(folders);
QFile file(path + "/.easyrpmbuilder/macrofolders.txt");
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream stream(&file);
		QString temp = it.next();
		while (it.hasNext()){
			stream << it.next() << endl;
		}
		file.close();
	}
}

void macroViewContainer::slot_tabCloseRequest(int index){
QString tabName = tabWidget->tabText(index);
int rc;
	if (index == 0){
		QMessageBox::information(this,tr("ATTENTION"),tr("Your private marco file can not be removed!"));
	} else {
		rc = QMessageBox::question(this,tr("ATTENTION"),tr("You are about to remove the tab: ") + tabName + "\nDo you want to proceed?",QMessageBox::Yes,QMessageBox::No);
		if (rc == QMessageBox::Yes){
			tabWidget->removeTab(index);
			folders.removeAt(index);
			saveTabs();
		}
	}
}
//
