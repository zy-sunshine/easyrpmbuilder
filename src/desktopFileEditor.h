#ifndef DESKTOPFILEEDITOR_H
#define DESKTOPFILEEDITOR_H

//
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QMessageBox>
#include <QFileDialog>
#include "highlighter.h"
#include "ui_editPrivateMacroFileDialog.h"
//
class desktopFileEditor : public QDialog, Ui::editPrivateMacroFileDialog
{
Q_OBJECT
public:
        desktopFileEditor(QString file, QWidget * parent = 0);
private:
        highlighter		* myHighLighter;
        QString                 _file;
private slots:
        void slot_submitButtonClicked();
        void slot_discardButtonClicked();
};

#endif // DESKTOPFILEEDITOR_H
