#include "assets/HelperFunctions/helperFunction2.h"
int main()
{
    ProductTree avlTree;
    avlTree.loadFromFile();
    showMenu(&avlTree);
    // insertInTree(&avlTree);
    // clearscreen();
    // avlTree.inorderTraversal();
    // cout << endl;
    // avlTree.saveToFile();
    getchar();
    return 0;
}