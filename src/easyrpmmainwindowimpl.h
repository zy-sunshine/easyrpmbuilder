#ifndef EASYRPMMAINWINDOWIMPL_H
#define EASYRPMMAINWINDOWIMPL_H
//
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QStringListIterator>
#include <QFile>
#include <QProcess>
#include <QInputDialog>
#include <QProgressDialog>
#include <QTimer>
#include <QDate>
#include <QAction>
#include <QByteArray>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextCodec>
#include "ui_easyrpmMainwindow.h"
#include "settings.h"
#include "templateeditor.h"
#include "documentviewer.h"
#include "logview.h"
#include "sectionedit.h"
#include "changelogdialog.h"
#include "sourceeditdialog.h"
#include "patcheditdialog.h"
#include "highlighter.h"
#include "editspecialoptions.h"
#include "macroviewcontainer.h"
#include "editDesktopFile.h"
#include "execscriptdialog.h"
#include "packageresultdialog.h"
#include "configtoolbardialog.h"

//
class EasyRPMMainWindowImpl : public QMainWindow, public Ui::EasyRPMMainWindow
{
Q_OBJECT
public:
	EasyRPMMainWindowImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	~EasyRPMMainWindowImpl();
private:
	QAction				* actionNewSpecFile;
	QAction				* actionOpenSpecFile;
	QAction				* actionSaveSpecFile;
	QAction				* actionPrintSpecFile;
	QAction				* actionOpenTemplateEditor;
	QAction				* actionOpenTemplate;
	QAction				* actionQuit;
	QAction				* recentlyUsed1;
	QAction				* recentlyUsed2;
	QAction				* recentlyUsed3;
	QAction				* recentlyUsed4;
	QAction				* recentlyUsed5;
	QAction				* actionBuildBinary;
	QAction				* actionBuildSource;
	QAction				* actionBuildAll;
	QLabel				* unknownSectionLabel;
	QLabel				* logoLabel;
	QComboBox			* unknownSectionComboBox;
	QAction				* actionAddSection;
	QAction				* actionDelSection;
	QAction				* actionEditRequire;
	QAction				* actionEditProvide;
	QAction				* actionEditObsolete;
	QAction				* actionEditConflict;
	QAction				* actionEditSources;
	QAction				* actionEditPatches;
	QAction				* actionShowMacros;
	QProgressDialog		* progress;
	highlighter			* installHighlighter;
	highlighter			* buildHighlighter;
	highlighter			* outputHighlighter;
        highlighter                      * filesHighlighter;
	QString				  rpmRootPath;
	QString				  buildRoot;
	QString				  actualFilename;
	QString				  homePath;
	QString				  defaultVendor;
	QString				  defaultPackager;
	QString				  defaultHomepage;
        QString                           defaultSource;
        QString                           defaultSource1;
        QString                           defaultBuildroot;
	QString				  changeLogEntry;
	QString				  recentlyUsed;
        QStringList			  requires;
        QStringList			  provides;
        QStringList     			  obsoletes;
        QStringList			  conflicts;
	QStringList			  unknownSection;
	QStringList			  unknownSectionContent;
	QStringList			  sources;
	QStringList			  patches;
	bool				  contentChanged;
	long int			  toolbarMask;
	int 				  value;
	int					  offset;
	int					  maxOffset;
	QTimer				* logoTimer;
	QTimer				* hideTimer;
	QProcess			* process;
	void transferSectionInfo(QString,QString);
	void loadSettings();
	void loadRecentlyUsed();
	void rebuildRecentlyUsedMenu();
	void checkRecentlyUsedStructur(QString);
	QString makeLogTimeStamp();
	void checkForContentChanged();
	void loadFile(QString);
	void execScript(QString);
	bool signatureCheck();
	void configToolBars();
private slots:
	void slot_actionNewOtherSpecFile();
	void slot_actionOpenSpecFile();
	void slot_actionSaveSpecFile();
	void slot_actionSaveSpecFileAs();
	void slot_sourceSearchButtonClicked();
        void slot_source1SearchButtonClicked();
	void slot_actionOptionStartRPMBuild();
	void slot_buildPackageButtonClicked();
	void slot_readyReadStandardOutput();
	void slot_readyReadStandardError();
	void slot_processFinished();
	void slot_contentChanged();
	void slot_nameContentChanged();
	void slot_versionContentChanged();
	void slot_vendorContentChanged();
	void slot_actionSettings();
	void slot_buildBinaryOnlyButtonClicked();
	void slot_buildSourceOnlyButtonClicked();
	void slot_actionTemplateEditor();
	void slot_actionOpenTemplate();
	void slot_about();
	void slot_aboutQt();
	void slot_logoTimerTimeout();
	void slot_rpmHowTo();
	void slot_actionLogView();
	void slot_distroComboBoxValueChanged();
	void slot_actionEditSectionActivated(QString);
	void slot_addSectionButtonClicked();
	void slot_delSectionButtonClicked();
	void slot_actionRecentlyUsed1Activated();
	void slot_actionRecentlyUsed2Activated();
	void slot_actionRecentlyUsed3Activated();
	void slot_actionRecentlyUsed4Activated();
	void slot_actionRecentlyUsed5Activated();
        void slot_buildrootButtonClicked();
	void slot_buildRootPathButtonClicked();
	void slot_editSources();
	void slot_editPatches();
	void slot_actionEditRequiresActivated();
	void slot_actionEditProvidesActivated();
	void slot_actionEditConflictsActivated();
	void slot_actionEditObsoletesActivated();
	void slot_hideLogo();
	void slot_actionOptionToolBar(bool);
	void slot_actionProjectToolBar(bool);
	void slot_actionShowMacrosActivated();
	void slot_rebuildButtonClicked();
        void slot_editDesktopFileButtonClicked();
	void slot_actionPrintSpecFileActivated();
	void slot_menuSettingsAboutToShow();
	void slot_vendorButtonClicked();
	void slot_packagerButtonClicked();
	void slot_homepageButtonClicked();
        void slot_sourceButtonClicked();
        void slot_source1ButtonClicked();
	void slot_actionConfigToolBars();
};
#endif




