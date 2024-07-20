#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int shared = 0;

void *foo()
{
    // 뮤텍스 락을 걸어서 한 번에 하나의 스레드에서만 임계 구역에 접근하도록 동기화
    // 각 스레드는 임계구역을 진입하기 위해 mutex 변수를 확보해야함
    // 확보하지 못했다면 임계구역 앞에서 대기

    pthread_mutex_lock(&mutex); 

    for (int i = 0; i < 10000; ++i) {
        shared += 1;
    }

    // 잠금을 해제하여 다른 스레드가 shared 변수를 수정할 수 있도록 함
    // -> 레이스 컨디션을 해결하고 동기화
    pthread_mutex_unlock(&mutex);
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
