#ifndef EDITDESKTOPFILE_H
#define EDITDESKTOPFILE_H
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QPushButton>
#include "ui_macroViewContainer.h"
#include "showmacros.h"
#include "desktopFileEditor.h"
//
class editDesktopFile : public QDialog, public Ui::macroViewContainer
{
Q_OBJECT
public:
        editDesktopFile( QString rpmbuildPath, QString desktopFile, QWidget * parent = 0);
        QString                 _getFileName();
private:
        QStringList		files;
        QString                 _rpmbuildPath;
        QString                 _desktopFile;
        void loadTabs();
        void makeTabs();
        QString getDesktopFileName();
        bool createDesktopFile(QString file);
private slots:
        //void slot_addFolderButtonClicked();
        void slot_delFolderButtonClicked();
        void slot_tabCloseRequest(int);
};

#endif // EDITDESKTOPFILE_H
