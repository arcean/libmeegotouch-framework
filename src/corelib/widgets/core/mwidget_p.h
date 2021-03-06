/***************************************************************************
**
** Copyright (C) 2010, 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (directui@nokia.com)
**
** This file is part of libmeegotouch.
**
** If you have questions regarding the use of this file, please contact
** Nokia at directui@nokia.com.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#ifndef MWIDGET_P_H
#define MWIDGET_P_H

#include <mwidget.h>
#include <QMap>

class M_CORE_EXPORT MWidgetPrivate
{
    Q_DECLARE_PUBLIC(MWidget)
public:
    MWidgetPrivate();
    virtual ~MWidgetPrivate();

    virtual void doEnterDisplayEvent();
    virtual void doExitDisplayEvent();

    void sendOnDisplayChangeEvent(MWidget *widget, const QRectF *visibleSceneRect);
    void resolveIsOnDisplay(QGraphicsItem *item, const QRectF *visibleSceneRect,
                            MOnDisplayChangeEvent *event = NULL);
    QGraphicsView *fetchGraphicsView();

    void setVisible(bool visible);

    //! \internal
    QPointF mapToRoot(const QPointF &point);
    //! \internal_end

    bool explicitlyHidden;  //< true if the user called hide(), as opposed to MLayout hiding it
    bool layoutHidden;  //< true if MLayout is currently hiding the widget

protected:
    MWidget *q_ptr;
    bool onDisplay;
    bool selected;

    QMap<Qt::GestureType, MWidget::MouseEventCancelPolicy> cancelPolicies;
};

#endif // MWIDGET_P_H
