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
    do
    {
        cout << "Enter Product Id : ";
        cin >> productId;
        if (isPresentInTree(productId))
        {
            cout << "Product Id is Already Present in Stock !!!\n";
            cout << "Try again\n";
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
ProductTree::~ProductTree()
{
}