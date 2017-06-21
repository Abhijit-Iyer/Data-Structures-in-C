#include<stdio.h>
#include<alloc.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
struct node
{
	int data;
	struct node *next;
}n;
struct node *start=NULL;
struct node *start1=NULL;
struct DLL
{
	int data;
	struct DLL *next;
	struct DLL *prev;
}m;
struct DLL *start2=NULL;
struct stack
{
	int arr[5];
	int top;
}s;
int gd=DETECT, gm=DETECT;
void xsound();
void welcome();
void xrectangle(int,int,int,int);
void sll();
void create(struct node **);
void display(struct node **);
void Delete();
void insertb();
void inserta();
void create2();
void insertb2();
void Delete2();
void insertao();
void insertbo();
void delo();   //Delete occuerence of node
void removed(); //delete all similar node
void create_assending();
void reverse();
void alternate();
void app();
void noa();
void deln();
void delp();
void tpa();
void scll();    //Single circular linked list
void ccreate();
void cdisplay();
void cdelete();
void cinserta();
void cinsertb();
void dll();      //doubly linked list
void dcreate();
void ddisplay();
void dinserta();
void dinsertb();
void ddelete();
void dcll(); //doubly circular linked list
void dccreate();
void dcdisplay();
void dcinserta();
void dcinsertb();
void dcdelete();
void dstack();
void push();
void pop();
void peep();
void stack();
void spush(int);
void spop();
void speep();
void concatenate();
void concate();
void create2l();
void xsound();
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
void main()
{
	int ch;

	initgraph(&gd, &gm, "C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	welcome();
	system("cls");
	detectgraph(&gd,&gm);
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	while(1)
	{
		printf("\n1-Single Linked List");
		printf("\n2-Single Circular Linked List");
		printf("\n3-Doubly Linked List ");
		printf("\n4-Doubly Circluar Linked List");
		printf("\n5-Stack Implimentaion using Linked List ");
		printf("\n6-Static Stack Implimentation ");
		printf("\n7-Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		clrscr();
		closegraph();
		initgraph(&gd, &gm, "C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);
		switch(ch)
		{
			case 1:
			sll();
			break;
			case 2:
			scll();
			break;
			case 3:
			dll();
			break;
			case 4:
			dcll();
			break;
			case 5:
			dstack();
			break;
			case 6:
			stack();
			break;
			case 7:
			closegraph();
			return;
			default:
			printf("\nWrong choice..");
		}
	}
}
void sll()
{
	int ch;
	while(1)
	{
		clrscr();
		closegraph();
		initgraph(&gd, &gm, "C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);
		printf("\n1-Create");
		printf("\n2-Display");
		printf("\n3-Delete");
		printf("\n4-Insert node before a specific node");
		printf("\n5-Insert node after a specific node");
		printf("\n6-Application of Linked List");
		printf("\n7-Back to Main Menu ");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			create(&start);
			break;
			case 2:
			display(&start);
			break;
			case 3:
			Delete();
			break;
			case 4:
			insertb();
			break;
			case 5:
			inserta();
			break;
			case 6:
			app();
			break;
			case 7:
			return;
			default:
			printf("\nWrong choice .......");
			getch();
		}
		clrscr();
		closegraph();
		initgraph(&gd, &gm, "C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);
	}
}

void create(struct node **start)     //add node at last
{

	struct node *temp,*t;
	t=*start;
	temp=(struct node*)malloc(sizeof(n));
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=NULL;
	if(*start==NULL)
	{
		*start=temp;
		return;
	}
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
}
void display(struct node **start)     //Display
{
	struct node *temp;
	temp=*start;
	if(*start==NULL)
	{
		printf("\nList is empty ............");
		sound(900);
		delay(90);
		nosound();
		getch();
		return;
	}
	printf("\n\nList is:\n\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	getch();
}

void Delete()        //delete by number
{
	int n,i,j;
	struct node *t,*p;
	if(start==NULL)
	{
		system("cls");
		printf("\n\n\n\t");
		textcolor(9);
		cprintf("List is empty ..........");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the number which you want to delete :");
	scanf("%d",&n);
	sound(900);
	delay(90);
	nosound();
	t=start;
	system("cls");
	xsound();
	while(t->data!=n&&t->next!=NULL)
	{
		p=t;
		t=t->next;
	}
	if(t->data!=n)
	{
		printf("\n\n\t");
		setcolor(9);
		cprintf("Value is not found .......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	if(t==start)
	{
		start=start->next;
	}
	else
	{
		p->next=t->next;
	}
	printf("\n\t");
	textcolor(9);
	cprintf("Node has deleted sucessfully...........");
	sound(900);
	delay(90);
	nosound();
	getch();
	free(t);
}
void inserta()            //Insert after
{
	struct node *t,*temp;
	int v,i,j;
	if(start==NULL)
	{
		system("cls");
		printf("\n\n\n\n\t\t");
		textcolor(9);
		cprintf("List is Empty.........");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter node value at which after you want to enter new node ");
	scanf("%d",&v);
	sound(900);
	delay(90);
	nosound();
	t=start;
	system("cls");
	xsound();
	while(t->data!=v&&t->next!=NULL)
	{
		t=t->next;
	}
	if(t->data!=v)
	{
		printf("\n\n\n\t");
		textcolor(9);
		cprintf("Node is not found .......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\n");
	textcolor(9);
	cprintf("Node is present........");
	sound(900);
	delay(90);
	nosound();
	getch();
	temp=(struct node*)malloc(sizeof(n));
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	draw_pixelbackground(BLUE,15);
	printf("\Enter the value :");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=t->next;
	t->next=temp;
}
void insertb()                          //insert before
{
	struct node *temp,*t,*p;
	int v,i,j;
	if(start==NULL)
	{       system("cls");
		printf("\n\n\n\n\t\t");
		textcolor(9);
		cprintf("List is empty ........");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the node value at which before you want to insert:");
	scanf("%d",&v);
	sound(900);
	delay(90);
	nosound();
	t=start;
	system("cls");
	xsound();
	while(t->data!=v&&t->next!=NULL)
	{
		p=t;
		t=t->next;
	}
	if(t->data!=v)
	{
	       printf("\n\n\n\t");
	       textcolor(9);
		cprintf("Node is not found ........");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\n\n\t");

	textcolor(9);
	cprintf("Node is found.....");
	sound(900);
	delay(90);
	nosound();
	getch();
	temp=(struct node*)malloc(sizeof(n));
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	draw_pixelbackground(BLUE,15);
	printf("\nEnter the new node information .:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	if(t==start)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		temp->next=t;
		p->next=temp;
	}
	printf("\nNode has inserted sucessfully.......");
	sound(900);
	delay(90);
	nosound();
	getch();
}
void app()
{
	int ch;
	clrscr();
	clearviewport();
	//initgraph(&gd,&gm,"C:\\tc\\bgi");
	draw_pixelbackground(BLUE,5);
	while(1)
	{
		printf("1-Two pointer application:");
		printf("\n2-Nth Occurance application");
		printf("\n3-Delete all similar node:");
		printf("\n4-Concate two list");
		printf("\n5-Break list in two alternate list");
		printf("\n6-Create list in sorted order ");
		printf("\n7-Reverse the list");
		printf("\n8-Back to Previos menu:");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			tpa();
			break;
			case 2:
			noa();
			break;
			case 3:
			removed(); //delete all similar node
			break;
			case 4:
			concate();
			break;
			case 5:
			alternate();
			break;
			case 6:
			create_assending();
			break;
			case 7:
			reverse();
			break;
			case 8:
			return;
			default:
			printf("\nWrong choice.....");
		}
		initgraph(&gd,&gm,"C:\\tc\\bgi");
		clrscr();
		clearviewport();
		draw_pixelbackground(BLUE,15);
	}
}
void tpa()
{
	int ch;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	clrscr();
	clearviewport();
	draw_pixelbackground(BLUE,15);
	while(1)
	{
		printf("\n1-Create");
		printf("\n2-Insert before a specific node");
		printf("\n3-Delete");
		printf("\n4Display");
		printf("\n5-Back to Previous menu");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			create2();
			break;
			case 2:
			insertb2();
			break;
			case 3:
			Delete2();
			break;
			case 4:
			display(&start);
			break;
			case 5:
			return;
			default:
			printf("\nWrong choice....");
		}
		initgraph(&gd,&gm,"C:\\tc\\bgi");
		clrscr();
		clearviewport();
		draw_pixelbackground(BLUE,15);
	}
}
void create2()
{
	struct node *t;       //create using two pointer only

	if(start==NULL)
	{
		start=(struct node *)malloc(sizeof(n));
		printf("\nEnter value");
		scanf("%d",&start->data);
		sound(900);
		delay(90);
		nosound();

		start->next=NULL;
		return;
	}
	t=start;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=(struct node *)malloc(sizeof(n));
	t=t->next;
	printf("Enter value:");
	scanf("%d",&t->data);
	sound(900);
	delay(90);
	nosound();
	t->next=NULL;
}
void insertb2()     //insert b with out using p pointer
{
	int v;
	struct node *t,*temp;
	if(start==NULL)
	{
	system("cls");
	textcolor(9);
	cprintf("List is Empty......");
	getch();
	sound(900);
	delay(90);
	nosound();

	return;
	}
	printf("\nEnter the value for searching");
	scanf("%d",&v);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	t=start;
	while(t->next->data!=v&&t->next!=NULL&&t->data!=v)
	{
		t=t->next;
	}
	if(t->data==v&&t==start)
	{
		temp=(struct node *)malloc(sizeof(n));
		printf("Enter the value to be insert ");
		scanf("%d",&temp->data);
		sound(900);
		delay(90);
		nosound();
		temp->next=start;
		start=temp;
		return;
	}
	if(t->next->data!=v||t->next==NULL)
	{
		printf("\n Value is not found ");
		sound(900);
		delay(90);
		nosound();
		getch();
		return;
	}
	temp=(struct node *)malloc(sizeof(n));
	printf("Enter the value to be insert ");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();

	temp->next=t->next;
	t->next=temp;
	getch();
}
void Delete2()     //Deleting of node without using 'p' pointer
{
	int v;
	struct node *t;
	if(start==NULL)
	{
		printf("\nList is empty....");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the value to be deleted .....");
	scanf("%d",&v);
	sound(900);
	delay(90);
	nosound();
	xsound();
	t=start;
	while(t->next->data!=v&&t->next!=NULL&&t->data!=v)
	{
		t=t->next;
	}
	if(t->data==v&&t==start)
	{
		start=start->next;
		free(t);
		return;
	}
	if(t->next->data!=v||t->next==NULL)
	{
		printf("\n Node is not found ");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;

	}
	t->next=t->next->next;
}
void  noa()
{
	int ch;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	clrscr();
	clearviewport();
	draw_pixelbackground(BLUE,15);
	while(1)
	{
		printf("\n1-Insert after nth occurence.");
		printf("\n2-Insert before nth occuence");
		printf("\n3-Delete nth occurence node ");
		printf("\n4-Dispaly");
		printf("\n5-Back to Privious Menu");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			insertao();
			break;
			case 2:
			insertbo();
			break;
			case 3:
			delo();
			break;
			case 4:
			display(&start);
			break;
			case 5:
			return;
			default:
			printf("\nWrong choice");
		}
		initgraph(&gd,&gm,"C:\\tc\\bgi");
		clrscr();
		clearviewport();
		draw_pixelbackground(BLUE,15);
	}
}
void insertao()     //Insert after occuerence
{
	struct node *temp,*t,*p;
	int n,o,ctr;
	t=start;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty .......");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the number after which you want to enter: ");
	scanf("%d",&n);
	sound(900);
	delay(90);
	nosound();
	printf("\nEnter the  value of occurence ");
	scanf("%d",&o);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	temp=(struct node*)malloc(sizeof(n));
	ctr=0;
	while(t->next!=NULL&&ctr!=o)
	{
		if(t->data==n)
		{
			ctr++;
		}
		p=t;
		t=t->next;
	}
	if(p->next==NULL&&ctr!=o)
	{
		printf("\nOccuerence of node is not found .......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	clrscr();
	clearviewport();
	draw_pixelbackground(BLUE,15);
	printf("\nEnter the value which you want to insert ");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=NULL;
	if(p==start)
	{
		temp->next=start;
		start=temp;
		textcolor(9);
		return;
	}
	if(ctr==o)
	{
		temp->next=p->next;
		p->next=temp;
		return;
	}
}
void insertbo()     //Insert before occuerence
{
	struct node *temp,*t,*p;
	int n,o,ctr;
	t=start;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		printf("\nList is empty .......");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the number before which you want to enter: ");
	scanf("%d",&n);
	sound(900);
	delay(90);
	nosound();
	printf("\nEnter the  value of occurence ");
	scanf("%d",&o);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	temp=(struct node*)malloc(sizeof(n));
	ctr=0;
	while(t->next!=NULL&&ctr!=o)
	{
		if(t->data==n)
		{
			ctr++;
			if(ctr==o)
			{
				break;
			}
		}
		p=t;
		t=t->next;
	}
	if(t==NULL||ctr!=o)
	{
		printf("\nNode of occuerence is not found .......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	clrscr();
	clearviewport();
	draw_pixelbackground(BLUE,15);
	printf("\nEnter the value which you want to insert ");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=NULL;
	if(t==start)
	{
		temp->next=start;
		start=temp;
		return;
	}
	if(ctr==o)
	{
		temp->next=p->next;
		p->next=temp;
		return;
	}
}
void delo()            //delete occurence of node
{
	int n,val,ctr;
	struct node *t,*old;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		printf("\nList is empty.........");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the value to be deleted ");
	scanf("%d",&val);
	sound(900);
	delay(90);
	nosound();
	printf("\nEnter the nth occurence");
	scanf("%d",&n);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	ctr=0;
	t=start;
	while(t->next!=NULL)
	{
		if(t->data==val)
		{
			ctr++;
			if(ctr==n)
			{
				break;
			}
		}
		old=t;
		t=t->next;
	}
	if(ctr!=n)
	{
		printf("\n\n\n\t");
		textcolor(9);
		cprintf("Occuerence is not found .........");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	if(ctr==n)
	{
		if(t==start)
		{
			start=start->next;
			printf("\n\n\n\t");
			textcolor(9);
			cprintf("Node is deleted sucessfully.....");
			sound(900);
			delay(90);
			nosound();
			getch();
			sound(900);
			delay(90);
			nosound();
			return;
		}
		old->next=t->next;
		printf("\n\n\n\t");
		textcolor(9);
		cprintf("Node is deleted sucessfully.....");

	}
	free(t);
}
void removed()      //remove all similar node
{
	struct node *p,*t,*old;
	int val,i,j;
	if(start==NULL)
	{
		printf("\nList is empty..");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	p=start;
	system("cls");
	for(i=1;i<8;i++)
	{
		printf("\n\n\n\tRemoving all similar node");
		for(j=1;j<10;j++)
		{
			sound(500*j);
			delay(30);
			nosound();
			delay(80);
			printf(".");
		}
		clrscr();
	}

	while(p->next!=NULL)
	{
		val=p->data;
		old=p;
		t=p->next;
		while(t!=NULL)
		{
			if(t->data==val)
			{
				old->next=t->next;
				free(t);
				t=old->next;
				continue;
			}
			old=t;
			t=t->next;
		}
		p=p->next;
	}
}
void alternate()  //Alternate
{
	struct node *temp,*temp1;
	temp=start;
	if(start==NULL)
	{
		printf("\nList is empty ............");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nFirst alternate list is...\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next->next;
	}
	printf("NULL");
	sound(900);
	delay(90);
	nosound();
	temp1=start->next;
	if(temp1==NULL)
	{
		printf("\nSecond alternate list is empty ...");
		getch();
		return;
	}
	printf("\nSecond alternate list is..\n");
	while(temp1!=NULL)
	{
		printf("%d->",temp1->data);
		temp1=temp1->next->next;
	}
	printf("NULL");
	sound(900);
	delay(90);
	nosound();
	getch();
}

void create_assending()
{
	struct node *t,*temp,*r;
	start=NULL;
	temp=start;
	t=start;
	r=(struct node *)malloc(sizeof(n));
	printf("\nEnter data: ");
	scanf("%d",&r->data);
	sound(900);
	delay(90);
	nosound();
	if(t==NULL||t->data>r->data)
	{
		start=r;
		start->next=temp;
	}
	else
	{
		while(temp!=NULL)
		{
			if(temp->data<=r->data&&(temp->next->data>r->data||temp->next==NULL))
			{
				r->next=temp->next;
				temp->next=r;
				return;
			}
			temp=temp->next;
		}
	}
}
void reverse()
{
	struct node *temp2,*old,*temp;
	int i,j;
	temp=start;
	temp2=NULL;
	if(start==NULL)
	{
		printf("\nList is empty.............");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	system("cls");
	for(i=1;i<8;i++)
	{
		printf("\n\n\n\tReversing the List");
		for(j=1;j<10;j++)
		{
			sound(500*j);
			delay(30);
			nosound();
			delay(80);
			printf(".");
		}
		clrscr();
	}
	while(temp!=NULL)
	{
		old=temp;
		temp=temp->next;
		old->next=temp2;
		temp2=old;
	}
	start=old;
}
void xrectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y);
    printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
	gotoxy(i,y);
	printf("%c",205);
    }
    gotoxy(i,y);
    printf("%c",187);
    for (m=y+1;m<b;m++)
    {
	gotoxy(x,m);
	for(i=x;i<l;i++)
	{
	    if(i==x||i==l-1)
	    {
		gotoxy(i,m); printf("%c",186);
	    }

	}

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
	gotoxy(i,m);
	printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);

}

void welcome()
{
    int i;
    sound(900);
    delay(90);
    nosound();
    //system("cls");
    xrectangle(5,3,77,23);
    gotoxy(26,4);
    printf("LINKED LIST IMPLIMENTATION");
    gotoxy(25,5); for(i=0;i<27;i++) printf("%c",196);
    gotoxy(25,8); printf("Designed and Programmed by:");
    gotoxy(25,9);for(i=0;i<27;i++) printf("%c",196);
    gotoxy(33,13); printf("Rajkaran");
    gotoxy(24,20);

    printf("Press Any key to continue...");
    getch();
    sound(900);
    nosound();
}
void scll()
{
	int ch;
	start=NULL;
	clrscr();
	clearviewport();
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	while(1)
	{
		printf("\n1-Create ");
		printf("\n2-Display ");
		printf("\n3-Delete ");
		printf("\n4-Insert afetr a specific node ");
		printf("\n5-Insert before a specific node ");
		printf("\n6-Back to Main Menu ");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			ccreate();
			break;
			case 2:
			cdisplay();
			break;
			case 3:
			cdelete();
			break;
			case 4:
			cinserta();
			break;
			case 5:
			cinsertb();
			break;
			case 6:
			return;
			default :
			printf("\nWrong choice ");
		}
		clrscr();
		clearviewport();
		initgraph(&gd, &gm, "C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);
	}
}
void ccreate()
{
	struct node *temp,*t;
	temp=(struct node*)malloc(sizeof(n));
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	if(start==NULL)
	{
		start=temp;
		start->next=start;
		return;
	}
	t=start;
	while(t->next!=start)
	{
		t=t->next;
	}
	temp->next=t->next;
	t->next=temp;
}
void cdisplay()
{
	struct node *temp;
	temp=start;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty ............");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	do
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	while(temp!=start);
	printf("%d",temp->data);
	sound(900);
	delay(90);
	nosound();
	getch();
	sound(900);
	delay(90);
	nosound();
}
void cinserta()
{
	struct node *temp,*t;
	int v;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is Empty......");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter a value after which you want to enter:");
	scanf("%d",&v);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	t=start;
	while(t->data!=v&&t->next!=start)
	{
		t=t->next;
	}
	if(t->data!=v)
	{
		textcolor(9);
		cprintf("\nNode  is not found........");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	clrscr();
	clearviewport();
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	temp=(struct node*)malloc(sizeof(n));
	printf("\nEnter the info. for new node :");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=t->next;
	t->next=temp;
}
void cinsertb()
{
	struct node *temp,*t,*p,*t1;
	int ch;
	int v;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is Empty......");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter a value before which you want to enter:");
	scanf("%d",&v);
	system("cls");
	xsound();
	t=start;
	while(t->data!=v&&t->next!=start)
	{
		p=t;
		t=t->next;
	}
	if(t->data!=v)
	{
		textcolor(9);
		cprintf("\nNode is not found ........");
		getch();
		return;
	}
	temp=(struct node*)malloc(sizeof(n));
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI ");
	draw_pixelbackground(BLUE,15);
	printf("\nEnter the value you want to enter after that place :");
	scanf("%d",&temp->data);
	if(t==start)
	{
		while(t->next!=start)
		{
			t=t->next;
		}
		temp->next=start;
		start=temp;
		t->next=start;
		return;
	}
	temp->next=t;
	p->next=temp;
}
void cdelete()
{
	int n,ctr;
	struct node *t,*p;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty ..........");
		getch();
		return;
	}
	printf("\nEnter the node info. which you want to delete :");
	scanf("%d",&n);
	t=start;
	system("cls");
	xsound();
	while(t->data!=n&&t->next!=start)
	{
		p=t;
		t=t->next;
	}
	if(t->data!=n)
	{
		textcolor(9);
		cprintf("\nNode is not found .......");
		getch();
		return;
	}
	if(t==start)
	{
		p=t;
		ctr=0;
		while(t->next!=start)
		{
			t=t->next;
			ctr++;
		}
		if(ctr==0)
		{
			start=NULL;
			printf("\n\n\n\t");
			textcolor(9);
			cprintf("Node is deleted sucessfully ");
			getch();
			return;
		}
		start=start->next;
		t->next=start;
	}
	else
	{
		p->next=t->next;
	}
	printf("\n\n\n\t");
	textcolor(9);
	cprintf("Node is deleted sucessfully....");
	free(t);
}
void dll()
{
	int ch;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	while(1)
	{
		printf("\n1-Create ");
		printf("\n2-Display");
		printf("\n3-Insert after a specific node ");
		printf("\n4-Insert before a specific node ");
		printf("\n5-Delete a spcific node ");
		printf("\n6-Back to Main Menu ");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			dcreate();
			break;
			case 2:
			ddisplay();
			break;
			case 3:
			dinserta();
			break;
			case 4:
			dinsertb();
			break;
			case 5:
			ddelete();
			break;
			case 6:
			return;
			default:
			printf("\nWrong choice.....");
		}
		clrscr();
		clearviewport();
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);

	}
}
void dcreate()
{
	struct DLL *temp,*t;
	temp=(struct DLL*)malloc(sizeof(n));
	printf("\nEnter data:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->next=NULL;
	temp->prev=NULL;
	if(start2==NULL)
	{
		start2=temp;
		return;
	}
	t=start2;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=temp;
	temp->prev=t;
}
void ddisplay()
{
	struct DLL *t;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty .....");

		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	t=start2;
	while(t!=NULL)
	{
		printf("%d<->",t->data);
		t=t->next;
	}
	printf("NULL");
	sound(900);
	delay(90);
	nosound();

}
void dinserta()
{
	struct DLL *temp,*t;
	int n;
	if(start2==NULL)
	{
		printf("\n\n\n\t");
		system("cls");
		textcolor(9);
		cprintf("List is empty........");
		getch();
		return;
	}
	t=start2;
	printf("\nEnter a number after which you want to enter the new node info..");
	scanf("%d",&n);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	while(t->data!=n&&t->next!=NULL)
	{
		t=t->next;
	}
	if(t->data!=n)
	{
		textcolor(9);
		cprintf("\nNode is not found ......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	temp=(struct DLL*)malloc(sizeof(m));
	printf("\Enter the info for new node:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	temp->prev=t;
	temp->next=t->next;
	t->next->prev=temp;
	t->next=temp;
}
void dinsertb()
{
	struct DLL *t,*temp;
	int val;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is Empty......");
		getch();
		return;
	}
	t=start2;
	printf("\nEnter a value before which you want to enter :");
	scanf("%d",&val);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	while(t->data!=val&&t->next!=NULL)
	{
		t=t->next;
	}
	if(t->data!=val)
	{
		textcolor(9);
		cprintf("\nNode is not found.......");
		sound(900);
		delay(90);
		nosound();
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	temp=(struct DLL*)malloc(sizeof(m));
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	printf("\nEnter the value of new node:");
	scanf("%d",&temp->data);
	if(t==start2)
	{
		temp->next=start2;
		start2->prev=temp;
		temp->prev=NULL;
		start2=temp;
		return;
	}
	temp->next=t;
	temp->prev=t->prev;
	t->prev->next=temp;
	t->prev=temp;
}

void ddelete()
{
	struct DLL *t,*old;
	int val;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty........");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	t=start2;
	printf("\nEnter a value which you want to delete:");
	scanf("%d",&val);
	system("cls");
	xsound();
	while(t->data!=val&&t->next!=NULL)
	{
		old=t;
		t=t->next;
	}
	if(t==start2)
	{
		start2=start2->next;
		start2->prev=NULL;
		textcolor(9);
		cprintf("Node is deleted ");
		return;
	}
	if(t->data!=val)
	{
		printf("\nNode is not found.......");
		getch();
		return;
	}
	old->next=t->next;
	t->next->prev=old;
	textcolor(9);
	cprintf("Node is deleted ");
	free(t);
}
void dcll()
{
	int ch;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	start2=NULL;
	while(1)
	{
		printf("\n1-Create ");
		printf("\n2-Display");
		printf("\n3-Insert after specific node ");
		printf("\n4-Insert before specific node ");
		printf("\n5-Delete a specific node ");
		printf("\n6-Back to Main Menu");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			dccreate();
			break;
			case 2:
			dcdisplay();
			break;
			case 3:
			dcinserta();
			break;
			case 4:
			dcinsertb();
			break;
			case 5:
			dcdelete();
			break;
			case 6:
			return;
			default:
			printf("\nWrong choice.");
			sound(900);
			delay(90);
			nosound();
		}
		clrscr();
		clearviewport();
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);
	}
}
void dccreate()
{
	struct DLL *temp,*t;
	temp=(struct DLL *)malloc(sizeof(m));
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();
	if(start2==NULL)
	{
		start2=temp;
		start2->next=start2->prev=start2;
		return;
	}
	t=start2;
	while(t->next!=start2)
	{
		t=t->next;
	}
	temp->next=start2;
	t->next=temp;
	temp->prev=t;
	start2->prev=temp;
}
void dcdisplay()
{
	struct DLL *t;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty .....");
		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	t=start2;
	do
	{
		printf("%d<->",t->data);
		t=t->next;
	}
	while(t!=start2);
	printf("%d",t->data);
	sound(900);
	delay(90);
	nosound();

}
void dcinserta()
{
	struct DLL *t,*temp;
	int val;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty ....");
		sound(900);
		delay(90);
		nosound();

		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	printf("\nEnter the info of node after which you want to insert ");
	scanf("%d",&val);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	t=start2;
	while(t->data!=val&&t->next!=start2)
	{
		t=t->next;
	}
	if(t->data!=val)
	{
		printf("\nNode is not found ...");
		sound(900);
		delay(90);
		nosound();

		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);
	temp=(struct DLL *)malloc(sizeof(m));
	printf("\nEnter the info. of new node ");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();

	temp->prev=t;
	t->next->prev=temp;
	temp->next=t->next;
	t->next=temp;
}
void dcinsertb()
{
	struct DLL *temp,*t;
	int val;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is empty....");
		getch();
		sound(900);
		delay(90);
		nosound();
		return;
	}
	printf("\nEnter the info of node before which you want to insert ");
	scanf("%d",&val);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	t=start2;
	while(t->data!=val&&t->next!=start2)
	{
		t=t->next;
	}
	if(t->data!=val)
	{
		textcolor(9);
		cprintf("\nNode is not found ....");
		sound(900);
		delay(90);
		nosound();

		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	temp=(struct DLL *)malloc(sizeof(m));
	printf("\nEnter the info of new node ");
	scanf("%d",&temp->data);
	sound(900);
	delay(90);
	nosound();

	temp->prev=t->prev;
	temp->next=t;
	t->prev->next=temp;
	t->prev=temp;
	if(t==start2)
	{
		start2=temp;
	}
}
void dcdelete()
{
	struct DLL *t;
	int val;
	int ctr=0;
	if(start2==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nList is Empty......");
		getch();

		sound(900);
		delay(90);
		nosound();

		return;
	}
	printf("\nEnter the info of node which you want to delete ");
	scanf("%d",&val);
	sound(900);
	delay(90);
	nosound();
	system("cls");
	xsound();
	t=start2;
	while(t->data!=val&&t->next!=start2)
	{
		t=t->next;
		ctr++;
	}
	if(t->data!=val)
	{
		textcolor(9);
		cprintf("\nNode is not found ....");
		sound(900);
		delay(90);
		nosound();

		getch();
		sound(900);
		delay(90);
		nosound();

		return;

	}
	if(ctr==0&&t->next==start2&&t->data==val)
	{
		start2=NULL;
		textcolor(9);
		cprintf("Node is deleted sucessfully ....");
		sound(900);
		delay(90);
		nosound();

		getch();
		sound(900);
		delay(90);
		nosound();


		return;
	}
	if(t==start2)
	{
		start2=start2->next;
	}
	t->prev->next=t->next;
	t->next->prev=t->prev;
	textcolor(9);
	cprintf("Node is deleted sucessfully ....");
	sound(900);
	delay(90);
	nosound();


}
void xsound()
{
	int i,j;
	for(i=1;i<8;i++)
	{
		printf("\n\n\n\tSearching");
		for(j=1;j<10;j++)
		{
			sound(500*j);
			delay(30);
			nosound();
			delay(80);
			printf(".");
		}
		clrscr();
	}

}
void dstack()
{
	int ch;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	start=NULL;
	while(1)
	{
		printf("\n1-Push ");
		printf("\n2-Pop ");
		printf("\n3-Peep");
		printf("\n4-Back to Main Menu ");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		clrscr();
		switch(ch)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			peep();
			break;
			case 4:
			return;
			default:
			printf("\nWrong choice ...");
			sound(900);
			delay(90);
			nosound();

		}
		clrscr();
		clearviewport();
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);

	}
}
void push()
{
	struct node *t=start;
	if(start==NULL)
	{
		start=(struct node *)malloc(sizeof(n));
		printf("\nEnter the data:");
		scanf("%d",&start->data);
		sound(900);
		delay(90);
		nosound();
		start->next=NULL;
		t=start;
		return;
	 }
	 start=(struct node *)malloc(sizeof(n));
	 printf("\nEnter data:");
	 scanf("%d",&start->data);
	 sound(900);
	 delay(90);
	 nosound();

	 start->next=t;
}
void pop()
{
	struct node *t;
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nStack in  underflow .....");

		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	printf("\nDeleted data is:%d",start->data);
	start=start->next;
}
void peep()
{
	if(start==NULL)
	{
		system("cls");
		textcolor(9);
		cprintf("\nStack in underflow....");
		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	printf("\nPeep element is:%d",start->data);
	sound(900);
	delay(90);
	nosound();

}
void stack()
{
	int ch,v;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	s.top=-1;
	while(1)
	{

		printf("\n1-Push");
		printf("\n2-Pop");
		printf("\n3-Peep");
		printf("\n4-Back to Main Menu");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			printf("\nEnter data:");
			scanf("%d",&v);
			sound(900);
			delay(90);
			nosound();
			spush(v);
			break;
			case 2:
			spop();
			break;
			case 3:
			speep();
			break;
			case 4:
			return;
			default:
			printf("\nWrong choice .....");
			sound(900);
			delay(90);
			nosound();

		}
	}

}
void spush(int v)
{
	if(s.top==4)
	{
		system("cls");
		textcolor(9);
		cprintf("\nStack is Overflow.....");
		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	s.top++;
	s.arr[s.top]=v;
}
void spop()
{
	int p;
	if(s.top==-1)
	{
		system("cls");
		textcolor(9);
		cprintf("\nStack  in Underflow.....");
		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	p=s.arr[s.top];
	s.top--;
	printf("Deleted data is %d",p);
	sound(900);
	delay(90);
	nosound();

}
void speep()
{
	if(s.top==-1)
	{
		printf("\nStack in Underflow.....");
		getch();
		sound(900);
		delay(90);
		nosound();

		return;
	}
	printf("\nPeep element of stack is:%d",s.arr[s.top]);
	sound(900);
	delay(90);
	nosound();

}
void conactenate()
{

	int ch,c;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	while(1)
	{
		printf("1-Create two list ");
		printf("\n2-Concatenate");
		printf("\n3-Display");
		printf("\n4-Exit ");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			create2l();
			break;
			case 2:
			concate();
			display(&start);
			break;
			case 3:
			sound(900);
			delay(90);
			nosound();
			printf("\n1-First list ");
			printf("\n2-Second list ");
			printf("Enter choice ");
			scanf("%d",&c);
			sound(900);
			delay(90);
			nosound();

			if(c==1)
			display(&start);
			else if(c==2)
			display(&start1);
			else
			printf("Wrong choice...");
			sound(900);
			delay(90);
			nosound();

			break;
			case 4:
			return;
			default :
			printf("\nWrong choice .......");
			sound(900);
			delay(90);
			nosound();

		}

	}
}
void create2l()
{
	int ch;
	clrscr();
	clearviewport();
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	draw_pixelbackground(BLUE,15);

	while(1)
	{
		printf("\n1-Add in first ");
		printf("\n2-Add in second ");
		printf("\n3-Stop");
		printf("\nEnter your choice ");
		scanf("%d",&ch);
		sound(900);
		delay(90);
		nosound();
		switch(ch)
		{
			case 1:
			create(&start);
			break;
			case 2:
			create(&start1);
			break;
			case 3:
			return;
			default:
			printf("\nWrong choice");
			sound(900);
			delay(90);
			nosound();

		}
		clrscr();
		clearviewport();
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		draw_pixelbackground(BLUE,15);

	}
}
void concate()
{
	struct node *t,*t1;
	t=start;
	t1=start1;
	if(t==NULL)
	{

		t=t1;
		return;

	}
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next=t1;
	printf("\nAfter concatenation resultant list is :\n");
	sound(900);
	delay(90);
	nosound();

	start1=t1;
	free(t1);

}

