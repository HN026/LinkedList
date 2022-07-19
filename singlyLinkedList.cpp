# include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL, *second = NULL, *third = NULL;



// In this way, first gets declared globally.

void create1( int A[], int n)
{
    
    struct Node *t, *last;
    first = new struct Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i<n; i++)
    {
        t = new struct Node;
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
}

void create2( int A[], int n)
{
    
    struct Node *t, *last;
    second = new struct Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for (int i = 1; i<n; i++)
    {
        t = new struct Node;
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
    }
}


void Display(struct Node *p)
{
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
} 


void RDisplay (struct Node *p)
{
    if (p!=NULL)
    {
        cout<<p->data;
        RDisplay(p->next);

        // If we reverse the order of print and recursion, the linked list will get reversed.
    }
}

int count(struct Node *p)
{
    int l = 0;
    while(p!=NULL)
    {
        l++;
        p = p->next;
    }
    return l;
}

int Rcount(struct Node *p)
{
    if(p!=NULL)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

int sum(struct Node *p)
{
    int s = 0;
    while(p!=NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;

}

int Rsum(struct Node *p)
{
    if (p==NULL)
    {
        return 0;
    }
    else
    {
        return Rsum(p->next) + p->data;
    }
}

int Max (struct Node *p)
{
    int max = INT32_MIN;

    while(p!=0){
        if(p->data>max){
            max = p->data;
            p = p->next;
        }
    }
    return max;
}

int RMax (struct Node *p)
{
    int x = 0;
    if (p==0){
        return INT32_MIN;
    }
    else{
        x = RMax(p->next);
        if(x>p->data)
        {
            return x;
        }
        else{
            return p->data;
        }
    }
}

// Binary search is not suitable for finding a number in linked list because we cannot go directly in middle of a linked list.



// Linear Search
Node *Search( struct Node *p, int key){
    while (p!=NULL)
    {
        if (key==p->data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *RSearch ( struct Node *p, int key)
{
    if (p==NULL)
    {
        return NULL;
    }
    else if (key==p->data)
    {
        return p;
    }
    return RSearch(p->next, key);
}

// Improved Linear Search


struct Node *LSearch( struct Node *p, int key)
{
    struct Node *q;
    while(p!=NULL)
    {
       if(key==p->data)
       {
        q->next = p->next;
        p->next = first;
        first = p;
        return p;
       }
       else{
        q = p;
        p = p->next;
       }
    }
    return NULL;
}


// Inserting new element in a linked list: 

void Insert( struct Node *p, int index, int x)
{
    struct Node *t;
    
    if (index < 0 || index > count(p))
    {
        cout<<"The node cannot be inserted."<<endl;
    }

    t = new struct Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for ( int i = 1; i<index-1; i++)
        {
            p = p->next;
        }
         t->next = p->next;
         p->next = t;
    }

}


void InsertLast ( struct Node *p, int x)
{
    struct Node *k, *temp;
    temp = new struct Node;
    k = first;
    temp->data = x;
    temp->next = NULL;

    while(k->next!=NULL)
    {
            k = k->next;
    }
    
    k->next = temp;
}

// Inserting in a sorted list: 

// This code cannot put an integer before the first node if its smaller than that
// void Insertinalist ( struct Node *p, int x)
// {
//     struct Node *k, *q;
//     k = first;
//     q = NULL;
//     while(k!=NULL && k->data<x)
//     {
//         q = k;
//         k = k->next;
//     }
//     struct Node *t;
//     t = new struct Node;
//     t->data = x;
//     t->next = q->next;
//     q->next = t;
// }

void SortedInsert( struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new struct Node;
    t->data = x;
    t->next = NULL;
    
    if(first==NULL)
    {
        first = t;
    }
    else 
    {
       while(p!=NULL && p->data<x)
       {
        q = p;
        p = p->next;
       } 
       if(p==first)
       {
        t->next = first;
        first = t;
       }
       else{
        t->next = q->next;
        q->next = t;
       }
    }


}

// Deleting a Node from the linked list at a given mistake:

void Delete (struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if( index < 1 || index > count(p))
    {
        cout<<"Invalid Index"<<endl;
    }
    if(index==1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
    }
    else{
        for ( int i = 0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
}


//  In C language, for delete we use Free(p) not delte;

int isSorted ( struct Node *p)
{
    int x = INT32_MIN;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            return false;
            // return 0
        }
        else{
            x = p->data;
            p = p->next;
        }
    }
    return true;
    // return 1
}

// Removing duplicate elements from a linked list: 

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while(q!=NULL)
    {
        if(p->data != q->data)
        {
          p = q;
          q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Reversing a linked list using an array: 

void Reverse1( struct Node *p)
{
    int *A;
    struct Node *q;
    A = new int [count(p)];
    int i = 0;
    q = p;
    while(q!=NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q!=NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}


void Reverse3 (struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        Reverse3(p,p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void Concat( struct Node *p, struct Node *q)
{
    third = p;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
}


void Merge (struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while(p!=NULL && q!=NULL)
    {
        if(p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p!=NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int isLoop (struct Node *f)
{
    struct Node *p, *q;
    p = q =f;
    do{
        p = p->next;
        q = q->next;
        if(q!=NULL)
        {
            q = q->next;
        }
    }while(p!=NULL && q!=NULL && p!=q);
    if(p==q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}




int main(){
    int A[] = {3,5,6,10,15};
    int B[] = {14,16,17,23,35};
    create1(A,5);
    create2(B,5);



    // Display(first);
    // RDisplay(first);
    // cout<<"Length is: "<<count(first);
    // cout<<"Length is: "<<Rcount(first);
    // cout<<"Sum is: "<<sum(first);
    // cout<<"Sum is: "<<Rsum(first);
    //    cout<<"Max is: "<<Max(first);
    //    cout<<"Max is: "<<RMax(first);
    // cout<<"Number is: "<<RSearch(first,5);

    // Organised code for Lsearch, Search, RSearch: 

    // struct Node *temp;

    // temp = LSearch(first,15);
    // if(temp->data == 15)
    // {
    //     cout<<"Key is found: "<<temp->data<<endl;
    // }
    // else{
    //     cout<<"Key is not found"<<endl;
    // }

    
    // Display(first);
    // cout<<endl;
    //  Inserting node in a linked list
    // Insert(first,0,6);
    // Display(first);

    // InsertLast(first,12);
    // struct Node *second;
    
    // Inserting a number in a sorted linked list
    // Insertinalist(first,1);
    // Display(first);


    //  This will enter the numbers in an increasing order: 
    //  SortedInsert(first,34);
    //  SortedInsert(first,23);
    //  Display(first);
    //  Display(first);
    //  Delete(first,1);
    //  cout<<endl;
    //  Display(first);

    // cout<<isSorted(first)<<endl;
    //    Display(first);
    //    cout<<endl;
    //    RemoveDuplicate(first);
    //    Display(first);

    // Reverse1(first);
    // Display(first);
    // cout<<endl;
    // Reverse2(first);
    // Display(first);
    // cout<<endl;
    // Reverse3(NULL,first);
    // Display(first);


    // cout<<"First Linked List"<<endl;
    // Display(first);
    // cout<<endl;
    // cout<<"Second Linked List"<<endl;
    // Display(second);

    // Concat(first,second);
    // cout<<"Concatenated Linked List"<<endl;
    // Display(third);

    // for merging, the condition is both lists should be sorted.

    // Merge(first,second);
    // Display(third);
    

    // Making a loop: 
    // struct Node *t1, *t2;

    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;

   cout<<isLoop(first);


    return 0;
}




