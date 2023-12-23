#include "assets/HelperFunctions/helperFunction2.h"
int main()
{
    ProductTree avlTree;
    insertInTree(&avlTree);
    clearscreen();
    avlTree.inorderTraversal();
    cout << endl;
    getchar();
    return 0;
}