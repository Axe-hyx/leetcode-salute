#include <iostream>
#include <string.h> //memset
#include <unistd.h> //sleep
#define SIZE (80 * 1024 * 1024) //80M
int main(void)
{

    std::cout << "1---->sleep 10s" << std::endl;
    sleep(10);

    std::cout << "2---->sleep 10s end, begin malloc" << std::endl;
    char *buf = (char *)malloc(SIZE);
    //char *buf = (char *)new char[SIZE];
    if (!buf) {
        std::cout << "malloc failed" << std::endl;
        exit(1);
    }

    std::cout << "3---->sleep 10s" << std::endl;
    sleep(10);

    std::cout << "4---->sleep 10s end, begin init" << std::endl;
    memset(buf, 0, SIZE);
    std::cout << "5---->sleep 10s" << std::endl;
    sleep(10);

    std::cout << "6---->sleep 10s end, exit" << std::endl;
    return 0;
}
