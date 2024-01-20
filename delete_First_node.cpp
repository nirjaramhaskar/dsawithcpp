/*  Visit - https://mahajanonlineclasses.teachable.com
Highly acclaimed online programming courses C, C++, Java, Data Strcutures, Python,
             HTML,etc.
               Anand Mahajan,India - Online course creator -  
	   Whatsapp - 9812164949   */
#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <alloc.h>
typedef struct linklist
	 {
	  int no;
	  struct linklist *link;
	 } node;
char ch;
node *create(node *start)
	{
		node *temp,*p ;
		ch='y';
	//	clrscr();
		printf("\n\t\t **** INPUT BLOCK ****\n");
		if(start != NULL)
		  {
			printf("\n\n\t **** LIST ALREADY EXIST *****");
			getch();
			return(start);
		   }
		fflush(stdin);
		while(ch=='y')
		  {
		   temp=(node *)malloc(sizeof(node));
		   printf("\n\t Enter the no :==> " );
		   scanf("%d",&temp->no);
		   temp->link = NULL;
		   if(start == NULL)
			 p=start=temp ;
		   else
			{
			p->link=temp;
			p=temp;
			}
		   fflush(stdin);
		   printf("\t Do you want to continue (y/n) ? : ");
	 	   ch=getchar();
		  } // end of loop
		  return(start);
	 }


void print(node *start)
	{
	 node *temp;
	// clrscr(); system("cls") ;
	 printf("\n\nBase address    Number     Link");
	 printf("\n===============================");
for(temp=start;temp != NULL;temp=temp->link)
printf("\n%10u  %10d  %10u",temp,temp->no,temp->link);
printf("\n\n\t Press any key to goto MAIN BLOCK.....");
	 getch();
	 return;
	}

node *insf(int item,node *p,node *start)    // modified from previous lectures
	  {
	   	p->no=item;  // assigning value to new node
		p->link=start;   // assigning start to link of new node
		start=p;         // now new node is the first node
printf("\n\n\t Element is succesfully Inserted ");
		getch();
		return(start);
	  }
  
  node *insb(int item,int var,node *start)
	{
  node *temp,*p1,*p;
  p=(node *) malloc(sizeof(node)); // creating the new node using dynamic memory allocation
 for(temp=start;(temp->no != var) && (temp != NULL);temp=temp->link)
		  p1=temp;

	   if(temp==NULL)
		 {
		   printf("\n\n\t Number not found in the Linklist");
		   getch();
		 }
	   else
		 if(temp==start)
			start=insf(item,p,start);
		 else
		   {
		    p->no=item;
		    p->link=p1->link;   // p->link=temp
		    p1->link=p;
		    printf("\n\n\t Element is succesfully Insrted ");
		    getch();
		   }
	   return(start);
	}
	
void insa(int item,int var,node *start)
	  {
 node *temp,*p;
 p=(node *)malloc(sizeof(node)) ;
 for(temp=start;(temp->no != var) && (temp !=NULL);temp=temp->link);

		if(temp == NULL)
		  {
		    printf("\n\n\t Number not found in the Linklist");
		    getch();
		    return;
		  }
		else
	  {
		    p->no=item;
		    p->link=temp->link;
		    temp->link=p;
		    printf("\n\n\t Element is succesfully Insrted ");
		    getch();
		  }
		return;
	  }

void inse(int item,node *start)
	{
	 node *temp,*p;
	 p=(node *) malloc(sizeof(node));
	 p->no=item;
	 for(temp=start;temp->link != NULL;temp=temp->link);
	 temp->link=p;
	 p->link=NULL;
	 printf("\n\n\t Element is succesfully Insrted ");
	 getch();
	 return;
	}

 node *delf(node *start)
   {
	node *tmp=start ;
	start=start->link;
	printf("\n\n\t Element is succesfully deleted ");
	getch();
	free(tmp) ;  // garbage collection - deallocation of memory - reclaiming space
	return(start);
    }

  			
				
 node *search1(int item,node *start)
	 {
	  node *temp;
	  for(temp=start;temp != NULL;temp=temp->link)
	   {
		if(temp->no == item)      // if found
		   return(temp);
	  }
		   return(NULL);          // not found then return NULL

	 }

 	
 int main()
  {
node *start,*temp;
int item,op,var ;
start=NULL;
while(1)     // infinite loop
{
	system("cls") ;    // clears the screen
printf("\n**************** Menu ***************");
printf("\n1) Create the linked list");
printf("\n2) Insert a new node in the beginning");
printf("\n3) Insert a new node before a given node") ;
printf("\n4) Insert a new node after a given node") ;
printf("\n5) Insert a new node at the end") ;
printf("\n6) Delete the first node") ;
printf("\n7) Search a node") ;
printf("\n8) Display the linked list");
printf("\n9) Exit");
printf("\nEnter your option please ");
scanf("%d",&op);
switch(op)
{
case 1:
 			start=create(start) ;
 	        break ;
case 2:
	 		printf("Enter the value") ;
	 		scanf("%d",&item);
			//start=insf(item,start);
	 		break ;
case 3:
	     		printf("\n\n\t Enter the number before which to insert ==> ");
				scanf("%d",&var);
				printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&item);
				start=insb(item,var,start);
				break;

case 4:				
				printf("\n\n\t Enter the number after which insert ==> ");
				scanf("%d",&var);
				printf("\n\n\t Enter the element you want to insert ==> ");
				scanf("%d",&item);
				insa(item,var,start);
				break;

case 5:      	printf("\n\n\t Enter the element you want to insert ==> " );
				scanf("%d",&item);
				inse(item,start);
				break;

case 6:      start=delf(start);
			 break;
 
     		 
case 7:
	        printf("\n\n\t Enter the number to be found ==> ");
			scanf("%d",&item);
				temp=search1(item,start);
				if(temp != NULL)
				   {
				    printf("\n\n\t The number is found");
				    printf("\n\n\t The address of location is = %d",temp);
				   }
				else
				    printf("\n\n\t Number not found in the linklist ");
				getch();
	            break ; 
case 8:			  
 	        print(start) ;
			break ;
case 9: 
            exit(0) ;    // terminates the program			  
 	        
	 }    // end of switch case
}  // end of loop
}  // end of main()

  
	
	
