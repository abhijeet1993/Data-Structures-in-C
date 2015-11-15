#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
	
	int element;
	struct linkedlist *next;
	struct linkedlist *prev;
	int count;
}ll;

//function prototypes
void insertAtBeg(ll ** , ll **);//insert element at the beginning of the linked list.
void insertAtPos(ll ** , ll **);//insert element at a position entered by the user.
void insertAtEnd(ll ** , ll **);//insert element at the end of the linked list.
int deleteFromBeg(ll ** , ll **);//deleting an element from the beginning of the list.
int deleteFromPos(ll ** , ll **);//deleting an element from a position entered by the user.
int deleteFromEnd(ll ** , ll **);//deleting an element from the end of the list.
int isEmpty(ll *);//to check if the linked list is empty.
void display(ll * , ll *);//to display all the elements of the linked list.

void main(){

	ll *head = NULL;
	ll *tail = NULL;
	//head->count = 0;
	int choice;
	while(1){
	printf("\n\n\t---------------MENU----------------");
	printf("\n\t1.Insert at Beginning of the List.");
	printf("\n\t2.Insert at a particular position in the List.");
	printf("\n\t3.Insert at End of the List.");
	printf("\n\t4.Delete from Beginning of the List.");
	printf("\n\t5.Delete from a particular position in the List.");
	printf("\n\t6.Delete from End of the List.");
	printf("\n\t7.Display the List.");
	printf("\n\t8.Exit");
	printf("\n\tEnter your choice:");
	scanf("%d",&choice);
	switch(choice){

		case 1:	insertAtBeg(&head , &tail);
			break;

		case 2: insertAtPos(&head , &tail);
			break;

		case 3: insertAtEnd(&head , &tail);
			break;
		
		case 4: if(head == NULL)
				printf("\n\nList is empty, cannot delete(delete from beg).");
			else
				printf("\n\nThe element deleted from the beginnig of the list is:%d",deleteFromBeg(&head , &tail));
			break;

		case 5: if(head == NULL)//checking for empty list
				printf("\n\nList is empty, cannot delete(delete from pos).");
			
			
			else{
				int deleted_element;
				 deleted_element = deleteFromPos(&head , &tail);	
				if(deleted_element != -99)
					printf("\n\nThe deleted element is:%d",deleted_element);
			
				else
					printf("\n\nInvalid delete attempt(switch case delete from pos).");
			}//outer if ended
			break;

		case 6: if(head == NULL)//if the list is empty then deleteFromEnd() won't be called.
				printf("\n\nList is empty, cannot delete(delete from end).");
			else//if there is even a single element in the list then thi sblock will get executed.
				printf("\n\nThe element deleted from the end of the list is:%d",deleteFromEnd(&head , &tail));
			
			break;

		case 7: if(head == NULL)
				printf("\n\nList is empty. Cannot print.");
			else
				display(head , tail);
			break;


		case 8: exit(0);

		default: printf("\n\nEnter valid choice.");
		}//switch ended
	
	}//while ended
}//main ended

//---------------------------------------------------------------------------------------

//function definition for inserting element at the beginning of the linked list.

void insertAtBeg(ll **head , ll **tail){
	
	ll *temp;
	temp = (ll*) calloc(1 , sizeof(ll));
	printf("\n\nEnter the data you want to enter at the beginning of the list:");		
	scanf("%d",&temp->element);

	
	//(*head)->count++;
	if(*head == NULL)//checking for the condition of empty list.
		{
			temp->next = NULL;
			*tail = temp;
		}		
	else{
		(*head)->prev = temp;
		temp->next = *head;	
	}
	temp->prev = NULL;
	*head = temp;

	printf("\n\n The element inserted is:%d",temp->element);
}

//----------------------------------------------------------------------------------------
//function to insert an element at a postition entered by the user.

void insertAtPos(ll **head , ll **tail)
{
	int no_of_elements=0;
	
	ll *temp = *head;
	while(temp != NULL){// while loop for counting the number of elements in the list.
		no_of_elements++;
		temp = temp->next;
	}//while ended
	
	printf("\n\nNumber of elements=%d",no_of_elements);
	temp = *head;
	int pos,count=1;
	
	printf("\n\n Enter the position at which you want to enter the element:");
	scanf("%d",&pos);
	
	if(pos > 0){//checking if the position entered by the user is valid or not
		if(pos == 1)//if position entered is 1, then insertAtBeg() is called.
		  insertAtBeg(&*head , &*tail);

		else if(pos == no_of_elements+1)
		  insertAtEnd(&*head , &*tail);//if position entered is the last position in the list, then insertAtEnd() is called.	

		else if(pos <= no_of_elements){//if the position entered is some intermediate position then this block will get executed.
			
			ll *temphead = *head;
			

			while(count != pos){
				count++;
				temp = temp->next;
			}//while ended
			
			temphead = (ll*) calloc(1 , sizeof(ll));
			printf("\n\nEnter the data you want to enter at position %d:",pos);		
			scanf("%d",&temphead->element);

			temphead->prev = temp->prev;
			temphead->next = temp;
			temp->prev->next = temphead;
			temp->prev = temphead; 	

			printf("\n\n The element inserted is:%d",temphead->element);
		}//2nd else if ended ended
		else
			printf("\n\nEnter value less than or 1 greater equal to the number of elements.");
	}//if ended

	else	
		printf("\n\nEnter value greater than 0.");
}

//----------------------------------------------------------------------------------------
//function to insert element at the end of the list.
void insertAtEnd(ll **head , ll **tail)
{
	ll *temp;
	temp = (ll*) calloc(1 , sizeof(ll));
	printf("\n\nEnter the data you want to enter at the end of the list:");		
	scanf("%d",&temp->element);

	
	//(*head)->count++;
	if(*head == NULL)//checking for the condition of empty list.
		{
			temp->prev = NULL;
			*head = temp;
		}		
	else{
		(*tail)->next = temp;
		temp->prev = *tail;	
	}
	temp->next = NULL;
	*tail = temp;

	printf("\n\n The element inserted is:%d",temp->element);
}

//----------------------------------------------------------------------------------------
//function definition to delete an element from the beggining of the list.

int deleteFromBeg(ll **head , ll **tail){
	int deleted_element = (*head)->element;

	if(*head == *tail)//checking if there is only one node on the list.
		*head = *tail = NULL;

			
	else{//this block will get executed if there are multiple elements in the list.
		*head = (*head)->next;
		(*head)->prev = NULL;
	}//else ended	
	
	return deleted_element;
	
}//deleteFromBeg() ended

//----------------------------------------------------------------------------------------
//function definition to delete an element from a particular position which is entered by the user.

int deleteFromPos(ll **head , ll **tail){
	
	int no_of_elements=0;
	
	ll *temp = *head;
	while(temp != NULL){// while loop for counting the number of elements in the list.
		no_of_elements++;
		temp = temp->next;
	}//while ended
	
	printf("\n\nNumber of elements=%d",no_of_elements);
	temp = *head;
	int pos,count=1;
	
	printf("\n\n Enter the position from which you want to deleted the element:");
	scanf("%d",&pos);
	
	int deleted_element = -99;// if an invalid delete is attempted then -99 will be returned which will indicate invalid delete attempt.

	if(pos > 0){
		
	
		if(pos == 1)
			 deleted_element = deleteFromBeg(&*head , &*tail);

		else if(pos == no_of_elements)
			 deleted_element = deleteFromEnd(&*head , &*tail);

		else if(pos <= no_of_elements){
			

			while(count != pos){
				count++;
				temp = temp->next;
			}//while ended
			
			deleted_element = temp->element;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		
			
		}//2nd else if ended

		else
			printf("\n\nEnter position less than or equal to the number of elements.");

	}//outer if ended
	
	else
		printf("\n\nEnter position greater than Zero.");
	
	printf("\n\n In deleteFromPos(), deleted element is:%d",deleted_element);
	return deleted_element;
}


//----------------------------------------------------------------------------------------
//function definition for deleting an element from the end of the list.

int deleteFromEnd(ll **head , ll **tail){

	int deleted_element = (*tail)->element;
	
	if(*head ==  *tail)//checking if there is only one element in the list.
		*head = *tail = NULL;

	else{//if there are nultiple elements in the list then this block will get executed.
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}//else ended

	return deleted_element;	
}//deleteFromEnd() ended

//----------------------------------------------------------------------------------------

//function deifinition to display the elements of the list.

void display(ll *head , ll *tail)
{	
	
	printf("\n\n-------From Head to Tail------------");	
	printf("\n\nHEAD-->");
	while(head != NULL){	
		printf("[%d]-->",head->element);
		head = head->next;
	}//while ended
	printf("TAIL");


	printf("\n\n-------From Tail to Head------------");
	printf("\n\nTAIL-->");
	while(tail != NULL){	
		printf("[%d]-->",tail->element);
		tail = tail->prev;
	}//while ended
	printf("HEAD");
}
