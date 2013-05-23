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

#include "buttongrouppage.h"
#include <MLabel>
#include <MLayout>
#include <MLocale>
#include <MApplicationPage>
#include <MGridLayoutPolicy>
#include <MLinearLayoutPolicy>
#include <MButton>
#include <MButtonGroup>
#include <MDebug>
#include <MApplication>

ButtonGroupPage::ButtonGroupPage() :
    TemplatePage(TemplatePage::Buttons),
    pushButton1(NULL),
    pushButton2(NULL),
    pushButton3(NULL),
    pushButton4(NULL),
    pushButton5(NULL),
    pushButton6(NULL),
    pushButton7(NULL),
    pushButton8(NULL),
    pushButton9(NULL),
    hLabel1(NULL),
    hLabel2(NULL),
    vLabel(NULL)

{
}

ButtonGroupPage::~ButtonGroupPage()
{
}

QString ButtonGroupPage::timedemoTitle()
{
    return "ButtonGroup";
}

void ButtonGroupPage::createContent()
{
    TemplatePage::createContent();

  // Init horizontal button group, default style
    MLayout* hLayout1 = new MLayout;
    MLinearLayoutPolicy* hPolicy1 = new MLinearLayoutPolicy(hLayout1, Qt::Horizontal);
    hPolicy1->setContentsMargins(0, 0, 0, 0);
    hPolicy1->setSpacing(0);
    // The policy notifies the widgets of their relative position inside the layout,
    // this causes the buttons to be rendered with different backgrounds for each position
    hPolicy1->setNotifyWidgetsOfLayoutPositionEnabled(true);

    pushButton1 = new MButton();
    pushButton1->setObjectName("pushButton1");
    pushButton1->setStyleName(inv("CommonLeftSplitButton"));
    // The group type makes the button use the MButton[group] CSS block from the theme,
    // this allows for gapless groups by modifying the margins.
    pushButton1->setViewType(MButton::groupType);
    pushButton2 = new MButton();
    pushButton2->setObjectName("pushButton2");
    pushButton2->setStyleName(inv("CommonHorizontalCenterSplitButton"));
    pushButton2->setViewType(MButton::groupType);
    pushButton3 = new MButton();
    pushButton3->setObjectName("pushButton3");
    pushButton3->setStyleName(inv("CommonRightSplitButton"));
    pushButton3->setViewType(MButton::groupType);
    hPolicy1->addItem(pushButton1);
    hPolicy1->addItem(pushButton2);
    hPolicy1->addItem(pushButton3);

    // Init horizontal button group, exclusive
    MLayout* hLayout2 = new MLayout;
    MLinearLayoutPolicy* hPolicy2 = new MLinearLayoutPolicy(hLayout2, Qt::Horizontal);
    hPolicy2->setContentsMargins(0, 0, 0, 0);
    hPolicy2->setSpacing(0);
    hPolicy2->setNotifyWidgetsOfLayoutPositionEnabled(true);
    pushButton4 = new MButton();
    pushButton4->setObjectName("pushButton4");
    pushButton4->setStyleName(inv("CommonLeftSplitButton"));
    pushButton4->setCheckable(true);
    pushButton4->setViewType(MButton::groupType);
    pushButton5 = new MButton();
    pushButton5->setObjectName("pushButton5");
    pushButton5->setStyleName(inv("CommonHorizontalCenterSplitButton"));
    pushButton5->setCheckable(true);
    pushButton5->setChecked(true); // Let's make this our default
    pushButton5->setViewType(MButton::groupType);
    pushButton6 = new MButton();
    pushButton6->setObjectName("pushButton6");
    pushButton6->setStyleName(inv("CommonRightSplitButton"));
    pushButton6->setCheckable(true);
    pushButton6->setViewType(MButton::groupType);
    hPolicy2->addItem(pushButton4);
    hPolicy2->addItem(pushButton5);
    hPolicy2->addItem(pushButton6);
    // The group enforces the logical exclusivity
    MButtonGroup* group = new MButtonGroup(this);
    group->setObjectName("buttonGroup");
    group->addButton(pushButton4);
    group->addButton(pushButton5);
    group->addButton(pushButton6);

    // Init vertical button group, checkable
    MLayout* vLayout = new MLayout;
    MLinearLayoutPolicy* vPolicyP = new MLinearLayoutPolicy(vLayout, Qt::Vertical);
    vLayout->setPortraitPolicy(vPolicyP);
    vPolicyP->setNotifyWidgetsOfLayoutPositionEnabled(true);
    vPolicyP->setContentsMargins(0, 0, 0, 0);
    vPolicyP->setSpacing(0);
    MLinearLayoutPolicy* vPolicyL = new MLinearLayoutPolicy(vLayout, Qt::Horizontal);
    vLayout->setLandscapePolicy(vPolicyL);
    vPolicyL->setNotifyWidgetsOfLayoutPositionEnabled(true);
    vPolicyL->setContentsMargins(0, 0, 0, 0);
    vPolicyL->setSpacing(0);

    pushButton7 = new MButton();
    pushButton7->setObjectName("pushButton7");
    pushButton7->setStyleName(inv("CommonTopSplitButton"));
    pushButton7->setCheckable(true);
    pushButton7->setViewType(MButton::groupType);
    pushButton8 = new MButton();
    pushButton8->setObjectName("pushButton8");
    pushButton8->setStyleName(inv("CommonVerticalCenterSplitButton"));
    pushButton8->setCheckable(true);
    pushButton8->setViewType(MButton::groupType);
    pushButton9 = new MButton();
    pushButton9->setObjectName("pushButton9");
    pushButton9->setStyleName(inv("CommonBottomSplitButton"));
    pushButton9->setCheckable(true);
    pushButton9->setViewType(MButton::groupType);
    vPolicyP->addItem(pushButton7);
    vPolicyP->addItem(pushButton8);
    vPolicyP->addItem(pushButton9);
    vPolicyL->addItem(pushButton7);
    vPolicyL->addItem(pushButton8);
    vPolicyL->addItem(pushButton9);

    //add label and horizontal button group into page
    hLabel1 = new MLabel();
    hLabel1->setObjectName("hLabel1");
    hLabel1->setStyleName(inv("CommonFieldLabel"));
    containerPolicy->addItem(hLabel1);
    containerPolicy->addItem(hLayout1);

    //add small spacer between button groups
    MWidgetController* spacer1 = new MWidgetController;
    spacer1->setObjectName("spacer1");
    spacer1->setStyleName("CommonSpacer");
    containerPolicy->addItem(spacer1);

    //add label and horizontal button group into page
    hLabel2 = new MLabel();
    hLabel2->setObjectName("hLabel2");
    hLabel2->setStyleName(inv("CommonFieldLabel"));
    containerPolicy->addItem(hLabel2);
    containerPolicy->addItem(hLayout2);

    //add small spacer between button groups
    MWidgetController* spacer2 = new MWidgetController;
    spacer2->setObjectName("spacer2");
    spacer2->setStyleName("CommonSpacer");
    containerPolicy->addItem(spacer2);

    //add label and vertical button group into page
    vLabel = new MLabel();
    vLabel->setObjectName("vLabel");
    vLabel->setStyleName(inv("CommonFieldLabel"));
    containerPolicy->addItem(vLabel);
    containerPolicy->addItem(vLayout);

    retranslateUi();
}

void ButtonGroupPage::retranslateUi()
{
    //% "Button Group"
    setTitle(qtTrId("xx_button_group_page_title"));
    if (!isContentCreated())
        return;
        
    /*% "Buttons can be grouped together based on visual or logic requirements.\n\n"
        "The basic group is formed by placing buttons together "
        "into a layout. Depending on the theme, the buttons are typically "
        "drawn as connected with each other.\n\n"
        "Logical exclusivity can be added to a group, which ensures only one "
        "of the buttons can be selected at a time. If a group is not exclusive, "
        "multiple options from the group can be selected."
     */
    infoLabel->setText("<a></a>" + qtTrId("xx_button_group_page_info_label").replace('\n', "<br>"));

    //% "Horizontal group"
    hLabel1->setText(qtTrId("xx_button_group_page_hlabel1"));
    //% "Yes"
    pushButton1->setText(qtTrId("xx_button_group_page_button1"));
    //% "No"
    pushButton2->setText(qtTrId("xx_button_group_page_button2"));
    //% "Maybe"
    pushButton3->setText(qtTrId("xx_button_group_page_button3"));

    //% "Horizontal group, exclusive"
    hLabel2->setText(qtTrId("xx_button_group_page_vlabel2"));
    //% "Cost"
    pushButton4->setText(qtTrId("xx_button_group_page_button4"));
    //% "Quality"
    pushButton5->setText(qtTrId("xx_button_group_page_button5"));
    //% "Schedule"
    pushButton6->setText(qtTrId("xx_button_group_page_button6"));

    //% "Vertical group, checkable"
    vLabel->setText(qtTrId("xx_button_group_page_vlabel"));
    //% "Milk"
    pushButton7->setText(qtTrId("xx_button_group_page_button7"));
    //% "Sugar"
    pushButton8->setText(qtTrId("xx_button_group_page_button8"));
    //% "Biscotti"
    pushButton9->setText(qtTrId("xx_button_group_page_button9"));
}
