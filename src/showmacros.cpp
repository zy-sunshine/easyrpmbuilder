#include "showmacros.h"
//
showMacros::showMacros( QWidget * parent, QString path ) : QDialog(parent)
{
	setupUi(this);
	sourceDir = new QDir(path);
	directory = path;
	sourceDir->setFilter(QDir::Files);
	sourceDir->setNameFilters(QStringList("*macro*"));
	macroViewHighlighter = new highlighter(macroView->document());
	fillTable();
}

void showMacros::fillTable(){
QStringList entryList = sourceDir->entryList();
QStringListIterator it(entryList);
QStringList headerString;
QString entry;
int index = 0;
	headerString << tr("File");
	tableWidget->clear();
	tableWidget->setHorizontalHeaderLabels(headerString);
	while (it.hasNext()){
		entry = it.next();
		if ((entry != ".") && (entry != "..")){
			tableWidget->insertRow(index);
			tableWidget->setItem(index,0,new QTableWidgetItem(entry));
			tableWidget->setColumnWidth(0,250);
			index++;		
		}
	}
	if (tableWidget->rowCount() > 0){
		tableWidget->setCurrentCell(0,0);
		slot_tableClicked();
	}
}

void showMacros::slot_tableClicked(){
QString entry = tableWidget->item(tableWidget->currentRow(),0)->text();
QString content;
QFile file(directory + "/" + entry);
	if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
		QTextStream stream(&file);
		while (!stream.atEnd()){
			content = content + stream.readLine() + "\n";
		}
		file.close();
		macroView->setPlainText(content);
	}
}
//
