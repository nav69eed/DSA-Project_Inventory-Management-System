#include "assets/HelperFunctions/helperFunction2.h"
int main()
{
    ProductTree avlTree;
    avlTree.loadFromFile();
    showMenu(&avlTree);
    getchar();
    return 0;
}