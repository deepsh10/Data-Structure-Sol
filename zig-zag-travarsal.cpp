#include <iostream>
#include <stack>

using namespace std;


struct Node {
  int data;
  struct Node *left,*right;
};

struct Node* newNode(int data)
{
  struct Node* node = new struct Node;
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void zigzagtravelsal(struct Node* root)
{
  if(!root)
  {
    return;
  }

  stack<struct Node* >currentlevel;
  stack<struct Node* >nextlevel;

  currentlevel.push(root);

  bool lefttoright=true;

  while(!currentlevel.empty())
  {
    struct Node* temp= currentlevel.top();
    currentlevel.pop();

    if(temp){
      cout << temp->data;

      if(lefttoright){
        if(temp->left){
          nextlevel.push(temp->left);
        }
        if(temp->right)
        {
          nextlevel.push(temp->right);
        }
      }

      if(!lefttoright){
        if(temp->right){
          nextlevel.push(temp->right);
        }
        if(temp->left) 
        {
          nextlevel.push(temp->left);
        }
      }
    }

    if(currentlevel.empty()){
      lefttoright = !lefttoright;
      swap(currentlevel,nextlevel);
    }
  }

}

int main()
{
  struct Node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left= newNode(7);
  root->left->right = newNode(6);
  root->right->left= newNode(5);
  root->right->right = newNode(4);
  printf("Node value is :<%ld>\n",root->left->right->data);

  zigzagtravelsal(root);
}
