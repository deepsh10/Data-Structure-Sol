#include "iostream"
#include "string"

struct Node{
    int data;
    Node* next;
};

struct Node* newNode(int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main(int argc, char** argv) {
    struct Node* n1 = newNode(0);
    n1->next = newNode(2);
    n1->next->next = newNode(5);
    n1->next->next = newNode(7);
    n1->next->next->next =newNode(4);
    n1->next->next->next->next =newNode(6);
    n1->next->next->next->next->next= newNode(10);
    n1->next->next->next->next->next->next = newNode(20);
    n1->next->next->next->next->next->next->next = newNode(-10);
    n1->next->next->next->next->next->next->next->next->data=-1;
    return 0;
}

