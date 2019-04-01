#include "Tree.hpp"
using namespace ariel;

int Tree::size()
{
    return Tree::treeSize;
}

Tree &Tree::insert(int i)
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

int Tree::root()
{
    if (head == NULL)
    {
        throw runtime_error("THE TREE IS EMPTY");
    }
    return head->getValue();
}

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

struct node *Tree::smallOrLarge(int i, struct node *node)
{
    if (i < node->getValue())
    {
        return node->getLeft();
    }
    return node->getRight();
}

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

int Tree::left(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("NOT EiIST");
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

void Tree::print()
{
    if (Tree::head == NULL)
    {
        throw runtime_error("TREE IS EMPTY");
    }
    print(Tree::head);
}

void Tree::print(struct node *node)
{
    if (node != NULL)
    {
        print(node->getLeft());
        cout << node->getValue() << " ";
        print(node->getRight());
    }
}

bool Tree::isRight(struct node *node, struct node *parent)
{
    if (parent->getValue() > node->getValue())
    {
        return false;
    }
    return true;
}

struct node *Tree::findMin(struct node *t)
{
    if (t == NULL)
        return NULL;
    else if (t->getLeft() == NULL)
        return t;
    else
        return findMin(t->getLeft());
}

void Tree::remove(int i)
{
    if (!this->contains(i))
    {
        throw runtime_error("DOESN'T EXIST");
    }
    if (head->getValue() == i) // Case 1, root contain the data.
    {
        if (head->getRight() == NULL && head->getLeft() == NULL)
        { // No children
            delete head;
            head = NULL;
        }
        
        else if (head->getRight() == NULL && head->getLeft() != NULL)
        { // Left child
            struct node *temp = head->getLeft();
            delete head;
            head = temp;
        }
        else if (head->getRight() != NULL && head->getLeft() == NULL)
        { // Right child
            struct node *temp = head->getRight();
            delete head;
            head = temp;
        }
        else
        {                                                // Root has 2 children
            struct node *max = maxNode(head->getLeft()); // Search on left tree max data value
            int maxData = max->getValue();
            remove(maxData);         // Remove the max data that we found
            head->setValue(maxData); // Set root to be the max data
            treeSize++;              // Just because we remove "twice"
        }
    }
    head = remove(i, head);
    treeSize--;
}

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

struct node *Tree::maxNode(struct node *root)
{
    while (root->getRight() != NULL)
    {
        root = root->getRight();
    }
    return root;
}

Tree::~Tree(){
    deleteTree(head);
}

 void Tree::deleteTree(node *nodee)
{
    if(nodee !=NULL) {
        deleteTree(nodee->getLeft());
        deleteTree(nodee->getRight());
        delete nodee;
    }

}


// int main(){
//     Tree t;
//     cout << "size:" << t.size() << endl;
//     t.insert(3);
//     cout << "size:" << t.size() << endl;
//     cout << "root:" << t.root() << endl;
//     t.insert(2);
//     t.insert(4);
//      t.insert(10);
//     t.insert(12);
//     t.insert(11);
//     t.insert(32);

//     cout << "size:" << t.size() << endl;
//     t.insert(5).insert(6);
//     cout << "size:" << t.size() << endl;
//     cout << t.contains(5) << endl;
//     cout << t.left(12) << endl;
//     cout << t.right(12) << endl;
//     cout << t.parent(32) << endl;
//     t.print();
//     cout << endl;
//   //  t.print();
//     t.remove(3);
//     t.print();
//     cout << endl;
//    // cout << "2 removed" << endl;

//     return 0;
// }
