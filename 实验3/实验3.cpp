#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	char data;
	struct node *next;
}Qnode,*Qlink;
typedef struct
{
	Qnode *front, *rear;
}linkqueue;

void creatQueue(linkqueue *q)
{
	q->front = (Qlink)malloc(sizeof(Qnode));
	q->front->next = NULL;
	q->rear = q->front;
}

int emptyQueue(linkqueue *q)
{
	if (q->front == q->rear)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void enQueue(linkqueue *q, char e)
{
	Qlink p;
	p = (Qlink)malloc(sizeof(Qnode));
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

char deQueue(linkqueue *q)
{
	Qlink p;
	if (emptyQueue(q))
		return(NULL);
	else
	{
		p = q->front;
		q->front = p->next;
		free(p);
		return(q->front->data);
	}
}

void main()
{
	linkqueue Q;
	char c,temp;
	int i = 0;
	int k = 0;
	creatQueue(&Q);
	do
	{
		while (scanf("%c",&c))
		{
			if(c!='@' && c!='0')
			{
				enQueue(&Q, c);
				i++;
			}
			else if (c == '0')
			{
				temp = deQueue(&Q);
				printf("%c\n", temp);
				i--;
			}
			else if (c == '@')
			{
				for (int j = 0; j < i; j++)
				{
					printf("%c", deQueue(&Q));
				}
				printf("ÊÇ·ñ¼ÌÐø£¿ÊÇ£º1£»·ñ£º0");
				printf("\n");
				scanf("%c",&k);
				getchar();
			}
		}
	}while(k == 1);

}