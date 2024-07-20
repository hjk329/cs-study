from threading import Thread

num = 0

def foo():
    for _ in range(100000):
        global num

        # 다중 스레드에서 num 변수를 수정하며 레이스 컨디션 발생
        num += 1 

if __name__ == '__main__':
    t1 = Thread(target=foo)
    t2 = Thread(target=foo)

    t1.start()
    t2.start()

    print(num)
