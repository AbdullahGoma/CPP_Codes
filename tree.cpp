#include <iostream>
#include <string>

using namespace std;

struct Data
{
    string name;
    int degree[4];
    float average;
};

struct node
{
    int data;
    node* right = NULL;
    node* lift = NULL;
};

node* root = NULL;

node* insertnode(node* pnode,int item){
    if(pnode == NULL){
        node *newNode = new node;
        newNode -> data = item;
        pnode = newNode;
    }else if(item < pnode ->data){
        pnode -> lift = insertnode(pnode -> lift ,item);
    }else{
        pnode -> right = insertnode(pnode -> right ,item);
    }
    return pnode;
}

void insert(int item){
    root = insertnode(root,item);
}

void preOrder(node* pnode){ //root -> left -> right
    if(pnode == NULL){
        cout << "Tree is empty." << endl;
        return;
    }
    cout << pnode << "  ";
    preOrder(pnode -> lift);
    preOrder(pnode -> right);
}

void inOrder(node* pnode){ //left -> root -> right
    if(pnode == NULL){
        cout << "Tree is empty." << endl;
        return;
    }
    inOrder(pnode -> lift);
    cout << pnode << "  ";
    inOrder(pnode -> right);
}

void postOrder(node* pnode){ //left -> right -> root
    if(pnode == NULL){
        cout << "Tree is empty." << endl;
        return;
    }
    postOrder(pnode -> lift);
    postOrder(pnode -> right);
    cout << pnode << "  ";  
}

node* BSTsearsh(node* pnode,int key){
    if(pnode == NULL){
        cout << "Key not found." << endl;
        return NULL;
    }else if(pnode -> data == key){
        return pnode;
    }else if(key < pnode -> data){
        return BSTsearsh(pnode -> lift ,key);
    }else{
        return BSTsearsh(pnode -> right ,key);
    }
}

bool search(int key){
    node* result = BSTsearsh(root,key);
    if(result == NULL){
        return false;
    }else{
        return true;
    }
}

int main(){
    insert(45);
    insert(15);
    insert(79);
    insert(90);
    insert(10);
    insert(55);
    insert(12);
    insert(20);
    insert(50);

    cout << "Display tree is : " << endl;
    // preOrder(BST);
    // inOrder(BST);
    // postOrder(BST);
    bool find = search(55);
    if(find == true){
        cout << "FOUND." << endl;
    }else{
        cout << "not FOUND." << endl;
    }
    return 0;
}