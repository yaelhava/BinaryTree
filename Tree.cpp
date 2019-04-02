#include "Tree.hpp"
using namespace ariel;

//returns the size of the tree
int Tree::size()
{
    return Tree::treeSize;
}

//add a leaf to the tree
Tree& Tree::insert(int i)
{
    if (head == NULL)
    {
        head = new struct node(i);
        treeSize++;
    }
    else if (this->contains(i))
    {
        throw runtime_error("ALREADY EiIST");
    }
    else
    {
        insert(i, head);
    }

    return *this;
}

//help method for insert method
void Tree::insert(int i, struct node *n)
{
    if (i < n->getValue())
    {
        if (n->getLeft() != NULL)
        {
            insert(i, n->getLeft());
        }
        else
        {
            n->setLeft(new struct node(i));
            treeSize++;
        }
    }
    else if (i > n->getValue())
    {
        if (n->getRight() != NULL)
        {
            insert(i, n->getRight());
        }
        else
        {
            n->setRight(new struct node(i));
            treeSize++;
        }
    }
}

//returns the value of the root of the tree
int Tree::root()
{
    if (head == NULL)
    {
        throw runtime_error("THE TREE IS EMPTY");
    }
    return head->getValue();
}


//check if the node exsits in the tree
bool Tree::contains(int i)
{
    if (head == NULL)
    {
        return false;
    }
    else if (head->getValue() == i)
    {
        return true;
    }
    struct node *temp = smallOrLarge(i, Tree::head);
    while (temp != NULL)
    {
        if (temp->getValue() == i)
        {
            return true;
        }
        temp = smallOrLarge(i, temp);
    }
    return false;
}


//returns thr right child if the value is bigger' and the left child if the 
//value is smaller
struct node *Tree::smallOrLarge(int i, struct node *node)
{
    if (i < node->getValue())
    {
        return node->getLeft();
    }
    return node->getRight();
}


//returns the parent of this node
int Tree::parent(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("NOT EiIST");
    }
    if (Tree::head->getValue() == i)
    {
        throw runtime_error("ROOT- DOESN'T HAVE PARENT");
    }
    struct node *first = Tree::head;
    struct node *second = smallOrLarge(i, Tree::head);
    while (second->getValue() != i)
    {
        first = second;
        second = smallOrLarge(i, second);
    }
    return first->getValue();
}


//returns the left child of this node
int Tree::left(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("NOT EXIST");
    }
    if (Tree::head->getValue() == i)
    {
        if (Tree::head->getLeft() == NULL)
        {
            throw runtime_error("DOESN'T HAVE LEFT CHILDE");
        }
        return Tree::head->getLeft()->getValue();
    }
    struct node *temp = smallOrLarge(i, Tree::head);
    while (temp->getValue() != i)
    {
        temp = smallOrLarge(i, temp);
    }
    if (temp->getLeft() == NULL)
    {
        throw runtime_error("DOESN'T HAVE LEFT CHILDE");
    }
    return temp->getLeft()->getValue();
}


//returns the right child of this node
int Tree::right(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("NOT EiIST");
    }
    if (Tree::head->getValue() == i)
    {
        if (Tree::head->getRight() == NULL)
        {
            throw runtime_error("DOESN'T HAVE RIGHT CHILDE");
        }
        return Tree::head->getRight()->getValue();
    }
    struct node *temp = smallOrLarge(i, Tree::head);
    while (temp->getValue() != i)
    {
        temp = smallOrLarge(i, temp);
    }
    if (temp->getRight() == NULL)
    {
        throw runtime_error("DOESN'T HAVE RIGHT CHILDE");
    }
    return temp->getRight()->getValue();
}

//prints the tree in inorder
void Tree::print()
{
    if (Tree::head == NULL)
    {
        throw runtime_error("TREE IS EMPTY");
    }
    print(Tree::head);
}


//help method for print method
void Tree::print(struct node *node)
{
    if (node != NULL)
    {
        print(node->getLeft());
        cout << node->getValue() << " ";
        print(node->getRight());
    }
}


//check if the node is right child  or left child
bool Tree::isRight(struct node *node, struct node *parent)
{
    if (parent->getValue() > node->getValue())
    {
        return false;
    }
    return true;
}


//delete the from the tree
void Tree::remove(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("DOESN'T EXIST");
    }
    if(head->getValue() == i) 
    {
        if(head->getRight() == NULL && head->getLeft() == NULL)
        {
            delete head;
            head = NULL;
        }
        else if(head->getLeft() != NULL && head->getRight() == NULL)
        { 
            node *temp = head->getLeft();
            delete head;
            head = temp;
        }
        else if(head->getRight() != NULL && head->getLeft() == NULL)
        { 
            node *temp = head->getRight();
            delete head;
            head = temp;
        }
        else
        {            
            struct node* min = findMin(head->getRight());
            int minVal = min->getValue();
            remove(minVal);
            treeSize++;
            head->setValue(minVal);
        }
    }
    head = remove(i, head);
    treeSize--;
}


//help method for remove method
struct node *Tree::remove(int i, struct node *t)
{

    struct node *temp;
    if (t == NULL)
        return NULL;

    else if (i < t->getValue())
        t->setLeft(remove(i, t->getLeft()));
    else if (i > t->getValue())
        t->setRight(remove(i, t->getRight()));
    else if (t->getLeft() && t->getRight())
    {
        temp = findMin(t->getRight());
        t->setValue(temp->getValue());
        t->setRight(remove(t->getValue(), t->getRight()));
    }
    else
    {
        temp = t;
        if (t->getLeft() == NULL)
            t = t->getRight();
        else if (t->getRight() == NULL)
            t = t->getLeft();
        delete temp;
    }

    return t;
}


//find the minimum node under that node
struct node* Tree::findMin(struct node* node)
{
    while (node->getLeft() != NULL)
    {
        node = node->getLeft();
    }
    return node;
}


//destructor
Tree::~Tree()
{
    deleteTree(head);
}


//help method for the destructor
void Tree::deleteTree(node *nodee)
{
    if (nodee != NULL)
    {
        deleteTree(nodee->getLeft());
        deleteTree(nodee->getRight());
        delete nodee;
    }
}


