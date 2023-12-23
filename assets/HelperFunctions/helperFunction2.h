#include "../ProductTree/ProductTree.cpp"
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
start_of_main_menu:
    cout << "**************************************************************************\n\n                          WELCOME TO STORE                      \n\n**************************************************************************\n";
    while (1)
    {
        int choice;
        cout << "Select any Option :\n";
        cout << "\t1.Show Available Products\n";
        cout << "\t2.Add a Product\n";
        cout << "\t3.Save All Products to Files\n";
        cout << "\tYour Choice : ";
        cin >> choice;
        if (choice >= 1 && choice <= 3)
        {
            if (choice == 1)
            {
                tree->inorderTraversal();
            }
            else if (choice == 2)
            {
                tree->insert();
            }
            else
            {
                tree->saveToFile();
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