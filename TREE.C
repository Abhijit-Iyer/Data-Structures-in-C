#include<stdio.h>
#include<conio.h>
struct stk
{
  struct tree *a[100];
  int top;
}s;
struct stack
{
  struct tr *a[10];
  int flag[40];
  int top;
}p;
void push1(struct tree *t)
{
  if(s.top==99)
  {
    printf("\n OVERFLOW");
    return;
  }
  s.a[++s.top]=t;
}
struct tree *pop1()
{
  struct tree *t;
  if(s.top==-1)
  {
    printf("\n UNDERFLOW");
    return;
  }
  t=s.a[s.top];
  s.top--;
  return t;
}
struct tree
{
  int val;
  struct tree *left;
  struct tree *right;
}tr;
struct tree *root=NULL;
void create(int v)
{
  struct tree *t,*temp;
  t=root;
  temp=(struct tree *)malloc(sizeof(tr));
  temp->val=v;
  temp->left=NULL;
  temp->right=NULL;
  if(root==NULL)
  {
    root=temp;
    return;
  }
  while(1)
  {
    if(v<t->val)
    {
      if(t->left==NULL)
      {
	t->left=temp;
	return;
      }
      else
      {
	t=t->left;
      }
    }
    else
    {
      if(t->right==NULL)
      {
	t->right=temp;
	return;
      }
      else
      {
	t=t->right;
      }
    }
  }
}
void preorder(struct tree *t)
{
   if(t==NULL)
   return;
   printf(" %d",t->val);
   preorder(t->left);
   preorder(t->right);
}
void inorder(struct tree *t)
{
   if(t==NULL)
   return;
   inorder(t->left);
   printf(" %d",t->val);
   inorder(t->right);
}
void postorder(struct tree *t)
{
   if(t==NULL)
   return;
   postorder(t->left);
   postorder(t->right);
   printf(" %d",t->val);
}
void iter_preorder()
{
   struct tree *t=root;
   s.top=-1;
   push1(NULL);
   if(!t)
   {
     return;
   }
   while(1)
   {
     if(t->right!=NULL)
     {
       push1(t->right);
     }
     printf("%d ",t->val);
     t=t->left;
     if(t==NULL)
     t=pop1();
     if(t==NULL)
     return;
   }
}
void iter_inorder()
{
  struct tree *t=root;
  s.top=-1;
  push1(NULL);
  if(!t)
  return;
  while(1)
  {
    while(t)
    {
      push1(t);
      t=t->left;
    }
    t=pop1();
    if(!t)
    return;
    printf("%d  ",t->val);
    if(t->right!=NULL)
    {
      t=t->right;
    }
    else
    {
      t=pop1();
      if(!t)
      return;
      printf("%d  ",t->val);
      t=t->right;
    }
  }
}
void push(struct tree *t,int f)
{
  if(p.top==39)
  {
    printf("\n OVERFLOW");
    return;
  }
  p.top++;
  p.a[p.top]=t;
  p.flag[p.top]=f;
}
int pop()
{
  int v;
  if(p.top==-1)
  {
    printf("\n UNDERFLOW");
    return;
  }
  v=p.top;
  p.top--;
  return v;
}
void iter_postorder()
{
  struct tree *t=root;
  int tp,fl;
  p.top=-1;
  push(NULL,0);
  while(1)
  {
    while(t)
    {
      if(t->right!=NULL)
      {
	push(t,1);
      }
      else
      {
	push(t,0);
      }
      t=t->left;
    }
    if(t==NULL)
    {
      tp=pop();
      t=p.a[tp];
      fl=p.flag[tp];
      while(fl==0&&t)
      {
	printf("%d  ",t->val);
	tp=pop();
	t=p.a[tp];
	fl=p.flag[tp];
      }
      if(t==NULL)
      return;
      else
      {
	push(t,0);
	t=t->right;
      }
    }
  }
}
void search(int v)
{
  struct tree *t=root;
  s.top=-1;
  push1(NULL);
  if(t==NULL)
  {
    return;
  }
  while(1)
  {
    if(t->right!=NULL)
    {
      push1(t->right);
    }
    if(t->val==v)
    {
      printf("\n Value %d found in the tree.",t->val);
      getch();
      return;
    }
    t=t->left;
    if(t==NULL)
    t=pop1();
    if(t==NULL)
    {
      printf("\n No such node found in the tree. ");
      getch();
      return;
    }
  }
}
void del(int v)
{
  int temp;
  struct tree *t=root,*p=NULL,*q=NULL,*S=NULL,*k=NULL;
  s.top=-1;
  push1(NULL);
  if(!t)
  {
     return;
  }
  while(1)
  {
    if(t->right!=NULL)
    {
      k=t;
      push1(t->right);
    }
    /*while(k->right->val!=v&&k->right!=NULL)
    {
      k=k->right;
    }*/
    if(k->right->val==v)
    {
       k->right=k->right->right;
       return;
    }
    if(t->val==v)
    {
      if(t==root&&t->left!=NULL&&t->right==NULL)
      {
	t=t->left;
	root->left=NULL;
	t->right=root->right;
	root=t;
	return;
      }
      if(t==root&&t->right!=NULL&&t->left==NULL)
      {
	t=t->right;
	t->left=root->left;
	root->right=NULL;
	root=t;
	return;
      }
      if(t==root&&t->left==NULL&&t->right==NULL)
      {
	root=NULL;
	printf("\n All the nodes of the tree have been deleted. ");
	getch();
	return;
      }
      if(t->left==NULL&&t->right==NULL)
      {
	if(p->right==t)
	{
	  p->right=NULL;
	}
	if(p->left==t)
	{
	  p->left=NULL;
	}
	return;
      }
      if(p->right==t)
      {
	if(t->left==NULL&&t->right!=NULL)
	{
	   p->right=t->right;
	   return;
	}
	if(t->left!=NULL&&t->right==NULL)
	{
	  p->right=t->left;
	  return;
	}
      }
      if(p->left==t)
      {
	if(t->right==NULL&&t->left!=NULL)
	{
	  p->left=t->left;
	  return;
	}
	if(t->right!=NULL&&t->left==NULL)
	{
	  p->left=t->right;
	  return;
	}
      }
      if(t->left!=NULL&&t->right!=NULL)
      {
	 q=t->right;
	 if(q->left==NULL)
	 {
	   t->val=q->val;
	   t->right=NULL;
	   return;
	 }
	 while(q->left!=NULL)
	 {
	   S=q;
	   q=q->left;
	 }
	 t->val=q->val;
	 if(q->right!=NULL)
	 {
	   S->left=q->left;
	 }
	 if(t->right==q)
	 {
	   t->right=NULL;
	 }
	 S->left=NULL;
	 q->left=NULL;
	 q->right=NULL;
	 free(q);
      }
    }
    if(t->left!=NULL||t->right!=NULL)
    p=t;
    t=t->left;
    if(t==NULL)
    {
      t=pop1();
    }
    if(t==NULL)
    return;
  }
}
void main()
{
  int ch,v,ch1;
  clrscr();
  while(1)
  {
    clrscr();
    printf("\n\t\t\t TREES ");
    printf("\n\n 1) Create 2) Traverse 3) Search 4) Delele 5) Exit");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: clrscr();
	      printf("\n Enter the value to be inserted to the tree: ");
	      scanf("%d",&v);
	      create(v);
	      break;
      case 2: clrscr();
	      if(root==NULL)
	      {
		printf("\n No tree created. ");
		getch();
		break;
	      }
	      printf("\n 1) Traversal by Recursion \n 2) Traversal by Itertion ");
	      printf("\n\n Enter your choice: ");
	      scanf("%d",&ch1);
	      switch(ch1)
	      {
		case 1:
			clrscr();
			printf("\n\n PREORDER:- ");
			preorder(root);
			printf("\n\n INORDER:- ");
			inorder(root);
			printf("\n\n POSTORDER:- ");
			postorder(root);
			getch();
			break;
		case 2:
			clrscr();
			printf("\n\n PREORDER:- ");
			iter_preorder();
			printf("\n\n INORDER:- ");
			iter_inorder();
			printf("\n\n POSTORDER:- ");
			iter_postorder();
			getch();
			break;
		case 3:
			printf("\n Invalid Choice. ");
			getch();
			break;
	      }
	      break;
      case 3: clrscr();
	      if(root==NULL)
	      {
		printf("\n No tree exists. ");
		getch();
		break;
	      }
	      printf("\n Enter the element you'd like to search: ");
	      scanf("%d",&v);
	      search(v);
	      break;
      case 4: clrscr();
	      if(root==NULL)
	      {
		printf("\n No tree exists. ");
		getch();
		break;
	      }
	      printf("\n Enter the element you'd like to delete: ");
	      scanf("%d",&v);
	      del(v);
	      break;
      case 5: exit(0);
    }
  }
  getch();
}
