
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*root;
void insert();
void inorder(struct node *root);
struct node* minValueNode(struct node *curr);
struct node *deletion(struct node *root, int item);
void search();
int main()
{
	int choice,item;
	while(1)
	{
		printf("\nMENU\n---------\n1.insertion\n2.deletion\n3.Inorder\n4.search\n5.exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
			break;
			case 2:printf("enter the value to be deleted\n");
			scanf("%d",&item);
			deletion(root,item);
			break;
			case 3: printf("The Inorder Traversal is:\n");
			inorder(root);
			break;
			case 4: search();
			break;
			case 5: exit(0);
			default: printf("\n invalid choice");
		}
	}
}

void insert()
{
	int item;
	struct node *temp, *pre, *ptr;
	printf("Enter the value of node\n");
	scanf("%d",&item);
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node*));
		root->data=item;
		root->left==NULL;
		root->right==NULL;
		printf("Node is inserted\n");
	}
	else
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=item;
		ptr->left=NULL;
		ptr->right=NULL;
		temp=root;
		// find the last node  for insertion
		while(temp!=NULL)
		{
			pre=temp;
			if(temp->data<=item)
				temp=temp->right;
			else
				temp=temp->left;
		}
		// check whether value greater than or less than last node
		if(pre->data<=item)
			pre->right=ptr;
		else
			pre->left=ptr;
		printf("Node is inserted\n");
	}
}


void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}


void search()
{
	int item,flag=0;
	struct node *temp;
	printf("Enter the item to search\n");
	scanf("%d",&item);
	temp=root;
	while(temp!=NULL)
	{
		if(temp->data==item)
		{
			flag=1;
			printf("%d found\n",item);
			return;
		}
		else if(temp->data<item)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(flag==0)
		printf("%d not found\n",item);
}

struct node *deletion(struct node *root, int item)
{
	struct node *curr;
	if (root == NULL)

		return 0;

	else if (item < root->data)

		root->left= deletion(root->left,item);

	else if (item > root->data)

		root->right= deletion(root->right,item);

	else
	{
		//deletion node with one or zero child
		if(root->left==NULL)
		{
			curr=root->right;
			free(root);
			return curr;
		}
		else if(root->right==NULL)
		{
			curr=root->left;
			free(root);
			return curr;
		}
		else
		{
			//deletion node with two child
			struct node *curr=minValueNode(root->right);

			root->data=curr->data;

			root->right=deletion(root->right,curr->data);

		}
	}
	return root;

}

struct node* minValueNode(struct node *curr){

	while(curr->left!=NULL){
		curr=curr->left;
	} 
	return curr;
}
