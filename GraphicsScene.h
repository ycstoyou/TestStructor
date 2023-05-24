#pragma once

#include <QGraphicsScene>

class GraphicsScene :public QGraphicsScene
{
public:
	GraphicsScene(QObject* parent = nullptr);
	virtual ~GraphicsScene();

	virtual bool eventFilter(QObject* watched, QEvent* event) override;

};

