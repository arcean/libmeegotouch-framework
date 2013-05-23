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
#ifndef SAMPLEWINDOW_H
#define SAMPLEWINDOW_H

#include <MApplicationWindow>

#include <MApplicationPage>
#include <MAction>
#include <QActionGroup>

class SampleWindow : public MApplicationWindow {
    Q_OBJECT

public:
    SampleWindow(QWidget *parent = 0);

private slots:
    void showPageForAction(QAction *action);

private:
    MApplicationPage *createPage(const QString &name);
    QAction *createAction(const QString &name, bool checked = false);

    QAction *currentAction;
    QActionGroup *actionGroup;
};

#endif
