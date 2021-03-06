//
// Created by liu on 2016/12/21.
//

#pragma once

#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>
#include "UIPropertyBrowserModel.h"
#include "UIPropertyBrowserCategory.h"
#include <QDebug>

namespace TCUIEdit
{

    class UIPropertyBrowser : public QTreeView
    {
    Q_OBJECT
    protected:
        UIPropertyBrowserModel *model;
    public:
        UIPropertyBrowser(QWidget *parent = Q_NULLPTR);

        ~UIPropertyBrowser();

        void init();

        void addCategory(const QString &text);

    };

};


