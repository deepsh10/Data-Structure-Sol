/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   findingEndOfNodes.cpp
 * Author: shaw
 *
 * Created on March 8, 2018, 10:42 PM
 */

#include <cstdlib>
#include "iostream"
#include "stack"

using namespace std;



struct Node
{
    int data;
    Node *right=NULL,*left=NULL;
};

struct Node* newNode(int data)
{
    struct Node* temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

void findEndOfTree(Node *root)
{
    stack < Node * > currentStack;
    stack < Node * > nextStack;
    
    currentStack.push(root);
    
    while(!currentStack.empty())
    {
        struct Node* temp = currentStack.top();
        currentStack.pop();
        
        if(temp->left == NULL && temp->right == NULL)
        {
            printf("-> Ending node : <%d>\n",temp->data);
        }
        
        if(temp->left)
        {
            nextStack.push(temp->left);
        }
        if(temp->right)
        {
            nextStack.push(temp->right);
        }
        
        if(currentStack.empty())
        {
            swap(currentStack,nextStack);
        }
    }
}

int main(int argc, char** argv) {
    struct Node* root = newNode(3);
    root->right = newNode(4);
    root->left = newNode(6);
    root->right->right = newNode(7);
    
    findEndOfTree(root);
    
    return 0;
}

