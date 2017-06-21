#include<stdio.h>
#include<conio.h>
void array_create(int *p,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("\n Enter the value at a[%d]: ",i);
    scanf("%d",(p+i));
  }
  clrscr();
  printf("\n The array is: \n");
  for(i=0;i<n;i++)
  {
    printf("\t%d",*(p+i));
  }
  printf("\n");
}
void linear_search(int *p,int n)
{
   int i,item;
   printf("\n\n Enter the ele,ent to be searched: ");
   scanf("%d",&item);
   for(i=0;i<n;i++)
   {
     if(*(p+i)==item)
     {
       printf("\n\n\t Element found. ");
       return;
     }
   }
   printf("\n\n\t Element not found. ");
}
void binary_search(int *p,int n)
{
  int i,item,low,high,mid;
  printf("\n\n Enter the value to be searched: ");
  scanf("%d",&item);
  low=0;
  high=n-1;
  while(low<=high)
  {
    mid=(low+high)/2;
  if(*(p+mid)==item)
  {
    printf("\n\n\t Element Found. ");
    return;
  }
  if(item<*(p+mid))
  {
    high=mid-1;
  }
  if(item>*(p+mid))
  {
    low=mid+1;
  }
  }
  printf("\n\n\t Element not found. ");
}
void selection_sort(int *p,int n)
{
 int i,j,temp;
 for(i=0;i<n-1;i++)
 {
   for(j=i+1;j<n;j++)
   {
     if(*(p+i)>*(p+j))
     {
       temp=*(p+i);
       *(p+i)=*(p+j);
       *(p+j)=temp;
     }
   }
 }
 clrscr();
 printf("\n\n The sorted array is: \n");
 for(i=0;i<n;i++)
 {
   printf("\t %d",*(p+i));
 }
}
void selection_sort_advanced(int *p,int n)
{
 int i,j,k,temp;
 for(i=0;i<n;i++)
 {
   k=i;
   for(j=i+1;j<n;j++)
   {
     if(*(p+k)>*(p+j))
     {
      k=j;
     }
   }
   if(i!=k)
   {
     temp=*(p+k);
     *(p+k)=*(p+i);
     *(p+i)=temp;
   }
 }
 clrscr();
 printf("\n\n The sorted array is: ");
 for(i=0;i<n;i++)
 {
   printf("\t %d",*(p+i));
 }
}
void bubble_sort(int *p,int n)
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(*(p+j)>*(p+j+1))
      {
	temp=*(p+j);
	*(p+j)=*(p+j+1);
	*(p+j+1)=temp;
      }
    }
  }
  clrscr();
  printf("\n\n The sorted list:- \n");
  for(i=0;i<n;i++)
 {
   printf("\t %d",*(p+i));
 }
}
void bubble_sort_advanced(int *p,int n)
{
  int i,j,temp,flag;
  for(i=0;i<n-1;i++)
  {
    flag=0;
    for(j=0;j<n-i;j++)
    {
      if(*(p+j)>*(p+j+1))
      {
	flag=1;
	temp=*(p+j);
	*(p+j)=*(p+j+1);
	*(p+j+1)=temp;
      }
    }
    if(flag==0)
    {
      break;
    }
  }
  clrscr();
  printf("\n\n The sorted list:- \n");
  for(i=0;i<n;i++)
  {
    printf("\t %d",*(p+i));
  }
}
void insertion_sort(int *p,int n)
{
  int i,temp,j;
  for(i=0;i<n;i++)
  {
    for(j=i;j>0;j--)
    {
      if(*(p+j)<*(p+j-1))
      {
	temp=*(p+j);
	*(p+j)=*(p+j-1);
	*(p+j-1)=temp;
      }
    }
  }
  clrscr();
  printf("\n\n The sorted list:- \n");
  for(i=0;i<n;i++)
  {
     printf("\t %d",*(p+i));
  }
}
void insertion_sort_advanced(int *p,int n)
{
  int i,temp,j;
  for(i=1;i<n;i++)
  {
    for(j=i;j>0;j--)
    {
      if(*(p+j)<*(p+j-1))
      {
	temp=*(p+j);
	*(p+j)=*(p+j-1);
	*(p+j-1)=temp;
      }
      else
      {
	break;
      }
    }
  }
  clrscr();
  printf("\n\n The sorted list:- \n");
  for(i=0;i<n;i++)
  {
     printf("\t %d",*(p+i));
  }
}
void shaker_sort(int *p,int n)
{
  int i,j,k,temp;
  for(i=0,j=n-1;i<j;i++)
  {
    for(k=i;k<j;k++)
    {
      if(*(p+k)>*(p+k+1))
      {
	temp=*(p+k);
	*(p+k)=*(p+k+1);
	*(p+k+1)=temp;
      }
    }
    j=j-1;
    for(k=j;k>i;k--)
    {
	if(*(p+k-1)>*(p+k))
	{
	  temp=*(p+k);
	  *(p+k)=*(p+k-1);
	  *(p+k-1)=temp;
	}
    }
  }
  clrscr();
  printf("\n\n The sorted list:- \n");
  for(i=0;i<n;i++)
  {
    printf("\t %d",*(p+i));
  }
}
void merge_sort(int *p,int *q,int n,int m)
{
  int i=0,j=0,c[10],k=0;
  while(i<n&&j<m)
  {
    if(*(p+i)>*(q+j))
    {
      *(c+(k++))=*(q+j);
      j++;
    }
    else
    {
      *(c+(k++))=*(p+i);
      i++;
    }
  }
  while(i<n)
  {
    *(c+(k++))=*(p+i);
    i++;
  }
  while(j<m)
  {
    *(c+(k++))=*(q+j);
    j++;
  }
  clrscr();
  printf("\n\n The sorted array is:- \n");
  for(i=0;i<m+n;i++)
  {
    printf("\t %d",*(c+i));
  }
}
void radix_sort(int *p,int n)
{
  int sum,m,q[10][10],rear[]={0,0,0,0,0,0,0,0,0,0},k,i,j;
  for(sum=10;sum<=1000;sum*=10)
  {
    for(i=0;i<n;i++)
    {
      m=(p[i]%sum)*10/sum;
      q[m][rear[m]++]=p[i];
    }
    k=0;
    for(i=0;i<10;i++)
    {
      for(j=0;j<rear[i];j++)
      {
	p[k++]=q[i][j];
      }
      rear[i]=0;
    }
  }
  for(i=0;i<n;i++)
  {
    printf("\t %d",p[i]);
  }
}
void main()
{
  int ch,a[10],b[10],n,m;
  clrscr();
  while(1)
  {
  printf("\n1) Array Creation \t\t2) Linear Search \n3) Binary Search \t\t4) Selection Sort \n5) Selection Sort ( Advanced ) \t6) Bubble Sort \n7) Bubble Sort(Advanced) \t8) Insertion Sort \n9) Insertion Sort (Advanced) \t10) Shaker Sort \n11) Merge Sort \t\t\t12) Radix Sort \n\t\t    13)Exit ");
  printf("\n\n NOTE: Do ensure that you create an array before performing any of the above \n\tmentioned searching or sorting operations. ");
  printf("\n\n Enter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: clrscr();
	    printf("\n Enter the array range: ");
	    scanf("%d",&n);
	    array_create(a,n);
	    break;
    case 2: clrscr();
	    linear_search(a,n);
	    break;
    case 3: clrscr();
	    binary_search(a,n);
	    break;
    case 4: clrscr();
	    selection_sort(a,n);
	    break;
    case 5: clrscr();
	    selection_sort_advanced(a,n);
	     break;
    case 6: clrscr();
	    bubble_sort(a,n);
	    break;
    case 7: clrscr();
	    bubble_sort_advanced(a,n);
	    break;
    case 8: clrscr();
	    insertion_sort(a,n);
	    break;
    case 9: clrscr();
	    insertion_sort_advanced(a,n);
	    break;
    case 10: clrscr();
	     shaker_sort(a,n);
	     break;
    case 11: clrscr();
	     insertion_sort(a,n);
	     printf("\n Please create another array:- \n ");
	     printf("\n Enter the size of array ");
	     scanf("%d",&m);
	     array_create(b,m);
	     insertion_sort(b,m);
	     merge_sort(a,b,n,m);
	     break;
    case 12: clrscr();
	     radix_sort(a,n);
	     break;
    case 13: exit(0);
    default: printf("\n Invalid choice. ");
  }
  }
  getch();
}