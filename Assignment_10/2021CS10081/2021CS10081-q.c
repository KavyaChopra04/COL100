#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

// create a node with data as x
struct Node* create_node(int x) {
    struct Node* ptr = malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}

// delete the node at `ptr` and free its memory
void delete_node(struct Node* ptr) {
    free(ptr);
}
int len();
// ------------------------------ Node struct definition ends here ------------------------------

// Use this to operate on the list, this will always point at the head of the list.
struct Node* PythonListHead = NULL;


// prints the list in space seperated format
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}


// Add an item to the end of the list
void append(int x) {
    struct Node* ctr=PythonListHead;
    struct Node* addn=create_node(x);
    if(ctr==NULL)
    {
        PythonListHead=addn;
        return;
    }
    while(ctr->next!=NULL)
    {
        ctr=ctr->next;
    }
    ctr->next=addn;
}


// Insert an item at a given position. 
// The first argument is the index of the element before which to insert
// second argument is the value to insert at that position
// if the position does not exist, do nothing
void insert(int position, int x) {
    int n=len();
    struct Node* addn=create_node(x);
    if(position>n-1 || position<0)
    {
        return;
    }
    if(position==0)
    {
        struct Node* rest=PythonListHead;
        PythonListHead=addn;
        addn->next=rest;
        return;
    }
    int i=0;
    struct Node* ctr= PythonListHead;
    while(i<position-1)
    {
        i++;
        ctr=ctr->next;
    }
    struct Node* mid=ctr->next;
    ctr->next=addn;
    addn->next=mid;
}


// Remove the item at the end of the list
void pop() {
    struct Node* ctr=PythonListHead;
    if(ctr==NULL)
    {
        return;
    }
    int l=0;
    while(ctr!=NULL)
    {
        ctr=ctr->next;
        l++;
    }
    struct Node* ctr1=PythonListHead;
    for(int i=0;i<l-2;i++)
    {
        ctr1=ctr1->next;
    }
    delete_node(ctr1->next);
    ctr1->next=NULL;
}


// Remove all items from the list
void clear() {
    
    struct Node* ctr=PythonListHead;
    while(ctr!=NULL)
    {
        struct Node* temp=ctr->next;
        delete_node(ctr);
        ctr=temp;
    }
    PythonListHead=NULL;
    return;
}


// Return the number of times x appears in the list.
int count(int x) {
    // your code goes here
    struct Node* ctr=PythonListHead;
    int l=0;
    while(ctr!=NULL)
    {
        if(ctr->data==x)
        {
            l++;
        }
        ctr=ctr->next;
    }
    return l;
}


// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    int k=len();
    struct Node* newh=PythonListHead;
    struct Node* newt=PythonListHead;
    for(int i=0;i<k-1;i++)
    {
        struct Node* temp=newh;
        newh=PythonListHead->next;
        PythonListHead->next=newh->next;
        newh->next=temp;
    }
    PythonListHead=newh;
}


// Return the number of elements in the list
int len() {
    // your code goes here
    int l=0;
    struct Node* ctr=PythonListHead;
    while(ctr!=NULL)
    {
        ctr=ctr->next;
        l++;
    }
    return l;
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, int x) {
    int k=len();
    if(position>k-1 || position<0)
    {
        return;
    }
    else
    {
        struct Node* ctr=PythonListHead;
        for (int i = 0; i < position; ++i)
        {
            ctr=ctr->next;
        }
        ctr->data=x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
int getitem(int position) {
    // your code goes here
    int k=len();
    if(position>k-1 || position<0)
    {
        return -1;
    }
    else
    {
        struct Node* ctr=PythonListHead;
        for (int i = 0; i < position; ++i)
        {
            ctr=ctr->next;
        }
        return ctr->data;
    }
    
}
// erase the node at position
// if no such position, do nothing
void erase(int position) {
    int n=len();
    if(position>n-1 || position<0)
    {
        return;
    }
    if(position==0)
    {
        if(PythonListHead!=NULL)
        {
            struct Node* rest=PythonListHead->next;
            free(PythonListHead);
            PythonListHead=rest;
        }
        return;
    }
    int i=0;
    struct Node* ctr= PythonListHead;
    while(i<position-1)
    {
        i++;
        ctr=ctr->next;
    }
    struct Node* nlink=ctr->next->next;
    free(ctr->next);
    ctr->next=nlink;    
}
// Returns a the head of the newly formed Python List
// containing elements present in positions in the original List.
// Note: you have to create new Python List and return its head.
// Here positions is an array of size n.
// eg. if positions = [2, 3, 5], you need to return a newly formed list
// having nodes that were at position 2, 3 and 5 in the original list.
// if there is such a position that is not present in the original list, do nothing
// with that position.
struct Node* index_into(int *positions, int n) {
    struct Node* newh=NULL;
    int k=len();
    for(int i=n-1;i>=0;i--)
    {
        if(positions[i]<k)
        {
            struct Node* temp=create_node(getitem(positions[i]));
            temp->next=newh;
            newh=temp;
        }
    }
    return newh;
}


// swaps the nodes present at `position` and `position+1`
// if either of  `position` or `position+1` does not exist, do nothing
void swap(int position) {
    int n=len();
    if(position+1>n-1 || position<0)
    {
        return;
    }
    if(position==0)
    {
        if(PythonListHead!=NULL)
        {
            struct Node* rest=PythonListHead->next;
            struct Node* temp=PythonListHead->next->next; 
            struct Node* temp1=PythonListHead; 
            PythonListHead=rest;
            PythonListHead->next=temp1;
            PythonListHead->next->next=temp;
        }
        return;
    }
    int i=0;
    struct Node* ctr= PythonListHead;
    while(i<position-1)
    {
        i++;
        ctr=ctr->next;
    }
    struct Node* nlink=ctr->next->next;
    struct Node* tl=nlink->next;
    struct Node* tl1=ctr->next;
    ctr->next=nlink; 
    ctr->next->next=tl1; 
    ctr->next->next->next=tl;  
}


// sort the Python list
// you may use the above defined swap function to 
// implement bubble sort. But its upto you, use whatever algorithm
// that you seem comfortable.
void sort() {
    int n=len();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(getitem(j)>getitem(j+1))
            {
                swap(j);
            }
        }
    }
}


// ----------------------- Driver program starts here -----------------------

int main(int argc, char const *argv[])
{
    int T; 
    scanf("%d", &T);

    char operation_type[20];
    int indices[100];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "append") == 0) {
            int x;
            scanf("%d", &x);
            append(x);
        } 

        if(strcmp(operation_type, "insert") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            insert(pos, x);
        }

        if(strcmp(operation_type, "pop") == 0) {
            pop();
        }

        if(strcmp(operation_type, "clear") == 0) {
            clear();
        }

        if(strcmp(operation_type, "count") == 0) {
            int x;
            scanf("%d", &x);
            int cnt = count(x);
            printf("%d\n", cnt);
        }

        if(strcmp(operation_type, "reverse") == 0) {
            reverse();
        }

        if(strcmp(operation_type, "len") == 0) {
            int length = len();
            printf("%d\n", length);
        }

        if(strcmp(operation_type, "setitem") == 0) {
            int pos, x;
            scanf("%d %d", &pos, &x);
            setitem(pos, x);
        }

        if(strcmp(operation_type, "getitem") == 0) {
            int pos;
            scanf("%d", &pos);
            int value = getitem(pos);
            printf("%d\n", value);
        }

        if(strcmp(operation_type, "print") == 0) {
            print_list(PythonListHead);
        }

        if(strcmp(operation_type, "erase") == 0) {
            int pos;
            scanf("%d", &pos);
            erase(pos);
        }

        if(strcmp(operation_type, "swap") == 0) {
            int pos;
            scanf("%d", &pos);
            swap(pos);
        }

        if(strcmp(operation_type, "index_into") == 0) {
            int n;
            scanf("%d", &n);
            for(int i=0;i<n;i++) scanf("%d", &indices[i]);
            struct Node* new_head = index_into(indices, n);
            print_list(new_head);
        }

        if(strcmp(operation_type, "sort") == 0) {
            sort();
        }
    }
}
