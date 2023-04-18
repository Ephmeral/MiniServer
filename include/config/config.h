#ifndef CONFIG_H
#define CONFIG_H

const int Port = 9090;                  // 服务器端口
const int TrigMode = 3;                 // ET模式
const int TimeoutMS = 60000;            // 超时时间（毫秒）
const bool OptLinger = false;           // 是否优雅退出

const int MySQLPort = 3306;             // MySQL端口号
const char *MySQLUser = "root";         // MySQL用户名
const char *MySQLPasswd = "wxl7756212";        // MySQL密码
const char *DataBaseName = "webserver"; // MySQL数据库名

const int ConnPoolNum = 12;         // 连接池数量
const int ThreadNum = 6;                // 线程池数量
const bool OpenLog = true;              // 日志开关
const int LogLevel = 1;                 // 日志等级
const int LogQueSize = 1024;            // 日志异步队列容量

#endif // CONFIG_H