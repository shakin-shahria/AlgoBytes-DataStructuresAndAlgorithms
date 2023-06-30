#include<iostream>

using namespace std;



struct node
{
	int data;
	node *parent;
	node *left;
	node *right;

	node(int val)
	{
		data = val;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

};


struct binary_tree
{
	node *root;

	binary_tree()
	{
		root = NULL;
	}

	void insert(node *z)
	{
		node *y = NULL;
		node *x = root;

		while(x!=NULL)
		{
			y = x;
			if(z->data < x->data) x = x->left;
			else x = x->right;
		}

		z->parent=y;

		if(y==NULL) root=z;
		else
		{
			if(z->data < y->data) y->left = z;
			else y->right = z;
		}
	}

	node* search(int data)
	{
		node *temp = root;
		while(temp!=NULL && temp->data!=data)
		{
			if(data < temp->data) temp = temp->left;
			else temp = temp->right;
		}

		return temp;
	}

	node* tree_min(node *x)
	{
		if(x!=NULL)
		{
			while(x->left!=NULL)
			{
				x = x->left;
			}
			return x;
		}
		else return NULL;
	}

	void inorder_tree_walk(node *x)
	{
		if(x!=NULL)
		{
			inorder_tree_walk(x->left);
			cout << x->data << "	";
			inorder_tree_walk(x->right);
		}
	}

	node* get_root()
	{
		return root;
	}

	node* tree_successor(node *x)
	{
		if(x->right!=NULL)
		{
			node *temp = tree_min(x->right);
			return temp;
		}
		else
		{

			while(x->parent->right == x)
			{
				if(x->parent!=NULL) x = x->parent;
				else break;
			}
			if(x->parent==NULL) return NULL;
			else return x->parent;
		}
	}

	void tree_delete(node *x)
	{
		//Case - 1 (NO CHILD)
		if(x->left==NULL && x->right==NULL)
		{
			node *y = x->parent;
			if(y->left==x) y->left=NULL;
			else y->right=NULL;
			delete x;
		}

		//Case - 2 (1 CHILD)
		else if(x->left==NULL || x->right==NULL)
		{
			if(x->left==NULL)
			{
				node *y = x->parent;
				if(y->left==x) y->left = x->right;
				else y->right = x->right;
			}

			else
			{
				node *y = x->parent;
				if(y->left==x) y->left = x->left;
				else y->right = x->left;
			}
			delete x;
		}

		//Case - 3 (2 CHILDREN)
		else
		{
			node *succ = tree_successor(x);
			x->data = succ->data;
			tree_delete(succ);
		}
		//return x;
	}

	//for Online
	int tree_height(node *x)
	{
		if(x==NULL) return 0;
		else return 1 + max(tree_height(x->left), tree_height(x->right));
	}

	int tree_depth(node *x)
	{
		if(x==root) return 0;
		else return 1 + tree_depth(x->parent);
	}

};

int main()
{
	binary_tree bt;
	node *x, *ret;
	int data, ch, key;

	while(1)
	{
		printf("\n----------MENU----------\n");
		printf("\n(1)INSERT");
		printf("\n(2)TREE_MIN");
		printf("\n(3)SEARCH");
		printf("\n(4)INORDER-VIEW");
		printf("\n(5)SUCCESSOR");
		printf("\n(6)DELETE");
		printf("\n(7)HEIGHT");
		printf("\n(8)DEPTH");
		printf("\n(9)EXIT");
		printf("\n------------------------\n");

		scanf("%d",&ch);

		switch(ch)
		{
			case 1: // insert
					printf("\n------------------------------");
					printf("\nEnter Integer Data : ");
					scanf("%d",&data);
					printf("\n------------------------------");

					x = new node(data);

					bt.insert(x);
					printf("\n...........Inserted...........\n");
					break;

			case 2: // Tree min
					ret = bt.tree_min(bt.get_root());

					if(ret == NULL) printf("\n......Tree is empty......\n");
					else
					{
						printf("\n------------------------------");
						printf("\nMinimum Data : ");
						printf("%d",ret->data);
						printf("\n------------------------------");
					}
					break;

			case 3: // Search
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
					if(ret == NULL)printf("\nNOT FOUND\n");
					else
					{
						printf("\n------------------------------");
						printf("\nData : ");
						printf("%d",ret->data);
						printf("\n------------------------------");
					}
					break;

			case 4: // Inorder traversal
					bt.inorder_tree_walk(bt.get_root());
					break;

			case 5:
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
					if(ret == NULL)printf("Not found");
					else
					{
						ret = bt.tree_successor(ret);
						if(ret == NULL)printf("No successor available\n");
						else
						{
							printf("\n------------------------------");
					        printf("\nSuccessor Data : ");
							printf("%d",ret->data);
					        printf("\n------------------------------");
						}
					}
					break;

			case 6: // delete
	            	printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
				    if(ret == NULL)printf("Not found");
					else
					{
						//ret = bt.tree_delete(ret);
						bt.tree_delete(ret);
				        printf("\n------------------------------");
			     		printf("\nDeleted Data : ");
				        printf("%d",ret->data);
				 		printf("\n------------------------------");
				       	//delete ret;
					}
					break;

			case 7:
					int height;
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
				    if(ret == NULL)printf("Not found");
					else
					{
						height = bt.tree_height(ret);
						cout << "Height of the given node : " << height << endl;
					}


					break;
			case 8:
					int depth;
					printf("\nEnter Data : ");
					scanf("%d",&key);
					ret = bt.search(key);
				    if(ret == NULL)printf("Not found");
					else
					{
						depth = bt.tree_depth(ret);
						cout << "Depth of the given node : " << depth << endl;
					}


					break;

			case 9: // Exit
					exit(0);
					break;

			default:
					printf("\nWRONG CHOICE\n");
					break;
		}
	}
	return 0;

}
