#if !defined(Helper_Function_h)
#define Helper_Function_h
#include <cstdlib>
#include <iostream>
#include <string>
// #include "../ProductTree/ProductTree.h"
using namespace std;
void clearscreen()
{
    system("CLS");
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
#endif // Helper_Function_h
