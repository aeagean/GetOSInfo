/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * QQ群: 732271126
 * Email: 2088201923@qq.com
 * LICENSE: MIT
**********************************************************/

#pragma execution_character_set("utf-8")

#include "GetNetworkInfo.h"
#include <QRegExp>
#include <QProcess>
#include <QDebug>

using namespace AeaQt;

QString getNetworkInfoPlain()
{
    QProcess process;
    process.start("ipconfig /all");
    process.waitForFinished();

    QByteArray data = process.readAllStandardOutput();
    return QString::fromLocal8Bit(data).trimmed();
}

/* name使用枚举代替 */
QString findNetworkInfo(const QString &name, const QString &data)
{
    if (data.indexOf(name) != -1) {
        QString content = QString(data).remove(QRegExp(R"(\(.+\))"));

        int index = content.indexOf(":");
        if (index != -1) {
            return content.remove(0, index + 1);
        }
    }

    return "";
}

GetNetworkInfo::GetNetworkInfo()
{

}

NetworkInfo GetNetworkInfo::networkInfo()
{
    NetworkInfo networkInfo;

    QRegExp rx(R"(^.*适配器)");
    QList<int> indexList;
    QString plainData = getNetworkInfoPlain();

    /* 通过换行分割为一段段的字符串 */
    QStringList plainList = plainData.split("\r\n", QString::SkipEmptyParts);
    for (int i = 0; i < plainList.size(); i++) {
        QString plain = plainList.at(i);
        /* 查找符合正则表达式[适配器]的字符串 */
        if (plain.indexOf(rx) != -1) {
            if (plain.indexOf(" ") != -1)
                networkInfo.name = QString(plain).remove(0, plain.indexOf(" "));

            for (i += 1; i < plainList.size() && plainList.at(i).indexOf(rx) == -1; i++) {
                QString plain = plainList.at(i);
                QString ipv4Address = findNetworkInfo("IPv4 地址", plain);
                QString gateway = findNetworkInfo("默认网关", plain);

                if (! ipv4Address.isEmpty())
                    networkInfo.ipv4Address = ipv4Address;

                if (! gateway.isEmpty())
                    networkInfo.gateway = gateway;
            }

            i--;
            qDebug() << networkInfo.name << networkInfo.ipv4Address << networkInfo.gateway;
        }
    }

    return NetworkInfo();
}
