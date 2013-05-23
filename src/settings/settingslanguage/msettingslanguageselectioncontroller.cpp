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

#include "msettingslanguageselectioncontroller.h"

#include <MButton>
#include <MDataStore>

MSettingsLanguageSelectionController::MSettingsLanguageSelectionController(QObject *parent) :
    QObject(parent)
{
}

MSettingsLanguageSelectionController::~MSettingsLanguageSelectionController()
{
}

void MSettingsLanguageSelectionController::buttonClicked(MButton *button)
{
    MDataStore *dataStore = static_cast<MDataStore *>(button->property("dataStore").value<void *>());
    if (dataStore != NULL) {
        dataStore->createValue(button->property("key").toString(), button->property("value").toInt());
    }
}
