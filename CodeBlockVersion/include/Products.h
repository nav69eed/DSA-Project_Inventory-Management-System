#if !defined(Product_h)
#define Product_h
#include <fstream>
#include <cstdlib>
#include "helperfunctions.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
class Product
{
private:
    string Brand_Name, Product_Category, Shelf_Location, Color;
    double Base_Price, Discount_Percentage;
    string Manufacturing_Date, Date_Received, Expiry_Date;
    void calculate_Discount();
    void Add_Product_Details();

public:
    string Product_Name;
    double Sale_Price, Discount;
    int Quantity_Remaining, Quantity_Sold;
    Product *Left;
    Product *Right;
    int Product_ID;
    void saveProductToFile();
    int height;
    void displayProductDetails();
    Product(int id);
    Product(int productId, string name, string brand_name, string color, string Product_Category, string shelf_location, double base_price, double sale_price, double discount, double discount_percentage, int q_remaining, int q_sold, string M_date, string R_date, string E_date);
    void showProductDetails();
    void CLS();
    ~Product();
};
#endif // Product_h
