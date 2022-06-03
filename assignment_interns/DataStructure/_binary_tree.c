#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

void top_down(struct node *);
void bottom_up(struct node *);
void inorder(struct node *);
int enqueue(int [], int *, int *, struct node *, int);
int dequeue(int [], int *, int *);
int front(int [], int *);

int count;

int main()
{
	struct node *head=NULL, *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o;
	//int count=0;

	a = (struct node *)malloc(sizeof(struct node));
	b = (struct node *)malloc(sizeof(struct node));
	c = (struct node *)malloc(sizeof(struct node));
	d = (struct node *)malloc(sizeof(struct node));
	e = (struct node *)malloc(sizeof(struct node));
	f = (struct node *)malloc(sizeof(struct node));
	g = (struct node *)malloc(sizeof(struct node));
	h = (struct node *)malloc(sizeof(struct node));
	i = (struct node *)malloc(sizeof(struct node));
	j = (struct node *)malloc(sizeof(struct node));
	k = (struct node *)malloc(sizeof(struct node));
	l = (struct node *)malloc(sizeof(struct node));
	m = (struct node *)malloc(sizeof(struct node));
	n = (struct node *)malloc(sizeof(struct node));
	o = (struct node *)malloc(sizeof(struct node));

	head = a;

	a->data = 1;
	a->lptr = b;
	a->rptr = c;
	++count;

	b->data = 2;
	b->lptr = d;
	b->rptr = e;
	++count;

	c->data = 3;
	c->lptr = f;
	c->rptr = g;
	++count;

	d->data = 4;
	d->lptr = h;
	d->rptr = i;
	++count;

	e->data = 5;
	e->lptr = j;
	e->rptr = k;
	++count;

	f->data = 6;
	f->lptr = l;
	f->rptr = m;
	++count;

	g->data = 7;
	g->lptr = n;
	g->rptr = o;
	++count;

	h->data = 8;
	h->lptr = NULL;
	h->rptr = NULL;
	++count;

	i->data = 9;
	i->lptr = NULL;
	i->rptr = NULL;
	++count;

	j->data = 10;
	j->lptr = NULL;
	j->rptr = NULL;
	++count;

	k->data = 11;
	k->lptr = NULL;
	k->rptr = NULL;
	++count;

	l->data = 12;
	l->lptr = NULL;
	l->rptr = NULL;
	++count;

	m->data = 13;
	m->lptr = NULL;
	m->rptr = NULL;
	++count;

	n->data = 14;
	n->lptr = NULL;
	n->rptr = NULL;
	++count;

	o->data = 15;
	o->lptr = NULL;
	o->rptr = NULL;
	++count;

	printf("Total no of nodes in tree are: %d\n",count);

	printf("Inorder\n");
	inorder(head);
	printf("\n");

	printf("top-down approach\n");
	top_down(head);
	printf("\n");

	return 0;
}

void inorder(struct node *h)
{
	if(h == NULL)
	{
		printf("Tree is empty!\n");
	}

	if(h->lptr != NULL)
	{
		inorder(h->lptr);
	}

	printf("%d ",h->data);

	if(h->rptr != NULL)
	{
		inorder(h->rptr);
	}
}

void top_down(struct node *h)
{
	int queue[count+1];
	int f=0, r=0;
	struct node *first=NULL, *second=NULL;

	if(h == NULL)
	{
		printf("Tree is Empty!\n");
	}

	printf("%d ",h->data);

	if(h->lptr != NULL)
		printf("%d %d ",h->lptr->data,h->rptr->data);

	if(h->lptr->lptr == NULL)
		return;

	if(h->lptr->lptr != NULL)
		printf("%d %d %d %d ",h->lptr->lptr->data,h->rptr->rptr->data,h->lptr->rptr->data,h->rptr->lptr->data);

	if(h->lptr->lptr->lptr == NULL)
		return;


	enqueue(queue, &f, &r, h->lptr,count);
	enqueue(queue, &f, &r, h->rptr,count);

	while(f != r)
	{
		printf("value of queue 1st value: %d\n",queue[1]);
		first = front(queue, &f);
		dequeue(queue, &f, &r);
		printf("value of queue 2nd value: %d\n",queue[2]);
		second = front(queue, &f);
		dequeue(queue, &f, &r);

		printf("Removed from queue\n");

		printf("%d %d %d %d ",first->lptr->data,second->rptr->data,first->rptr->data,second->lptr->data);

		if (first->lptr->lptr != NULL)
		{
			enqueue(queue, &f, &r, first->lptr, count);
			enqueue(queue, &f, &r, second->rptr, count);
			enqueue(queue, &f, &r, first->rptr, count);
			enqueue(queue, &f, &r, second->lptr, count);
		}
	}


}

int enqueue(int s[], int *f, int *r, struct node *x, int l)
{
	if(*r >= l)
	{
		printf("Stack overflow\n");
		return 0;
	}
	else
	{
		*r = *r + 1;
		printf("enq *r=%d\n",*r);

		s[*r] = x->data;

		if(*f == 0)
		{
			*f = *f+1;
			printf("enq *f=%d\n",*f);
		}

		return 1;
	}

}

int dequeue(int s[], int *f, int *r)
{
	if(*f == 0)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	else
	{
		int z = s[*f];
		if(*f == *r)
		{
			*f=*r=0;
		}
		else
		{
			*f = *f+1;
			printf("deq *f=%d\n",*f);

		}

		return z;
	}
}

int front(int queue[], int *f)
{
	return queue[*f];
}
