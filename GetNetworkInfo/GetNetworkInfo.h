/**********************************************************
 * Author: Qt君
 * 微信公众号: Qt君(首发)
 * QQ群: 732271126
 * Email: 2088201923@qq.com
 * LICENSE: MIT
**********************************************************/
#ifndef GETNETWORKINFO_H
#define GETNETWORKINFO_H

#include <QString>

namespace AeaQt {
struct NetworkInfo {
    QString name;
    QString descript;
    QString macAddress;
    QString ipv4Address;
    QString ipv6Address;
    QString netmask;
    QString gateway;
    QString dns;
};

class GetNetworkInfo
{
public:
    GetNetworkInfo();

    static NetworkInfo networkInfo();
};

}
#endif // GETNETWORKINFO_H
