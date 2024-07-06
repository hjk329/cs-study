#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("hello, os\n");
    printf("my pid is %d\n", getpid());
    return 0;
}
