#include <QtWidgets/QApplication>
#include "src/view/mainwindow.h"


int main(int argc, char *argv[])
{
    /*TCUIEdit::UIProject project;

    auto ui = new TCUIEdit::UIBase(&project);

    ui->setName("123");

    auto ui2 = project.getUIMap().getUI("123");

    if (ui2.size() == 1)
    {
        std::cout << "1";
    }
    else
    {
        std::cout << "0";
    }*/


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}