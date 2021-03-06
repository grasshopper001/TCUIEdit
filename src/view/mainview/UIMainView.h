//
// Created by liu on 2016/12/21.
//

#pragma once

#include "UIMainView_Base.h"
#include "UIMainView_Category.h"

namespace TCUIEdit
{
    class UIMainView
    {
    protected:
        UIPropertyBrowser *browser;

        UIMainView_Base *base;

    public:
        UIMainView(UIPropertyBrowser *browser);

        void displayUI(UI::Base* ui);

        void displayPackageBase(UI::Base* pkgBase);

        void displayPackage(Package::Package* pkg);

    };
};



