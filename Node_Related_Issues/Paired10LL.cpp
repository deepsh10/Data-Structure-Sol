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

void findPairsOf10(Node *start)
{
    int length=0;
    int index,match;
    
    struct Node* temp = start;
    struct Node* next = NULL;
    
    while(temp->data != -1)
    {
        next = temp->next;
        while(next->data  != -1)
        {
            length++;
            if(temp->data + next->data == 10)
            {
                printf("(%d,%d)\n",temp->data,next->data);
            }
            next = next->next;
        }
        temp = temp->next;
    }
    return;
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
    n1->next->next->next->next->next->next->next->next = newNode(-1);
    
    findPairsOf10(n1);
    
    return 0;
}

