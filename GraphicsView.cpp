#include "GraphicsView.h"
#include <QScrollBar>
#include <qDebug>
#include <QEvent>
#include <QMouseEvent>

#include <QGraphicsLineItem>

GraphicsView::GraphicsView(QWidget* parent ) : QGraphicsView(parent)
{
	setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
	verticalScrollBar()->setEnabled(false);
	horizontalScrollBar()->setEnabled(false);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	InitView();
	//installEventFilter(this);
	setObjectName("graphics view");
	setMouseTracking(true);

}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::InitView()
{
	graphics_scene_ = new GraphicsScene();
	setScene(graphics_scene_);

	rendering_result_ = new QGraphicsPixmapItem();
	rendering_result_->setZValue(0.0f);

	graphics_scene_->addItem(rendering_result_);
	graphics_scene_->setBackgroundBrush(QBrush(Qt::transparent, Qt::NoBrush));
}


void GraphicsView::resizeEvent(QResizeEvent* event)
{
	QGraphicsView::resizeEvent(event);


	setSceneRect(0.0f, 0.0f, width(), height());
	fitInView(sceneRect());

}

void GraphicsView::mousePressEvent(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
	

}

void GraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
	QGraphicsView::mouseReleaseEvent(event);

	if (event->button() == Qt::LeftButton)
	{
		// 마우스 클릭 위치
		QPointF click_pos = event->screenPos();
		QPointF clickPos = mapToScene(event->pos());
		if (draw_flag_ == true)
		{
			if (test_line_ == nullptr)
			{
				test_line_ = new QGraphicsLineItem();
				scene()->addItem(test_line_);

				start_point_ = clickPos;

			}
		}
	}
	else
	{
		QGraphicsView::mousePressEvent(event);
	}

}

void GraphicsView::mouseMoveEvent(QMouseEvent* event)
{
	QGraphicsView::mouseMoveEvent(event);

	//QPointF move_pos = event->screenPos();
	
	if (test_line_ != nullptr)
	{
		QPointF move_pos = mapToScene(event->pos());
		end_point_ = mapFromScene(QPoint(move_pos.x(), move_pos.y()));
		test_line_->setLine(QLineF(start_point_, end_point_));
	}


}

void GraphicsView::mouseDoubleClickEvent(QMouseEvent* event)
{
	SetDraw(false);

	test_line_ = nullptr;

	QGraphicsView::mouseDoubleClickEvent(event);
}

bool GraphicsView::eventFilter(QObject* watched, QEvent* event)
{
	
/*
	if (event->type() == QEvent::KeyPress)
	{
		qDebug() << "Event filter for ";
		
		//send event to control view
	}
	else if(event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* me = static_cast<QMouseEvent*>(event);
		QPoint coordinates = me->pos();
		qDebug() << "mouse pos x : " <<coordinates.x()<<" mouse pos y : "<< coordinates.y();

	}*/
	return QGraphicsView::eventFilter(watched, event);
}


// 
// bool GraphicsView::event(QEvent* event)
// {
// 
// 
// 	return false;
// }
// 
