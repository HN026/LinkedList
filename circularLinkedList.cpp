#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*Head;


void create (int A[], int n)
{
    int i;
    struct Node *t,*last;
    Head = new struct Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for(i = 1; i<n; i++)
    {
        t = new struct Node;
        t->data = A[i];
        t->next = last->next;
        last->next=t;
        last = t;
    }
}


void Display ( struct Node *h)
{
  do{
    cout<<h->data<<" ";
    h = h->next;
  }while(h!=Head);
   
    
}

void RDisplay (struct Node *h)
{
    static int flag = 0;
    if(h!=Head || flag==0)
    {
        flag = 1;
        cout<<h->data<<" ";
        RDisplay(h->next);
    }
    flag = 0;
}

int length (struct Node *p)
{
    int l = 0;
    do
    {
        l++;
        p = p->next;
    } while (p!=Head);
    
    return l;
    
}

void Insert ( struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index<0 || index>length(p)){
        cout<<"Invalid Index"<<endl;
    }
    if(index==0)
    {
        t = new struct Node;
        t->data = x;
        if(Head==NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else{
            while(p->next!=Head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for(i = 0; i< index-1; i++)
        {
            p =  p->next;
        }
        t = new struct Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
 
    
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;

    if(index<0 || index>length(Head))
    {
        return -1;
    }
    if(index == 1)
    {
        while(p->next!=Head)
        {
            p = p->next;
        }
        if(Head==p)
        {
            delete Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else{
        for ( i = 0; i<index-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
         x = q->data;
        delete q;
    }

    return x;
}












int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    // RDisplay(Head);
    // Display(Head);
    // cout<<endl;
    // Insert(Head,12,10);
    // Display(Head);

    Delete(Head,2);
    Display(Head);


    return 0;
}
