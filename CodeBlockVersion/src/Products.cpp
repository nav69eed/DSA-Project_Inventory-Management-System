#include "Products.h"
Product::Product(int id)
{
    Product_ID = id;
    Quantity_Sold = 0;
    height = 1;
    Left = nullptr;
    Right = nullptr;
    Add_Product_Details();
}
Product::Product(int productId, string name, string brand_name, string color, string Product_Category, string shelf_location, double base_price, double sale_price, double discount, double discount_percentage, int q_remaining, int q_sold, string M_date, string R_date, string E_date /*, other attributes as needed*/)
{
    height = 1;
    Left = nullptr;
    Right = nullptr;
    Product_ID = productId;
    Product_Name = name;
    Brand_Name = brand_name;
    Color = color;
    this->Product_Category = Product_Category;
    Shelf_Location = shelf_location;
    Base_Price = base_price;
    Sale_Price = sale_price;
    Discount = discount;
    Discount_Percentage = discount_percentage;
    Quantity_Remaining = q_remaining;
    Quantity_Sold = q_sold;
    Manufacturing_Date = M_date;
    Date_Received = R_date;
    Expiry_Date = E_date;
}

void Product::Add_Product_Details()
{
    cin.ignore();
    cout << "Enter Product Name : ";
    getline(cin, Product_Name);
    cout << "Enter Brand Name : ";
    getline(cin, Brand_Name);
    cout << "Enter Product Catagory : ";
    getline(cin, Product_Category);
    cout << "Enter Base Price : ";
    cin >> Base_Price;
    cout << "Enter Discount Percentage : ";
    cin >> Discount_Percentage;
    calculate_Discount();
    cout << "Enter Shelf Location : ";
    cin.ignore();
    getline(cin, Shelf_Location);
    cout << "Enter Color : ";
    cin >> Color;
    cout << "Enter Current Stock :  ";
    cin >> Quantity_Remaining;
    cout << "Enter Manufacturing Date : ";
    cin >> Manufacturing_Date;
    cout << "Enter Expiry Date : ";
    cin >> Expiry_Date;
    cout << "Enter Date Received : ";
    cin >> Date_Received;
}
void Product::calculate_Discount()
{
    Discount = (Discount_Percentage / 100) * Base_Price;
    Sale_Price = (Base_Price) - (Discount);
}
void Product::displayProductDetails()
{
    cout << "Product ID: " << Product_ID << "\t";
    cout << "Product Name: " << Product_Name << "\t";
    cout << "Product Brand Name: " << Brand_Name << "\t";
    cout << "Stock Remaining: " << Quantity_Remaining << endl;
    cout << "\n";
}

void Product::saveProductToFile()
{
    ofstream OutFile("Products.txt", ios::app | ios::out);
    if (OutFile.is_open())
    {
        OutFile << "****************************" << endl;
        OutFile << Product_ID << endl;
        OutFile << Product_Name << endl;
        OutFile << Brand_Name << endl;
        OutFile << Color << endl;
        OutFile << Product_Category << endl;
        OutFile << Shelf_Location << endl;
        OutFile << Base_Price << endl;
        OutFile << Sale_Price << endl;
        OutFile << Discount << endl;
        OutFile << Discount_Percentage << endl;
        OutFile << Quantity_Remaining << endl;
        OutFile << Quantity_Sold << endl;
        OutFile << Manufacturing_Date << endl;
        OutFile << Date_Received << endl;
        OutFile << Expiry_Date << endl;
        OutFile.close();
    }
    else
    {
        cout << "\n\nFile Write Opening Error!!!!!\n";
    }
}
void Product::showProductDetails()
{
    CLS();
    cout << "\n\n********************DISPLAYING SINGLE PRODUCT DETAIL********************\n\n";
    cout << "Product ID: " << Product_ID << endl;
    cout << "Product Name: " << Product_Name << endl;
    cout << "Brand Name: " << Brand_Name << endl;
    cout << "Product Category: " << Product_Category << endl;
    cout << "Shelf Location: " << Shelf_Location << endl;
    cout << "Color: " << Color << endl;
    cout << "Base Price: " << Base_Price << endl;
    cout << "Sale Price: " << Sale_Price << endl;
    cout << "Discount: " << Discount << endl;
    cout << "Discount Percentage: " << Discount_Percentage << endl;
    cout << "Manufacturing Date: " << Manufacturing_Date << endl;
    cout << "Date Received: " << Date_Received << endl;
    cout << "Expiry Date: " << Expiry_Date << endl;
    cout << "Current Stock: " << Quantity_Remaining << endl;
    cout << "Quantity Sold: " << Quantity_Sold << endl;
    cout << "\n\n************************** END PRODUCT *************************\n\n";
}
void Product::CLS()
{
    system("cls");
}
Product::~Product()
{
}
