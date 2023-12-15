#include "ProductList.h"
ProductList::ProductList()
{
}

ProductList::~ProductList()
{
}
void ProductList::Add_Product()
{
    Product *newProduct = new Product;
    newProduct->nextProduct = nullptr;
    if (Head == nullptr)
    {
        Head = newProduct;
    }
    else
    {
        Product *ptr = Head;
        while (ptr->nextProduct != nullptr)
        {
            ptr = ptr->nextProduct;
        }
        ptr->nextProduct = newProduct;
    }
}
void ProductList::Show_Products()
{
    Product *ptr = Head;
    while (ptr != nullptr)
    {
        ptr->displayProductDetails();
        ptr = ptr->nextProduct;
    }
}
