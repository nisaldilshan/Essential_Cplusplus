#include <iostream>
#include <thread>

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// Global threadlocal variable shared among threads

// thread_local int i=0;

// void f(int newval){
//     i=newval;
// }

// void threadfunc(int id){
//     f(id);
//     ++i;
//     std::cout<<i;
// }

// int main(){
//     i=9;
//     std::thread t1(threadfunc,1);
//     std::thread t2(threadfunc,2);
//     std::thread t3(threadfunc,3);

//     t1.join();
//     t2.join();
//     t3.join();
//     std::cout<<i<<std::endl;
// }


//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// Single object with threadlocal member shared among threads


// class A
// {
// public:
//     A()
//     {
//         std::cout << "Constructor : " << m_tlmemeber << std::endl;
//     }

//     void inc()
//     {
//         ++m_tlmemeber;
//     }

//     void print(std::string str)
//     {
//         std::cout << str << m_tlmemeber << std::endl;
//     }

// private:
//     static thread_local int m_tlmemeber; //static is need to compile
// };

// thread_local int A::m_tlmemeber(10);

// void thread1func(A& a)
// {
//     a.inc();
//     a.print("End Thread1 func : ");
// }

// void thread2func(A& a)
// {
//     a.inc();
//     a.inc();
//     a.inc();
//     a.print("End Thread2 func : ");
// }

// int main()
// {
//     A a;
//     std::thread t1(thread1func,std::ref(a));
//     std::thread t2(thread2func,std::ref(a));
//     t1.join();
//     t2.join();
//     a.print("End Main : ");
//     return 0;
// }


//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
// thread local variable in function scope

class A
{
public:
    A(){}

    void inc(int count)
    {
        thread_local int tl = 100;
        for (size_t i = 0; i < count; i++)
        {
            ++tl;
        }
        std::cout << tl << std::endl;
    }
};

void thread1func(A& a)
{
    a.inc(3);
    a.inc(10);
}

void thread2func(A& a)
{
    a.inc(5);
}

int main()
{
    A a;
    std::thread t1(thread1func,std::ref(a)); 
    t1.join();
    std::thread t2(thread2func,std::ref(a));
    t2.join();
    return 0;
}

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\