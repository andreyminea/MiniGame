#include <iostream>
#include <thread>

void hello(int tid)
{
    std::cout << "Hello Concurrent World from thread number " << tid << "\n";
}

int main(void)
{
    std::thread tr1(hello, 1);
    std::thread tr2(hello, 2);
    std::thread tr3(hello, 3);
    std::thread tr4(hello, 4);
    std::thread tr5(hello, 5);
    std::thread tr6(hello, 6);
    std::thread tr7(hello, 7);
    std::thread tr8(hello, 8);


    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    tr5.join();
    tr6.join();
    tr7.join();
    tr8.join();


    std::cout << "Hello Concurrent World from main thread\n";
    


    return 0;
}