#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class node
{
	int value;
	node* right;
	node* left;
	
	public:
	node()
	{
		left=right=NULL;
		value=0;
	}
	//SETTERS
	void setvalue(int v){value=v;}
	void setright(node* r){right=r;}
	void setleft(node* l){left=l;}
	//GETTERS
	int getvalue(){return value;}
	node* getright(){return right;}
	node* getleft(){return left;}
};

class BST
{
	node* root;
	node* newnode;
	node* temp;
	node* prev;
	void preorder(node* r);
	void inorder(node* r);
	void postorder(node* r);

public:

	BST();
	void insert();
	void delete_n();
	void search();
	void maximum_value();
	void minimum_value();
	void print_preorder();
	void print_inorder();
	void print_postorder();
	void menue();
	void invalid();
	void success();
	void display();
};

int main()
{
	system("COLOR 0F" );	
	BST tree;
	int choice=0;

	while(choice!=6)
{
	system("cls");
	tree.display();
	tree.menue();
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		tree.insert();
		break;
		
		case 2:
		tree.delete_n();
		break;
		
		case 3:
		tree.search();
		break;
		
		case 4:
		tree.maximum_value();
		break;

		case 5:
		tree.minimum_value();
		break;
		
		case 6:
		exit(0);break;
		
		default:
		tree.invalid();
		break;
	}		
}	
	return 0;
}


//DEFINITIONS

BST :: BST()
{
	root=temp=newnode=prev=NULL;
}

void BST :: insert()
{
	int v;
	cout<<"\nEnter the value to be inserted:";
	cin>>v;
	newnode=new node;
	newnode->setvalue(v);
	newnode->setright(NULL);
	newnode->setleft(NULL);
	
	temp=prev=root;
	if(root==NULL)
	{
		root=newnode;
	}
	else
	{
	while(temp!=NULL)
	{
		prev=temp;
		if(v<temp->getvalue())
		temp=temp->getleft();
		else
		temp=temp->getright();
	}
	if(v<prev->getvalue())
	prev->setleft(newnode);
	else
	prev->setright(newnode);
	}
	success();
}

void BST :: delete_n()
{
	node* current;
	node* temp2=NULL;
	node* temp3;
	temp=root;
	prev=NULL;
	int v;
	cout<<"\nEnter the value you want to delete:";
	cin>>v;
	//This while will place your temp where value found
	//and prev one behind it
	while(temp!=NULL && temp->getvalue()!=v)
	{
		prev =temp;
		if(v<temp->getvalue())
		temp=temp->getleft();
		else
		temp=temp->getright();
	}
	
	//temp should be NULL if no value found
	if(temp==NULL){cout<<"\nValue not found!!!";}
	
	//If not found then check for different possibilities!!!
	else if(temp->getleft()==NULL || temp->getright()==NULL)
	{
		if(temp->getleft()==NULL)
		current=temp->getright();
		else
		current=temp->getleft();
		//This will run when only root left
		if(prev==NULL)
		{
			root=current;
			success();
			return;
		}
		if(temp==prev->getleft())
		prev->setleft(current);
		else
		prev->setright(current);
		
		free(temp);
	}
	else
	{	
		temp3=temp->getright();
		while(temp3->getleft()!=NULL)
		{
			temp2=temp3;
			temp3=temp3->getleft();
		}
		if(temp2!=NULL)
		{
			temp2->setleft(temp3->getright());
		}
		else
		{
			temp->setright(temp3->getright());
		}
		
		temp->setvalue(temp3->getvalue());
		free(temp3);
	}
	success();
}

void BST :: search()
{
	int v;
	cout<<"\nEnter the value you want to search:";
	cin>>v;
	int count=0;
	temp=root;
	while(temp!=NULL)
	{
		if(v==temp->getvalue())
		{
			count++;
			temp=temp->getright();
			
		}
		else if(v<temp->getvalue())
		{
			temp=temp->getleft();
		}
		else
		{
			temp=temp->getright();
		}
	}
	if(count==0)cout<<"\nNot Found";
	else cout<<"\nFound in '"<<count<<"' nodes...";
	success();
}

void BST :: maximum_value()
{
	temp=root;
	while(temp!=NULL)
	{
		prev=temp;
		temp=temp->getright();
	}
	cout<<"\nMaximum Value is: "<<prev->getvalue();
	success();
}

void BST :: minimum_value()
{
	temp=root;
	while(temp!=NULL)
	{
		prev=temp;
		temp=temp->getleft();
	}
	cout<<"\nMinimum Value is: "<<prev->getvalue();
	success();
}

void BST :: preorder(node* r )
{
	if(r==NULL)
	return;
	
		cout<<r->getvalue()<<"\t";
		preorder(r->getleft());
		preorder(r->getright());
}

void BST :: inorder(node* r)
{
	if(r==NULL)
	return;
	
		inorder(r->getleft());
		cout<<r->getvalue()<<"\t";
		inorder(r->getright());
}

void BST :: postorder(node* r)
{
	if(r==NULL)
	return;
	
		postorder(r->getleft());
		postorder(r->getright());
		cout<<r->getvalue()<<"\t";
}

void BST :: display()
{
	cout<<"\nPre-Order:\t";print_preorder();
	cout<<"\n\nIn-Order:\t";print_inorder();
	cout<<"\n\nPost-Order:\t";print_postorder();cout<<endl;

}

void BST :: menue()
{
	cout<<"\nEnter '1' to Insert";
	cout<<"\nEnter '2' to Delete";
	cout<<"\nEnter '3' to Search";
	cout<<"\nEnter '4' to find Maximum";
	cout<<"\nEnter '5' to find Minimum";
	cout<<"\nEnter '6' to Exit";
	cout<<"\nEnter:";
}

void BST :: invalid()
{
	cout<<"\nInavlid Input!!!";
	cout<<"\nEnter Again!!!";
	cout<<"\nPress Any key to enter again";getch();
}

void BST::success()
{
	cout<<"\nProcess Successful!!!";
	cout<<"\nPress Any Key To Continue";
	getch();system("cls");
}
void BST :: print_preorder(){preorder(root);}
void BST :: print_inorder(){inorder(root);}
void BST :: print_postorder(){postorder(root);}

