# GetOSInfo(请持续关注)
获取操作系统的信息，版本号，CPU(未完成)，网卡(未完成)，显卡(未完成)，内存(未完成)，硬盘(未完成)，电脑名称(未完成)。

<!-- ---
title:  使用Qt获取系统版本
date: 2019-09-09 22:03:22
tags: 
    - Qt
comments: true
--- -->

> 获取Windows，Mac，IOS，Android，Linux等系统版本信息。

### Qt 4版本
&emsp;&emsp;可以获取到系统版本的**变量**或**函数**

* **头文件**
```cpp
#include <QSysInfo>
```

* 使用公有静态变量和静态方法获取**Windows**系统版本
```cpp
const WinVersion WindowsVersion
WinVersion windowsVersion ()
```

* 使用公有静态变量获取Mac系统版本
```cpp
const MacVersion MacintoshVersion
```

* 使用静态方法获取**塞班**系统版本和**塞班S60**系统版本
```cpp
S60Version s60Version ()
SymbianVersion symbianVersion ()
```

* 系统版本**枚举**部分预览
```cpp
enum MacVersion { MV_9, MV_10_0, MV_10_1, MV_10_2, ..., MV_YOSEMITE }
enum S60Version { SV_S60_3_1, SV_S60_3_2, SV_S60_5_0, SV_S60_5_1, ..., SV_S60_Unknown }
enum SymbianVersion { SV_9_2, SV_9_3, SV_9_4, SV_SF_1, ..., SV_Unknown }
enum WinVersion { WV_32s, WV_95, WV_98, WV_Me, ..., WV_CE_based }
```

### Qt 5.0 - Qt 5.9版本
&emsp;&emsp;以下方法在**Qt 5.9版本**以上被官方标记为**不推荐使用**

* 头文件
```cpp
#include <QSysInfo>
```

* 使用公有静态变量和静态方法获取**Windows**系统版本
```cpp
const WinVersion WindowsVersion
QSysInfo::WinVersion windowsVersion()
```

* 使用公有静态变量和静态方法获取**Mac**系统版本
```cpp
const MacVersion MacintoshVersion
QSysInfo::MacVersion macVersion()
```

* 系统版本**枚举**部分预览
```cpp
enum MacVersion { MV_9, MV_10_0, MV_10_1, MV_10_2, ..., MV_None }
enum WinVersion { WV_32s, WV_95, WV_98, WV_Me, ..., WV_None }
```

### Qt 5.4 版本以上(推荐使用)
* 头文件
```cpp
#include <QSysInfo> 
```

* 获取系统**类型**
```cpp
QString productType()
// windows, macos, osx, android, ios, 
// tvos, debian, winrt, watchos, unknown
```

* 获取**版本信息**
```cpp
QString productVersion()
```
部分版本信息**列表**：   
```cpp
"2016.09" (Amazon Linux AMI 2016.09)
"7.1" (Android Nougat)
"25" (Fedora 25)
"10.1" (iOS 10.1)
"10.12" (macOS Sierra)
"10.0" (tvOS 10)
"16.10" (Ubuntu 16.10)
"3.1" (watchOS 3.1)
"7 SP 1" (Windows 7 Service Pack 1)
"8.1" (Windows 8.1)
"10" (Windows 10)
"Server 2016" (Windows Server 2016)
```
