#if !defined(ProductTree_h)
#define ProductTree_h

#include "Products.h"
class ProductTree
{
private:
    void updateHeight(Product *node);
    Product *rightRotate(Product *y);
    Product *leftRotate(Product *x);
    Product *minValueNode(Product *node);

    Product *insert(Product *node, int productId /*, other attributes as needed*/);
    Product *insert(Product *node, int Product_ID, string name, string brand_name, string color, string Product_Category, string shelf_location, double base_price, double sale_price, double discount, double discount_percentage, int q_remaining, int q_sold, string M_date, string R_date, string E_date /*, other attributes as needed*/);
    void inorderTraversal(Product *node);
    int getBalance(Product *node);
    int getHeight(Product *node);
    bool isPresent(Product *node, int id);
    Product *saveSingleProduct(Product *node);

public:
    Product *deleteNode(Product *root, int Product_ID);
    Product *root;
    Product *Search_Product(Product *node, int P_id);
    bool isPresentInTree(int id);
    void insert();
    int max(int a, int b);
    void Delete();
    void saveToFile();
    void loadFromFile();
    void inorderTraversal();
    void P_viewProductDetail();
    void Update_Product();
    ProductTree();
    ~ProductTree();
};
#endif // ProductTree_h
