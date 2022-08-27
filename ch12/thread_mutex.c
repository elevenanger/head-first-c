/*
 * @author 刘昂林 
 * @date 2022/8/27
 * @brief 线程互斥锁
 */
#include <stdio.h>
#include <pthread.h>

void* do_stuff(void* param) {
    // 将参数转回 long
    long thread_no = (long) param;
    printf("Thread number %ld\n", thread_no);
    // 将参数类型转回 void 指针
    return (void*) (thread_no + 1);
}

// 声明互斥锁
pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;

int beers = 2000000;

void* drink_lots(void *a) {
    int i;
    // 使用互斥锁
    pthread_mutex_lock(&beers_lock);

    for (i = 0; i < 100000; i ++) {
        beers = beers- 1;
    }
    // 释放互斥锁
    pthread_mutex_unlock(&beers_lock);
    printf("beers = %i \n", beers);
    return NULL;
}

void multi_stuff() {
    pthread_t threads[10];
    long t;
    for (t = 0; t < 10; t ++) {
        pthread_create(&threads[t], NULL, do_stuff, (void*)t);
    }

    void *result;

    for (t = 0; t < 10; t ++) {
        pthread_join(threads[t], &result);
        printf("Thread %ld returned %ld \n", t, (long)result);
    }
}

void beer_party() {
    pthread_t threads[20];
    int t;
    printf("%i bottles beer on the wall \n %i bottles beer\n",
           beers, beers);
    for (t = 0; t < 20; t ++)
        pthread_create(&threads[t], NULL, drink_lots, NULL);
    void *result;
    for (t = 0; t < 20; t ++)
        pthread_join(threads[t], &result);

    printf("There are now %i bottles of beer on the wall\n", beers);
}


int main() {

    multi_stuff();

    beer_party();

    return 0;
}