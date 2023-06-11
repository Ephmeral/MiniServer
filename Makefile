server: main.cpp ./threadpool/threadpool.h ./http/http_conn.cpp ./http/http_conn.h ./lock/lock.h 
	g++ -o server main.cpp ./threadpool/threadpool.h ./http/http_conn.cpp ./http/http_conn.h ./lock/lock.h -lpthread


clean:
	rm  -r server
