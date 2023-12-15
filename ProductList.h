#if !defined(ProductList_h)
#define ProductList_h
#include "Product.cpp"
class ProductList
{
private:
    Product *Head = nullptr;
    bool isPresent(int id);

public:
    ProductList();
    void Add_Product();
    void Show_Products();
    ~ProductList();
};
#endif // ProductList_h
