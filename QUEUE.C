#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
int c=0,o=0;
struct  queue
{
  int a[10];
  int f,r;
}q;
struct que
{
   int val;
   struct que *next;
}node;
struct que *root=NULL;
//struct que *f=NULL;
//struct que *r=NULL;
void loading()
{
  setgraphmode(2);
  delay(500);
  printf("\n\n\n\n\n\n\n\t\t\t LOADING");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
  printf(".");
  snd();
  delay(250);
}
void load2()
{
  setgraphmode(2);
  delay(500);
  printf("\n\n\n\n\n\n\n\t\t\t LOADING");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
  printf(".");
  snd();
  delay(150);
}
int snd()
{
   sound(500);
    delay(100);
    nosound();
    return 0;
}
int snd2()
{
   sound(1000);
   delay(100);
   nosound();
   return 0;
}
void rear_insert(int v)
{
  if(q.r==10)
  {
    delay(100);
    snd();
    printf("\n The queue is full. ");
    return;
  }
  q.a[q.r]=v;
  q.r++;
}
void front_delete()
{
  int v;
  if(q.f==q.r)
  {
    delay(100);
    snd();
    printf("\n The queue is empty");
    return;
  }
  c--;
  v=q.a[q.f];
  snd();
  printf("\n Deleted element = %d",v);
  q.f++;
}
void stat_display()
{
   int i;
   if(q.f==q.r)
   {
      printf("\n The queue is empty ");
      return;
   }
   printf("\n\n The Queue:- \n");
   for(i=q.f;i<=q.r-1;i++)
   {
      printf("| %d |",q.a[i]);
      snd2();
      delay(300);
   }
}
void dy_insert()
{
  struct que *temp,*t;
  t=root;
  temp=(struct que *)malloc(sizeof(node));
  if(root==NULL)
  {
    snd();
     printf("\n Enter the value to be inserted: ");
     scanf("%d",&temp->val);
     snd2();
     temp->next=NULL;
     root=temp;
     //r=temp;
    // f=temp;
     return;
  }
    snd();
    printf("\n Enter the value to be inserted: ");
    scanf("%d",&temp->val);
    snd2();
    temp->next=root;
    root=temp;
   // f=temp;
   // r=root;
}
void dy_delete()
{
  struct que *t;
  t=root;
  if(root==NULL)
  {
    snd2();
    printf("\n The queue is empty: ");
    snd2();
    return;
  }
  while(t->next->next!=NULL)
  {
    t=t->next;
  }
  free(t->next->next);
  t->next=NULL;
}
void dy_display()
{
  struct que *t;
  t=root;
  if(root==NULL)
  {
    snd2();
    printf("\n The queue is empty. ");
    snd2();
     return;
  }
  while(t!=NULL)
  {
    if(t->next!=NULL)
    {
     delay(200);
     snd2();
     printf("| %d | ->",t->val);
    }
     else
     {
       delay(200);
       snd2();
       printf("| %d |",t->val);
     }
     t=t->next;
  }
}
void sq_delete()
{
  int v,i;
  if(q.f==q.r)
  {
     snd();
     printf("\n The queue is empty. "); return;
  }
  v=q.a[q.f];
  printf("\n Deleted Element = %d",v);
  for(i=1;i<q.r;i++)
  {
    q.a[i-1]=q.a[i];
  }
  q.r--;
}
void cq_insert(int v)
{
  if(c==10)
  {
    snd();
    printf("\n The queue is full. ");   return;
  }
  q.a[q.r]=v;
  c++;
  q.r=(q.r+1)%10;
}
void cq_delete()
{
  int v;
  if(q.r==0)
  {
    printf("\n The queue is empty. "); return;
  }
  v=q.a[q.f];
  c--;
  snd2();
  printf("\n Deleted Element = %d ",v);
  q.f=(q.f+1)%10;
}
void cq_display()
{
  int i;
  if(c==0)
  {
      printf("\n The queue is empty. "); return;
  }
  for(i=q.f;i<=c-1;i++)
  {
     printf("\n| %d |",q.a[i]);
  }
}
void dy_cq_insert()
{
  struct que *temp,*t;
  t=root;
  temp=(struct que *)malloc(sizeof(node));
  if(root==NULL)
  {
    snd();
     printf("\n Enter the value to be inserted: ");
     scanf("%d",&temp->val);
     snd2();
     temp->next=temp;
     root=temp;
     return;
  }
    snd();
    printf("\n Enter the value to be inserted: ");
    scanf("%d",&temp->val);
    snd2();
    temp->next=root;
    root=temp;
   do
    {
      t=t->next;
    }while(t->next!=temp->next);
    t->next=root;
}
void dy_cq_delete()
{
  struct que *t;
  t=root;
  if(root==NULL)
  {
    snd2();
    printf("\n The queue is empty. ");
    snd2();
    return;
  }
  if(o==0)
  {
     root=NULL;
     snd();
     printf("\n The list is empty now. ");
     return;
  }
  while(t->next->next!=root)
  {
    t=t->next;
  }
  t->next->next=NULL;
  t->next=root;
  o--;
}
void dy_cq_display()
{
  struct que *t;
  t=root;
  if(root==NULL)
  {
    snd2();
    printf("\n The queue is empty. ");
    snd2();
    return;
  }
  do
  {
    if(t->next!=root)
    {
     delay(200);
     snd2();
     printf("| %d | ->",t->val);
    }
    else
    {
      delay(200);
      snd2();
      printf("| %d |",t->val);
    }
     t=t->next;
  }while(t!=root);
}
dq_ipr_delete(int ch)
{
  int v;
  switch(ch)
  {
    case 1: if(q.f==q.r)
	    {
	      snd2();
	      printf("\n The queue is empty. ");
	      snd2();
	      return;
	    }
	    v=q.a[q.f];
	    snd2();
	    printf("\n Element Deleted = %d",v);
	    q.f++;
	    break;
    case 2:if(q.f==q.r)
	    {
	      snd2();
	      printf("\n The queue is empty. ");
	      snd2();
	      return;
	    }
	    v=q.a[q.r-1];
	    snd2();
	    printf("\n Element Deleted = %d",v);
	    q.r--;
	    break;
  }
}
void dq_opr_insert(int ch)
{
  int p,i;
  switch(ch)
  {
    case 1:  if(q.f==0&&q.r==10)
	     {
	       snd2();
	       printf("\n Queue is full. ");
	       snd2();
	       return;
	     }
	     if(c==0)
	     {
	       snd();
	       printf("\n Enter the element you'd like to insert: ");
	       scanf("%d",&p);
	       snd2();
	       q.a[q.f]=p;
	       q.r++;
	       c++;
	       return;
	     }
	    if(c>0)
	    {
	      for(i=q.r;i>q.f;i--)
	      {
		 q.a[i]=q.a[i-1];
	      }
	      q.r++;
	    }
	    snd();
	    printf("\n Enter the element you'd like to insert: ");
	    scanf("%d",&p);
	    snd2();
	    q.a[q.f]=p;
	    c++;
	    break;
    case 2: if(q.f==0&&q.r==10)
	    {
	      snd();
	      printf("\n The queue is full. ");
	      snd2();
	      return;
	    }
	    if(q.r==10&&q.f!=0)
	    {
	      for(i=q.f;i<q.r;i++)
	      {
		q.a[i-1]=q.a[i];
	      }
	      q.f--;
	    }
	      snd();
	      printf("\n Enter the number you'd like to insert: ");
	      scanf("%d",&p);
	      snd2();
	      q.a[q.r]=p;
	      q.r++;
	      c++;
	    break;
    }
}
void dy_dq_ipr_delete(int ch)
{
   struct que *t;
   switch(ch)
   {
      case 1: dy_delete();
	      break;
      case 2: t=root;
	      root=root->next;
	     // free(t);
   }
}
void dy_dq_opr_insert(int ch)
{
  struct que *t,*temp;
  t=root;
  switch(ch)
  {
    case 1:
	   temp=(struct que *)malloc(sizeof(node));
	   snd();
	   printf("\n Enter the value to be inserted: ");
	   scanf("%d",&temp->val);
	   snd2();
	   temp->next=NULL;
	   if(root==NULL)
	   {
	     root=temp;
	   }
	   while(t->next!=NULL)
	   {
	     t=t->next;
	   }
	   t->next=temp;
	   break;
    case 2:
	   dy_insert();
	   break;
  }
}
void main()
{
  int ch,v,ch1,gd=DETECT,gm,ch2,ch3,i=0;
  char y,t;
  q.f=0;
  q.r=0;
  clrscr();
  initgraph(&gd,&gm,"C:\\TC\\BGI");
ax:     setgraphmode(2);
	setbkcolor(9);
  while(1)
  {
    delay(750);
    printf("\n\t\t\t\t==============");
    printf("\n\t\t\t\t||  QUEUES  || ");
    printf("\n\t\t\t\t==============");
    delay(750);
    printf("\n\n 1) Static Implementation");
    snd();
    delay(750);
    printf("\t\t 2) Dynamic Implementation ");
    snd();
    delay(750);
    printf("\n\n\t\t\t      3) Exit");
    snd();
    delay(750);
    printf("\n\n\t\t\t Enter your choice: ");
    snd();
    scanf("%d",&ch);
    snd2();
    switch(ch)
    {
    case 1: do
	      { loading();
	  ex:	setgraphmode(2);
		setbkcolor(13);
		printf("\n\n\t\t\t     STATIC QUEUES:- ");
		printf("\n\n\t\t ********************************************");
		snd();
		delay(500);
		printf("\n\n\n\t1) Simple Queue ");
		snd();
		delay(500);
		printf("\t\t\t2) Shifted Queue  ");
		snd();
		delay(500);
		printf("\n\n\t3) Circular Queue(Static) ");
		snd();
		delay(500);
		printf("\t\t4) Dequeue(Input Restricted) ");
		snd();
		delay(500);
		printf("\n\n\t5) Dequeue(Output Restricted) ");
		snd();
		delay(500);
		printf("\t\t6)Previous Menu ");
		snd();
		delay(500);
		printf("\n\n\t\t   Enter your choice: ");
		snd();
		scanf("%d",&ch2);
		snd2();
		switch(ch2)
		{
		 case 1: load2();
			 do
			 {
			 setgraphmode(2);
			 setbkcolor(10);
			 printf("\n\n\t\t\t     SIMPLE QUEUE:- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 printf("\n\n 1) Insert  ");
			 snd();
			 printf("\t\t 2) Delete ");
			 snd();
			 delay(500);
			 printf("\n\n 3) Display ");
			 snd();
			 printf("\t\t 4) Previous Menu");
			 snd();
			 delay(500);
			 printf("\n\n\t Enter your choice: ");
			 snd();
			 scanf("%d",&ch3);
			 snd2();
			 switch(ch3)
			 {
			    case 1: snd();
				    printf("\n Enter the element to be inserted: ");
				    scanf("%d",&v);
				    snd2();
				    rear_insert(v);
				   // load2();
			    break;
			    case 2: snd();
				    front_delete();
				   // load2();
			    break;
			    case 3: snd();
				    stat_display();
				   // load2();
			    break;
			    case 4: //load2();
				    goto ex;
				    break;
			 }
			  printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			  y=getch();
			  }while(y=='y');
			   load2();
			   goto ex;
			   break;
		 case 2:   load2();
			   do
			   {
			     setgraphmode(2);
			     setbkcolor(12);
			     printf("\n\n\t\t\t     SHIFTED QUEUE:- ");
			     printf("\n\n\t\t ********************************************");
			     delay(500);
			     printf("\n\n 1) Insert  ");
			     snd();
			     printf("\t\t 2) Delete ");
			     delay(500);
			     snd();
			     printf("\n\n 3) Display ");
			     snd();
			     printf("\t\t 4) Previous Menu");
			     delay(500);
			     snd();
			     printf("\n\n\t Enter your choice: ");
			     scanf("%d",&ch3);
			     snd2();
			     switch(ch3)
			     {
				case 1: snd();
				printf("\n Enter the element to be inserted: ");
				scanf("%d",&v);
				rear_insert(v);
				break;
			   case 2: snd();
				   sq_delete();
					 break;
			   case 3: snd();
				   stat_display();
					 break;
			   case 4: snd();
				   goto ex;
			 }
			 printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			 y=getch();
			 }while(y=='y');
			 load2();
			 goto ex;
			 break;
		 case 3:   load2();
			   do
			   {
			     setgraphmode(2);
			   setbkcolor(8);
			   printf("\n\n\t\t\t     CIRCULAR QUEUE:- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			      printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: printf("\n Enter the element to be inserted: ");
					scanf("%d",&v);
					cq_insert(v);
					break;
				case 2: cq_delete();
					break;
				case 3: cq_display();
					break;
				case 4: goto ex;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   load2();
			   goto ex;
			   break;
		 case 4:
			   load2();
			   do
			   {
			      setgraphmode(2);
			   setbkcolor(9);
			   printf("\n\n\t\t\t     DEQUEUE(INPUT RESTRICTED):- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			      printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: printf("\n Enter the value to be inserted: ");
					scanf("%d",&v);
					rear_insert(v);
					break;
				case 2: printf("\n Enter whether you'd like to delete from (1)front or (2)rear: ");
					 scanf("%d",&ch1);
					 dq_ipr_delete(ch1);
						break;
				case 3: stat_display();
						break;
				case 4: goto ex;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   load2();
			   goto ex;
			 break;
		 case 5:   load2();
			   do
			   {
			      setgraphmode(2);
			   setbkcolor(11);
			   printf("\n\n\t\t\t  DEQUEUE(OUTPUT RESTRICTED):- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			      printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: case 17: printf("\n Enter whether you'd like to insert at (1)front or (2)rear: ");
					scanf("%d",&ch1);
					snd2();
					dq_opr_insert(ch1);
					break;
				case 2: front_delete();
					break;
				case 3: stat_display();
					 break;
				case 4: goto ex;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   goto ax;
			 break;
		 case 6: goto ax;
			 break;
		 default: printf("\n Invalid Choice. ");
	      }
	   printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
	      y=getch();
	      }while(y=='y');
	      goto ax;
	      break;
    case 2:
	      do
	      {
    ey:	        load2();
		setgraphmode(2);
		setbkcolor(12);
		printf("\n\n\t\t\t     DYNAMIC QUEUES :- ");
		printf("\n\n\t\t ********************************************");
		delay(500);
		snd();
		printf("\n\n\n1) Simple Queue ");
		printf("\t\t 2) Circular Queue ");
		delay(500);
		snd();
		printf("\n\n3) Dequeue(Input Restricted)     4) Dequeue(Output Restricted) ");
		delay(500);
		snd();
		printf("\n\n5) Previous Menu");
		delay(500);
		printf("\n\n\t\t   Enter our choice: ");
		scanf("%d",&ch2);
		snd2();
		switch(ch2)
		{
		 case 1: load2();
			 do
			 {
			 setgraphmode(2);
			 setbkcolor(14);
			 printf("\n\n\t\t\t     SIMPLE QUEUE:- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			 printf("\n\n\t Enter your choice: ");
			 scanf("%d",&ch3);
			 snd2();
			 switch(ch3)
			 {
			    case 1: dy_insert();
			    break;
			    case 2: dy_delete();
			    break;
			    case 3: dy_display();
			    break;
			    case 4: goto ey;
			 }
			  printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			  y=getch();
			  }while(y=='y');
			   goto ey;
			   break;
		 case 2:   load2();
			   do
			   {
			     setgraphmode(2);
			   setbkcolor(13);
			      printf("\n\n\t\t\t     CIRCULAR QUEUE:- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			      printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: dy_cq_insert();
					  break;
				case 2: dy_cq_delete();
					break;
				case 3: dy_cq_display();
					break;
				case 4: goto ey;
					break;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   goto ey;
			   break;
		 case 3:   load2();
			   do
			   {
			     setgraphmode(2);
			   setbkcolor(13);
			   printf("\n\n\t\t\t     DEQUEUE( INPUT RESTRICED) :- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			    printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: dy_insert();
					break;
				case 2: snd();
					printf("\n Enter whether you'd like to delete from (1)front or (2)rear: ");
					scanf("%d",&ch1);
					snd2();
					dy_dq_ipr_delete(ch1);
					break;
				case 3: dy_display();
					break;
				case 4: goto ey;
					break;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   goto ey;
			   break;
		 case 4:   load2();
			   do
			   {
			      setgraphmode(2);
			   setbkcolor(13);
			   printf("\n\n\t\t\t     DEQUEUE(OUTPUT RESTRICTED) :- ");
			 printf("\n\n\t\t ********************************************");
			 delay(500);
			 snd();
			 printf("\n\n 1) Insert  ");
			 printf("\t\t 2) Delete ");
			 delay(500);
			 snd();
			 printf("\n\n 3) Display ");
			 printf("\t\t 4) Previous Menu");
			 delay(500);
			 snd();
			      printf("\n\n\t Enter your choice: ");
			      scanf("%d",&ch3);
			      snd2();
			      switch(ch3)
			      {
				case 1: snd();
					printf("\n Enter whether you'd like to insert from (1)front or (2)rear ");
					scanf("%d",&ch1);
					snd2();
					dy_dq_opr_insert(ch1);
					break;
				case 2: dy_delete();
					break;
				 case 3: dy_display();
					break;
				case 4: goto ey;
					break;
			      }
			      printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
			      y=getch();
			   }while(y=='y');
			   goto ey;
			 break;
		 case 5: goto ax;
		 default: printf("\n Invalid Choice. ");
			  break;
	      }
	   printf("\n\n Enter 'y' to continue with this menu, or enter any other key to return to the \n previous menu.");
	      y=getch();
	      }while(y=='y');
	      goto ax;
	      break;
    case 3: exit(0);
    default: do
	     {
	     setgraphmode(2);
	     delay(1000);
	     snd();
	     snd2();
	     printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t INVALID CHOICE ");
	     delay(1000);
	     snd();
	     snd2();
	     printf(" ");
	     i++;
	     }while(y=getch());
	     getch();
	     goto ax;
    }
  }
  getch();
}