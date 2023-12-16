#include "ProductList.h"
ProductList::ProductList()
{
}

ProductList::~ProductList()
{
}
bool ProductList::isPresent(int id)
{
    Product *ptr = Head;
    while (ptr != nullptr)
    {
        if (id == ptr->get_Product_ID())
        {
            return true;
        }
        ptr = ptr->nextProduct;
    }
    return false;
}
void ProductList::Add_Product()
{
    cout << "\n\n********ADDING PRODUCT**********\n\n";
    int Product_ID;
    do
    {
        cout << "Enter Product ID: ";
        cin >> Product_ID;
    } while (isPresent(Product_ID));

    Product *newProduct = new Product(Product_ID);
    newProduct->nextProduct = nullptr;

    if (Head == nullptr || Head->get_Product_ID() > Product_ID)
    {
        newProduct->nextProduct = Head;
        Head = newProduct;
    }
    else
    {
        Product *ptr = Head;

        while (ptr->nextProduct != nullptr && ptr->nextProduct->get_Product_ID() < Product_ID)
        {
            ptr = ptr->nextProduct;
        }

        newProduct->nextProduct = ptr->nextProduct;
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
