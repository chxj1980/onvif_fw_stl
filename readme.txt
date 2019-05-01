Windows环境使用gsoap生成onvif框架代码工程。

## FAQ
* Q：为什么有这个仓库？
* A：这是onvif框架代码产生的命令、源码。注意，“框架代码”不能直接应用到项目中，要经过大量的编码才行。本仓库仅是onvif项目的开端。  

* Q：本仓库如何使用？
* A：onvif有不同的模块，使用不同的wsdl文件产生对应的代码。本仓库默认最大兼容，包括作者认为有用的模块（但不保证绝对性）。实际应用中，根据需求选择恰当的wsdl，以减小文件体积。本仓库提供思路和步骤，仅供参考。   
 
* Q：为什么用2.8.27版本？
* A：gsoap更新太快，且gsoap源码下载较困难，且这个版本能work，就不折腾、纠结gsoap的版本了。


## 生成onvif.h
```
wsdl2h.exe -t ../gsoap/typemap.dat -o onvif.h -d http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl  http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl http://www.onvif.org/onvif/ver10/display.wsdl http://www.onvif.org/onvif/ver10/deviceio.wsdl http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl http://www.onvif.org/onvif/ver10/receiver.wsdl http://www.onvif.org/onvif/ver10/recording.wsdl http://www.onvif.org/onvif/ver10/search.wsdl http://www.onvif.org/onvif/ver10/replay.wsdl http://www.onvif.org/onvif/ver20/analytics/wsdl/analytics.wsdl http://www.onvif.org/onvif/ver10/analyticsdevice.wsdl http://www.onvif.org/onvif/ver10/schema/onvif.xsd http://www.onvif.org/ver10/actionengine.wsdl http://www.onvif.org/ver10/pacs/accesscontrol.wsdl http://www.onvif.org/ver10/pacs/doorcontrol.wsdl http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl http://www.onvif.org/ver10/accessrules/wsdl/accessrules.wsdl http://www.onvif.org/ver10/credential/wsdl/credential.wsdl http://www.onvif.org/ver10/schedule/wsdl/schedule.wsdl http://www.onvif.org/ver10/pacs/types.xsd
```
## 在onvif.h文件 #import "wsa5.h" 后添加：
```
#import "wsse.h"
```
## 生成框架代码：  
```
soapcpp2.exe -x -c -I ../gsoap/import/ -I ../gsoap/ onvif.h
```

`soapcpp2`参数说明：  
* -j：soap作为服务类成员  
* -i：服务类继承soap结构体  
* -x：产生xml文件  
* -S：服务端代码  
* -C：客户端代码  
* -I：导入文件路径  


## 文件说明
gsoap-2.8.27
 gsoap ：gsoap-2.8.27源码，有删减，也可以直接下载gsoap源码，再解压。
 onvif_latelee：生成的onvif框架代码
   proxy：客户端代码
   xml：xml文件，协议命令，开发时可参考
   1.bat：生成onvif.h脚本
   2.bat：生成实现文件脚本
   soapXXXService.h/.cpp：服务端代码
   wsdd.nsmap：命名空间文件

------------------------

gsoap-2.8.29 (存档，暂不维护更新)
2.8.29：同上，版本最新。


---------------------------
