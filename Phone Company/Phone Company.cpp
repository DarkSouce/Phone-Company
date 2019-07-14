#include<stdio.h>
#include<string.h>
#define SIZE 20
#define STACK_EMPTY '#'

// information stack
typedef struct
{
	char name[20];
	char surname[20];
	char adress[20];
	char date[20];
	char number[20];	
}form_t;

typedef struct{
	int front, rear;
	form_t data[SIZE];
}queue_t;

typedef struct
{
	int top;
	char number[5][15];
}number_t;

// queue functions
void initialize_s(number_t *s)
{
	s->top = -1;
}

int is_empty_s(number_t *s)
{
	if(s->top == -1)
		return 1;
	return 0;
}

int is_full_s(number_t *s)
{
	if(s->top == SIZE - 1)
		return 1;
	return 0;
}

//this function push the phone numbers
void push(number_t *s, char p_number[][15])
{
	int i,j;
	if(is_full_s(s))
	{
		printf("Stack is full\n");
	}
	else
	{
		
		for(j = 0; j < 5; j++)
		{
			s->top++;
			for(i = 15; i >= 0; i--)
			{
			s->number[s->top][i] = p_number[j][i];
			}
		}
	}
}

//this function pop the phone numbers
void pop(number_t *s, char av_number[][15])
{
	int i,j;
	char item;
	if(is_empty_s(s))
	{
		printf("Error: Stack is empty!\n");
		item = STACK_EMPTY;
	}
	else
	{
		for(i = 4; i >= 0; i--)
		{
			for(j = 0; j < 15 ; j++)
			{
			av_number[i][j] = s->number[s->top][j];
			}
			s->top--;
		}		
	}
}

void initialize(queue_t *q)
{
	q->front = 0;
	q->rear = -1;
}

int is_empty(queue_t *q)
{
	if(q->front > q->rear)
	{
		return 1;
	}
	return 0;
}

int is_full(queue_t *q)
{
	if(q->rear == SIZE - 1)
	{
		return 1;
	}
	return 0;
}

	/* INSERT IN QUEUE PART PART*/
	
void insert_name(queue_t *q, char p_name[], int n_size)
{
	int i;
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		p_name[strlen(p_name)] = '\0';//because of get rid of garbage value
		q->rear++;//increment to rear at first data(name), we dont need otherone.
		for(i = 0; i <= n_size; i++)
		{
			q->data[q->rear].name[i] = p_name[i];
		}
	}
}

void insert_surname(queue_t *q, char p_surname[], int surn_size)
{
	int i;
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		p_surname[surn_size] = '\0';//because of get rid of garbage value
		for(i = 0; i <= surn_size; i++)
		{
			q->data[q->rear].surname[i] = p_surname[i];
		}
	}
}

void insert_adress(queue_t *q, char p_adress[], int a_size)
{
	int i;
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		p_adress[a_size] = '\0';//because of get rid of garbage value
		for(i = 0; i <= a_size; i++)
		{
			q->data[q->rear].adress[i] = p_adress[i];
		}
	}
}

void insert_date(queue_t *q, char p_date[], int d_size)
{
	int i;
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		p_date[d_size] = '\0';//because of get rid of garbage value
		for(i = 0; i <= d_size; i++)
		{
			q->data[q->rear].date[i] = p_date[i];
		}
	}
}


void insert_num(queue_t *q, char p_number[], int num_size)
{
	int i;
	if(is_full(q))
	{
		printf("Queue is full\n");
	}
	else
	{
		for(i = 0; i < num_size; i++)
		{
			q->data[q->rear].number[i]= p_number[i];
		}
	}
}

	/*REMOVE QUEUE PART PART*/	
void remove_name(queue_t *q, int n_size, char p_name[])
{
	int i;
	int item;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(i = 0; i < n_size; i++)
		{
			p_name[i] = q->data[q->front].name[i];
		}
	}
}

void remove_surname(queue_t *q, int surn_size, char p_surname[])
{
	int i;
	int item;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(i = 0; i < surn_size; i++)
		{
			p_surname[i] = q->data[q->front].surname[i];
		}
	}
}

void remove_adress(queue_t *q, int a_size, char p_adress[])
{
	int i;
	int item;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(i = 0; i < a_size; i++)
		{
			p_adress[i] = q->data[q->front].adress[i];
		}
	}
}

void remove_date(queue_t *q, int d_size, char p_date[])
{
	int i;
	int item;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(i = 0; i < d_size; i++)
		{
			p_date[i] = q->data[q->front].date[i];
		}
	}
}

void remove_number(queue_t *q, int num_size, char p_number[])
{
	int i;
	int item;
	if(is_empty(q))
	{
		printf("Queue is empty\n");
		return;
	}
	else
	{
		for(i = 0; i < num_size; i++)
		{
			p_number[i] = q->data[q->front].number[i];
		}
		q->front++;
	}
}

void menu()
{
	printf("\n\n\t\t1-Fill an application form\n");
	printf("\t\t2-Show available phone numbers\n");
	printf("\t\t3-Cancel the phone membership\n");
	printf("\t\t4-Show persons in the queue\n");
	printf("\t\t5-Exit\n\n");
	printf("\nEnter your choice: ");
}

// THIS FUNCTION DELETING NUMBERS

void del_number(char number[][15], char chosen_number[][15], int num_size, int chosen_size, int num_index)
{
	char temp[5][15];
	int i,j = 0;
	for(i = 0; i < num_size; i++)
	{
		if(i == num_index)
		{
			strcpy(chosen_number[chosen_size], number[i]);
		}
		else
		{
			strcpy(temp[j++], number[i]);
		}
	}
	for(j = 0; j < (num_size - chosen_size); j++)
	{
		strcpy(number[j], temp[j]);
	}
}

void display(char number[][15], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d->%s\n",i+1, number[i]);
	}
	printf("\n");
}

	//THIS FUNCTION SEARCHIG AND DELETING INFORMATION ON THE QUEUE
void seq_search(queue_t *q, char p_name[], char p_surname[], int n_size, int sur_size)
{
	char garbage[100];
	char temp_name[SIZE];
	char temp_surname[SIZE];
	char temp_adress[SIZE];
	char temp_date[SIZE];
	char temp_number[SIZE];
	queue_t t;
	initialize(&t);
	while(!is_empty(q))
	{
		remove_name(q, SIZE, temp_name);
		remove_surname(q, SIZE, temp_surname);
		remove_adress(q, SIZE, temp_adress);
		remove_date(q, SIZE, temp_date);
		remove_number(q, SIZE, temp_number);		
		if(strcmp(temp_name, p_name) != 0 && strcmp(temp_surname, p_surname) != 0)
		{
			
			insert_name(&t, temp_name, SIZE);
			insert_surname(&t, temp_surname, SIZE);
			insert_adress(&t, temp_adress, SIZE);
			insert_date(&t, temp_date, SIZE);
			insert_num(&t, temp_number, SIZE);
			printf("This person could not found!");
		}
	}
	initialize(q);
	while(!is_empty(q))
	{
		remove_name(q, SIZE, garbage);
		remove_surname(q, SIZE, garbage);
		remove_adress(q, SIZE, garbage);
		remove_date(q, SIZE, garbage);
		remove_number(q, SIZE, garbage);
	}
	while(!is_empty(&t))
	{
		remove_name(&t, n_size, temp_name);
		remove_surname(&t, SIZE, temp_surname);
		remove_adress(&t, SIZE, temp_adress);
		remove_date(&t, SIZE, temp_date);
		remove_number(&t, SIZE, temp_number);
		insert_name(q, temp_name, SIZE);
		insert_surname(q, temp_surname, SIZE);
		insert_adress(q, temp_adress, SIZE);
		insert_date(q, temp_date, SIZE);
		insert_num(q, temp_number, SIZE);
	}
}

	//THIS FUNCTION SHOWS US TO QUEUE
void print(queue_t *q)
{
	int i = 0;
	char temp_name[SIZE];
	char temp_surname[SIZE];
	char temp_adress[SIZE];
	char temp_date[SIZE];
	char temp_number[SIZE];
	queue_t t;
	initialize(&t);
	while(!is_empty(q))
	{
		remove_name(q, SIZE, temp_name);
		remove_surname(q, SIZE, temp_surname);
		remove_adress(q, SIZE, temp_adress);
		remove_date(q, SIZE, temp_date);
		remove_number(q, SIZE, temp_number);
		i++;
		printf("%d. Person \n**************\n\nName = %s\nSurname = %s\nAdress = %s\nDate = %s\nNumber = %s\n\n", i, temp_name, temp_surname, temp_adress, temp_date, temp_number);
		
		insert_name(&t, temp_name, SIZE);
		insert_surname(&t, temp_surname, SIZE);
		insert_adress(&t, temp_adress, SIZE);
		insert_date(&t, temp_date, SIZE);
		insert_num(&t, temp_number, SIZE);	
		
	}
	initialize(q);
	while(!is_empty(&t))
	{
		remove_name(&t, SIZE, temp_name);
		remove_surname(&t, SIZE, temp_surname);
		remove_adress(&t, SIZE, temp_adress);
		remove_date(&t, SIZE, temp_date);
		remove_number(&t, SIZE, temp_number);
		insert_name(q, temp_name, SIZE);
		insert_surname(q, temp_surname, SIZE);
		insert_adress(q, temp_adress, SIZE);
		insert_date(q, temp_date, SIZE);
		insert_num(q, temp_number, SIZE);
	}
	
}
int main()
{
	int i, num;
	char adress[20] = "";
	char date[20] = "";
	int choice, status, size = 0, chosen_size = 0;
	char name[20], surname[20], av_number[5][15], number[5][15], chosen_number[5][15];
	queue_t q;
	number_t s;
	initialize_s(&s);
	initialize(&q);
	
	FILE *inp = fopen("Numbers.txt", "r");
	status = fscanf(inp, " %[^\n]s", av_number[size]);
	while(status != EOF)
	{
		size++;
		status = fscanf(inp, " %[^\n]s", av_number[size]);
	}
	printf("\n\t|-------------------------------------------|\n");
	printf("\t|                                           |");
	printf("\n\t|\tWELCOME TO TELEPHONE COMPANY        |\n");
	printf("\t|                                           |");
	printf("\n\t|-------------------------------------------|");
	push(&s, av_number);
	pop(&s, number);
	menu();
	scanf("%d", &choice);
	size = 5;
	while(choice != 5)
	{
		switch(choice)
		{
			case 1:
				printf("Enter your name:");
				scanf(" %[^\n]", name);
				printf("Enter your surname:");
				scanf(" %[^\n]", surname);
				printf("Enter your town:");
				scanf(" %[^\n]", adress);
				printf("Enter the date of today:");
				scanf(" %[^\n]", date);
				printf("List of the available phone numbers\n");
				printf("*****************\n\n");
				display(number,size);
				printf("*****************\n");
				printf("\nChose a number in the list: ");
				scanf("%d", &num);
				num--;
				del_number(number, chosen_number, size, chosen_size, num);
				chosen_size++;
				size--;
				printf("Phone number activation is successfully.\n");
				insert_name(&q, name, strlen(name));
				insert_surname(&q, surname, strlen(surname));
				insert_adress(&q, adress, strlen(adress));
				insert_date(&q, date, strlen(date));
				insert_num(&q, number[num], strlen(number[num]));
				break;
			case 2:
				display(number,size);
				break;
			case 3:
				printf("Enter your name:");
				scanf(" %s", name);
				printf("Enter your surname:");
				scanf(" %s", surname);
				seq_search(&q, name, surname, strlen(name), strlen(surname));
				i = 0; 
				strcpy(number[size], chosen_number[i]);//keeping numbers
				size++;
				i++;
				break;
			case 4:
				print(&q);
				break;
			default:
				break;
		}
		menu();
		scanf("%d", &choice);
	}
	return 0;
}
