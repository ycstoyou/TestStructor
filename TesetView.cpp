
#include "TesetView.h"
#include <qdebug.h>
#include <QPushButton>

bool KeyPressEater::eventFilter(QObject* obj, QEvent* event)
{

	//qDebug() << event->type();
	if (event->type() == QEvent::Enter)
	{
		//qDebug() << event->type() << __FUNCTION__;;
	}
	else if (event->type() == QEvent::Leave)
	{
		//qDebug() << event->type() << __FUNCTION__;;
	}
	if (event->type() == QEvent::KeyPress)
	{
		QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
		qDebug("Ate key press %d", keyEvent->key());
		return true;
	}
	else {
		// standard event processing
		return QObject::eventFilter(obj, event);
	}
}

bool MousePressFilter::eventFilter(QObject* obj, QEvent* event)
{

	//qDebug() << event->type();
	if (event->type() == QEvent::Enter)
	{
		//qDebug() << event->type()<<__FUNCTION__;
	}
	else if (event->type() == QEvent::Leave)
	{
		//qDebug() << event->type()<<__FUNCTION__;
	}
	if (event->type() == QEvent::MouseButtonPress)
	{
		if (obj == view_)
		{
			qDebug("filter view click");
		}
		else
		{
			qDebug("mouse filter left click");
		}
		//QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);


		// standard event processing
		return QObject::eventFilter(obj, event);
	}
	return QObject::eventFilter(obj, event);
}

TesetView::TesetView(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
	InitView();
	InitButtons();

	//////////////////////////////////////////////////////////////////////////
	
	KeyPressEater* keyPressEater = new KeyPressEater();
	MousePressFilter* mouse_filter = new MousePressFilter();
	mouse_filter->view_ = &main_graphices_view_;
	//draw_button->installEventFilter(keyPressEater);
	draw_button->installEventFilter(mouse_filter);


	main_graphices_view_.installEventFilter(mouse_filter);
	//////////////////////////////////////////////////////////////////////////
	 
	//register view 
	//draw_button->installEventFilter(&filter);
	//main_graphices_view_.installEventFilter(this);
	//draw_button->installEventFilter(this);
	//draw_button->show();
	//installEventFilter(this);
	
}

TesetView::~TesetView()
{}

void TesetView::InitView()
{
	QHBoxLayout* main_layout = new QHBoxLayout();
	left_layout = new QHBoxLayout();
	right_layout = new QHBoxLayout();

	QFrame* main_frame = new QFrame();
	QFrame* left_frame = new QFrame();
	QFrame* right_frame = new QFrame();

	QLabel* test_label = new QLabel();
	test_label->setText("abc");
	
	main_frame->setLayout(main_layout);
	main_layout->addWidget(left_frame);
	main_layout->addWidget(right_frame);
	
	//set w size
	left_frame->setFixedWidth(200);
	right_frame->setFixedWidth(400);
		
	left_frame->setLayout(left_layout);
	right_frame->setLayout(right_layout);


	//left_layout->addWidget(test_label);
	right_layout->addWidget(&main_graphices_view_);
	

	

	setLayout(main_layout);
}

void TesetView::InitButtons()
{
	draw_button = new QPushButton("draw button", this);

	draw_button->setCheckable(true); // 버튼을 체크 가능하도록 설정

	left_layout->addWidget(draw_button);


	QObject::connect(draw_button, &QPushButton::clicked, this, &TesetView::UpdateDrawButton);

	
}

void TesetView::UpdateDrawButton()
{
	if (draw_button->isChecked()) {
		qDebug() << "check";
		main_graphices_view_.SetDraw(true);
	}
	else {
		qDebug() << "check false";
		main_graphices_view_.SetDraw(false);
		draw_button->setChecked(false);
	}
	

}

void TesetView::slotViewDoubleClick()
{
	qDebug() << "view functuon double click";
}

bool TesetView::eventFilter(QObject* watched, QEvent* event)
{
	QString objName = watched->objectName();
	if (watched == (QObject*)&main_graphices_view_)
	{
		qDebug() << "graphics filter";
		qDebug() << event->type();
		if (event->type() == QEvent::MouseButtonDblCliwck)
		{
			qDebug() << "checked tsetview event filter";
			
			draw_button->setChecked(false);
		}
	}
	else if (watched == (QObject*)draw_button)
	{
		if (event->type() == QEvent::Enter)
		{
			qDebug() << event->type();
		}
		else if (event->type() == QEvent::Leave)
		{
			qDebug() << event->type();
		}
		if (event->type() == QEvent::MouseButtonRelease)
		{
			qDebug() << "button release";
		}

		//qDebug() << "this event button";
	}
	
	
	return QDialog::eventFilter(watched, event);
}
