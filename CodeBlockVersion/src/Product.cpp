#include "Product.h"
Product::Product(int id)
{
    Product_ID = id;
    height = 1;
    Left = nullptr;
    Right = nullptr;
    Add_Product_Details();
}
Product::Product(int id, string name, double sPrice)
{
    Product_ID = id;
    height = 1;
    Left = nullptr;
    Right = nullptr;
    Product_Name = name;
    Sale_Price = sPrice;
}

void Product::Add_Product_Details()
{
    cout << "Enter Product Name : ";
    cin.ignore();
    getline(cin, Product_Name);
    // cout << "Enter Brand Name : ";
    // cin.ignore();
    // getline(cin, Brand_Name);
    cout << "Enter Base Price : ";
    cin >> Base_Price;
    cout << "Enter Discount Percentage : ";
    cin >> Discount_Percentage;
    calculate_Discount();
    // cout << "Enter Shelf Location : ";
    // cin.ignore();
    // getline(cin, Shelf_Location);
    // cout << "Enter Color : ";
    // cin >> Color;
    // cout << "Enter Quantity Remaining:  ";
    // cin >> Quantity_Remaining;
    // cout << "Enter Manufacturing Date : ";
    // cin >> Manufacturing_Date;
    // cout << "Enter Expiry Date : ";
    // cin >> Expiry_Date;
    // cout << "Enter Date Received : ";
    // cin >> Date_Received;
}
void Product::calculate_Discount()
{
    Discount = (Discount_Percentage / 100) * Base_Price;
    Sale_Price = (Base_Price) - (Discount);
}
void Product::displayProductDetails()
{
    cout << "\n\n*************DISPLAYING PRODUCT**************\n\n";
    cout << "Product ID: " << Product_ID << endl;
    cout << "Product Name: " << Product_Name << endl;
    cout << "Product Sale Price: Rs " << Sale_Price << "/-" << endl;
}

void Product::saveProductToFile()
{
    ofstream OutFile("Products.txt", ios::app | ios::out);
    if (OutFile.is_open())
    {
        OutFile << "****************************" << endl;
        OutFile << Product_ID << endl;
        OutFile << Product_Name << endl;
        OutFile << Sale_Price << endl;
        OutFile.close();
    }
    else
    {
        cout << "\n\nFile Write Opening Error!!!!!\n";
    }
}

Product::~Product()
{
}
