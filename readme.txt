Windows环境使用gsoap生成onvif框架代码工程。

命令：
wsdl2h.exe -t ../gsoap/typemap.dat -o onvif.h -d http://www.onvif.org/onvif/ver10/network/wsdl/remotediscovery.wsdl  http://www.onvif.org/onvif/ver10/device/wsdl/devicemgmt.wsdl http://www.onvif.org/onvif/ver10/events/wsdl/event.wsdl http://www.onvif.org/onvif/ver10/display.wsdl http://www.onvif.org/onvif/ver10/deviceio.wsdl http://www.onvif.org/onvif/ver20/imaging/wsdl/imaging.wsdl http://www.onvif.org/onvif/ver10/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/media/wsdl/media.wsdl http://www.onvif.org/onvif/ver20/ptz/wsdl/ptz.wsdl http://www.onvif.org/onvif/ver10/receiver.wsdl http://www.onvif.org/onvif/ver10/recording.wsdl http://www.onvif.org/onvif/ver10/search.wsdl http://www.onvif.org/onvif/ver10/replay.wsdl http://www.onvif.org/onvif/ver20/analytics/wsdl/analytics.wsdl http://www.onvif.org/onvif/ver10/analyticsdevice.wsdl http://www.onvif.org/onvif/ver10/schema/onvif.xsd http://www.onvif.org/ver10/actionengine.wsdl http://www.onvif.org/ver10/pacs/accesscontrol.wsdl http://www.onvif.org/ver10/pacs/doorcontrol.wsdl http://www.onvif.org/ver10/advancedsecurity/wsdl/advancedsecurity.wsdl http://www.onvif.org/ver10/accessrules/wsdl/accessrules.wsdl http://www.onvif.org/ver10/credential/wsdl/credential.wsdl http://www.onvif.org/ver10/schedule/wsdl/schedule.wsdl http://www.onvif.org/ver10/pacs/types.xsd

soapcpp2.exe -i -I ../gsoap/import/ -I ../gsoap/ onvif.h

------------------------

gsoap-2.8.27
 gsoap ：gsoap-2.8.27源码，有删减
 onvif_latelee：生成的onvif框架代码
   proxy：客户端代码
   xml：xml文件
   1.bat：生成onvif.h脚本
   2.bat：生成实现文件脚本
   soapXXXService.h/.cpp：服务端代码
   wsdd.nsmap：命名空间文件

------------------------

gsoap-2.8.29
2.8.29：同上，版本最新。


---------------------------
