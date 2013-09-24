#include "editDesktopFile.h"
//
editDesktopFile::editDesktopFile( QString rpmbuildPath, QString desktopFile, QWidget * parent) : QDialog(parent)
{
        setupUi(this);
        _rpmbuildPath = rpmbuildPath.trimmed();
        _desktopFile = desktopFile.trimmed();
        //QPushButton * addFolderButton = new QPushButton(QIcon(":/icon/icons/add.png"),tr("add"),this);
        //tabWidget->setCornerWidget(addFolderButton,Qt::TopRightCorner);
        this->showMaximized();
        tabWidget->removeTab(0);
        loadTabs();
        makeTabs();
        tabWidget->setTabsClosable(true);
       // connect(addFolderButton,SIGNAL(clicked()),this,SLOT(slot_addFolderButtonClicked()));
        connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(slot_tabCloseRequest(int)));
}

void editDesktopFile::loadTabs(){
    QString desktopFilePath;
        files.clear();
        if( _desktopFile == ""){
            _desktopFile = getDesktopFileName();
        }else{
            if(!_desktopFile.contains(".desktop")){
                QMessageBox::information(this, tr("Error"), tr("Source1 is not a Desktop File, Can't Edit it."));
                return;
            }
        }
        desktopFilePath = _rpmbuildPath + "/SOURCES/" + _desktopFile;
        if( !QFile::exists(desktopFilePath)){

            if( !createDesktopFile(desktopFilePath) ){
               QMessageBox::information(this, tr("Error"), tr("Can't Create Desktop File %1, Please Check your access right.").arg(desktopFilePath));
               return;
           }
       }

       files << desktopFilePath;
}

void editDesktopFile::makeTabs(){
QStringListIterator it(files);
QString entry;
int index = 0;

        tabWidget->clear();
        while (it.hasNext()){
                entry = it.next();
                tabWidget->addTab(new desktopFileEditor(_rpmbuildPath+"/SOURCES/"+_desktopFile, this), entry);
                index++;
        }
}
QString editDesktopFile::getDesktopFileName(){
    QString filename = QFileDialog::getSaveFileName(this, tr("First Create Desktop File"), _rpmbuildPath + "/SOURCES", "Desktop Files (*.desktop)");
    QFileInfo fi(filename);
    return fi.fileName();
}
/*
void editDesktopFile::slot_addFolderButtonClicked(){//与macroViewContainer用一个ui文件，懒得做了...
QString filename = QFileDialog::getOpenFileName(this, tr("Get Macro Folder"), _rpmbuildPath + "/SOURCES",  "Desktop Files (*.desktop)");
        if (filename != ""){
                files << filename;
                makeTabs();
        }
}
*/
bool editDesktopFile::createDesktopFile(QString file){
    /*
    QFile f(file);
    QTextStream stream(&f);
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    stream << << endl ;
    */
    if( !QFile::copy((QString)getenv("HOME")+ "/template.desktop", file ) )
        return false;
    else
        return true;
}
QString editDesktopFile::_getFileName()
{
    return _desktopFile;
}
void editDesktopFile::slot_delFolderButtonClicked(){
int index = tabWidget->currentIndex();
QString tabName = tabWidget->tabText(index);
int rc;
        if (index == 0){
                QMessageBox::information(this,tr("ATTENTION"),tr("Your can not remove your Created Desktop file!"));
        } else {
                rc = QMessageBox::question(this,tr("ATTENTION"),tr("You are about to remove the tab: ") + tabName + tr("\nDo you want to proceed?"),QMessageBox::Yes,QMessageBox::No);
                if (rc == QMessageBox::Yes){
                        tabWidget->removeTab(index);
                        files.removeAt(index);
                }
        }
}


void editDesktopFile::slot_tabCloseRequest(int index){
QString tabName = tabWidget->tabText(index);
int rc;
        if (index == 0){
                QMessageBox::information(this,tr("ATTENTION"),tr("Your Created Desktop file can not be removed!"));
        } else {
                rc = QMessageBox::question(this,tr("ATTENTION"),tr("You are about to remove the tab: ") + tabName + "\nDo you want to proceed?",QMessageBox::Yes,QMessageBox::No);
                if (rc == QMessageBox::Yes){
                        tabWidget->removeTab(index);
                        files.removeAt(index);
                }
        }
}
//
