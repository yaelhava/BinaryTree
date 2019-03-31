#include <iostream>
using namespace std;


struct node{
    private:
    int value;
    struct node* left;
    struct  node* right; 

    public: 
    node(int v){
        value = v;
    }
    
    int getValue(){
        return value;
    }

    struct node* getLeft(){
        return left;
    }
    
    struct node* getRight(){
        return right;
    }

    void setLeft(struct node* temp){
        left = temp;
    }

    void setRight(struct node* temp){
        right = temp;
    }

};

namespace ariel{

    class Tree{

        private:
        struct node* head;
        int treeSize;

        void insert(int i, struct node* node);
        struct node* smallOrLarge(int i, struct node* node);
        void print(struct node* node);
        struct node* deleteTree(struct node* node);
        void remove(int i, struct node* node, struct node* parent);
        bool isRight(struct node* node, struct node* parent);
        

        public:
        Tree(){ 
            head = NULL;
            treeSize = 0;
        }
        ~Tree();
        Tree& insert(int i);
        void remove(int i);
        int size(); 
        bool contains(int i);
        int root(); 
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();

    };
}
