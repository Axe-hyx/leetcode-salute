#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <climits>
#include <iostream>
using namespace std;

class A{
    public:
        A() = default;
        A(const string& a):str(a){}
        ~A() noexcept{
            printf("decons A\n");
        }
    private:
        string str;

};
class B{
    public:
        B(){
            printf("default cons\n");
        }
        A a;
        ~B() noexcept{
            printf("decons b ");
        }
    private:

};

int main(int argc, char* argv[])
{

#ifdef DEBUG
	printf("gcc 的-D 选项测试\n");
#endif

    string s = string(1, 'c');
    printf("%d\n", (1<<16)-1);
    printf("%d\n", INT_MAX);
    printf("%ld\n", ((long)1<<31)-1);
    printf("%lld", ((unsigned long long)1<<63)-1);
    cout<<endl;
    B b;
    b.a = A("italia");
	return 0;
}
