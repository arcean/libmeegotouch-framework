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

#ifndef MAPPLETHANDLESTYLE_H
#define MAPPLETHANDLESTYLE_H

#include "mextensionhandlestyle.h"

//! \internal
class MAppletHandleStyle : public MExtensionHandleStyle
{
    Q_OBJECT
    M_STYLE(MAppletHandleStyle)
};

class MAppletHandleStyleContainer : public MExtensionHandleStyleContainer
{
    M_STYLE_CONTAINER(MAppletHandleStyle)
};
//! \internal_end

#endif // MAPPLETHANDLESTYLE_H
