#pragma once

#include <QtWidgets/QDialog>
#include "ui_TesetView.h"
#include <QtWidgets>
#include "GraphicsView.h"
class TesetView : public QDialog
{
    Q_OBJECT

public:
    TesetView(QWidget *parent = nullptr);
    ~TesetView();

    virtual bool eventFilter(QObject* watched, QEvent* event) override;

    void InitView();
    void InitButtons();
    void UpdateDrawButton();
    
private:
    Ui::TesetViewClass ui;

private:
    QHBoxLayout* left_layout;
    QHBoxLayout* right_layout;
    QPushButton* draw_button;
public slots:
    void slotViewDoubleClick();

public:
    
    GraphicsView main_graphices_view_;
};

class KeyPressEater : public QObject
{
	Q_OBJECT


protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
};

class MousePressFilter : public QObject
{
	Q_OBJECT


protected:
	bool eventFilter(QObject* obj, QEvent* event) override;
public:
    QObject* view_;
};

