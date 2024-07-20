from threading import Thread, Semaphore

num = 0

# 세마포를 사용하여 여러개의 스레드가 동일한 자원에 동시에 접근하지 않도록 보호
sem = Semaphore(1)

def foo(sem):
    global num

    # 세마포를 acquire하지 못한 스레드는 대기
    sem.acquire()
    for _ in range(100000):
        num += 1

    # 임계 구역 작업이 끝났으니 잠금 해제
    sem.release()

if __name__ == '__main__':
    t1 = Thread(target=foo, args=(sem,))
    t2 = Thread(target=foo, args=(sem,))
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(num)
