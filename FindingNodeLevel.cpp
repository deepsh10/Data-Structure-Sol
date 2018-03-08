#include "iostream"
#include "stack"

using namespace std;

struct Node {
	int data;
	Node *left,*right;
};

struct Node* newNode(int data)
{
	struct Node *node = new Node();
	node->data = data;
	node->left = node->right= NULL;
	return node;
}


int findingNode(Node *root,int data)
{
	stack < struct Node * >currentLevel;
	stack < struct Node * >nextLevel;

	currentLevel.push(root);
	int level = 0;

	while(!currentLevel.empty())
	{
		struct Node* temp = currentLevel.top();
		currentLevel.pop();

		if(temp->data == data)
		{
			return level;
		}

		if(temp->left)
		{ 
			nextLevel.push(temp->left);
		}
		if(temp->right)
		{
			nextLevel.push(temp->right);
		}
		
		if(currentLevel.empty())
		{
			swap(currentLevel,nextLevel);
			level++;
		}
	}
	return 999;
}


int main()
{
	int nodeToFind=-1,level=0;
	struct Node* root = newNode(3);
	root->left = newNode(2);
	root->right = newNode(4);
	root->left->left = newNode(1);
	root->right->right= newNode(5);

	printf("Enter the node you want to find out in tree :");
	scanf("%d",&nodeToFind);
	
	level = findingNode(root,nodeToFind);
	if(level != 999)
	{
		printf("Bruh level is : <%ld>\n",level);
	}
	else
	{
		printf("Sorry Bruh !! No level found \n");
	}

	return 1;
}
