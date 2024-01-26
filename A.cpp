#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct node
{
    int data;
    node *next;
};

node *head = NULL;
void Insertnum(int current)
{
    node *newnode = new node;
    newnode->data = current;
    newnode->next = head;
    head = newnode;
}
void dispaly()
{
    node *temp = head;
    if (temp != NULL)
    {
        cout << "The list contains: " << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }
    else
        cout << "the list is empty\n";
}
int main()
{
    node n;
    Insertnum(5);
    Insertnum(8);
    Insertnum(10);
    dispaly();

    return 0;
}