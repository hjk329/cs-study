#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("hello, os\n");
    printf("my pid is %d\n", getpid());
    return 0;
}

// 운영체제는 프로그램을 실행할 때마다 새로운 프로세스를 생성하고, 프로세스가 종료되면 해당 프로세스와 관련한 자원을 해제한다. 
// 따라서, 같은 소스 코드일지라도 실행할 때마다 프로세스의 식별자인 pid 는 달라질 수 있다. 