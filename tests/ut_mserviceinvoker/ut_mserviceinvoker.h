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

#ifndef UT_MSERVICEINVOKER_H
#define UT_MSERVICEINVOKER_H

#include <QtTest/QtTest>
#include <QObject>
#include <mserviceaction.h>

class MockServiceAction : public MServiceAction
{
    Q_OBJECT;

public:
    MockServiceAction();

    void trigger();

    virtual void executeService();

    bool executeServiceCalled;

};


class Ut_MServiceInvoker : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void testInvoke();

};

#endif
