#include "desktopFileEditor.h"
//
desktopFileEditor::desktopFileEditor(QString file,QWidget * parent) : QDialog(parent)
{
        setupUi(this);
        _file = file;

        myHighLighter = new highlighter(macroPlainTextEdit->document());
        slot_discardButtonClicked();
}

void desktopFileEditor::slot_submitButtonClicked(){
QString path = _file;
QFile file(path);
        if (file.open(QIODevice::WriteOnly|QIODevice::Text)){
                QTextStream stream(&file);
                stream.setCodec(QTextCodec::codecForName("UTF-8"));
                stream << macroPlainTextEdit->toPlainText();
                file.close();
                QMessageBox::information(this,"DEBUG",tr("Changes saved!"));
        }
}

void desktopFileEditor::slot_discardButtonClicked(){
QString path = _file;
QFile file(path);
QString content;

        if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
                QTextStream stream(&file);
                stream.setCodec(QTextCodec::codecForName("UTF-8"));
                while (!stream.atEnd()){
                        content = content + stream.readLine() + "\n";
                }
                macroPlainTextEdit->setPlainText(content);
                file.close();
        }
}

//
