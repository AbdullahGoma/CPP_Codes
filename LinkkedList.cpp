#include <iostream>
#include <string>

using namespace std;

struct Data{
    string name;
    float average;
    int degree[4];
};

struct node{
    int data;
    node* next;
};

node* head = NULL;

void insertnode(int key){
    node* newNode,*last;
    newNode = new node;
    newNode -> data = key;
    if(head == NULL){
        head = newNode;
        newNode -> next = NULL;
    }else{
        last = head;
        while (last -> next != NULL)
        {
            last = last -> next;
        }
        last -> next = newNode;
        newNode -> next = NULL;
    }
}

void display(){
    node* currNode;
    if(head == NULL){
        cout << "The list is empty." << endl;
    }else if(head -> next == NULL){
        cout << head -> data;
    }else{
        currNode = head;
        while(currNode != NULL){
            cout << currNode -> data << "  ";
            currNode = currNode -> next;
        }
    }
}

void deleteLast(){
    node* currNode;
    currNode = head;
    if(head == NULL){
        cout << "The list is empty." << endl;
        return;
    }else if (head -> next == NULL)
    {
        free(head);
        head == NULL;
        return;
    }else{
        currNode = head;
        while(currNode -> next -> next != NULL){
            currNode = currNode -> next;
        }
        free(currNode -> next);
        currNode -> next = NULL;
    }   
}

void deletebeginning()
{
    if(head == NULL)
    {
        cout << "There is no node in the list." << endl;
    }
    else
    {
        node* firstNode = head;
        head = firstNode -> next;
        free(firstNode);
    }
}

void deleteanyNode(int key){
    node* curr,*prev;
    curr = head;
    prev = head;
    if(head == NULL){
        cout << "The list is empty." << endl;
    }else if(curr -> data == key){
        head = curr -> next;
        free(curr);
    }
    while(curr -> data != key){
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    free(curr);

}

void sortList(node** head)
{
    node* prev = (*head);
    node* curr = (*head) -> next;
  
    while (curr != NULL)
    {
        if (curr -> data < prev -> data)
        {
            prev -> next = curr -> next;
            curr -> next = (*head);
            (*head) = curr;
            curr = prev;
        }
  
        else
            prev = curr;
        curr = curr -> next;
    }
}


int main(){
    insertnode(5);
    insertnode(10);
    insertnode(15);
    insertnode(20);
    //display();
    // cout << endl;
    // deleteLast();
    // display();
    // cout << endl;
    // deletebeginning();
    // display();
    // cout << endl;
    // deleteanyNode(10);
    display();
}