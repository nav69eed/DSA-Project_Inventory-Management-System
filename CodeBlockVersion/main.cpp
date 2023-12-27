#include "helperfunctions2.h"
int main()
{
    ProductTree avlTree;
    avlTree.loadFromFile();
    showMenu(&avlTree);
    getchar();
    return 0;
}
