# include<iostream>

using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new struct Node;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i<n; i++)
    {
        t = new struct Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last=t;
    }
}

void Display (struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int Length(struct Node *p)
{
    int l = 0;
    while(p!=NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index<0 || index > Length(p))
    {
        cout<<"Invalid Index"<<endl;
    }
    if (index==0)
    {
        t = new struct Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for( i = 0; i<index-1; i++)
        {
            p = p->next;
        }
        t = new struct Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next!=NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}


int Delete ( struct Node *p, int index)
{
    struct Node *q;
    int x = -1, i;
    if (index < 1 || index > Length(p))
    {
        return -1;
    }
    if( index ==1)
    {
        first = first->next;
        if(first!=NULL)
        {
            first->prev=NULL;
        }
        x = p->data;
        delete p;
    }
    else
    {
        for ( i = 0 ;i< index -1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next!=NULL)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}


void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL)
        {
            first = p;
        }
    }
}




int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);

    // cout<<"Length is: "<<Length(first)<<endl;
    // Insert(first,2,325);
    // Display(first);
    // Delete(first,1);
    // Display(first);

    // Reverse(first);
    // Display(first);


    return 0;
}