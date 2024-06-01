#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void create_tree(struct node*);
void preorder(struct node*);
void inorder(struct node*);
void postorder(struct node*);
struct node *insert(struct node*,int);
struct node *delete_element(struct node*,int);
struct node *delete_tree(struct node*);
struct node *largest(struct node*);
struct node *smallest(struct node*);
int total_nodes(struct node *);
int total_internalnodes(struct node *);
int total_externalnodes(struct node *);
int height(struct node *);
void main()
{
	int val,choice;
	struct node *ptr;
	create_tree(tree);
	do
	{
	printf("\n\tMENU\n");
	printf("\n1. INSERT ELEMENT\n");
	printf("\n2. DELETE ELEMENT\n");
	printf("\n3. PREORDER TRAVERSAL\n");
	printf("\n4. INORDER TRAVERSAL\n");
	printf("\n5. POSTORDER TRAVERSAL\n");
	printf("\n6. DELETE TREE\n");
	printf("\n7. TO FIND LARGEST ELEMENT IN TREE\n");
	printf("\n8. TO FIND SMALLEST ELEMENT IN TREE\n");
	printf("\n9. TO FIND TOTAL NODES\n");
	printf("\n10. TO FIND TOTAL EXTERNAL NODES\n");
	printf("\n11. TO FIND TOTAL INTERNAL NODES\n");
	printf("\n12. TO FIND HEIGHT OF THE TREE\n");
	printf("\n20. EXIT\n");
	printf("\nENTER CHOICE\n");
	scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
			printf("\nENTER VALUE TO INSERT IN TREE\n");

			scanf("%d",&val);
			tree = insert(tree,val);
			break;		
			case 2:
			printf("\nENTER VALUE TO DELETE IN TREE\n");
			scanf("%d",&val);
			tree = delete_element(tree,val);
			case 3:
			printf("\nPREORDER TRAVERSAL IS:\n");
			preorder(tree);
			break;
			case 4:
			printf("\nINORDER TRAVERSAL IS:\n");
			inorder(tree);
			break;
			case 5:
			printf("\nPOSTORDER TRAVERSAL IS:\n");
			postorder(tree);
			break;
			case 6:
			tree = delete_tree(tree);
			break;
			case 7:
			ptr = largest(tree);
			printf("\nLARGEST ELEMENT IS: %d",ptr->data);
			break;
			case 8:
			ptr = smallest(tree);
			printf("\nSMALLEST ELEMENT IS: %d",ptr->data);
			break;
			case 9:
			printf("\nTOTAL NODES = %d\n",total_nodes(tree));
			break;
			case 10:
			printf("\nTOTAL EXTERNAL NODES = %d\n",total_externalnodes(tree));
			break;
			case 11:
			printf("\nTOTAL INTERNAL NODES = %d\n",total_internalnodes(tree));
			break;
			case 12:
			printf("\nHEIGHT OF THE TREE IS = %d\n",height(tree));
			break;

			
		}
	}while(choice != 20);
}
void create_tree(struct node *tree)
{
	tree = NULL;
}
struct node *insert(struct node *tree, int val)
{
	
	struct node *ptr,*nodeptr,*parentptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tree == NULL)
	{
		tree = ptr;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
	{
		parentptr = NULL;
		nodeptr = tree;
		while(nodeptr != NULL)
		{
			parentptr = nodeptr;
			if(val < nodeptr->data)
			{
				nodeptr = nodeptr->left;
			}
			else
			{
				nodeptr = nodeptr->right;
			}
		}
		if(val < parentptr->data)
		{
			 parentptr->left = ptr;
		}
		else
		{
			parentptr->right = ptr;
		}
	}
    
	
	return tree;
}
void preorder(struct node *tree)
{
	if(tree != NULL)
	{
		printf("%d\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
	
}
void inorder(struct node *tree)
{
	if(tree != NULL)
	{
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
	
}
void postorder(struct node *tree)
{
	if(tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t",tree->data);
	}
	
}
struct node *delete_tree(struct node *tree)
{
	if(tree != NULL)
	{
		delete_tree(tree->left);
		delete_tree(tree->right);
		free(tree);
	}
}
struct node *largest(struct node *tree)
{
	if((tree == NULL) || (tree->right == NULL))
	{
		return tree;
	}
	else
	{
		return largest(tree->right);
	}
}
struct node *smallest(struct node *tree)
{
	if((tree == NULL) || (tree->left == NULL))
	{
		return tree;
	}
	else
	{
		return smallest(tree->left);
	}
}
int total_nodes(struct node *tree)
{
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		return (total_nodes(tree->left)) + (total_nodes(tree->right)) + 1;
	}
}
int total_internalnodes(struct node *tree)
{
	if((tree == NULL) || ((tree->left == NULL) && (tree->right == NULL)))
	{
		return 0;
	}
	else
	{
		return (total_internalnodes(tree->left)) + (total_internalnodes(tree->right)) + 1;
	}
}
int total_externalnodes(struct node *tree)
{
	if(tree == NULL)
	{
		return 0;
	}
	if(((tree->left == NULL) && (tree->right == NULL)))
	{
		return 1;
	}
	else
	{
		return (total_externalnodes(tree->left)) + (total_externalnodes(tree->right));
	}
}
int height(struct node *tree)
{
	int left_h,right_h;
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		left_h = height(tree->left);
		right_h = height(tree->right);
		if(left_h > right_h)
		{
			return (left_h + 1);
		}
		else
		{
			return (right_h +1);
		}
	}
}
struct node *delete_element(struct node *tree, int val)
{
	struct node *cur, *parent, *suc, *psuc, *ptr;
	if(tree ->left==NULL)
	{
		printf("\n The tree is empty ");
		return(tree);
	}
	parent = tree;
	cur = tree ->left;
	while(cur!=NULL && val!= cur ->data)
	{
			parent = cur;
			cur = (val<cur ->data)? cur ->left:cur ->right;
		}
	if(cur == NULL)
	{
		printf("\n The value to be deleted is not present in the tree");
		return(tree);
	}
	if(cur ->left == NULL)
	ptr = cur ->right;
	else if(cur ->right == NULL)
	 	ptr = cur ->left;
	else
	{
		psuc = cur;
		cur = cur ->left;
		while(suc ->left!=NULL)
 		{
			psuc = suc;
			suc = suc ->left;
	 	}
		if(cur==psuc)
 		{

			suc ->left = cur ->right;
 		}
		else
 		{

			suc ->left = cur ->left;
			psuc ->left = suc ->right;
			suc ->right = cur ->right;
 		}
		ptr = suc;
	}

	if(parent ->left == cur)
		parent ->left=ptr;
	else
		parent ->right=ptr;
		free(cur);
	return tree;
}
