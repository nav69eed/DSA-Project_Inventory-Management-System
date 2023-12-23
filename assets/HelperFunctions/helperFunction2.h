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