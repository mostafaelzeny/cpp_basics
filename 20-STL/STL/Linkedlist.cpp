#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct Node{
int value;
 Node *next;

};

struct Node* createNode(int data)
{
    struct Node* newnode = new Node;
    newnode->value = data;
    newnode->next = NULL;
    return newnode;
}
void insertatend(int data)
{
   struct Node* newend = new Node;
   newend->value = data;
   newend->next = *newnode ;

   



}


int main()
{
    struct Node* head = NULL;



    return 0;
}