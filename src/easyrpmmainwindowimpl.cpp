#include "easyrpmmainwindowimpl.h"
#include <unistd.h> //for getuid()
//
EasyRPMMainWindowImpl::EasyRPMMainWindowImpl( QWidget * parent, Qt::WFlags f) : QMainWindow(parent, f)
{
	homePath = getenv("HOME");
	setupUi(this);
	this->showMaximized();
	actualFilename = "";
	unknownSectionLabel = new QLabel(tr("Tag:"),this);
	unknownSectionLabel->setFont(QFont("Helvetic",10,QFont::Normal,false));
	unknownSectionComboBox = new QComboBox(this);
	unknownSectionComboBox->setMinimumWidth(200);
	actionAddSection = new QAction(QIcon(":/icon/icons/add.png"),"",this);
	actionAddSection->setToolTip(tr("Add a new Section"));
	actionDelSection = new QAction(QIcon(":/icon/icons/del.png"),"",this);
	actionDelSection->setToolTip(tr("Remove current Section"));
	actionBuildBinary = new QAction(QIcon(":/icon/icons/binary.png"),"",this);
	actionBuildBinary->setToolTip(tr("build binary only"));
	actionBuildSource = new QAction(QIcon(":/icon/icons/source.png"),"",this);
	actionBuildSource->setToolTip(tr("build source only"));
	actionBuildAll = new QAction(QIcon(":/icon/icons/both.png"),"",this);
	actionBuildAll->setToolTip(tr("build all"));
	actionEditSources = new QAction(QIcon(":/icon/icons/editsources.png"),"",this);
	actionEditSources->setToolTip(tr("Edit Sources Section"));
	actionEditPatches = new QAction(QIcon(":/icon/icons/editpatches.png"),"",this);
	actionEditPatches->setToolTip(tr("Edit Patches Section"));
	actionEditRequire = new QAction(QIcon(":/icon/icons/require.png"),"",this);
	actionEditRequire->setToolTip(tr("Edit Requires Section"));
	actionEditProvide = new QAction(QIcon(":/icon/icons/provides.png"),"",this);
	actionEditProvide->setToolTip(tr("Edit Provides Section"));
	actionEditObsolete = new QAction(QIcon(":/icon/icons/obsolete.png"),"",this);
	actionEditObsolete->setToolTip(tr("Edit Obsoletes Section"));
	actionEditConflict = new QAction(QIcon(":/icon/icons/conflicts.png"),"",this);
	actionEditConflict->setToolTip(tr("Edit Conflicts Section"));
	actionShowMacros = new QAction(QIcon(":/icon/icons/showmacros.png"),"",this);
	actionShowMacros->setToolTip(tr("Show / Edit Macros"));
	recentlyUsed1 = new QAction(this);
	recentlyUsed2 = new QAction(this);
	recentlyUsed3 = new QAction(this);
	recentlyUsed4 = new QAction(this);
	recentlyUsed5 = new QAction(this);
	connect(recentlyUsed1,SIGNAL(activated()),this,SLOT(slot_actionRecentlyUsed1Activated()));
	connect(recentlyUsed2,SIGNAL(activated()),this,SLOT(slot_actionRecentlyUsed2Activated()));
	connect(recentlyUsed3,SIGNAL(activated()),this,SLOT(slot_actionRecentlyUsed3Activated()));
	connect(recentlyUsed4,SIGNAL(activated()),this,SLOT(slot_actionRecentlyUsed4Activated()));
	connect(recentlyUsed5,SIGNAL(activated()),this,SLOT(slot_actionRecentlyUsed5Activated()));
	connect(menu_Settings,SIGNAL(aboutToShow()),this,SLOT(slot_menuSettingsAboutToShow()));
	
	process = new QProcess(this);
	connect(actionAddSection,SIGNAL(activated()),this,SLOT(slot_addSectionButtonClicked()));
	connect(actionDelSection,SIGNAL(activated()),this,SLOT(slot_delSectionButtonClicked()));
	connect(process,SIGNAL(readyReadStandardOutput()),this,SLOT(slot_readyReadStandardOutput()));
	connect(process,SIGNAL(readyReadStandardError()),this,SLOT(slot_readyReadStandardError()));
	connect(process,SIGNAL(finished(int, QProcess::ExitStatus)),this,SLOT(slot_processFinished()));
	connect(actionEditSources,SIGNAL(activated()),this,SLOT(slot_editSources()));
	connect(actionEditPatches,SIGNAL(activated()),this,SLOT(slot_editPatches()));
	connect(actionEditRequire,SIGNAL(activated()),this,SLOT(slot_actionEditRequiresActivated()));
	connect(actionEditProvide,SIGNAL(activated()),this,SLOT(slot_actionEditProvidesActivated()));
	connect(actionEditObsolete,SIGNAL(activated()),this,SLOT(slot_actionEditObsoletesActivated()));
	connect(actionEditConflict,SIGNAL(activated()),this,SLOT(slot_actionEditConflictsActivated()));
	connect(actionBuildBinary,SIGNAL(activated()),this,SLOT(slot_buildBinaryOnlyButtonClicked()));
	connect(actionBuildSource,SIGNAL(activated()),this,SLOT(slot_buildSourceOnlyButtonClicked()));
	connect(actionBuildAll,SIGNAL(activated()),this,SLOT(slot_buildPackageButtonClicked()));
	connect(actionShowMacros,SIGNAL(activated()),this,SLOT(slot_actionShowMacrosActivated()));
	logoTimer = new QTimer(this);
	connect(logoTimer,SIGNAL(timeout()),this,SLOT(slot_logoTimerTimeout()));
	hideTimer = new QTimer(this);
	connect(hideTimer,SIGNAL(timeout()),this,SLOT(slot_hideLogo()));
	actionNewSpecFile = new QAction(this);
	actionNewSpecFile->setToolTip(tr("Open New Spec File"));
	actionNewSpecFile->setIcon(QIcon(":/icon/icons/new.png"));
	actionOpenSpecFile = new QAction(this);
	actionOpenSpecFile->setToolTip(tr("Open Spec File"));
	actionOpenSpecFile->setIcon(QIcon(":/icon/icons/open.png"));
	actionSaveSpecFile = new QAction(this);
	actionSaveSpecFile->setToolTip(tr("Save Spec File"));
	actionSaveSpecFile->setIcon(QIcon(":/icon/icons/save.png"));
	actionPrintSpecFile = new QAction(this);
	actionPrintSpecFile->setToolTip(tr("Print Spec File"));
	actionPrintSpecFile->setIcon(QIcon(":/icon/icons/print.png"));
	actionOpenTemplateEditor = new QAction(this);
	actionOpenTemplateEditor->setToolTip(tr("Open Template Editor"));
	actionOpenTemplateEditor->setIcon(QIcon(":/icon/icons/settings.png"));
	actionOpenTemplate = new QAction(this);
	actionOpenTemplate->setToolTip(tr("Open Template"));
	actionOpenTemplate->setIcon(QIcon(":/icon/icons/open.png"));
	actionQuit = new QAction(this);
	actionQuit->setToolTip(tr("Quit the Application"));
	actionQuit->setIcon(QIcon(":/icon/icons/exit.png"));
	addAction(actionNewSpecFile);
	FileToolBar->addAction(actionOpenSpecFile);
	FileToolBar->addAction(actionSaveSpecFile);
	FileToolBar->addAction(actionPrintSpecFile);
	FileToolBar->addSeparator();
	FileToolBar->addAction(actionOpenTemplateEditor);
	FileToolBar->addAction(actionOpenTemplate);
	FileToolBar->addSeparator();
	ProjectToolBar->addWidget(unknownSectionLabel);
	ProjectToolBar->addWidget(unknownSectionComboBox);
	ProjectToolBar->addAction(actionAddSection);
	ProjectToolBar->addAction(actionDelSection);
	ProjectToolBar->addSeparator();
	ProjectToolBar->addAction(actionEditSources);
	ProjectToolBar->addAction(actionEditPatches);
	ProjectToolBar->addSeparator();
	ProjectToolBar->addAction(actionEditRequire);
	ProjectToolBar->addAction(actionEditProvide);
	ProjectToolBar->addAction(actionEditConflict);
	ProjectToolBar->addAction(actionEditObsolete);
	ProjectToolBar->addSeparator();
	ProjectToolBar->addAction(actionShowMacros);
	ProjectToolBar->addSeparator();
	ProjectToolBar->addAction(actionBuildBinary);
	ProjectToolBar->addAction(actionBuildSource);
	ProjectToolBar->addAction(actionBuildAll);
	FileToolBar->addAction(actionQuit);
	connect(actionNewSpecFile,SIGNAL(activated()),this,SLOT(slot_actionNewOtherSpecFile()));
	connect(actionOpenSpecFile,SIGNAL(activated()),this,SLOT(slot_actionOpenSpecFile()));
	connect(actionSaveSpecFile,SIGNAL(activated()),this,SLOT(slot_actionSaveSpecFile()));
	connect(actionPrintSpecFile,SIGNAL(activated()),this,SLOT(slot_actionPrintSpecFileActivated()));
	connect(actionOpenTemplateEditor,SIGNAL(activated()),this,SLOT(slot_actionTemplateEditor()));
	connect(actionOpenTemplate,SIGNAL(activated()),this,SLOT(slot_actionOpenTemplate()));
	connect(actionQuit,SIGNAL(activated()),this,SLOT(close()));
	connect(unknownSectionComboBox,SIGNAL(activated(QString)),this,SLOT(slot_actionEditSectionActivated(QString)));
	loadSettings();
	loadRecentlyUsed();
	statusbar->showMessage(tr("+ + +  Application startet  + + +"),3000);
	rebuildRecentlyUsedMenu();
	progress = new QProgressDialog(tr("Build process in progress ..... Please wait!"),0,0,100,this);
	installHighlighter = new highlighter(installPlainTextEdit->document());
	buildHighlighter = new highlighter(buildPlainTextEdit->document());
	outputHighlighter = new highlighter(systemOutput->document());
        filesHighlighter = new highlighter(filesPlainTextEdit->document());
	logoLabel = new QLabel("",this);
	logoLabel->setPixmap(QPixmap(":/icon/icons/logo.png"));
	logoTimer->setSingleShot(true);
	logoTimer->start(250);
}

EasyRPMMainWindowImpl::~EasyRPMMainWindowImpl(){
	QFile filesettingsFile(homePath + "/.easyrpmbuilder/filesettings");
	if (filesettingsFile.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream filesettingsStream(&filesettingsFile);
		filesettingsStream << actualFilename << endl;
		filesettingsStream << recentlyUsed;
		actionOption_ToolBar->isChecked()?filesettingsStream << "true" << endl: filesettingsStream << "false" << endl;
		actionProject_ToolBar->isChecked()?filesettingsStream << "true" << endl: filesettingsStream << "false" << endl;
		filesettingsStream << QString::number(toolbarMask);
		filesettingsFile.close();
	}
	QFile windowStateFile(homePath + "/.easyrpmbuilder/windowstate");
	if (windowStateFile.open(QIODevice::WriteOnly)){
		QByteArray windowState = this->saveState();
		QDataStream stream(&windowStateFile);
		stream << windowState;
		windowStateFile.close();
	}
	if ((contentChanged) && (actualFilename != "")){
		if (QMessageBox::question(this,tr("WARNING"),tr("There is unsaved data left\nDo you want to save the changes?"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
			slot_actionSaveSpecFile();
		}
	}
}

void EasyRPMMainWindowImpl::loadSettings(){
QString tempDistro = distributionComboBox->currentText();
QString tempGroup = groupComboBox->currentText();
bool tempContentChanged = contentChanged;

	if (QFile::exists(homePath + "/.easyrpmbuilder/settings")){
		QFile tempFile(homePath + "/.easyrpmbuilder/settings");
		if (tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream stream(&tempFile);
			rpmRootPath = stream.readLine();
			defaultVendor = stream.readLine();
			defaultPackager = stream.readLine();
			defaultHomepage = stream.readLine();
                        defaultSource = stream.readLine();
                        defaultSource1 = stream.readLine();
                        defaultBuildroot = stream.readLine();
			tempFile.close();
		}
	} else {
		QDir tempDir;
		tempDir.mkdir(homePath + "/.easyrpmbuilder");
		QFile tempFile(homePath + "/.easyrpmbuilder/settings");
		if (tempFile.open(QIODevice::WriteOnly|QIODevice::Text)){
			QTextStream stream(&tempFile);
                        stream << QDir::homePath()+"/rpmbuild" << endl;
                        stream << "MGC Group" << endl;
                        stream << "MGC Group" << endl;
                        stream << "http://www.linuxfans.org" << endl;
                        stream << "%{name}-%{version}.tar.gz" << endl;
                        stream << "%{name}.desktop" << endl;
                        stream << "%{_tmppath}/%{name}-%{version}-%{release}-buildroot-%(%{__id_u} -n)" << endl;
			stream << "auto" << endl;
                        rpmRootPath = QDir::homePath()+"/rpmbuild";
                        defaultVendor = "MGC Group";
                        defaultPackager = "MGC Group";
                        defaultHomepage = "http://www.linuxfans.org";
                        defaultSource = "%{name}-%{version}.tar.gz";
                        defaultSource1 = "%{name}.desktop";
                        defaultBuildroot = "%{_tmppath}/%{name}-%{version}-%{release}-buildroot-%(%{__id_u} -n)";
			tempFile.close();
		}
	}
	// copy Templates
	QDir tempDir;
	tempDir.setPath("/usr/share/easyrpmbuilder");
	QString destPath = (QString)getenv("HOME") + (QString)"/.easyrpmbuilder/";
	QStringList files = tempDir.entryList((QStringList)"*.tpl");
	QStringListIterator it(files);
	QString filename;
	while (it.hasNext()){
		filename = it.next();
		if (!QFile::exists(destPath+filename)){
			QFile::copy((QString)"/usr/share/easyrpmbuilder/" + (QString)filename,destPath + filename); 
		}
                if (!QFile::exists(destPath+"template.desktop"))
                    QFile::copy((QString)"/usr/share/easyrpmbuilder/template.desktop", destPath + "template.desktop");
	}
	QStringList distros = tempDir.entryList((QStringList)"*.grp");
	QStringListIterator it2(distros);
	if (it2.hasNext()) distributionComboBox->clear();
	QString distro;
	while (it2.hasNext()){
		distro = it2.next();
		distro = distro.mid(0,distro.indexOf(".grp"));
		distributionComboBox->addItem(distro);
	}
	distributionComboBox->setCurrentIndex(distributionComboBox->findText(tempDistro));
	groupComboBox->setCurrentIndex(groupComboBox->findText(tempGroup));
	if (!tempContentChanged){
		contentChanged = false;
		this->setWindowTitle("EasyRPM Builder - " + actualFilename);
	}
}

void EasyRPMMainWindowImpl::loadRecentlyUsed(){
QString line;
int index = 0;
	toolbarMask = 65535;
	if (QFile::exists(homePath + "/.easyrpmbuilder/filesettings")){
		QFile filesettingsFile(homePath + "/.easyrpmbuilder/filesettings");
		if (filesettingsFile.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream filesettingsStream(&filesettingsFile);
			actualFilename = filesettingsStream.readLine();
			while (!filesettingsStream.atEnd()){
				line = filesettingsStream.readLine();
				if ((line == "true") || (line == "false") || (index > 0)){
					switch (index){
					case 0 : if (line == "true"){
								FileToolBar->setVisible(true);
								actionOption_ToolBar->setChecked(true);
							 } else {
								FileToolBar->setVisible(false);
								actionOption_ToolBar->setChecked(false);
							 }
							 index++;
							 	break;
					case 1 : if (line == "true"){
								ProjectToolBar->setVisible(true);
								actionProject_ToolBar->setChecked(true);
							 } else {
								ProjectToolBar->setVisible(false);
								actionProject_ToolBar->setChecked(false);
							 }
							 index++;
							 	break;
					case 2 : toolbarMask = line.toLong();
								break;
					}
				} else {
					recentlyUsed += line + "\n";
				}
			}
			filesettingsFile.close();
			configToolBars();
			loadFile(actualFilename);
		}
	}
	if (QFile::exists(homePath + "/.easyrpmbuilder/windowstate")){
		QFile windowStateFile(homePath + "/.easyrpmbuilder/windowstate");
		if (windowStateFile.open(QIODevice::ReadOnly)){
			QByteArray buffer;
			QByteArray windowState;
			QDataStream stream(&buffer,QIODevice::ReadOnly);
			stream.setDevice(&windowStateFile);
			stream >> windowState;
			this->restoreState(windowState);
			windowStateFile.close();
		}
	}
}

void EasyRPMMainWindowImpl::slot_contentChanged(){
	contentChanged = true;
	this->setWindowTitle("EasyRPM Builder - " + actualFilename + " (unsaved)");
}

void EasyRPMMainWindowImpl::slot_actionNewOtherSpecFile(){
	checkForContentChanged();
	changeLogEntry = "";
	actualFilename = "";
	this->setWindowTitle("EasyRPM Builder - ");
        //buildRoot = "%{_tmppath}/build-root-%{name}";
        //buildRootPathEdit->setText(buildRoot);
	nameLineEdit->setText("Applicationname");
	summaryLineEdit->setText("Your short description (single line)");
	versionLineEdit->setText("0.1.0");
	releaseSpinBox->setValue(1);
	vendorLineEdit->setText(defaultVendor);
	packagerLineEdit->setText(defaultPackager);
	urlLineEdit->setText(defaultHomepage);
        sourceLineEdit->setText(defaultSource);
        source1LineEdit->setText(defaultSource1);
        buildRootPathEdit->setText(defaultBuildroot);
        //sourceLineEdit->setText("Zipped TAR-Archive of your Sources");
	descriptionTextEdit->setText("A long discription of your application (even multiple Lines)");
	buildPlainTextEdit->setPlainText("Commands necessary to build the dirctorystructur and to compile the sources\ne.g.\nmkdir -p %{buildroot}/usr/bin\nmkdir %{buildroot}/usr/share/doc/yourApp\nqmake\nCFLAGS=\"$RPM_OPT_FLAGS\" CXXFLAGS=\"$RPM_OPT_FLAGS\" \\\nmake");
	installPlainTextEdit->setPlainText("Commands necessary to install the application.\ne.g.\ncp bin/yourApp %{buildroot}/usr/bin\n/src/doc/index.html %{buildroot}/usr/share/doc/yourApp/index.htm");
	filesPlainTextEdit->setPlainText("List of Files that goes into the package.\ne.g.\n/usr/bin/yourApp\n/usr/share/doc/yourApp/index.html");
	unknownSectionComboBox->clear();
	unknownSectionComboBox->addItem("%prep");
	unknownSectionComboBox->addItem("%clean");
	unknownSection.clear();
	unknownSectionContent.clear();
	unknownSection << "%prep" << "%clean";
	unknownSectionContent << "rm -rf %{buildroot}\nmkdir %{buildroot}" << "rm -rf %{buildroot}";
	statusbar->showMessage(tr("+ + +  New Project opened  + + +"),3000); 
}



void EasyRPMMainWindowImpl::slot_actionOpenSpecFile(){
	checkForContentChanged();
QString filename = QFileDialog::getOpenFileName(this,tr("Open SPEC File"),rpmRootPath + "/SPECS","SPEC-Files (*.spec)");
	if (filename != "") {
		checkRecentlyUsedStructur(filename);
		loadFile(filename);
	}
}

void EasyRPMMainWindowImpl::checkRecentlyUsedStructur(QString filename){
	if (!recentlyUsed.contains(filename)){
		recentlyUsed = filename + "\n" + recentlyUsed;
		rebuildRecentlyUsedMenu();
	} else {
		recentlyUsed.replace(filename+"\n","");
		recentlyUsed = filename + "\n" + recentlyUsed;
		rebuildRecentlyUsedMenu();
	}
}

void EasyRPMMainWindowImpl::loadFile(QString filename){
QString line;
QString section="";
QString sectionContent;
QString tempString;
QString rebuildScript;
int sourceCount = 0;
int patchCount = 0;
bool skip;
bool readInfo = false;
	
	nameLineEdit->clear();
	versionLineEdit->clear();
	releaseSpinBox->setValue(0);
	sourceLineEdit->clear();
	licenceComboBox->clearEditText();
	groupComboBox->clearEditText();
	groupComboBoxMagic->setCurrentIndex(groupComboBoxMagic->findText( "" ));
	distributionComboBox->clearEditText();
	packagerLineEdit->clear();
	vendorLineEdit->clear();
	urlLineEdit->clear();
	summaryLineEdit->clear();
	summaryGBLineEdit->clear();
	descriptionTextEdit->clear();
	descriptionGBTextEdit->clear();
	buildPlainTextEdit->clear();
	installPlainTextEdit->clear();
	filesPlainTextEdit->clear();
	
	

	sources.clear();
	patches.clear();
	unknownSection.clear();
	unknownSectionContent.clear();
	unknownSectionComboBox->clear();
	changeLogEntry = "";
	if (filename != ""){
		actualFilename = filename;
		QFile specFile(filename);
		if (specFile.open(QIODevice::ReadOnly)){
                        requires.clear();
			provides.clear();
			obsoletes.clear();
			conflicts.clear();
			QTextStream stream(&specFile);
			do {
				line = stream.readLine();
				skip = false;
				if (line.indexOf("Name:",Qt::CaseInsensitive) == 0) nameLineEdit->setText(line.mid(line.indexOf(":")+2));
				if (line.indexOf("Summary:",Qt::CaseInsensitive) == 0) summaryLineEdit->setText(line.mid(line.indexOf(":")+2));
				if (line.indexOf("Summary(zh_CN.GB18030):",Qt::CaseInsensitive) == 0) summaryGBLineEdit->setText(line.mid(line.indexOf(":")+2));
				if (line.indexOf("Version:",Qt::CaseInsensitive) == 0) versionLineEdit->setText(line.mid(line.indexOf(":")+2));
                                if (line.indexOf("Release:",Qt::CaseInsensitive) == 0) {
                                    QRegExp rx("(\\d*)");
                                    (line.mid(line.indexOf(":")+2)).contains(rx);
                                    releaseSpinBox->setValue(rx.cap(1).toInt());

                                }
				if (line.indexOf("License:",Qt::CaseInsensitive) == 0) licenceComboBox->setCurrentIndex(licenceComboBox->findText(line.mid(line.indexOf(":")+2)));
                                if (line.indexOf("Requires:",Qt::CaseInsensitive) == 0) requires << line.mid(line.indexOf(":")+2);
                                if (line.indexOf("Provides:",Qt::CaseInsensitive) == 0) provides << line.mid(line.indexOf(":")+2);
                                if (line.indexOf("Conflicts:",Qt::CaseInsensitive) == 0) conflicts << line.mid(line.indexOf(":")+2);
                                if (line.indexOf("Obsoletes:",Qt::CaseInsensitive) == 0) obsoletes << line.mid(line.indexOf(":")+2);
				if (line.indexOf("Group:",Qt::CaseInsensitive) == 0) {
					tempString = line.mid(line.indexOf(":")+2);
					groupComboBox->setCurrentIndex(groupComboBox->findText(tempString));
				}
				if (line.contains("Distribution:",Qt::CaseInsensitive)) {
					distributionComboBox->setCurrentIndex(distributionComboBox->findText(line.mid(line.indexOf(":")+2)));
					groupComboBox->setCurrentIndex(groupComboBox->findText(tempString));
				}
				if (line.indexOf("Group(zh_CN.GB18030):",Qt::CaseInsensitive) == 0) {
					groupComboBoxMagic->setCurrentIndex(groupComboBoxMagic->findText( line.mid(line.indexOf(":")+2) ));
				}
				if (line.indexOf("Patch",Qt::CaseInsensitive) == 0){
					line = line.mid(line.indexOf(":")+2);
					patches << line;
					patchCount++;
				} 
				if (line.indexOf("Source",Qt::CaseInsensitive) == 0){
					line = line.mid(line.indexOf(":")+2);
					if (sourceCount == 0){
						sourceLineEdit->setText(line);
                                       }else if(line.contains(".desktop")){
                                                source1LineEdit->setText(line);
                                       }else {
						sources << line;
					}
					sourceCount++;
				}
				if (line.indexOf("Packager:",Qt::CaseInsensitive) == 0) packagerLineEdit->setText(line.mid(line.indexOf(":")+2));
				if (line.indexOf("Url:",Qt::CaseInsensitive) == 0) urlLineEdit->setText(line.mid(line.indexOf(":")+2));
                                if (line.indexOf("URL:",Qt::CaseInsensitive) == 0) urlLineEdit->setText(line.mid(line.indexOf(":")+2));//因为在magic圈子中有人习惯用大写的URL
				if (line.indexOf("Vendor:",Qt::CaseInsensitive) == 0){
					QString tempString = packagerLineEdit->text();
					vendorLineEdit->setText(line.mid(line.indexOf(":")+2));
					packagerLineEdit->setText(tempString);
				} 
				if (line.indexOf("BuildRoot:",Qt::CaseInsensitive) == 0) buildRootPathEdit->setText(line.mid(line.indexOf(":")+2));
				if (line.indexOf("#>",Qt::CaseInsensitive) == 0){
					line = line.mid(2);
                                }
                                //QMessageBox::information(this,tr("find"),tr("find(%1)").arg(line));
                                if ((line.indexOf("%") == 0) && (line.indexOf("%{") == -1) ){
        //QMessageBox::information(this,tr("find"),tr("find(%1)").arg(line));
					if (section != "") transferSectionInfo(section,sectionContent);
					sectionContent = "";
					section = line;
					skip = true;
					readInfo = true;
				} else {
					if (section != ""){
						sectionContent = sectionContent + line + "\n";
					}
				}
			} while (!stream.atEnd());
			specFile.close();

			if (section != "") transferSectionInfo(section,sectionContent);
		}
		while (filesPlainTextEdit->toPlainText().right(1) == "\n") filesPlainTextEdit->setPlainText(filesPlainTextEdit->toPlainText().left(filesPlainTextEdit->toPlainText().length()-1));
		while (installPlainTextEdit->toPlainText().right(1) == "\n") installPlainTextEdit->setPlainText(installPlainTextEdit->toPlainText().left(installPlainTextEdit->toPlainText().length()-1));
		while (buildPlainTextEdit->toPlainText().right(1) == "\n") buildPlainTextEdit->setPlainText(buildPlainTextEdit->toPlainText().left(buildPlainTextEdit->toPlainText().length()-1));
		if (tempString != "") groupComboBox->setCurrentIndex(groupComboBox->findText(tempString));
		this->setWindowTitle("EasyRPM Builder - " + actualFilename);
		unknownSectionComboBox->addItems(unknownSection);
		contentChanged = false;
		statusbar->showMessage(tr("+ + +  Spec File loaded  + + +"),3000);
	}
}

void EasyRPMMainWindowImpl::slot_nameContentChanged(){
    /*
    if(sourceLineEdit->text().trimmed() == ""){
        QString packagename = nameLineEdit->text() + "-" + versionLineEdit->text();
                if (sourceLineEdit->text().contains(".tar.gz")){
                        packagename = packagename + ".tar.gz";
                }else if( sourceLineEdit->text().contains(".tar.bz2") ){
                        packagename = packagename + ".tar.bz2";
                }else {
                        packagename = packagename + ".tgz";
                }
                contentChanged = true;
                sourceLineEdit->setText(packagename);
     }
     */
}

void EasyRPMMainWindowImpl::slot_versionContentChanged(){
    /*
    if(sourceLineEdit->text().trimmed() == ""){
        QString packagename = nameLineEdit->text() + "-" + versionLineEdit->text();
                if (sourceLineEdit->text().contains(".tar.gz")){
                        packagename = packagename + ".tar.gz";
                }else if( sourceLineEdit->text().contains(".tar.bz2") ){
                        packagename = packagename + ".tar.bz2";
                }else {
                        packagename = packagename + ".tgz";
                }

                contentChanged = true;
                sourceLineEdit->setText(packagename);
    }
    */
}
void EasyRPMMainWindowImpl::slot_buildrootButtonClicked(){
    buildRootPathEdit->setText(defaultBuildroot);
    contentChanged = true;
}
void EasyRPMMainWindowImpl::slot_sourceButtonClicked(){
    sourceLineEdit->setText(defaultSource);
    contentChanged = true;
}
void EasyRPMMainWindowImpl::slot_source1ButtonClicked(){
    source1LineEdit->setText(defaultSource1);
    contentChanged = true;
}
void EasyRPMMainWindowImpl::transferSectionInfo(QString section, QString sectionContent){
bool sectionIdentified = false;
QString tempString;
//QRegExp rx_setup("%setup -.*n.* \\S*");
QRegExp rx_descrip_GB("%description\\s+-.*l.*zh_CN\\.GB18030");

	if (section == "%description") {
		 descriptionTextEdit->setText(sectionContent);
		 sectionIdentified = true;
	}

	if (section.contains(rx_descrip_GB)){
		descriptionGBTextEdit->setText(sectionContent);
		sectionIdentified = true;
	}
/*
        if (section.contains(rx_setup)){
            QMessageBox::information(this,tr("find"),tr("find(%1)").arg(section));
                unknownSection << "%setup -n";
                unknownSectionContent << section;
        }
*/
        if (section.contains("%prep")){
                unknownSection << section.trimmed();
                unknownSectionContent << sectionContent.trimmed();
                sectionIdentified = true;
        }
        if (section.indexOf("%setup") == 0){
            //setup一定在prep之后,在unknownSection 中的prep字段附加%setup
            unknownSectionContent[unknownSection.indexOf("%prep")] += "\n"+section.trimmed()+"\n"+sectionContent.trimmed() ;
                sectionIdentified = true;
        }
	if (section == "%files") {
		filesPlainTextEdit->setPlainText(sectionContent.trimmed());
		sectionIdentified = true;
	}

	if (section.contains("%defattr(")){
                tempString = filesPlainTextEdit->toPlainText().trimmed() + "\n" + section.trimmed() + "\n" + sectionContent.trimmed();
		filesPlainTextEdit->setPlainText(tempString.trimmed());
		sectionIdentified = true;
	}


	if (section.contains("%attr(")){
		tempString = filesPlainTextEdit->toPlainText().trimmed() + "\n" + section.trimmed() + "\n" + sectionContent.trimmed();
		filesPlainTextEdit->setPlainText(tempString.trimmed());
		sectionIdentified = true;
	}

	if ((section.contains("%doc")) && (!section.contains("%docdir"))){
		tempString = filesPlainTextEdit->toPlainText().trimmed() + "\n" + section.trimmed() + "\n" + sectionContent.trimmed();
		filesPlainTextEdit->setPlainText(tempString);
		sectionIdentified = true;
	}
	if (section.contains("%docdir")){
		tempString = section.mid(section.indexOf(" ") + 1);
		unknownSection << "%docdir";
		unknownSectionContent << tempString;
		sectionIdentified = true;
	}
	if (section.contains("%config")){
		tempString = filesPlainTextEdit->toPlainText().trimmed() + "\n" + section.trimmed() + "\n" + sectionContent.trimmed();
		filesPlainTextEdit->setPlainText(tempString);
		sectionIdentified = true;
	}

	if (section == "%install") {
		installPlainTextEdit->setPlainText(sectionContent);
		sectionIdentified = true;
	}
	if (section == "%build") {
		buildPlainTextEdit->setPlainText(sectionContent);
		sectionIdentified = true;
	}
	if (section == "%changelog") {
		int start = sectionContent.indexOf("-") + 2;
		int stop = sectionContent.indexOf("\n",start);
		changeLogEntry = sectionContent.mid(start,stop-start);
		sectionIdentified = false;
	}
	if (!sectionIdentified){
		unknownSection << section;
		unknownSectionContent << sectionContent;
	}
}

void EasyRPMMainWindowImpl::slot_actionSaveSpecFileAs(){
QString filename;
	if (actualFilename == "") {
		filename = QFileDialog::getSaveFileName(this,tr("Save File as"),rpmRootPath + "/SPECS","SPEC Files (*.spec)");
	} else {
		filename = QFileDialog::getSaveFileName(this,tr("Save File as"),actualFilename,"SPEC Files (*.spec)");
	}
	if (filename != "") {
		if (!filename.contains(".spec")) filename = filename + ".spec";
		actualFilename = filename;
		if (QFile::exists(actualFilename)) {
			if (QMessageBox::question(this,tr("WARNING"),tr("The file already exists!\nDo you realy want to overwrite it?"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes) slot_actionSaveSpecFile(); 
		} else {
			slot_actionSaveSpecFile();
		}
		
	}
}

void EasyRPMMainWindowImpl::slot_actionSaveSpecFile(){
if (actualFilename == "") {
	actualFilename = QFileDialog::getSaveFileName(this,tr("Save File as"),rpmRootPath + "/SPECS","SPEC Files (*.spec)");
	if ((actualFilename != "") && (!actualFilename.contains(".spec"))) actualFilename = actualFilename + ".spec";
}

QFile file(actualFilename);
QString timeStamp = makeLogTimeStamp();
QString tempString = changeLogEntry;
QString changeLogTempString;
QString section;
QString sectionContent;
QString rebuildScript;
int sourceCount = 0;
int patchCount = 0;
bool ok;
	if (unknownSection.indexOf("%changelog") != -1){
		changeLogTempString = unknownSectionContent.at(unknownSection.indexOf("%changelog"));
	} 
	
	if (unknownSection.indexOf("%rebuildscript") != -1){
		rebuildScript = unknownSectionContent.at(unknownSection.indexOf("%rebuildscript"));
		rebuildScript = rebuildScript.trimmed();
		rebuildScript = "#>" + rebuildScript;
		rebuildScript.replace("\n","\n#>");
		rebuildScript = rebuildScript.left(rebuildScript.length());
	}
	tempString = "* " + timeStamp + " Version " + versionLineEdit->text() + ". Package rebuild with Easy RPM Builder";
	if (changeLogTempString.contains(tempString)){
		changelogDialog * myChangeLogDialog = new changelogDialog(this,&changeLogTempString,&ok);
		myChangeLogDialog->exec();
	} else {
		changeLogTempString = tempString + "\n\n" + changeLogTempString;
		changelogDialog * myChangeLogDialog = new changelogDialog(this,&changeLogTempString,&ok);
		myChangeLogDialog->exec();
	}
	
	if (ok)	{
		this->setWindowTitle("EasyRPM Builder - " + actualFilename);
		if (file.open(QIODevice::WriteOnly)){
			contentChanged = false;
			QTextStream stream(&file);
			stream << "Name: " << nameLineEdit->text() << endl;
			stream << "Summary: " << (summaryLineEdit->text().left(1).toUpper())+(summaryLineEdit->text().mid(1)) << endl;
			if(summaryGBLineEdit->text().trimmed() != ""){
				stream << "Summary(zh_CN.GB18030): " << summaryGBLineEdit->text().trimmed() << endl;
			}
			stream << "Version: " << versionLineEdit->text() << endl;
                        stream << "Release: " << QString::number(releaseSpinBox->value())+"mgc" << endl;
			stream << "License: " << licenceComboBox->currentText() << endl;
			stream << "Group: " << groupComboBox->currentText() << endl;
			if(groupComboBoxMagic->currentText() != ""){
				stream << "Group(zh_CN.GB18030): " << groupComboBoxMagic->currentText() << endl;
			}
			if (buildRootPathEdit->text() != ""){ stream << "BuildRoot: " << buildRootPathEdit->text() << endl;}
			stream << "Source" + QString::number(sourceCount) + ": " << sourceLineEdit->text() << endl;
			sourceCount++;
                        if(source1LineEdit->text() != ""){
                            stream << "Source" + QString::number(sourceCount) + ": " << source1LineEdit->text() << endl;
                            sourceCount++;
                        }
			QStringListIterator it2(sources);
			while (it2.hasNext()){
				stream << "Source" + QString::number(sourceCount) + ": " << it2.next() << endl;
				sourceCount++;
			}
			QStringListIterator it3(patches);
			while (it3.hasNext()){
				stream << "Patch" + QString::number(patchCount) + ": " << it3.next() << endl;
				patchCount++;
			}
			stream << "Packager: " << packagerLineEdit->text() << endl;
			stream << "Distribution: " << distributionComboBox->currentText() << endl;
                        stream << "URL: " << urlLineEdit->text() << endl;
			stream << "Vendor: " << vendorLineEdit->text() << endl;
                        if (!requires.empty()){
                            QStringList::iterator it;
                            for(it = requires.begin(); it != requires.end(); ++it)
                                stream << "Requires: " << *it << endl;
                        }
                        if(!provides.empty()){
                            QStringList::iterator it;
                            for(it = provides.begin(); it != provides.end(); ++it)
                                stream << "Provides: " << *it << endl;
                        }
                        if(!obsoletes.empty()){
                            QStringList::iterator it;
                            for(it = obsoletes.begin(); it != obsoletes.end(); ++it)
                                stream << "Obsoletes: " << *it << endl;
                        }
                        if(!conflicts.empty()){
                            QStringList::iterator it;
                            for(it = conflicts.begin(); it != conflicts.end(); ++it)
                                stream << "Conflicts: " << *it << endl;
                        }
			stream << "\n%description" << endl << descriptionTextEdit->toPlainText().trimmed() << endl;
			if(descriptionGBTextEdit->toPlainText().trimmed() != ""){
				stream << "\n%description -l zh_CN.GB18030" << endl;
				stream << descriptionGBTextEdit->toPlainText().trimmed() << endl;
			}
                        if (rebuildScript != ""){ stream << "\n#>%rebuildscript\n" << rebuildScript.trimmed() << endl; }
			if (unknownSection.indexOf("%prep") != -1){
                            if (unknownSectionContent.at(unknownSection.indexOf("%prep")).trimmed() != ""){
                                stream << "\n%prep\n" << unknownSectionContent.at(unknownSection.indexOf("%prep")).trimmed() << endl;
                            }else{
                                stream << "%setup -q" << endl;
                            }
			}

			stream << "\n%build\n" << buildPlainTextEdit->toPlainText().trimmed() << endl;
			stream << "\n%install\n" << installPlainTextEdit->toPlainText().trimmed() << endl;
                        /*
			if (unknownSection.indexOf("%kde_post_install") != -1){
				stream << "\n%kde_post_install\n" << unknownSectionContent.at(unknownSection.indexOf("%kde_post_install")).trimmed() << endl;
			}
                        */
			if (unknownSection.indexOf("%clean") != -1){
				stream << "\n%clean\n" << unknownSectionContent.at(unknownSection.indexOf("%clean")).trimmed() << endl;
			}
			QStringListIterator it(unknownSection);
			while (it.hasNext()){
				section = it.next();
                                if ((section != "%docdir") &&
                                    (section != "%rebuildscript") &&
                                    (section != "%changelog") &&
                                    (section != "%clean") &&
                                    (section != "%prep") &&
                                    (section != "%kde_post_install")){
					sectionContent = unknownSectionContent.at(unknownSection.indexOf(section));
					stream << "\n" << section << "\n" << sectionContent.trimmed() << endl;
				}
			}
                        stream << "\n%files\n" << filesPlainTextEdit->toPlainText().trimmed() << endl;
			if (unknownSection.indexOf("%docdir") != -1){
				stream << "%docdir " << unknownSectionContent.at(unknownSection.indexOf("%docdir")) << endl;
			}
			stream << "\n%changelog\n" << changeLogTempString.trimmed() << endl;
			if (unknownSection.indexOf("%changelog") != -1){
				unknownSectionContent.replace(unknownSection.indexOf("%changelog"),changeLogTempString);
			} else {
				unknownSection << "%changelog";
				unknownSectionContent << changeLogTempString;
			}
		}
                file.close();
		statusbar->showMessage(tr("+ + +  Spec File saved  + + +"),3000);
	}
}

void EasyRPMMainWindowImpl::slot_sourceSearchButtonClicked(){
QString rc = QFileDialog::getOpenFileName(this,tr("Get Source Package Archive File"),rpmRootPath + "/SOURCES","Archive (*.tgz *.tar.gz *.tar.bz2)");
QFileInfo fi(rc);
	if (rc != "") {
            sourceLineEdit->setText(fi.fileName());

	}
}
void EasyRPMMainWindowImpl::slot_source1SearchButtonClicked(){
QString rc = QFileDialog::getOpenFileName(this,tr("Get Source Desktop CONFIG File"),rpmRootPath + "/SOURCES","Archive (*.desktop)");
QFileInfo fi(rc);
        if (rc != "") {
            source1LineEdit->setText(fi.fileName());

        }
}
void EasyRPMMainWindowImpl::slot_vendorContentChanged(){
       /*
	packagerLineEdit->setText(vendorLineEdit->text());
        */
}

void EasyRPMMainWindowImpl::slot_actionOptionStartRPMBuild(){
	slot_buildPackageButtonClicked();
}


bool EasyRPMMainWindowImpl::signatureCheck(){
bool flag = false;
QString line;
QString filename = (QString)getenv("HOME") + "/.rpmmacros";
QFile file(filename);

	if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			line = stream.readLine();
			if (line.indexOf("%_gpg_name") == 0) flag = true;
		}
		file.close();
	}
	return flag;
}


void EasyRPMMainWindowImpl::slot_buildPackageButtonClicked(){
QString signature = "";
	offset = 0;
	value = 0;
	if (signatureCheck() == true) signature = " --sign ";
	if (contentChanged){
		slot_actionSaveSpecFile();
	}
	if (actualFilename != ""){
		if (contentChanged){
			QMessageBox::information(this,tr("WARNING"),tr("Content changed! Please save the Spec-File first!"));
		} else {
			groupBox->setEnabled(false);
			FileToolBar->setEnabled(false);
			ProjectToolBar->setEnabled(false);
			menubar->setEnabled(false);
			systemOutput->setPlainText("");
			statusbar->showMessage(tr("+ + +  Package build (binary and source) started  + + +"));
			progress->setLabel(new QLabel(tr("Build process in progress ...... please wait!")));
			progress->setValue(1);
                        //我认为他这个地方写的不妥
                        //如果spec文件中没有biuldroot就指定buildroot，如果有就不用指定了，因为已经写在spec文件中了。
                        //这样正好和他的相反，而且默认的指定目录是按照MGC Group 习惯的标准目录。
                        //BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot-%(%{__id_u} -n)
                        if (buildRootPathEdit->text() != "") {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -ba " + signature + actualFilename);
                        } else {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -ba --buildroot " + \
                                           QDir::tempPath()+"/"+nameLineEdit->text()+"-"+versionLineEdit->text()+"-"+QString::number(releaseSpinBox->value())+"mgc"+"-buildroot-"+QString::number(::getuid()) + \
                                           signature + actualFilename);
                        }
                        /*
			if (buildRootPathEdit->text() == "") {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -ba " + signature + actualFilename);
			} else {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -ba --buildroot " + buildRootPathEdit->text() + " " + signature + actualFilename);
			}
                        */
			
		}
	} else {
		QMessageBox::information(this,tr("ATTENTION"),tr("Please save the SPEC-File first!"));
	}
}

void EasyRPMMainWindowImpl::slot_buildBinaryOnlyButtonClicked(){
QString signature = "";
	offset = 0;
	value = 0;
	if (signatureCheck() == true) signature = " --sign ";
	if (contentChanged){
		slot_actionSaveSpecFile();
	}
	if (actualFilename != ""){
		if (contentChanged){
			QMessageBox::information(this,tr("WARNING"),tr("Content changed! Please save the Spec-File first!"));
		} else {
			groupBox->setEnabled(false);
			FileToolBar->setEnabled(false);
			FileToolBar->setEnabled(false);
			menubar->setEnabled(false);
			systemOutput->setPlainText("");
			statusbar->showMessage(tr("+ + +  Package build (binary only) started  + + +"));
                        if (buildRootPathEdit->text() != "") {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -bb " + signature + actualFilename);
			} else {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -bb --buildroot " + \
                                           QDir::tempPath()+"/"+nameLineEdit->text()+"-"+versionLineEdit->text()+"-"+QString::number(releaseSpinBox->value())+"mgc"+"-buildroot-"+QString::number(::getuid()) + \
                                           signature + actualFilename);
                        }
                        /*
                        if (buildRootPathEdit->text() == "") {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -bb " + signature + actualFilename);
                        } else {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -bb --buildroot " + buildRootPathEdit->text() + " " + signature + actualFilename);
                        }
                        */
		}
	} else {
		QMessageBox::information(this,tr("ATTENTION"),tr("Please save the SPEC-File first!"));
	}
}

void EasyRPMMainWindowImpl::slot_buildSourceOnlyButtonClicked(){
QString signature = "";
	offset = 0;
	value = 0;
	if (signatureCheck() == true) signature = " --sign ";
	if (contentChanged){
		slot_actionSaveSpecFile();
	}
	if (actualFilename != ""){
		if (contentChanged){
			QMessageBox::information(this,tr("WARNING"),tr("Content changed! Please save the Spec-File first!"));
		} else {
			groupBox->setEnabled(false);
			FileToolBar->setEnabled(false);
			ProjectToolBar->setEnabled(false);
			menubar->setEnabled(false);
			systemOutput->setPlainText("");
			statusbar->showMessage(tr("+ + +  Package build (source only) started  + + +"));
                        if (buildRootPathEdit->text() != "") {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -bs " + signature + actualFilename);
			} else {
                                execScript("export LANG=zh_CN.GB18030;rpmbuild -bs --buildroot " + \
                                           QDir::tempPath()+"/"+nameLineEdit->text()+"-"+versionLineEdit->text()+"-"+QString::number(releaseSpinBox->value())+"mgc"+"-buildroot-"+QString::number(::getuid()) + \
                                           signature + actualFilename);
			}
                        /*
                        if (buildRootPathEdit->text() == "") {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -bs " + signature + actualFilename);
                        } else {
                                execScript("export LANG=en_GB.UTF-8;rpmbuild -bs --buildroot " + buildRootPathEdit->text() + " " + signature + actualFilename);
                        }
                        */
		}
	} else {
		QMessageBox::information(this,tr("ATTENTION"),tr("Please save the SPEC-File first!"));
	}
}

void EasyRPMMainWindowImpl::slot_readyReadStandardOutput(){

	QString rc=process->readAll();
	if (rc.contains("(%prep)")){
		value = 10;
		offset = 0;
		maxOffset = 5;
	}
	if (rc.contains("(%build)")){
		value = 15;
		offset = 0;
		maxOffset = 65;
	}
	if (rc.contains("(%install)")) {
		value = 80;
		offset = 0;
		maxOffset = 5;
	}
	if (rc.contains("Finding Supplements")) {
		value = 85;
		offset = 0;
		maxOffset = 5;
	}
	if (rc.contains("Checking for unpackaged file(s)")){
		value = 90;
		offset = 0;
		maxOffset = 5;
	}
	if (rc.contains("Wrote")){
		value = 95;
		offset = 0;
		maxOffset = 3;
	}
	if (rc.contains("(%clean)")){
		value = 98;
		offset = 0;
		maxOffset = 1;
	}
	if (offset < maxOffset) offset++;
	progress->setValue(value+offset);
	systemOutput->appendPlainText(rc.trimmed());
	systemOutput->moveCursor(QTextCursor::End);
}

void EasyRPMMainWindowImpl::slot_readyReadStandardError(){
	QString rc=process->readAllStandardError();
	if (rc.contains("Enter pass phrase:")){
		QString password = QInputDialog::getText(this,"Pass Phrase",tr("Process requires pass phrase for signing the package(s) :"),QLineEdit::Password) + "\n";
		QChar * charPointer = password.data();
		QByteArray passwd;
		while (!charPointer->isNull()){
			passwd.append(charPointer->unicode());
			++charPointer;
		}
		process->write(passwd);
	}
	systemOutput->appendPlainText(rc.trimmed());
	systemOutput->moveCursor(QTextCursor::End);
}

void EasyRPMMainWindowImpl::slot_processFinished(){
QString output = systemOutput->toPlainText();
QString message;
QString missingFiles;
QString line;
QString tempString = output;
QStringList packages;
QStringList obsoleteFiles;
QStringList outputList;
int packageCounter = 0;
int start,end;
bool success = true;
bool errorHandled = false;

	progress->setValue(100);
	while (output.indexOf("\n") != -1){
		outputList << output.left(output.indexOf("\n"));
		output = output.mid(output.indexOf("\n")+1);
	}
	output = tempString;
	QStringListIterator it(outputList);
	while (it.hasNext()){
		line = it.next();
		if (line.contains("Installed (but unpackaged) file(s) found:")){
			if (it.hasNext()) line = it.next(); else line = "";
			while (line.contains("/")){
				start = line.indexOf("/");
				end = line.indexOf("\n",start);
				missingFiles = missingFiles + line.mid(start,end-start) + "\n";
				if (it.hasNext()) line = it.next(); else line = "";
			}
			filesPlainTextEdit->appendPlainText(missingFiles);
			QMessageBox::warning(this,tr("INFO"),tr("Missing File(s):\n-----------------------------------------------\n\n") + missingFiles + tr("\n-----------------------------------------------\n were added to the file list!\nPlease start RPM Build again."));
			success = false;
			errorHandled = true;
		}
		if (line.contains("error: File not found")){
			QString message = tr("Obsolete files found in the list of installion files!\n----------------------------------------------\n") + "\n"; 
			while (line.contains("error: File not found")){
				start = line.indexOf(nameLineEdit->text()) + nameLineEdit->text().length();
				end = line.indexOf("\n",start);
				line = line.mid(start,end-start);
				message = message + line + "\n";
				obsoleteFiles << line;
				if (it.hasNext()) line = it.next(); else line = "";
			}
			success = false;
			message = message + "-------------------------------------------------------\n\n" + tr("Shall I remove this file from the List?");
			if (QMessageBox::question(this,tr("ATTENTION"),message,QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
				QStringListIterator it(obsoleteFiles);
				QString entry;
				QString installationFiles = filesPlainTextEdit->toPlainText();
				do {
					if (it.hasNext()) entry = it.next(); else entry = "";
					installationFiles.replace(entry,"");
				} while (it.hasNext());
				filesPlainTextEdit->setPlainText(installationFiles.trimmed());
			}
			errorHandled = true;
		}
		if ((success == true) && (line.indexOf("Requires:") == 0)){
			line = line.mid(10);
			if (line == "") {
				if (it.hasNext()) line = it.next(); else line = "";
			}
			QString tempString = line;
			QString entry;
			bool changed=false;
			while (tempString != ""){
				if (tempString.contains(" ")){
					end = tempString.indexOf(" ");
				} else {
					end = tempString.length();
				}
				entry = tempString.left(end);
				tempString = tempString.mid(end + 1);
				if (!requires.contains(entry)){
                                        requires << entry;
					changed = true;
				}
			}
			if (changed){
				QMessageBox::information(this,tr("ATTENTION"),tr("Requirements have changed. Please save Spec File and start package build again"));
				success = false;
				errorHandled = true;
				emit slot_contentChanged();
			} 
		}
		if ((success == true) && (line.contains(".rpm"))){
			if ((success == true) && (line.contains(".rpm"))){
				statusbar->showMessage(tr("+ + +  Package(s) successfully created  + + +"));
				start = 0;
				while (line.contains(".rpm")) {
					start = line.indexOf("/");
					end = line.indexOf("\n",start);
					line = line.mid(start,end-start);
					if (line.contains(".rpm")){
						packageCounter++;
						packages << line;
						message = message + "\n" + line;
					}
					if (it.hasNext()) line = it.next(); else line = "";
					while ((it.hasNext()) && (line == "")) line = it.next();
				}
			}
		}
		if (line.contains("error:")) success = false;
	}
	if ((success == true) && (packageCounter > 0)) {
		packageResultDialog * resultDialog = new packageResultDialog(this,&packages);
		resultDialog->exec();
	}
	if ((success == false) && (errorHandled == false)){
		statusbar->showMessage(tr("+ + +  An error occured.  + + +"));
		start = output.lastIndexOf("(%",output.lastIndexOf("error:"));
		end = output.indexOf(")",start);
		QString partOne = output.mid(start+2,end-start-2);
		start = output.lastIndexOf("+",output.lastIndexOf("error:"));
		end = output.indexOf("\n",start);
		QString partTwo = output.mid(start,end-start);
		QMessageBox::warning(this,tr("INFO"),tr("Process finished. Please check the output for error messages!") + tr("\n\nINFO\n--------------------------------------------------\n1. Problems in section: ") + partOne + tr("\n\n2. Line causing problems:\n") + partTwo + "\n--------------------------------------------------");
	}
	groupBox->setEnabled(true);
	FileToolBar->setEnabled(true);
	ProjectToolBar->setEnabled(true);
	menubar->setEnabled(true);
}

void EasyRPMMainWindowImpl::slot_actionSettings(){
settings * settingDialog = new settings(0);
	settingDialog->exec();
	loadSettings();
}

void EasyRPMMainWindowImpl::slot_actionTemplateEditor(){
templateEditor * editor = new templateEditor(0);
	editor->exec();
}

void EasyRPMMainWindowImpl::slot_actionOpenTemplate(){
	checkForContentChanged();
bool ok;
QDir templates((QString)getenv("HOME")+"/.easyrpmbuilder","*.tpl");
QString filename = QInputDialog::getItem(this,tr("Templates"),tr("Please select a template"),templates.entryList(),0,false,&ok);
QString line;
QString container;
QString groupString;
int index = 0;
	if (ok){
		changeLogEntry = "";
		buildRootPathEdit->setText("%{_tmppath}/build-root-%{name}");
		actualFilename = "";
		QFile templateFile((QString)getenv("HOME")+"/.easyrpmbuilder/"+filename);
		if (templateFile.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream stream(&templateFile);
			do {
				line = stream.readLine();
				if (line.contains("<-")){
					container = container + line + "\n";
					container = container.mid(1,container.length()-4);
					switch (index){
					case 1 : versionLineEdit->setText(container);
								break;
					case 2 : licenceComboBox->setCurrentIndex(licenceComboBox->findText(container));
								break;
					case 3 : groupComboBox->setCurrentIndex(groupComboBox->findText(container));
							 groupString = container;
								break;
					case 4 : distributionComboBox->setCurrentIndex(distributionComboBox->findText(container));
							 groupComboBox->setCurrentIndex(groupComboBox->findText(groupString));
								break;
					case 5 : buildPlainTextEdit->setPlainText(container);
								break;
					case 6 : installPlainTextEdit->setPlainText(container);
								break;
					}
					container = "";
					index++;
				} else {
					container = container + line + "\n";
				}
			} while (!stream.atEnd());
			templateFile.close();
			nameLineEdit->setText("");
			releaseSpinBox->setValue(1);
			summaryLineEdit->setText("");
			descriptionTextEdit->setPlainText("");
			filesPlainTextEdit->setPlainText("");
			systemOutput->setPlainText("");
			vendorLineEdit->setText(defaultVendor);
			packagerLineEdit->setText(defaultPackager);
			urlLineEdit->setText(defaultHomepage);
			unknownSectionComboBox->clear();
			unknownSectionComboBox->addItem("%prep");
			unknownSectionComboBox->addItem("%clean");
			unknownSection.clear();
			unknownSectionContent.clear();
			unknownSection << "%prep" << "%clean";
			unknownSectionContent << "rm -rf %{buildroot}\nmkdir %{buildroot}" << "rm -rf %{buildroot}";
		}
		contentChanged = false;
		this->setWindowTitle("EasyRPM Builder - ");
	}
}

void EasyRPMMainWindowImpl::slot_about(){
	QString version = "0.5.6";
	QMessageBox::about(this,tr("About EasyRPM Builder"),"Version : " + version + tr("\n\nThis programm is published under GPL 2.0\nor any newer version\n\nPlease change the application till it meets your requirements.\n\nBug-Reports can be send to Joerg.Zopes@gmx.de") + tr("\n\nSpecial Thanks to:\n- Marcio Moraes (Brazilian Translation)\n- Tomas Deltell Bonell (Spanish Translation)\n- BlogDrake (for svn hosting)"));
}

void EasyRPMMainWindowImpl::slot_aboutQt(){
	QMessageBox::aboutQt(this,"About Qt");
}

void EasyRPMMainWindowImpl::slot_logoTimerTimeout(){
	logoLabel->setGeometry((this->width()-400) / 2, (this->height() - 300) / 2, 400,300);
	logoLabel->show();
	contentChanged = false;
	this->setWindowTitle("EasyRPM Builder - " + actualFilename);
	hideTimer->setSingleShot(true);
	hideTimer->start(2500);
}

void EasyRPMMainWindowImpl::slot_hideLogo(){
	delete logoLabel;
	this->setWindowTitle("EasyRPM Builder - " + actualFilename);
	contentChanged = false;
}

void EasyRPMMainWindowImpl::slot_rpmHowTo(){
documentViewer * viewer = new documentViewer(0, "/usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/index.html");
	viewer->exec();
}

QString EasyRPMMainWindowImpl::makeLogTimeStamp(){
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
QString timeStamp = QDate::currentDate().toString();
        timeStamp.replace("周一 ", "Mon ");
        timeStamp.replace("周二 ", "Tue ");
        timeStamp.replace("周三 ", "Wed ");
        timeStamp.replace("周四 ", "Thu ");
        timeStamp.replace("周五 ", "Fri ");
        timeStamp.replace("周六 ", "Sat ");
        timeStamp.replace("周日 ", "Sun ");

        timeStamp.replace("11月 ", "Nov ");
        timeStamp.replace("12月 ", "Dec ");
        timeStamp.replace("1月 ", "Jan ");
        timeStamp.replace("2月 ", "Feb ");
        timeStamp.replace("3月 ", "Mar ");
        timeStamp.replace("4月 ", "Apr ");
        timeStamp.replace("5月 ", "May ");
        timeStamp.replace("6月 ", "Jun ");
        timeStamp.replace("7月 ", "Jul ");
        timeStamp.replace("8月 ", "Aug ");
        timeStamp.replace("9月 ", "Sep ");
        timeStamp.replace("10月 ", "Oct ");

	timeStamp.replace("Mo ","Mon ");
	timeStamp.replace("Di ","Tue ");
	timeStamp.replace("Mi ","Wed ");
	timeStamp.replace("Do ","Thu ");
	timeStamp.replace("Fr ","Fri ");
	timeStamp.replace("Sa ","Sat ");
	timeStamp.replace("So ","Sun ");
	timeStamp.replace("Mo. ","Mon ");
	timeStamp.replace("Di. ","Tue ");
	timeStamp.replace("Mi. ","Wed ");
	timeStamp.replace("Do. ","Thu ");
	timeStamp.replace("Fr. ","Fri ");
	timeStamp.replace("Sa. ","Sat ");
	timeStamp.replace("So. ","Sun ");
	timeStamp.replace("Jan ","Jan ");
	timeStamp.replace("Feb ","Feb ");
	timeStamp.replace("Mae ","Mar ");
	timeStamp.replace("Mai ","May ");
	timeStamp.replace("Okt ","Oct ");
	timeStamp.replace("Dez ","Dec ");
	return timeStamp;
}

void EasyRPMMainWindowImpl::slot_actionLogView(){
	if (actualFilename != ""){
		if (unknownSection.indexOf("%changelog") != -1){
			statusbar->showMessage(tr("+ + + Log-Viewer opened (read only) + + +"));
			logview * changeLogViewer = new logview(0,unknownSectionContent.at(unknownSection.indexOf("%changelog")));
			changeLogViewer->exec();
			statusbar->clearMessage();
		}
	}
}

void EasyRPMMainWindowImpl::slot_distroComboBoxValueChanged(){
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

void EasyRPMMainWindowImpl::slot_actionEditSectionActivated(QString section){
int index = unknownSection.indexOf(section);
QString content = unknownSectionContent.at(index);
bool ok = false;
	statusbar->showMessage(tr("+ + +  Tag Editor opened  + + +"));
	sectionEdit * secEdit = new sectionEdit(0,section,&content,&ok);
	secEdit->exec();
	if (ok) {
		unknownSectionContent.replace(index,content);
		contentChanged = true;
		emit slot_contentChanged();
	}
	statusbar->clearMessage();
}

void EasyRPMMainWindowImpl::slot_addSectionButtonClicked(){
	if (actualFilename != ""){
		bool ok = true;
		statusbar->showMessage(tr("Select a tag from the list or enter one manually"));
		QStringList items;
		items << "pre" << "preun" << "prep" << "clean" << "changelog" << "kde_post_install" << "debug_package" << "package" << "patch" << "post" << "postun" << "doc";
		QString sectionName = QInputDialog::getItem(this,tr("New Section"),tr("Input the name for the new section (omit %)"),items,0,true,&ok);
		if ((ok) & (unknownSection.indexOf("%"+sectionName) != -1)){
			ok = false;
			QMessageBox::information(this,tr("WARNING"),tr("This section already exists!"));
		}
		if (ok){
			unknownSection << "%" + sectionName;
			unknownSectionContent << "";
			unknownSectionComboBox->clear();
			QStringListIterator it(unknownSection);
			while (it.hasNext()){
				unknownSectionComboBox->addItem(it.next());
			}
			contentChanged = true;
			slot_contentChanged();
		}
	}
}

void EasyRPMMainWindowImpl::slot_delSectionButtonClicked(){
QString section;
	if (unknownSection.count() > 0){
		if (QMessageBox::question(this,tr("WARNING"),tr("Your are about to remove a section\nDo you want to proceed?"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
			section = unknownSectionComboBox->currentText();
			int index = unknownSection.indexOf(unknownSectionComboBox->currentText());
			unknownSection.removeAt(index);
			unknownSectionContent.removeAt(index);
			QStringListIterator it(unknownSection);
			unknownSectionComboBox->clear();
			while (it.hasNext()){
				unknownSectionComboBox->addItem(it.next());
			}
			contentChanged = true;
			emit slot_contentChanged();
		}
	}
}

void EasyRPMMainWindowImpl::checkForContentChanged(){
	if (contentChanged){
		if (QMessageBox::question(this,tr("WARNING"),tr("There is unsaved data left\nDo you want to save the changes?"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
			slot_actionSaveSpecFile();
		}
	}
}

void EasyRPMMainWindowImpl::slot_actionRecentlyUsed1Activated(){
	actualFilename = recentlyUsed1->text();
	actualFilename = actualFilename.mid(3);
	checkRecentlyUsedStructur(actualFilename);
	loadFile(actualFilename);
}

void EasyRPMMainWindowImpl::slot_actionRecentlyUsed2Activated(){
	actualFilename = recentlyUsed2->text();
	actualFilename = actualFilename.mid(3);
	checkRecentlyUsedStructur(actualFilename);
	loadFile(actualFilename);
}

void EasyRPMMainWindowImpl::slot_actionRecentlyUsed3Activated(){
	actualFilename = recentlyUsed3->text();
	actualFilename = actualFilename.mid(3);
	checkRecentlyUsedStructur(actualFilename);
	loadFile(actualFilename);
}

void EasyRPMMainWindowImpl::slot_actionRecentlyUsed4Activated(){
	actualFilename = recentlyUsed4->text();
	actualFilename = actualFilename.mid(3);
	checkRecentlyUsedStructur(actualFilename);
	loadFile(actualFilename);
}

void EasyRPMMainWindowImpl::slot_actionRecentlyUsed5Activated(){
	actualFilename = recentlyUsed5->text();
	actualFilename = actualFilename.mid(3);
	checkRecentlyUsedStructur(actualFilename);
	loadFile(actualFilename);
}

void EasyRPMMainWindowImpl::rebuildRecentlyUsedMenu(){
QString menuLine;
QString workString=recentlyUsed;
QString newRecentlyUsed;
int index=0;
int pos;

	recentlyUsedMenu->clear();
	
	if (workString != ""){
		while (workString.contains("\n")){
			pos = workString.indexOf("\n");
			menuLine = workString.mid(0,pos);
			if (index < 5) newRecentlyUsed = newRecentlyUsed + menuLine + "\n";
			index++;
			workString = workString.mid(pos+1);
			switch (index){
			case 1 : recentlyUsed1->setText("&" + QString::number(index) + " " + menuLine);
					 recentlyUsedMenu->addAction(recentlyUsed1);
					 	break;
			case 2 : recentlyUsed2->setText("&" + QString::number(index) + " " + menuLine);
					 recentlyUsedMenu->addAction(recentlyUsed2);
					 	break;
			case 3 : recentlyUsed3->setText("&" + QString::number(index) + " " + menuLine);
					 recentlyUsedMenu->addAction(recentlyUsed3);
					 	break;
			case 4 : recentlyUsed4->setText("&" + QString::number(index) + " " + menuLine);
					 recentlyUsedMenu->addAction(recentlyUsed4);
					 	break;
			case 5 : recentlyUsed5->setText("&" + QString::number(index) + " " + menuLine);
					 recentlyUsedMenu->addAction(recentlyUsed5);
					 	break;
			}
		}
		recentlyUsed = newRecentlyUsed;
	}
}


void EasyRPMMainWindowImpl::slot_buildRootPathButtonClicked(){
QString rc = QFileDialog::getExistingDirectory(0,tr("Select Build Root Dir"),buildRootPathEdit->text());
	if (rc != "") buildRootPathEdit->setText(rc);
}


void EasyRPMMainWindowImpl::slot_editSources(){
bool ok = false;
sourceEditDialog * editDialog = new sourceEditDialog(this, &sources, &ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_editPatches(){
bool ok = false;
patchEditDialog * editDialog = new patchEditDialog(this, &patches, &ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_actionEditRequiresActivated(){
bool ok = true;
editSpecialOptions * editDialog = new editSpecialOptions(this,tr("Requires"),&requires,&ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_actionEditProvidesActivated(){
bool ok = true;
editSpecialOptions * editDialog = new editSpecialOptions(this,tr("Provides"),&provides,&ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_actionEditConflictsActivated(){
bool ok = true;
editSpecialOptions * editDialog = new editSpecialOptions(this,tr("Conflicts"),&conflicts,&ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_actionEditObsoletesActivated(){
bool ok = true;
editSpecialOptions * editDialog = new editSpecialOptions(this,tr("Obsoletes"),&obsoletes,&ok);
	editDialog->exec();
	if (ok == false) slot_contentChanged();
}

void EasyRPMMainWindowImpl::slot_actionOptionToolBar(bool mode){
	FileToolBar->setVisible(mode);
}

void EasyRPMMainWindowImpl::slot_actionProjectToolBar(bool mode){
	ProjectToolBar->setVisible(mode);
}

void EasyRPMMainWindowImpl::slot_actionShowMacrosActivated(){
macroViewContainer * showMacrosDialog = new macroViewContainer(this);
	showMacrosDialog->exec();
}

void EasyRPMMainWindowImpl::execScript(QString command){
QFile file("/tmp/easyrpmtempscript.sh");
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
		QTextStream stream(&file);
		stream << "#!/bin/bash" <<endl;
		stream << command << endl;
		file.close();
		file.setPermissions(QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadUser|QFile::WriteUser|QFile::ExeUser|QFile::ReadGroup|QFile::WriteGroup|QFile::ExeGroup|QFile::ReadOther|QFile::WriteOther|QFile::ExeOther);
		process->start("/tmp/easyrpmtempscript.sh");
	}
}

void EasyRPMMainWindowImpl::slot_rebuildButtonClicked(){
int index = unknownSection.indexOf("%rebuildscript");
QString content;
bool ok = false;

	if (index != -1) content = unknownSectionContent.at(index);
	if (index != -1){
		execScriptDialog * scriptExecute = new execScriptDialog(0,content,nameLineEdit->text(),versionLineEdit->text());
		scriptExecute->exec();
	} else {
		QString initialString = tr("echo Rebuild package for $1 Version $2\ncd ~/Development\ncp -r $1 $1-$2\ncd $1-$2\nmake distclean\ncd $1-$2\n#find and remove .svn folder if exist.\nfind ./ -name .svn -exec rm -rf {} \\; 2>/dev/null\ncd ..\ntar -cvzf $1-$2.tgz $1-$2\nrm -rf $1-$2\nmv $1-$2.tgz /usr/src/packages/SOURCES\necho \"* * *  F I N I S H E D  * * *\"");
		unknownSection << "%rebuildscript";
		unknownSectionContent << initialString;
		unknownSectionComboBox->clear();
		QStringListIterator it(unknownSection);
		while (it.hasNext()){
			unknownSectionComboBox->addItem(it.next());
		}
		index = unknownSection.indexOf("%rebuildscript");
		content = unknownSectionContent.at(index);
		statusbar->showMessage(tr("+ + +  Tag Editor opened  + + +"));
		sectionEdit * secEdit = new sectionEdit(0,"%rebuildscript",&content,&ok);
		secEdit->exec();
		if (ok) {
			unknownSectionContent.replace(index,content);
			contentChanged = true;
			emit slot_contentChanged();
		}
		statusbar->clearMessage();
	}
}
void EasyRPMMainWindowImpl::slot_editDesktopFileButtonClicked(){
    QString source1 = source1LineEdit->text();
    if(source1.contains("%{name}")){
        source1.replace("%{name}", nameLineEdit->text());
    }
    editDesktopFile * editDesktopFileDialog = new editDesktopFile(rpmRootPath, source1 ,this);
    editDesktopFileDialog->exec();
    QFileInfo fi(editDesktopFileDialog->_getFileName());
    if(fi.fileName().trimmed() != ""){
        source1LineEdit->setText(fi.fileName());
    }
}
void EasyRPMMainWindowImpl::slot_actionPrintSpecFileActivated(){
QPlainTextEdit * tempText = new QPlainTextEdit(this);
QString content;
QPrinter * printer = new QPrinter();
printer->setColorMode(QPrinter::Color);
printer->setResolution(85);
printer->setOrientation(QPrinter::Landscape);
QPrintDialog dlg(printer,0);

	if (contentChanged == false){
		if ((actualFilename != "") && (dlg.exec() == QDialog::Accepted)){
			QFile file(actualFilename);
			if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
				QTextStream stream(&file);
				while (!stream.atEnd()){
					content = content + stream.readAll();
				}
				file.close();
				tempText->setPlainText(content);
				tempText->print(printer);
			}
		}
	} else {
		QMessageBox::information(this,tr("WARNING"),tr("Please save the SPEC-File first!"));
	}
}

void EasyRPMMainWindowImpl::slot_menuSettingsAboutToShow(){
	FileToolBar->isVisible()?actionOption_ToolBar->setChecked(true):actionOption_ToolBar->setChecked(false);
	ProjectToolBar->isVisible()?actionProject_ToolBar->setChecked(true):actionProject_ToolBar->setChecked(false);
}

void EasyRPMMainWindowImpl::slot_vendorButtonClicked(){
	vendorLineEdit->setText(defaultVendor);
}

void EasyRPMMainWindowImpl::slot_packagerButtonClicked(){
	packagerLineEdit->setText(defaultPackager);
}

void EasyRPMMainWindowImpl::slot_homepageButtonClicked(){
	urlLineEdit->setText(defaultHomepage);
}

void EasyRPMMainWindowImpl::configToolBars(){
long int filter = 1;
	while (filter < 65536){
		switch (filter){
		case      1 : (filter&toolbarMask)==filter?actionOpenSpecFile->setVisible(true):actionOpenSpecFile->setVisible(false);
						break;
		case      2 : (filter&toolbarMask)==filter?actionSaveSpecFile->setVisible(true):actionSaveSpecFile->setVisible(false);
						break;
		case      4 : (filter&toolbarMask)==filter?actionPrintSpecFile->setVisible(true):actionPrintSpecFile->setVisible(false);
						break;
		case      8 : (filter&toolbarMask)==filter?actionOpenTemplateEditor->setVisible(true):actionOpenTemplateEditor->setVisible(false);
						break;
		case     16 : (filter&toolbarMask)==filter?actionOpenTemplate->setVisible(true):actionOpenTemplate->setVisible(false);
						break;
		case     32 : (filter&toolbarMask)==filter?actionQuit->setVisible(true):actionQuit->setVisible(false);
						break;
		case     64 : (filter&toolbarMask)==filter?actionEditSources->setVisible(true):actionEditSources->setVisible(false);
						break;
		case    128 : (filter&toolbarMask)==filter?actionEditPatches->setVisible(true):actionEditPatches->setVisible(false);
						break;
		case    256 : (filter&toolbarMask)==filter?actionEditRequire->setVisible(true):actionEditRequire->setVisible(false);
						break;
		case    512 : (filter&toolbarMask)==filter?actionEditProvide->setVisible(true):actionEditProvide->setVisible(false);
						break;
		case   1024 : (filter&toolbarMask)==filter?actionEditConflict->setVisible(true):actionEditConflict->setVisible(false);
						break;
		case   2048 : (filter&toolbarMask)==filter?actionEditObsolete->setVisible(true):actionEditObsolete->setVisible(false);
						break;
		case   4096 : (filter&toolbarMask)==filter?actionShowMacros->setVisible(true):actionShowMacros->setVisible(false);
						break;
		case   8192 : (filter&toolbarMask)==filter?actionBuildBinary->setVisible(true):actionBuildBinary->setVisible(false);
						break;
		case  16384 : (filter&toolbarMask)==filter?actionBuildSource->setVisible(true):actionBuildSource->setVisible(false);
						break;
		case  32768 : (filter&toolbarMask)==filter?actionBuildAll->setVisible(true):actionBuildAll->setVisible(false);
						break;
		}
		filter*=2;
	}
}

void EasyRPMMainWindowImpl::slot_actionConfigToolBars(){
configToolBarDialog * configDialog = new configToolBarDialog(this,&toolbarMask);
	configDialog->exec();
	configToolBars();
}
//
