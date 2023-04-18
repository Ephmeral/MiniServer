#include <unistd.h>
#include "include/server/webserver.h"
#include "include/config/config.h"

int main() {
    /* 守护进程 后台运行 */
    // daemon(1, 0);

    WebServer server(
        Port, TrigMode, TimeoutMS, OptLinger,             /* 端口 ET模式 timeoutMs 优雅退出  */
        MySQLPort, MySQLUser, MySQLPasswd, DataBaseName,                    /* Mysql配置 */
        ConnPoolNum, ThreadNum, OpenLog, LogLevel, LogQueSize);             /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */
    server.Start();
}