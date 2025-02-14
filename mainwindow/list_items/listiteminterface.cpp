#include "listiteminterface.h"

ListItemInterface::ListItemInterface(QWidget *parent) : QWidget(parent)
{
    _bgLabel = new CustomPaintWidget(this);
    _bgLabel->move(_cardMargin, _cardMargin);
    // _bgLabel->setStyleSheet("background: white; border-radius: 5px;");

    vlayout = new QVBoxLayout(this);
    setLayout(vlayout);
    vlayout->setMargin(vlayout->margin() + _cardMargin);

    check = new QCheckBox("启用", this);
    btn = new InteractiveButtonBase("发送", this);

    hlayout = new QHBoxLayout;
    hlayout->addWidget(check);
    hlayout->addWidget(new QWidget(this));
    hlayout->addWidget(btn);
    hlayout->setStretch(1, 1);
    hlayout->setMargin(0);
    vlayout->addLayout(hlayout);

    btn->setBorderColor(Qt::black);
    btn->setCursor(Qt::PointingHandCursor);
    btn->setFixedForePos();
    check->setCursor(Qt::PointingHandCursor);

    const int radius = 5;
    _bgLabel->setPaint([=](QRect, QPainter* painter) {
        QPainterPath path;
        path.addRoundedRect(_bgLabel->rect(), radius, radius);
        /* {
            int left = check->geometry().right() + (check->x() - _bgLabel->x()) * 2;
            int right = btn->x() - (_bgLabel->geometry().right() - btn->geometry().right()) * 2;
            int bottom = check->geometry().bottom() + vlayout->spacing() / 2;
            QPainterPath cutted;
            cutted.addRoundedRect(QRect(left, 0, right - left, bottom), radius, radius);
            path -= cutted;
        } */
        painter->setRenderHint(QPainter::Antialiasing);
        painter->fillPath(path, Qt::white);
    });
}

void ListItemInterface::setRow(int row)
{
    this->_row = row;
}

int ListItemInterface::getRow() const
{
    return _row;
}

void ListItemInterface::resizeEvent(QResizeEvent *event)
{
    _bgLabel->resize(event->size() - QSize(_cardMargin * 2, _cardMargin * 2));

    return QWidget::resizeEvent(event);
}
