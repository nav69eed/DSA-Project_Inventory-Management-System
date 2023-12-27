#include "../ProductTree/ProductTree.cpp"
#include <queue>
void insertInTree(ProductTree *node)
{
    int choice;
    while (1)
    {
        node->insert();
    choice_for_another_prduct_addition:
        cout << "\nWant to add another Product (1 for Yes and 0 for No) : ";
        cin >> choice;
        if (choice == 1 || choice == 0)
        {
            if (choice == 1)
            {
                continue;
            }
            else
                break;
        }
        else
        {
            cout << "Wrong input!!!! Try again\n";
            goto choice_for_another_prduct_addition;
        }
    }
}

void showMenu(ProductTree *tree)
{
    cout << "**************************************************************************\n\n                          WELCOME TO STORE                      \n\n**************************************************************************\n";
    while (1)
    {
        int choice;
        cout << "Select any Option :\n";
        cout << "\t1.Show Available Products\n";
        cout << "\t2.Add a Product\n";
        cout << "\t3.Delete a Product\n";
        cout << "\t4.Save All Products to File\n";
        cout << "\t5.View Product Details\n";
        cout << "\t6.Update Product\n";
        cout << "\t7.Sell Product\n";
        cout << "\tEnter Your Choice : ";
        cin >> choice;
        if (choice >= 1 && choice <= 7)
        {
            if (choice == 1)
            {
                tree->inorderTraversal();
            }
            else if (choice == 2)
            {
                tree->insert();
            }
            else if (choice == 3)
            {
                tree->Delete();
            }
            else if (choice == 4)
            {
                tree->saveToFile();
            }
            else if (choice == 5)
            {
                tree->P_viewProductDetail();
            }
            else if (choice == 6)
            {
                tree->Update_Product();
            }
            else
            {
                int productId, temp, quantity;
                queue<Product *> myqueue;
                Product *node;
                queue<int> Quantity;
                do
                {
                    tree->inorderTraversal();
                    do
                    {
                        cout << "Enter Product Id : ";
                        cin >> productId;
                        if (tree->isPresentInTree(productId))
                        {
                            break;
                        }
                        else
                        {
                            cout << "Product Id is not Present in Stock !!!";
                            cout << " Try again\n";
                            continue;
                        }
                    } while (1);
                    node = tree->Search_Product(tree->root, productId);
                    do
                    {
                        cout << "Enter Quantity : ";
                        cin >> quantity;
                        if (quantity < 1 || (((node->Quantity_Remaining) - quantity) < 0))
                        {
                            continue;
                        }
                        else
                        {
                            node->Quantity_Remaining -= quantity;
                            break;
                        }
                    } while (1);
                    myqueue.push(node);
                    Quantity.push(quantity);
                    cout << "Do you want to Add another Product (1 or 0): ";
                    cin >> temp;
                    if (temp == 1)
                    {
                        continue;
                    }
                    else
                    {
                        clearscreen();
                        cout << "\n\n**************************PRINTING BILL**********************************\n\n";
                        int totalProducts = 0;
                        double TotalAmount = 0;
                        while (1)
                        {
                            if (myqueue.empty())
                            {
                                break;
                            }
                            else
                            {
                                node = myqueue.front();
                                quantity = Quantity.front();
                                cout << "Product name : " << node->Product_Name << "\t";
                                cout << "Product Quantity : " << quantity << "\t";
                                cout << "Products Price : Rs " << quantity * (node->Sale_Price) << "/-\n";
                                totalProducts++;
                                TotalAmount += quantity * (node->Sale_Price);
                                myqueue.pop();
                                Quantity.pop();
                                if (node->Quantity_Remaining == 0)
                                {
                                    if (node->Quantity_Remaining == 0)
                                    {
                                        tree->root = tree->deleteNode(tree->root, node->Product_ID);
                                    }
                                }
                            }
                        }
                        cout << "Total Products : " << totalProducts << "\t";
                        cout << "Total Amount : Rs " << TotalAmount << "/-\n";
                        cout << "\n\n**************************End of BILL**********************************\n\n";
                        break;
                    }
                } while (1);
            }
        }
        else
        {
            clearscreen();
            cout << "Wrong Choice!!!! Try again\n";
            showMenu(tree);
            // goto start_of_main_menu;
        }
        cout << "\n\n**************************************************************************\n\n";
    }
}
