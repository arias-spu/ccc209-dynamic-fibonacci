#include <map>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::cerr;
using std::endl;
using std::map;
using std::setw;
using std::ofstream;


unsigned long NormalFibonacci(unsigned short);
unsigned long DynamicFibonacci(unsigned short);



int main(int argc, char* argv[]){
    if (argc != 3){
        cerr << "Parameter missing" << endl;
        return 1;
    }
    size_t n = atoi(argv[1]);
    ofstream output(argv[2]);
    clock_t start, end;
    unsigned long normalFibonacciTicks, dynamicFibonacciTicks;
    for (size_t i = 0; i < n; i++) {
        start = clock();
        NormalFibonacci(i);
        end = clock();
        normalFibonacciTicks = end - start;

        start = clock();
        DynamicFibonacci(i);
        end = clock();
        dynamicFibonacciTicks = end - start;

        output << i << "," << normalFibonacciTicks << ","
                           << dynamicFibonacciTicks << endl;
        // cout << setw(4) << i
        //      << setw(12) << normalFibonacciTicks
        //      << setw(12) << dynamicFibonacciTicks
        //      << endl;
    }
    output.close();
    return 0;
}

unsigned long NormalFibonacci(unsigned short n){
    if (n <= 1)
        return n;
    else
        return NormalFibonacci(n - 1) + NormalFibonacci(n - 2);
}

unsigned long DynamicFibonacci(unsigned short n){
    static map<unsigned short, unsigned long> fiboMap;
    static bool initialized = false;
    if (!initialized){
        // ----------------------------------------------
            fiboMap[0] = 0;
            fiboMap[1] = 1;
        // ----------------------------------------------
        initialized = true;
    }
    if (fiboMap.find(n) != fiboMap.end())
        return fiboMap[n];
    unsigned long f2, f1;
    f1 = DynamicFibonacci(n - 1);
    f2 = DynamicFibonacci(n - 2);
    fiboMap[n] = f1 + f2;
    return f1 + f2;
}
