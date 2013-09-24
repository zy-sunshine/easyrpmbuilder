#include "documentviewer.h"
//
documentViewer::documentViewer(QWidget * parent,QString Url) : QDialog(parent)
{
	globalUrl = Url;
	this->setWindowTitle("How-To");
	this->setMinimumSize(640,480);
	backButton = new QPushButton(QIcon(":/icon/icons/back.png"),"",this);
	backButton->setEnabled(false);
	forwardButton = new QPushButton(QIcon(":/icon/icons/forward.png"),"",this);
	forwardButton->setEnabled(false);
	goHomeButton = new QPushButton(QIcon(":/icon/icons/gohome.png"),"",this);
	connect(backButton,SIGNAL(clicked()),this,SLOT(slot_backButtonClicked()));
	connect(forwardButton,SIGNAL(clicked()),this,SLOT(slot_forwardButtonClicked()));
	connect(goHomeButton,SIGNAL(clicked()),this,SLOT(slot_goHomeButtonClicked()));
	mainFrame = new QFrame(this);
	mainFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
	document = new QTextBrowser(this);
	document->setOpenExternalLinks(true);
	closeButton = new QPushButton("&Close",this);
	closeButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
	document->setSource(QUrl(Url));
	connect(document,SIGNAL(forwardAvailable(bool)),this,SLOT(slot_forwardAvailable(bool)));
	connect(document,SIGNAL(backwardAvailable(bool)),this,SLOT(slot_backwardAvailable(bool)));
}


void documentViewer::resizeEvent(QResizeEvent * e){
	e = e; // just to keep the compiler happy ....
	backButton->setGeometry(5,5,35,35);
	forwardButton->setGeometry(backButton->x()+backButton->width()+5,backButton->y(),backButton->width(),backButton->height());
	goHomeButton->setGeometry(forwardButton->x()+forwardButton->width()+5,forwardButton->y(),forwardButton->width(),forwardButton->height());
	mainFrame->setGeometry(5,45,this->width()-10,this->height()-90);
	document->setGeometry(mainFrame->x()+5,mainFrame->y()+5,mainFrame->width()-10,mainFrame->height()-10);
	closeButton->setGeometry(this->width()-60,this->height()-45,45,30);
}

void documentViewer::slot_goHomeButtonClicked(){
	document->setSource(QUrl(globalUrl));
}

void documentViewer::slot_backButtonClicked(){
	document->backward();
}

void documentViewer::slot_forwardButtonClicked(){
	document->forward();
}

void documentViewer::slot_backwardAvailable(bool state){
	backButton->setEnabled(state);
}

void documentViewer::slot_forwardAvailable(bool state){
	forwardButton->setEnabled(state);
}
//
