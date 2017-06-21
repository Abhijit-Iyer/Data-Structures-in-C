#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int i;
struct stack
{
  int stk[10];
  int top;
}s;
struct list
{
  int val;
  struct list *next;
}node;
struct list *root=NULL;
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
  for(i=0;i<=s.top;i++)
  printf("  %d",s.stk[i]);
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
void ll_disp()
{
  struct list *t;
  t=root;
  if(root==NULL)
  {
    printf("\n No list exists. ");
  }
  while(t!=NULL)
  {
    printf("\t %d",t->val);
    t=t->next;
  }
  t==root;
}
void ll_pop()
{
  root=root->next;
}
void main()
{
  int ch,val;
  s.top=-1;
  clrscr();
  while(1)
  {
    printf("\n 1) Push(Static)");
    printf("\n 2) Pop Operation(Static)");
    printf("\n 3) Push(Dynamic)");
    printf("\n 4) Pop(Dynamic)");
    printf("\n 5) Display(static)");
    printf("\n 6) Display(Dynamic)");
    printf("\n 7) Exit");
    printf("\n\tEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\n Enter the value to be pushed : ");
	     scanf("%d",&val);
	     push(val);
	     break;
      case 2:val=pop();
	     printf("\n Value popped : %d",val);
	     break;
      case 3: ll_push();
	      break;
      case 4: ll_pop();
	      break;
      case 5: disp();
	      break;
      case 6: ll_disp();
	      break;
      case 7:exit(0);
      default:printf("\n Invalid Input");
    }
  }
  getch();
}


