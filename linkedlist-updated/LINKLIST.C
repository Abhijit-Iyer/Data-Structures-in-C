#include<stdio.h>                  //1460
#include<alloc.h>
#include<graphics.h>
#include<conio.h>
struct list
{                       /* For Linear Linked Lists. */
  int val;
  struct list *next;
}node;
struct dll              /* For Doubly Linear Linked Lists. */
{
  int val;
  struct dll *next;
  struct dll *prev;
}node1;
struct stack
{                       /* For Static Stack */
  int stk[10];
  int top;
}s;
struct list2
{
   int coeff;           /* For Polynomials */
   int exp;
   struct list2 *next;
}node2;
struct list2 *root4=NULL;
struct list2 *root5=NULL;
struct list2 *root6=NULL;
//s.top=-1;
struct dll *root3=NULL;
struct list *root=NULL;
struct list *root2=NULL;
void draw_pixelbackground(int n,int b)
{
	int i;
	int xpos, ypos, color;
	int xmax = getmaxx();
	int ymax = getmaxy();

	setbkcolor(n);
	setcolor(b);
	rectangle(0,0,xmax, ymax);
	for(i = 0; i < 5000; i++)
	{
		xpos = rand() % xmax;
		ypos = rand() % ymax;
		color = rand() % 12;
		putpixel(xpos, ypos, color);
	}
}

void create()
{
  struct list *temp,*t;
  t=root;
  temp=(struct list *)malloc(sizeof(node));
  printf("\n\n Enter the new node info: ");
  scanf("%d",&temp->val);
  temp->next=NULL;
  if(root==NULL)
  {                            /* This function creates a new linked list. */
    root=temp;
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
  }
  t->next=temp;
}


void display(struct list *root)
{
  struct list *t;
  t=root;
  if(root==NULL)          /* This function displays the created linear linked list. */
  {
    printf("\n No list exists. Please create one first.");
    return;
  }
  printf("\n The List:- \n\n");
  while(t!=NULL)
  {
    if(t->next!=NULL)
    {
      printf(" %c %d %c ->",124,t->val,124);
      t=t->next;
    }
    else
    {
      printf(" %c %d %c ",124,t->val,124);
      t=t->next;
    }
  }
  //t=root;
}


void addafter()
{
  struct list *temp,*t;
  int p;
  t=root;                /* This function creates and adds a new node after a specific node to an existing linear linked list. */
  if(root==NULL)
  {
    printf("\n\n No list exists. Please create one first. ");
    return;
  }
  printf("\n\n Enter the value after which you'd like to  insert the node: ");
  scanf("%d",&p);
  while(t->val!=p&&t->next!=NULL)
  {
    t=t->next;
  }
  if(t->val!=p)
  {
    printf("\n\n Value is not found in the list. ");
    return;
  }
  temp=(struct list *)malloc(sizeof(node));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  temp->next=t->next;
  t->next=temp;
}


void addbefore()
{
  struct list *temp,*t,*p;int v;
  t=root;
  if(root==NULL)
  {
    printf("\n\n No list exists. Please create one first. ");
    return;
  }
  printf("\n\n Enter the value before which you'd like to  insert the node: ");
  scanf("%d",&v);
  while(t->val!=v&&t->next!=NULL)
  {
    p=t;
    t=t->next;   /* This function creates and adds a new node behind a specific node in the list. */
  }
  if(t->val!=v)
  {
    printf("\n\n Value is not found in the list. ");
    return;
  }
  temp=(struct list *)malloc(sizeof(node));
  printf("\n\n Enter the node info: ");
  scanf("%d",&temp->val);
  if(t==root)
  {
    temp->next=root;
    root=temp;
  }
  else
  {
    temp->next=t;
    p->next=temp;
  }
}


void del()
{
  struct list *t,*p;
  int n;
  t=root;
  if(t->next==NULL)
  {
    root=NULL;
    printf("\n\n You've deleted the last existing node from this list. The linked list is empty  now. ");
    return;
  }
  if(root==NULL)
  {
    printf("\n\n No list exists. Please create one first. ");
    return;
  }
  printf("\n\n Enter the value to be deleted. ");
  scanf("%d",&n);
  while(t->val!=n&&t->next!=NULL)
  {
    p=t;
    t=t->next;
  }
  if(t->val!=n)
  {
    printf("\n No node with this value found. ");
    return;
  }
  if(t==root)
  {                        /* This function deletes any specified node from the list. */
    root=root->next;
  }
  else
  {
    p->next=t->next;
  }
  free(t);
}


void clear()
{
  root=NULL;
  printf("\n The list has been cleared. ");
  return;
}

void clear2()
{
  root3=NULL;
  printf("\n The list has been cleared. ");
  return;
}


void circ_create()
{
  struct list *temp,*t;
  t=root;
  temp=(struct list *)malloc(sizeof(node));
  printf("\n Enter the new node info: ");
  scanf("%d",&temp->val);
  //temp->next=root;
  if(root==NULL)
  {                      /* This function creates a circular linked list. */
    root=temp;
    temp->next=root;
    return;
  }
  do
  {
    t=t->next;
  }while(t->next!=root);
  temp->next=root;
  t->next=temp;
 // circ_display();
  //t=root;
}


void circ_display()
{
  struct list *t;
  t=root;              /*This function displays a circular linked list. */
  if(root==NULL)
  {
    printf("\n No list exists. Please create one first.");
    return;
  }
  printf("\n\n The List:- \n\n");
  do
  {
    if(t->next!=root)
    {
      printf(" | %d | ->",t->val);
      t=t->next;
    }
    else
    {
       printf(" | %d | ",t->val);
       t=t->next;
    }
  }while(t!=root);
}


void circ_addafter()
{
  struct list *temp,*t;
  int p;
  t=root;
  if(root==NULL)  /* This function adds a new created node after a specified node in the list. */  {
    printf("\n No list exists. Please create one first. ");
    return;
  }
  printf("\n Enter the value after which you'd like to  insert the node: ");
  scanf("%d",&p);
  while(t->val!=p&&t->next!=root)
  {
    t=t->next;
  }
  if(t->val!=p)
  {
    printf("\n Value is not found in the list. ");
    return;
  }
  temp=(struct list *)malloc(sizeof(node));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  temp->next=t->next;
  t->next=temp;
}


void circ_addbefore()
{
  struct list *temp,*t,*p;int v;
  t=root;
  if(root==NULL)   /* This function adds a new created node before a specified node in the list. */
  {
    printf("\n No list exists. Please create one first. ");
    return;
  }
  printf("\n Enter the value before which you'd like to  insert the node: ");
  scanf("%d",&v);
  while(t->val!=v&&t->next!=root)
  {
    p=t;
    t=t->next;
  }
  if(t->val!=v)
  {
    printf("\n Value is not found in the list. ");
    return;
  }
  temp=(struct list *)malloc(sizeof(node));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  if(t==root)
  {
    temp->next=root;
    root=temp;
    while(t->next!=root->next)
    {
      t=t->next;
    }
    t->next=root;
  }
  else
  {
    temp->next=t;
    p->next=temp;
  }
}


void circ_del()
{
  struct list *t,*p;
  int n;  /* This function deletes a specified node from the list. */
  t=root;
  if(root==NULL)
  {
    printf("\n No list exists. Please create one first.");
    return;
  }
  if(root->next==root)
  {
    root=NULL;
    printf("\n The list is empty now. ");
    return;
  }
  printf("\n Enter the value to be deleted. ");
  scanf("%d",&n);
  /*if(t==root)
  {
    root=root->next;
    free(t);
    t=root;
    while(t->next!=root)
    {
      t=t->next;
    }
    t->next=root;
    return;
  }*/
  while(t->val!=n&&t->next!=root)
  {
    p=t;
    t=t->next;
  }
  if(t->val!=n)
  {
    printf("\n No node with this value found. ");
    return;
  }
  if(t==root)
  {
    //root=root->next;
    while(t->next!=root)
    {
      t=t->next;
    }
    root=root->next;
    t->next=root;
  }
  else
  {
    p->next=t->next;
  }
  //free(t);
}


void nth_occ_del()
{
  struct list *temp,*t,*p;
  int n,o,c=0;
  t=root;
  if(root==NULL)
  {
    printf("\n No list present. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
    return;
  }
  printf("\n Enter the value you want to delete: ");
  scanf("%d",&n);
  printf("\n Enter the occurence of the number to be deleted: ");
  scanf("%d",&o);
  do
  {
     if(t->val==n)
     {
       c++;
     }
     if(o==c)
     {
       if(t==root)
       {
	 root=root->next;
       }
       else
       {
	 p->next=t->next;
       }
       free(t);
       display(root);
       return;
     }
     p=t;
     t=t->next;
  }while(t!=NULL);
  if(t->next!=n)
  {
    printf("\n This %d'th  occurence of the element isn't found. ",o);
    return;
  }
  display(root);
}
void ins_bef_aft_nth()
{
  struct list *temp,*t,*p;
  int n,o,c=0,ch;
  t=root;
  if(root==NULL)
  {
    printf("\n No list is present. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
    return;
  }
  printf("\n Enter the value to find the nth occurence: ");
  scanf("%d",&n);
  printf("\n Enter the occurence of the number: ");
  scanf("%d",&o);
  while(t->next!=NULL)
  {
     if(t->val==n)
     {
       c++;
     }
     if(o==c)
     {
       printf("\n Enter (1) for insertion before this node and (2) for insertion after this node: ");
       scanf("%d",&ch);
       switch(ch)
       {
	 case 1: temp=(struct list *)malloc(sizeof(node));
		 printf("\n Enter the node info: ");
		 scanf("%d",&temp->val);
		 temp->next=t;
		 p->next=temp;
		 display(root);
		 return;
	 case 2: temp=(struct list *)malloc(sizeof(node));
		 printf("\n Enter the node info: ");
		 scanf("%d",&temp->val);
		 temp->next=t->next;
		 t->next=temp;
		 display(root);
		 return;
       }
     }
     p=t;
     t=t->next;
  }
  if(t->next!=n)
  {
    printf("\n This %d'th  occurence of the element isn't found. ",o);
    return;
  }
}
void clear_all()
{
 struct list *t,*p;
   int n,c=0;
   t=root;
   if(root==NULL)
   {
     printf("\n No list created. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
     return;
   }
   printf("\n Enter the value to be deleted: ");
   scanf("%d",&n);
   while(t!=NULL)
   {
     if(t->val==n)
     {
       if(t==root)
       {
	 root=root->next;
	 t=t->next;
       }
       else
       {
	 p->next=t->next;
       }
     }
     p=t;
     t=t->next;
     if(root->next==NULL)
     {
       root=NULL;
       printf("\n The entire list has been cleared. ");
       return;
     }
   }
   display(root);
}
void del_extra()
{
  struct list *t,*p;
  int c=0,n;
  p=NULL;
  t=root;
  if(root==NULL)
  {
    printf("\n No list present. Please create one. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
    return;
  }
  printf("\n Enter the value for extra nodes to be deleted: ");
  scanf("%d",&n);
  while(t!=NULL)
  {
    if(t->val==n)
    {
      c++;
    }
    if(c>1)
    {
	p->next=t->next;
	//free(t);
    }
    p=t;
    t=t->next;
    if(t->val==n&&c>1)
    {
      if(t->next=NULL)
      {
	p->next=t->next;
      }
    }
  }
  display(root);
}
void tp_create()
{
  struct list *t;
  t=root;
  if(root==NULL)
  {
    root=(struct list *)malloc(sizeof(node));
    printf("\n Enter the new node info: ");
    scanf("%d",&root->val);
    root->next=NULL;
    return;
  }
  while(t->next!=NULL)
  {
  t=t->next;
  }
    t->next=(struct list *)malloc(sizeof(node));
    printf("\n Enter the new node info: ");
    scanf("%d",&t->next->val);
    t->next->next=NULL;
    display(root);
}
void tp_ins_bef()
{
   struct list *t,*temp; int n;
   t=root;
   if(root==NULL)
   {
     printf("\n No list present. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
     return;
   }
   printf("\n Enter the value before which you'd like to insert a value: ");
   scanf("%d",&n);
   temp=(struct list *)malloc(sizeof(node));
   printf("\n Enter the node info: ");
   scanf("%d",&temp->val);
   if(t->val==n)
   {
      temp->next=t;
      root=temp;
      return;
   }
   while(t->next->val!=n&&t->next!=NULL)
   {
     t=t->next;
   }
   temp->next=t->next;
   t->next=temp;
   display(root);
}
void tp_delete()
{
  struct list *t;
  int n;
  t=root;
  if(root==NULL)
  {
    printf("\n No list found. Please create one first. (go back to the main menu and \n enter '1' for the same.)");
    return;
  }
  if(root->next==NULL)
  {
    root=NULL;
    printf("\n The list has beem cleared. ");
    return;
  }
  printf("\n Enter the value to be deleted: ");
  scanf("%d",&n);
  if(t->val==n)
  {
    root=t->next;
    //t->next=NULL;
    free(t);
    return;
  }
  while(t->next->val!=n&&t->next!=NULL)
  {
    t=t->next;
  }
  t->next=t->next->next;
  display(root);
 // free(t->next);
}
void sort()
{
  struct list *temp,*t;
  t=root;
  temp=(struct list *)malloc(sizeof(node));
  printf("\n Enter the value to be inserted: ");
  scanf("%d",&temp->val);
  if(root==NULL)
  {
    temp->next=NULL;
    root=temp;
    display(root);
    return;
  }
  if(root->next==NULL)
  {
    if(t->val<temp->val)
    {
      t->next=temp;
      temp->next=NULL;
      display(root);
      return;
    }
    if(t->val>temp->val)
    {
      temp->next=t;
      root=temp;
      display(root);
      return;
    }
  }
  while((t->next->val)<(temp->val)&&(t->next!=NULL))
  {
    t=t->next;
  }
  if(t==root)
  {
    if(t->val<temp->val)
    {
      temp->next=t->next;
      t->next=temp;
      root=t;
      display(root);
      return;
    }
    else
    {
      temp->next=t;
      root=temp;
      display(root);
      return;
    }
  }
  else
  {
    temp->next=t->next;
    t->next=temp;
    display(root);
  }
}
void dll_create()
{
  struct dll *temp,*t;
  t=root3;
  temp=(struct dll *)malloc(sizeof(node1));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  temp->next=NULL;
  temp->prev=NULL;
  if(root3==NULL)
  {
    root3=temp;
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
  }
  t->next=temp;
  temp->prev=t;
}
void dll_display()
{
  struct dll *t;
  t=root3;
  if(root3==NULL)
  {
    printf("\n No list exists. ");   return;
  }
  while(t!=NULL)
  {
    if(t->next!=NULL)
    {
      printf("  | %d | ->",t->val);
      t=t->next;
    }
    else
    {
      printf(" | %d | ",t->val);
      t=t->next;
    }
  }
}
void dll_addafter()
{
  struct dll *temp,*t;
  int n;
  t=root3;
  printf("\n Enter the node after which you'd like to insert a node: ");
  scanf("%d",&n);
  if(root3==NULL)
  {
    printf("\n No root exists. ");
  }
  while(t->val!=n&&t->next!=NULL)
  {
    t=t->next;
  }
  temp=(struct dll *)malloc(sizeof(node1));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  temp->next=t->next;
  temp->prev=t;
  temp->next->prev=temp;
  t->next=temp;
}
void dll_addbefore()
{
   struct dll *temp,*t;
   int n;
   t=root3;
   if(root3==NULL)
   {
     printf("\n No list is created. ");
   }
   printf("\n Enter the value before which you'd like to insert a new node: ");
   scanf("%d",&n);
   temp=(struct dll *)malloc(sizeof(node1));
   printf("\n Enter the node info: ");
   scanf("%d",&temp->val);
   if(t->val==n)
   {
     temp->next=root3;
     root3=temp;
     return;
   }
   while(t->next->val!=n&&t->next!=NULL)
   {
     t=t->next;
   }
   temp->prev=t;
   temp->next=t->next;
   temp->next->prev=temp;
   t->next=temp;
}
void dll_delete()
{
   struct dll *t;
   int n;
   t=root3;
   if(root3==NULL)
   {
     printf("\n NO list found. ");
   }
   if(root3->next==NULL)
   {
     root3==NULL;
     printf("\n The list has been cleared. ");
     return;
   }
   printf("\n Enter the value to be deleted: ");
   scanf("%d",&n);
   if(t->val==n)
     {
       root3=t->next;
       t->next=NULL;
       root3->prev=NULL;
       free(t);
       return;
     }
   while(t->next->val!=n && t->next!=NULL)
   {
      t=t->next;
   }
  if(t->next == NULL && t->val!=n)
  {
    printf("\n This element is not found in the list ");
  }
   t->next=t->next->next;
   t->next->next->prev=t;
  //d free(t->next);
}
void cdll_create()
{
  struct dll *temp,*t;
  t=root3;
  temp=(struct dll *)malloc(sizeof(node));
  printf("\n Enter the node info: ");
  scanf("%d",&temp->val);
  if(t==NULL)
  {
    temp->next=temp;
    temp->prev=temp;
    root3=temp;
    return;
  }
  do
  {
    t=t->next;
  }while(t->next!=root3);
  temp->next=t->next;
  temp->prev=t;
  t->next=temp;
  root3->prev=temp;
}
void cdll_display()
{
   struct dll *t;
   t=root3;
   if(t==NULL)
   {
     printf("\n No list exists. Please create one. ");
     return;
   }
   printf("\n\n The list:- \n");
   do
   {
     if(t->next!=root3)
     {
       printf("| %d | ->",t->val);
       t=t->next;
     }
     else
     {
       printf("| %d | ",t->val);
       t=t->next;
     }
   }while(t!=root3);
}
void cdll_addafter()
{
   struct dll *temp,*t;
   int n;
   t=root3;
   if(t==NULL)
   {
     printf("\n No list present. Please create one first. ");
     return;
   }
   printf("\n Enter the node after which you'd like to insert a node: ");
   scanf("%d",&n);
   do
   {
     t=t->next;
   }while(t->val!=n&&t!=root3);
   if(t->val!=n)
   {
     printf("\n There's no such node present in the list. ");
     return;
   }
   temp=(struct dll *)malloc(sizeof(node));
   printf("\n Enter the new node info: ");
   scanf("%d",&temp->val);
   temp->next=t->next;
   temp->prev=t;
   t->next->prev=temp;
   t->next=temp;
}
void cdll_addbefore()
{
   struct dll *temp,*t,*p;
   int n;
   t=root3;
   if(t==NULL)
   {
      printf("\n No list present. Please create one first. ");
      return;
   }
   printf("\n Enter the node before which you'd like to insert a node: ");
   scanf("%d",&n);
   temp=(struct dll *)malloc(sizeof(node));
   printf("\n Enter the new node info: ");
   scanf("%d",&temp->val);
   if(t->val==n)
   {
     temp->next=t;
     temp->prev=t->prev;
     t->prev=temp;
     temp->prev->next=temp;
     root3=temp;
     return;
   }
   do
   {
     p=t;
     t=t->next;
   }while(t->val!=n&&t->next!=root3);
   temp->next=t;
   temp->prev=p;
   p->next=temp;
   t->prev=temp;
}
void cdll_delete()
{
  struct dll *t,*p;
  int n;
  t=root3;
  if(root3==NULL)
  {
     printf("\n No list exists. Please create one first. ");
     return;
  }
  if(root3->next==root)
  {
    root3=NULL;
    printf("\n The list has been cleared. ");
    return;
  }
  printf("\n Enter the node which you'd like to delete: ");
  scanf("%d",&n);
  if(t->val==n)
  {
    root3=t->next;
    root3->prev=t->prev;
    t->prev->next=root3;
    free(t); root3 = NULL;
    return;
  }
  do
  {
    p=t;
    t=t->next;
  }while(t->val!=n&&t->next!=root3);
  if(t->val != n)
  {
    printf("\n Element not found. ");
    return;
  }
  p->next=t->next;
  t->next->prev=p;
  //free(t);
}
void ll_push()
{
   struct list *t,*temp;
   t=root;
   temp=(struct list *)malloc(sizeof(node));
   printf("\n Enter the value to be pushed: ");
   scanf("%d",&temp->val);
   if(root==NULL)
   {
     root=temp;
     temp->next=NULL;
     return;
   }
   temp->next=root;
   root=temp;
}
void ll_peep()
{
  printf("\n The top element is:-");
  printf("\n %d",root->val);
}
void ll_pop()
{
  struct list *t;
  t=root;
  t=t->next;
  root=t;
}
void push(int val)
{
  if(s.top==10)
  {
    printf("\n Overflow");
    return;
  }
  s.top++;
  s.stk[s.top]=val;
}
int pop()
{
  int val;
  if(s.top==-1)
  {
    printf("\n Underflow");
    return 0;
  }
  val=s.stk[s.top];
  s.top--;
  return val;
}
void disp()
{
  int i;
  if(s.top==-1)
  {
    printf("\n The stack is empty. ");
    return;
  }
  printf("\n");
  for(i=0;i<=s.top;i++)
  {
    printf(" | %d |",s.stk[i]);
    printf("\n ------ \n");
  }
}
void peep()
{
  printf("\n The top element is: ");
  printf("\n %d",s.stk[s.top]);
}
void reverse()
{
   struct list *t,*p,*u,*v;
   int a=0; int i;
   t=root;
   p=NULL;
   if(t==NULL)
   {
     printf("\n Please create a list. ");
     return;
   }
   while(t->next!=NULL)
   {
     while(t->next!=NULL)
     {
       p=t;
       t=t->next;
     }
     a++;
     if(a==1)
     {
       v=t;
     }
     t->next=p;
     p->next=NULL;
     t=root;
   }
   root=v;
   display(root);
}
void split_alt()
{
   struct list *s,*t,*u,*temp;
   int a;
   t=root;
   printf("\n Creation of list :-");
		do
		{
		t=root;
		temp=(struct list *)malloc(sizeof(node));
		printf("\n Enter the new node info: ");
		scanf("%d",&temp->val);
		temp->next=NULL;
		if(root==NULL)
		{
		  root=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding into this list: ");
		a=getch();
		}while(a=='y');
		printf("\n Created List:- \n");
		display(root);
		t=root;
		root2=t->next;
		s=root2;
		while(t->next!=NULL)
		{
		  t->next=s->next;
		  t=t->next;
		  s->next=t->next;
		  s=s->next;
		}
		printf("\n First Alternatives: \n");
		display(root);
		printf("\n Second Alternatives: \n");
		display(root2);
}
void concat()
{
  struct list *t,*temp;
  int ch,a,y;
  printf("\n Creation of list 1:-");
		do
		{
		t=root;
		temp=(struct list *)malloc(sizeof(node));
		printf("\n Enter the new node info: ");
		scanf("%d",&temp->val);
		temp->next=NULL;
		if(root==NULL)
		{
		  root=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding into this list: ");
		a=getch();
		}while(a=='y');
  printf("\n Creation of List 2:-");
		do
		{
		t=root2;
		temp=(struct list *)malloc(sizeof(node));
		printf("\n Enter the new node info: ");
		scanf("%d",&temp->val);
		temp->next=NULL;
		if(root2==NULL)
		{
		  root2=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding to this list: ");
		a=getch();
		}while(a=='y');
		printf("\n List 1:- \n");
		display(root);
		printf("\n List 2:- \n");
		display(root2);
		t=root;
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=root2;
		printf("\n The concatenated list is:- \n");
		display(root);
}
void merge_n_sort()
{
  struct list *t,*temp,*s;
  int ch,a,y,b;
  printf("\n Creation of list 1:-");
		do
		{
		t=root;
		temp=(struct list *)malloc(sizeof(node));
		printf("\n Enter the new node info: ");
		scanf("%d",&temp->val);
		temp->next=NULL;
		if(root==NULL)
		{
		  root=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding into this list: ");
		a=getch();
		}while(a=='y');
  printf("\n Creation of List 2:-");
		do
		{
		  t=root2;
		  temp=(struct list *)malloc(sizeof(node));
		  printf("\n Enter the new node info: ");
		  scanf("%d",&temp->val);
		  temp->next=NULL;
		  if(root2==NULL)
		  {
		    root2=temp;
		  }
		  else
		  {
		    while(t->next!=NULL)
		    {
		      t=t->next;
		    }
		    t->next=temp;
		  }
		  printf("\n Press y to continue adding to this list: ");
		  a=getch();
		}while(a=='y');
		printf("\n List 1:- \n");
		display(root);
		printf("\n List 2:- \n");
		display(root2);
		t=root;
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=root2;
		t=root;
		s=root;
		while(t->next!=NULL)
		{
		  s=root;
		  while(s->next!=NULL)
		  {
		    if((s->val)>(s->next->val))
		    {
		      b=s->val;
		      s->val=s->next->val;
		      s->next->val=b;
		    }
		    s=s->next;
		  }
		  t=t->next;
		}
		printf("\n Sorted List:- \n");
		display(root);
}
void create_two_lists()
{
  struct list2 *temp,*t;
  int ch,a,y;
  printf("\n Creation of list 1:-");
		do
		{
		t=root4;
		temp=(struct list2 *)malloc(sizeof(node1));
		printf("\n Enter the new node coeff: ");
		scanf("%d",&temp->coeff);
		printf("\n Enter the new node exp: ");
		scanf("%d",&temp->exp);
		temp->next=NULL;
		if(root4==NULL)
		{
		  root4=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding into this list: ");
		a=getch();
		}while(a=='y');
  printf("\n Creation of List 2:-");
		do
		{
		t=root5;
		temp=(struct list2 *)malloc(sizeof(node));
		printf("\n Enter the new node coeffinient: ");
		scanf("%d",&temp->coeff);
		printf("\n Enter the node exp: ");
		scanf("%d",&temp->exp);
		temp->next=NULL;
		if(root5==NULL)
		{
		  root5=temp;
		}
		else
		{
		while(t->next!=NULL)
		{
		  t=t->next;
		}
		t->next=temp;
		}
		printf("\n Press y to continue adding to this list: ");
		a=getch();
		}while(a=='y');
}
void add_poly()
{
   struct list2 *t,*s,*p,*temp,*u;
   t=root4;
   s=root5;
   p=root6;
   while((t!=NULL)&&(s!=NULL))
   {
     temp=(struct list2 *)malloc(sizeof(node));
     if(p==NULL)
     {
	root6=temp;
	p=temp;
     }
     u=p;
     p=temp;
     if(t==NULL)
     {
       /*p->coeff=s->coeff;
       p->exp=s->exp;
       p->next=NULL;
       if(u->next==NULL||u->next==u)
       u->next=p;
       s=s->next;*/
       u->next=s;
       continue;
     }
     if(s==NULL)
     {
       p->coeff=t->coeff;
       p->exp=t->exp;
       p->next=NULL;
       if(u->next==NULL||u->next==u)
       u->next=p;
       t=t->next;
       continue;
     }
     if(t->exp==s->exp)
     {
       p->coeff=t->coeff+s->coeff;
       p->exp=t->exp;
       p->next=NULL;
       if(u->next==NULL||u->next==u)
       {
	 u->next=p;
       }
       t=t->next;
       s=s->next;
       continue;
     }
     if(t->exp>s->exp)
     {
       p->coeff=t->coeff;
       p->exp=t->exp;
       p->next=NULL;
	 t=t->next;
       if(u->next==NULL||u->next==u)
       {
	 u->next=p;
       }
       continue;
     }
     if(t->exp<s->exp)
     {
       p->coeff=s->coeff;
       p->exp=s->exp;
       p->next=NULL;
       s=s->next;
       if(u->next==NULL||u->next==u)
       {
	 u->next=p;
       }
       continue;
     }
     //t=t->next;
     //s=s->next;
     //u->next=p;
   }
}
void mult_poly()
{
  struct list2 *temp,*t,*s,*p,*u;
  t=root4;
  s=root5;
  p=root6;
  while(t!=NULL)
  {
     s=root5;
     while(s!=NULL)
     {
      temp=(struct list2 *)malloc(sizeof(node));
      if(root6==NULL)
      {
	root6=temp;
      }
      u=p;
      p=temp;
      u->next=p;
      p->coeff=(t->coeff*s->coeff);
      p->exp=(t->exp+s->exp);
      p->next=NULL;
      s=s->next;
     }
     t=t->next;
  }
}
void frontpage()
{
  setgraphmode(2);
  draw_pixelbackground(RED,15);
  printf("\n\n\t\t\t\tA PROJECT ON \n\n\n\n\n\n\t\t\t\t\"LINKED LISTS\n\n\t\t\t\t      AND \n\n\t\t\t       ITS APPLICATIONS\" \n\n\n\t\t\t\t\t\t Presented by:-\n\n\t\t\t\t\t\t        ABHIJIT. S. IYER");
  rectangle(10,10,600,300);
  rectangle(9,9,601,301);
  rectangle(205,120,420,220);
  rectangle(202,118,422,222);
  textattr(128+10);
  cprintf("\n\n\n\n\n\n\t\t\t Press any key to continue.. ");
  getch();
}
void open()
{
  setgraphmode(2);
  draw_pixelbackground(3,15);
  rectangle(70,70,150,100);
  line(97,70,97,100);
  line(124,70,124,100);
  rectangle(190,70,250,100);
  line(220,70,220,100);
  line(137,85,190,85);
  //line(); //draw the arrow head
  getch();
}
void main()
{
  int ch1,ch2,val,gd=DETECT,gm,y,i,ch4;
  s.top=-1;
  clrscr();
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  //open();
  frontpage();
  while(1)
  {
    //ex: draw_pixelbackground(10,15);
     setgraphmode(2);
    ex:setbkcolor(9);
    //setcolor(5);
    /*for(i=350;i<500;i=i+20)
    {
       setcolor(7);
       circle(350,700,i);
       //circle(i-2,i-2,i-2);
    }*/
    printf("\n\t\t==========================================");
    printf("\n\t\t||  LINKED LISTS AND ITS APPLICATIONS  || ");
    printf("\n\t\t==========================================");
    //textcolor(3);
    printf("\n\n  1) Linear Linked List \t    2) Circular Linked List \n\n  3) Applications \t\t    4) Linear Linked Lists using two pointers  \n\n  5) Doubly Linked Lists \t    6) Stack Implementation \n\n  7) Circular Doubly Linked Lists   8) Exit ");
    printf("\n\n\n\t\t Enter your choice: ");
    scanf("%d",&ch1);
    setgraphmode(2);
    switch(ch1)
    {
      case 1: do
	      {
	      setgraphmode(2);
	      setbkcolor(1);
	      //setgraphmode(1);
	      //setviewport(0, 0, getmaxx(), getmaxy(), 0);
	      printf("\n\n\t\t\t      LINEAR LINKED LIST:- ");
	      printf("\n\n\t\t ********************************************");
	      printf("\n\n\n   1) Create a list \t\t\t2) Display the list \n\n   3) Add after a specified node\t4) Add before a specified node \n\n   5) Delete \t\t\t\t6) Previous Menu");
	      printf("\n\n\t\t   Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		 case 1: create();
		 break;
		 case 2: display(root);
		 break;
		 case 3: addafter();
		 break;
		 case 4: addbefore();
		 break;
		 case 5: if(root==NULL)
			 {
			    printf("\n No list created. ");\
			    break;
			 }
			 printf("\n 1) Delete a node \t\t2) Clear the list \n\n\t Enter your choice: ");
			 scanf("%d",&ch4);
			 switch(ch4)
			 {
			    case 1: del();
				    break;
			    case 2: clear();
				    break;
			 }
		 break;
		 case 6: setgraphmode(2);
			 goto ex;
		 default: printf("\n Invalid Choice. ");
	      }
	   printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 2: do
	      {
	      setgraphmode(2);
	      setbkcolor(2);
	      printf("\n\n\t\t\t CIRCULAR LINKED LIST:- ");
	      printf("\n\n\t\t *****************************************");
	      printf("\n\n  1) Create a list \t\t\t2) Display the list \n\n  3) Add after a speific node \t\t4) Add before a specific node \n\n  5) Delete a node \t\t\t6) Previous Menu");
	      printf("\n\n\t\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		case 1: circ_create();
		break;
		case 2: circ_display();
		break;
		case 3: circ_addafter();
		break;
		case 4: circ_addbefore();
		break;
		case 5: if(root==NULL)
			 {
			    printf("\n No list created. ");
			    break;
			 }
			printf("\n 1) Delete a node \t\t2) Clear the list \n\n\t Enter your choice: ");
			scanf("%d",&ch4);
			switch(ch4)
			{
			case 1: circ_del();
				break;
			case 2: clear();
				 break;
			}
			break;
		case 6: setgraphmode(2);
			goto ex;
		default: printf("\n Invalid Choice. ");
	      }
	      printf("\n\n Enter y to continue with this menu, or press any other key to return to the \n previous menu ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 3: do
	      {
	      setgraphmode(2);
	      setbkcolor(5);
	      printf("\n\n\t\t\t APPLICATIONS:-");
	      printf("\n\n\t\t ******************************");
	      printf("\n\n\t NOTE : Please create a list before you perform any of these operations. ");
	      printf("\n\n\t1) Deletion  of \"n'th\" occurence of a number");
	      printf("\n\t2) Insertion before or after nth occurence of node");
	      printf("\n\t3) Deletion of similar nodes");
	      printf("\n\t4) Deletion of extra nodes");
	      printf("\n\t5) Sorting ");
	      printf("\n\t6) Reversing");
	      printf("\n\t7) List Concate");
	      printf("\n\t8) Split List into two alternatives");
	      printf("\n\t9) Merge and Sorts two lists");
	      printf("\n\t10) Previous Menu");
	      printf("\n\n\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
	       case 1: nth_occ_del();
	       break;
	       case 2: ins_bef_aft_nth();
	       break;
	       case 3: clear_all();
	       break;
	       case 4: del_extra();
	       break;
	       case 5: sort();
	       break;
	       case 6: reverse();
	       break;
	       case 7: concat();
	       break;
	       case 8: split_alt();
	       break;
	       case 9: merge_n_sort();
	       break;
	       case 10:
			setgraphmode(2);
			goto ex;
	      }
	      printf("\n\n Press y to continue with this menu, or press any other key to go back to the \n previous menu. ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 4: do
	      {
	      setgraphmode(2);
	      setbkcolor(5);
	      printf("\n\n\t\t\t LINEAR LINKED LIST USING TWO POINTERS:-");
	      printf("\n\n\t\t ****************************************************");
	      printf("\n\n 1) Create a list  \t\t 2) Addbefore a specified node \n\n 3) Delete  \t\t\t 4) Previous Menu");
	      printf("\n\n\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		case 1: tp_create();
		break;
		case 2: tp_ins_bef();
		break;
		case 3: if(root==NULL)
			 {
			    printf("\n No list created. ");
			    break;
			 }
			printf("\n 1) Delete a node \t\t2) Clear the list \n\n\t Enter your choice: ");
			scanf("%d",&ch4);
			switch(ch4)
			{
			case 1: tp_delete();
				 break;
			case 2: clear();
				 break;
			}
			break;
		case 4: setgraphmode(2);
			goto ex;
		default: printf("\n Invalid Choice. ");
	      }
	      printf("\n\n Press y to continue with this menu, or press any other key to go back to the \n previous menu. ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 5: do
	      {
	      setgraphmode(2);
	      setbkcolor(6);
	      printf("\n\n\t\t\t DOUBLY LINKED LIST:- ");
	      printf("\n\n\t\t *****************************************");
	      printf("\n\n 1) Create a list \t\t\t 2) Display the list \n\n 3) Add before a specified node \t 4) Add after a specified node \n\n 5) Delete a specified node \t\t 6) Previous Menu");
	      printf("\n\n\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		case 1: dll_create();
		break;
		case 2: dll_display();
		break;
		case 3: dll_addbefore();
		break;
		case 4: dll_addafter();
		break;
		case 5: if(root3==NULL)
			 {
			    printf("\n No list created. ");
			    break;
			 }
			printf("\n 1) Delete a node \t\t2) Clear the list \n\n\t Enter your choice: ");
			scanf("%d",&ch4);
			switch(ch4)
			{
			case 1: dll_delete();
				 break;
			case 2: clear2();
			      break;
			}
			break;
		case 6: setgraphmode(2);
			goto ex;
	      }
	      printf("\n Press y to continue, else press any other key to return. ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 6: do
	      {
	      setgraphmode(2);
	      setbkcolor(8);
	      printf("\n\n\t\t\t STACK:- ");
	      printf("\n\n\t\t ***********************");
	      printf("\n\n 1) Push(Dynamic)   \t\t\t2) Pop(Dynamic)   \n\n 3) Peep(Dynamic) \t\t\t4) Push(Static)    \n\n 5) Pop(Static)    \t\t\t6) Display(Static) \n\n 7) Peep(Static)    \t\t\t8) Display(Dynamic) \n\n 9) Previous Menu");
	      printf("\n\n\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		  case 1: ll_push();
		  break;
		  case 2: ll_pop();
		  break;
		  case 3: ll_peep();
		  break;
		  case 4: printf("\n\n Enter the value to be pushed : ");
		   scanf("%d",&val);
		 push(val);
		 break;
	       case 5: val=pop();
	       printf("\n\n Value popped : %d",val);
	       break;
		case 6: disp();
		break;
		case 7: peep();
	       break;
	       case 8: display(root);
		     break;
	       case 9: setgraphmode(2);
		       goto ex;

	      }
	      printf("\n\n Enter y to continue, else press any other key to return. ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 7: do
	      {
	      setgraphmode(2);
	      setbkcolor(4);
	      printf("\n\n\t\t\t CIRCULAR DOUBLY LINKED LIST:- ");
	      printf("\n\n\t\t ************************************************");
	      printf("\n\n 1) Create a list \t\t2) Display \n\n 3) Add after a specified node \t4) Add before a specified node \n\n 5) Delete a node \t\t6) Previous Menu");
	      printf("\n\n\t Enter your choice: ");
	      scanf("%d",&ch2);
	      switch(ch2)
	      {
		case 1: cdll_create();
	       break;
		case 2: cdll_display();
	       break;
		case 3: cdll_addafter();
	       break;
		case 4: cdll_addbefore();
	       break;
		case 5:  if(root3==NULL)
			 {
			    printf("\n No list created. ");
			    break;
			 }
			printf("\n 1) Delete a node \t\t2) Clear the list \n\n\t Enter your choice: ");
			scanf("%d",&ch4);
			switch(ch4)
			{
			case 1: cdll_delete();
				 break;
			case 2: clear2();
			      break;
			}
	       break;
		case 6: setgraphmode(2);
			goto ex;
	      }
	      printf("\n\n Press y to continue, else press any other key to exit. ");
	      y=getch();
	      }while(y=='y');
	      setgraphmode(2);
	      break;
      case 8: exit(0);
      default: printf("\n Invalid Choice. ");
	       goto ex;
   }
  }
  getch();
}