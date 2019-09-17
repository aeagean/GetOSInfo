/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * QQ群: 732271126
 * Email: 2088201923@qq.com
 * LICENSE: MIT
**********************************************************/
#include <QDebug>
#include "Widget.h"
#include "GetNetworkInfo.h"
#include <QApplication>

using namespace AeaQt;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    GetNetworkInfo::networkInfo();
    return a.exec();
}
