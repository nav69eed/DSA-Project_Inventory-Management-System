#if !defined(Product_h)
#define Product_h
#include <fstream>
#include "../HelperFunctions/helperFunctions.h"
class Product
{
private:
    int Quantity_Remaining, Quantity_Sold;
    string Product_Name, Brand_Name, Product_Category, Shelf_Location, Color;
    double Base_Price, Sale_Price, Discount, Discount_Percentage;
    string Manufacturing_Date, Date_Received, Expiry_Date;
    void calculate_Discount();
    void Add_Product_Details();
public:
    Product *Left;
    Product *Right;
    int Product_ID;
    void saveProductToFile();
    int height;
    void displayProductDetails();
    Product(int id);
    Product(int id,string name,double sPrice);
    ~Product();
};
#endif // Product_h
