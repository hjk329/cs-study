#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4

int shared = 0; // 모든 스레드가 공통적으로 공유하는 변수

void *foo() // 모든 스레드에서 공유되는 변수에 접근하는 임계 구역임. 레이스 컨디션이 발생
{
    for (int i = 0; i < 10000; ++i) {
        shared += 1;
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, foo, NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("final result is %d\n", shared);

    return 0;
}
