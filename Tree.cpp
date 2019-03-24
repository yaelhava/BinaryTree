#include "Tree.hpp"
using namespace ariel;


int Tree::size(){
    return Tree::treeSize;
}

Tree& Tree::insert(int i){ 
    if(Tree::head == NULL){
        head = new node(i);
        Tree::treeSize++;
        return *this;
    }
    else if(this->contains(i)){
        throw runtime_error("ALREADY EXIST");
    }
    else{
        insert(i, Tree::head);
        return *this;
    }
    
}

void Tree::insert(int i, struct node* n){
    if(i < n->node::getValue()){
        if (n->getLeft() != NULL) {
            insert(i, n->getLeft());
        }
        else{
           n->setLeft(new node(i));
           Tree::treeSize++;
        }  
    }
    else if(i > n->node::getValue()){
        if (n->getRight() != NULL) {
            insert(i, n->getRight());
        }
        else{
            n->setRight(new node(i)) ;
            Tree::treeSize++;
        }  
    }   
}

int Tree::root(){
   return Tree::head->node::getValue(); 
}


bool Tree::contains(int i){
    if(Tree::head == NULL){
        return false;
    }
    else if(Tree::head->getValue() == i){
        return true;
    }
    struct node* temp = smallOrLarge(i, Tree::head);
    while(temp != NULL){
        if(temp->getValue() == i){
            return true;
        }
        temp = smallOrLarge(i, temp);
    }
    return false;   
}


struct node* Tree::smallOrLarge(int i, struct node* node){
    if (i < node->getValue()){
        return node->getLeft();
    }
       // i > node->getValue())
    return node->getRight();
        
}

int Tree::parent(int i){
    if(!this->contains(i)){
        throw runtime_error("NOT EXIST");
    }
    if(Tree::head->getValue() == i){
        throw runtime_error("ROOT- DOESN'T HAVE PARENT");
    }
    struct node* first = Tree::head;
    struct node* second = smallOrLarge(i, Tree::head);
    while(second->getValue() != i){
        first = second;
        second = smallOrLarge(i, second);
    }
    return first->getValue();
}


int Tree::left(int i){
    if(!this->contains(i)){
        throw runtime_error("NOT EXIST");
    }
    if(Tree::head->getValue() == i){
        if(Tree::head->getLeft() == NULL){
        throw runtime_error("DOESN'T HAVE LEFT CHILDE");
        }
        return Tree::head->getLeft()->getValue();
    }
    struct node* temp = smallOrLarge(i, Tree::head);
    while(temp->getValue() != i){
        temp = smallOrLarge(i, temp);
    }
    if(temp->getLeft() == NULL){
        throw runtime_error("DOESN'T HAVE LEFT CHILDE");
    }
    return temp->getLeft()->getValue();
}


int Tree::right(int i){
    if(!this->contains(i)){
        throw runtime_error("NOT EXIST");
    }
    if(Tree::head->getValue() == i){
        if(Tree::head->getRight() == NULL){
        throw runtime_error("DOESN'T HAVE RIGHT CHILDE");
    }
        return Tree::head->getRight()->getValue();
    }
    struct node* temp = smallOrLarge(i, Tree::head);
    while(temp->getValue() != i){
        temp = smallOrLarge(i, temp);
    }
    if(temp->getRight() == NULL){
        throw runtime_error("DOESN'T HAVE RIGHT CHILDE");
    }
    return temp->getRight()->getValue();
}


void Tree::print(){
    if(Tree::head == NULL){
        throw runtime_error("TREE IS EMPTY");
    }
    print(Tree::head);
}

void Tree::print(struct node* node){
    if(node != NULL){
        print(node->getLeft());
    
    cout << node->getValue() << " ";
    print(node->getRight());
    }
}


 void Tree::remove(int i){
     
 }


// int main(){
//     Tree t;
//     cout << "size:" << t.size() << endl;
//     t.insert(3);
//     cout << "size:" << t.size() << endl;
//     cout << "root:" << t.root() << endl;
//     t.insert(2);
//     t.insert(4);
//     t.insert(12);
//     t.insert(11);
//     t.insert(32);
//     //t.insert(32);
//     cout << "size:" << t.size() << endl;
//     t.insert(5).insert(6);
//     cout << "size:" << t.size() << endl;
//     cout << t.contains(5) << endl;
//     cout << t.left(12) << endl;
//     cout << t.right(12) << endl;
//     cout << t.parent(32) << endl;
//     t.print();
//     cout << endl;
//     return 0;
// }
