#include "GraphicsScene.h"
#include <qDebug>
#include <QEvent>

GraphicsScene::GraphicsScene(QObject* parent /*= nullptr*/)
{


}

GraphicsScene::~GraphicsScene()
{

}

bool GraphicsScene::eventFilter(QObject* watched, QEvent* event)
{
	QGraphicsScene::eventFilter(watched, event);

	if (event->type() == QEvent::KeyPress)
	{
		qDebug() << "scene filter ";

	}
	return false;
}
