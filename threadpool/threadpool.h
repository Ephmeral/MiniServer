#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "../lock/lock.h"

template <typename T>
class ThreadPool {
public:
    ThreadPool(int thread_num = 8, int max_request = 10000);
    ~ThreadPool();

    /* 往请求队列中添加任务 */
    bool append(T *request);
private:
    static void *worker(void *arg);
    void run();

private:
    int m_thread_number;        /* 线程池中的线程数 */
    int m_max_requests;         /* 请求队列中允许的最大请求数 */
    pthread_t *m_threads;       /* 描述线程池的数组，其大小为m_thread_number */
    std::list<T*> m_workqueue;  /* 请求队列 */
    Locker m_queuelocker;       /* 保护请求队列的互斥锁 */
    Sem m_queuestat;            /* 是否有任务需要处理 */
    bool m_stop;                /* 是否结束线程 */
};

template<typename T>
ThreadPool<T>::ThreadPool(int thread_number, int max_requests) :
    m_thread_number(thread_number),  
    m_max_requests(max_requests),
    m_stop(false), 
    m_threads(NULL) {
    
    if ((thread_number <= 0) || max_requests <= 0) {
        thorw std::exception();
    }
    m_threads = new pthread_t[m_thread_number];
    if (!m_threads) {
        throw std::exception();
    }

    for (int i = 0; i < thread_number; ++i) {
        printf("create the %dth thread\n", i);
        if (pthread_create(m_threads + i, NULL, worker, this) != 0) {
            delete[] m_threads;
            throw std::exception();
        }
        if (pthread_detach(m_threads[i])) {
            delete[] m_threads;
            throw std::exception();
        }
    }
}

template<typename T>
ThreadPool<T>::~ThreadPool() {
    delete[] m_threads;
    m_stop = true;
}

template<typename T>
bool ThreadPool<T>::append(T *request) {
    /* 操作工作队列时一定要加锁，因为它被所有线程共享 */
    m_queuelocker.lock();
    if (m_workqueue.size() > m_max_requests) {
        m_queuelocker.lock();
        return false;
    }
    m_wordqueue.push_back(request);
    m_queuelocker.unlock();
    m_queuestat.post();
    return true;
}

template<typename T>
void *ThreadPool<T>::worker(void *arg) {
    ThreadPool *pool = (ThreadPool*)arg;
    pool->run();
    return pool;
}

template<typename T>
void ThreadPool<T>::run() {
    while (!m_stop) {
        m_queuestat.wait();
        m_queuelocker.lock();
        if (m_workqueue.empty()) {
            m_queuelocker.unlock();
            continue;
        }
    }
    T* request = m_wordqueue.front();
    m_wordqueue.pop_front();
    m_queuelocker.unlock();
    if (!request) {
        continue;
    }
    request->process();
}

#endif // THREADPOOL_H