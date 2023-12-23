#include "ProductTree.h"
ProductTree::ProductTree(/* args */)
{
    root = nullptr;
}

void ProductTree::updateHeight(Product *node)
{
    if (node != nullptr)
    {
        node->height = 1 + max(getHeight(node->Left), getHeight(node->Right));
    }
}
Product *ProductTree::rightRotate(Product *y)
{
    Product *x = y->Left;
    Product *T2 = x->Right;

    // Perform rotation
    x->Right = y;
    y->Left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}
Product *ProductTree::leftRotate(Product *x)
{
    Product *y = x->Right;
    Product *T2 = y->Left;

    // Perform rotation
    y->Left = x;
    x->Right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

Product *ProductTree::insert(Product *node, int Product_ID /*, other attributes as needed*/)
{
    // Perform standard BST insertion
    if (node == nullptr)
        return new Product(Product_ID /*, other attributes as needed*/);

    if (Product_ID < node->Product_ID)
    {
        node->Left = insert(node->Left, Product_ID /*, other attributes as needed*/);
    }
    else if (Product_ID > node->Product_ID)
    {
        node->Right = insert(node->Right, Product_ID /*, other attributes as needed*/);
    }
    else
    {
        // Duplicate keys are not allowed
        return node;
    }

    // Update height of current node
    updateHeight(node);

    // Get the balance factor
    int balance = getBalance(node);

    // Perform rotations if necessary
    if (balance > 1 && Product_ID < node->Left->Product_ID)
    {
        return rightRotate(node);
    }
    if (balance < -1 && Product_ID > node->Right->Product_ID)
    {
        return leftRotate(node);
    }
    if (balance > 1 && Product_ID > node->Left->Product_ID)
    {
        node->Left = leftRotate(node->Left);
        return rightRotate(node);
    }
    if (balance < -1 && Product_ID < node->Right->Product_ID)
    {
        node->Right = rightRotate(node->Right);
        return leftRotate(node);
    }

    return node;
}
Product *ProductTree::insert(Product *node, int Product_ID, string name, double sPrice /*, other attributes as needed*/)
{
    // Perform standard BST insertion
    if (node == nullptr)
        return new Product(Product_ID, name, sPrice /*, other attributes as needed*/);

    if (Product_ID < node->Product_ID)
    {
        node->Left = insert(node->Left, Product_ID, name, sPrice /*, other attributes as needed*/);
    }
    else if (Product_ID > node->Product_ID)
    {
        node->Right = insert(node->Right, Product_ID, name, sPrice /*, other attributes as needed*/);
    }
    else
    {
        // Duplicate keys are not allowed
        return node;
    }

    // Update height of current node
    updateHeight(node);

    // Get the balance factor
    int balance = getBalance(node);

    // Perform rotations if necessary
    if (balance > 1 && Product_ID < node->Left->Product_ID)
    {
        return rightRotate(node);
    }
    if (balance < -1 && Product_ID > node->Right->Product_ID)
    {
        return leftRotate(node);
    }
    if (balance > 1 && Product_ID > node->Left->Product_ID)
    {
        node->Left = leftRotate(node->Left);
        return rightRotate(node);
    }
    if (balance < -1 && Product_ID < node->Right->Product_ID)
    {
        node->Right = rightRotate(node->Right);
        return leftRotate(node);
    }

    return node;
}

void ProductTree::inorderTraversal(Product *node)
{
    if (node != nullptr)
    {
        inorderTraversal(node->Left);
        node->displayProductDetails(); // Display or process the product information
        inorderTraversal(node->Right);
    }
}

// Public function to insert a product into the AVL tree
void ProductTree::insert()
{
    int productId;
    cout << "\n**************ADDING PRODUCT*****************\n";
    do
    {
        cout << "Enter Product Id : ";
        cin >> productId;
        if (isPresentInTree(productId))
        {
            cout << "Product Id is Already Present in Stock !!!";
            cout << " Try again\n";
            continue;
        }
        else
            break;
    } while (1);
    root = insert(root, productId);
}

// Public function to perform an inorder traversal of the AVL tree
void ProductTree::inorderTraversal()
{
    inorderTraversal(root);
}
int ProductTree::getBalance(Product *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->Left) - getHeight(node->Right);
}
int ProductTree::getHeight(Product *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

bool ProductTree::isPresent(Product *node, int id)
{
    if (node == nullptr)
    {
        return false;
    }

    if (id < node->Product_ID)
    {
        return isPresent(node->Left, id);
    }
    else if (id > node->Product_ID)
    {
        return isPresent(node->Right, id);
    }
    else
    {
        return true;
    }
}
bool ProductTree::isPresentInTree(int id)
{
    return isPresent(root, id);
}
Product *ProductTree::saveSingleProduct(Product *node)
{
    if (node != nullptr)
    {
        saveSingleProduct(node->Left);
        node->saveProductToFile(); // Display or process the product information
        saveSingleProduct(node->Right);
    }
}

void ProductTree::saveToFile()
{
    ofstream outFile("Products.txt", ios::out | ios::trunc);
    outFile.close();
    saveSingleProduct(root);
}

void ProductTree::loadFromFile()
{
    int id;
    string name, sample, sample1;
    double sPrice;
    ifstream inFile("Products.txt", ios::in);
    if (inFile.is_open())
    {
        while (getline(inFile, sample))
        {
            getline(inFile, sample);
            getline(inFile, name);
            getline(inFile, sample1);
            id = stoi(sample);
            sPrice = stod(sample1);
            root = insert(root, id, name, sPrice);
        }
        inFile.close();
    }
    else
    {
        cout << "Loading Product File Opening Error!!!\n";
    }
}
Product *ProductTree::deleteNode(Product *root, int Product_ID)
{
    // Perform standard BST deletion
    if (root == nullptr)
        return root;

    if (Product_ID < root->Product_ID)
        root->Left = deleteNode(root->Left, Product_ID);
    else if (Product_ID > root->Product_ID)
        root->Right = deleteNode(root->Right, Product_ID);
    else
    {
        // Node with only one child or no child
        if (root->Left == nullptr || root->Right == nullptr)
        {
            Product *temp = (root->Left) ? root->Left : root->Right;

            // No child case
            if (temp == nullptr)
            {
                temp = root;
                root = nullptr;
            }
            else               // One child case
                *root = *temp; // Copy the contents of the non-empty child

            delete temp;
        }
        else
        {
            // Node with two children, get the inorder successor
            Product *temp = minValueNode(root->Right);

            // Copy the inorder successor's data to this node
            root->Product_ID = temp->Product_ID;

            // Delete the inorder successor
            root->Right = deleteNode(root->Right, temp->Product_ID);
        }
    }

    // If the tree had only one node, then return
    if (root == nullptr)
        return root;

    // Update height of the current node
    updateHeight(root);

    // Get the balance factor
    int balance = getBalance(root);

    // Perform rotations if necessary
    if (balance > 1 && getBalance(root->Left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->Left) < 0)
    {
        root->Left = leftRotate(root->Left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->Right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->Right) > 0)
    {
        root->Right = rightRotate(root->Right);
        return leftRotate(root);
    }

    return root;
}

Product *ProductTree::minValueNode(Product *node)
{
    Product *current = node;

    // Find the leftmost leaf
    while (current->Left != nullptr)
        current = current->Left;

    return current;
}

void ProductTree::Delete()
{
    int productId;
    cout << "\n\n**************Deleting PRODUCT*****************\n\n";
    inorderTraversal(root);
    do
    {
        cout << "Enter Product Id : ";
        cin >> productId;
        if (isPresentInTree(productId))
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
    root = deleteNode(root, productId);
}

ProductTree::~ProductTree()
{
}
