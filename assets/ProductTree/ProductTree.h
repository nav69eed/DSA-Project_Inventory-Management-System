#if !defined(ProductTree_h)
#define ProductTree_h

#include "../Products/Product.cpp"
class ProductTree
{
private:
    Product *root;
    void updateHeight(Product *node);
    Product *rightRotate(Product *y);
    Product *leftRotate(Product *x);

    Product *insert(Product *node, int productId /*, other attributes as needed*/);
    void inorderTraversal(Product *node);
    int getBalance(Product *node);
    int getHeight(Product *node);
    bool isPresent(Product* node,int id);
    bool isPresentInTree(int id);
public:
    void insert();
    void inorderTraversal();
    ProductTree();
    ~ProductTree();
};
#endif // ProductTree_h
