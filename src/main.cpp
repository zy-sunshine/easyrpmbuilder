#include <QApplication>
#include "easyrpmmainwindowimpl.h"
#include <QTranslator>
#include <QFile>
#include <QDir>
//
int main(int argc, char ** argv)
{
QDir baseDir;
QString homepath = (QString)getenv("HOME") + "/.easyrpmbuilder";
QString lang = QLocale::system().name();
QString line;
QString languageFilename;
int index = 0;
QFile logFile("/home/wusel/log.txt");

// Check whether there is a language selection in the setting file ....
	if (QFile::exists(homepath + "/settings")){
		QFile file(homepath + "/settings");
		if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
			QTextStream stream(&file);
			while (!stream.atEnd()){
				line = stream.readLine();
				index++;
				if (index==5){
					line != "auto"?languageFilename = line:languageFilename = "";
				}
			}
		}
	}

logFile.close();
// If there is a language file in the home folder the remomve the file.
	if (QFile::exists(homepath+"/translation.qm")) {
		QFile::remove(homepath+"/translation.qm");
	}
// If a language file was selected through the setting file then use this 
// information ......
	if (languageFilename != ""){
		lang = languageFilename;
	} else {
// .... otherwise build the name for the language file 
// through the language information of the system.
		lang = "easyrpmbuilder_" + lang + ".qm";
	}
// Copy the appropriate language file into the applications home folder.
	QFile::copy((QString)"/usr/share/qt4/translations/"+lang,homepath+(QString)"/translation.qm");
	
	if (!QFile::exists(homepath)) baseDir.mkpath(homepath);
	QTranslator translator(0);
	if (QFile::exists(homepath)){
		translator.load("translation.qm",homepath);
	}
	QApplication app( argc, argv );
	app.installTranslator(&translator);
	EasyRPMMainWindowImpl win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
