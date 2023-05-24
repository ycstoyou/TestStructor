#pragma once
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "GraphicsScene.h"
#include <QLineF>
class GraphicsView : public QGraphicsView
{
	Q_OBJECT;
public:
	GraphicsView(QWidget* parent = nullptr);
	virtual ~GraphicsView();

protected:
	virtual void resizeEvent(QResizeEvent* event) override;
	
	//virtual bool event(QEvent* event) override;
	void InitView();
	virtual bool eventFilter(QObject* watched, QEvent* event) override;

	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
	GraphicsScene* graphics_scene_ = nullptr;
	QGraphicsPixmapItem* rendering_result_ = nullptr;

	QGraphicsLineItem* test_line_ = nullptr;
	
	QPointF start_point_;
	QPointF end_point_;

	bool draw_flag_ = false;

signals:
	//void sigDoubleClick();
public:
	void SetDraw(bool flag) { draw_flag_ = flag; }
};

