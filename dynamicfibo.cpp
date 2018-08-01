#include <map>
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::map;

unsigned long NormalFibonacci(unsigned short);
unsigned long DynamicFibonacci(unsigned short);

map<unsigned short, unsigned long> fiboMap;

int main(int argc, char* argv[]){
    fiboMap[0] = 0;
    fiboMap[1] = 1;

    return 0;
}

unsigned long NormalFibonacci(unsigned short n){
    if (n <= 1)
        return n;
    else
        return NormalFibonacci(n - 1) + NormalFibonacci(n - 2);
}

unsigned long DynamicFibonacci(unsigned short n){
    

}
