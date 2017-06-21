#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct list2
{
   int coeff;
   int exp;
   struct list2 *next;
}node;
struct list2 *root4=NULL;
struct list2 *root5=NULL;
struct list2 *root6=NULL;
/*struct list2
{
   int coeff;
   int exp;
   struct list2 *next;
}node;
struct list2 *root1=NULL;
struct list2 *root2=NULL;
struct list2 *root3=NULL;*/
void create_two_lists()
{
  struct list2 *temp,*t;
  int ch,a,y;
  printf("\n Creation of list 1:-");
		do
		{
		t=root4;
		temp=(struct list2 *)malloc(sizeof(node));
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
void display(struct list2 *root)
{
  struct list2 *t;
  t=root;
  while(t!=NULL)
  {
    printf("\t %d |",t->coeff);
    printf(" %d",t->exp);
    t=t->next;
  }
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
void main()
{
  int ch;
  clrscr();
  while(1)
  {
  printf("\n 1) Create 2) Display 3) Add 4) Mult 5) Exit");
  printf("\n Enter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: create_two_lists();
	    break;
    case 2: printf("\n List 1:- ");
	    display(root4);
	    printf("\n List 2:- ");
	    display(root5);
	    printf("\n Added List:- ");
	    display(root6);
	    break;
    case 3: add_poly();
	     break;
    case 4: mult_poly();
	     break;
    case 5: exit(0);
    default: printf("\n Invalid Choice. ");
  }
  }
  getch();
}