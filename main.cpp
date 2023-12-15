#include "Helper_Functions.h"
#include "ProductList.cpp"
int main()
{
    ProductList List;
    List.Add_Product();
    List.Add_Product();
    List.Add_Product();
    List.Add_Product();
    clearscreen();
    List.Show_Products();
    getchar();
    return 0;
}