#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct Employee {
    int emp_id; // emp_ids will be unique
    struct Employee* subordinate_1;
    struct Employee* subordinate_2;
};
struct Node
{
    struct Employee* data;
    struct Node* next;
};
struct Node* create_node(struct Employee* x) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = NULL;
    ptr->data = x;
    return ptr;
}
void delete_node(struct Node* ptr) {
    free(ptr);
}
struct Node* PythonListHead = NULL;
void print_list(struct Node* head) {
    struct Node* cur = head;
    while(cur) {
        printf("%d ", cur->data->emp_id);
        cur = cur->next;
    }
    printf("\n");
}
struct Node* get_node_at_pos(int position) {
    int pos = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        if(pos == position) return cur;
        pos++;
        cur = cur->next;
    }
    return NULL;
}
int len() {
    int length = 0;
    struct Node* cur = PythonListHead;
    while(cur) {
        length++;
        cur = cur->next;
    }
    return length;
}
void append(struct Employee* x) {
    struct Node* cur = PythonListHead;
    if(cur == NULL) {
        // no list exists, we have to create one
        PythonListHead = create_node(x);
    }
    else {
        int pos = len() - 1;
        struct Node* last_node = get_node_at_pos(pos);
        last_node->next = create_node(x);
    }
}
void insert(int position, struct Employee* x) {
    int n = len();
    if(position >= n) return;
    struct Node* node_at_position = get_node_at_pos(position);
    if(position == 0) {
        struct Node* new_node = create_node(x);
        new_node->next = node_at_position;
        PythonListHead = new_node;
    }
    else {
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = create_node(x);
        previous_node->next->next = node_at_position;
    }
}

void pop() {
    int n = len();
    if(n == 0) return;

    if(n == 1) {
        delete_node(PythonListHead);
        PythonListHead = NULL;
    }
    else {
        struct Node* second_last_node = get_node_at_pos(n-2);
        delete_node(second_last_node->next);
        second_last_node->next = NULL;
    }
}
void clear() {
    struct Node* cur = PythonListHead;
    PythonListHead = NULL;
    while(cur) {
        struct Node* next_node = cur->next;
        delete_node(cur);
        cur = next_node;
    }
}
struct Node* reverse_helper(struct Node* cur_node) {
    if(cur_node == NULL) return NULL;

    if(cur_node->next == NULL) {
        PythonListHead = cur_node;
        return cur_node;
    }

    struct Node* next_node = reverse_helper(cur_node->next);

    next_node->next = cur_node;
    cur_node->next = NULL;

    return cur_node;
}

// Reverse the elements of the list in place.
// Make sure you change `PythonListHead` accordingly
void reverse() {
    struct Node* last_node = reverse_helper(PythonListHead);
}


// Set the data attribute of the node at `position` to `x`
// if no such position, do nothing
void setitem(int position, struct Employee* x) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        node_at_pos->data = x;
    }
}


// Return the data of the node at `position` 
// if no such position, return -1
struct Employee* getitem(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(node_at_pos) {
        return node_at_pos->data;
    }
    else return NULL;
}


// erase the node at position
// if no such position, do nothing
void erase(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    if(!node_at_pos) return;

    // 2 cases now
    // if node_at_pos is the first node
    if(node_at_pos == PythonListHead) {
        PythonListHead = PythonListHead->next;
        delete_node(node_at_pos);
    }
    else {
        struct Node* previous_node = get_node_at_pos(position-1);
        previous_node->next = node_at_pos->next;
        delete_node(node_at_pos);
    }
}
struct Node* index_into(int *positions, int n) {
    // your code goes here
    struct Node* new_list_head = NULL;
    struct Node* new_list_tail = NULL;
    for(int i=0;i<n;i++) {
        struct Node* node_at_pos = get_node_at_pos(positions[i]);

        if(!node_at_pos) continue;

        if(new_list_tail) {
            new_list_tail->next = create_node(node_at_pos->data);
            new_list_tail = new_list_tail->next;
        }
        else {
            new_list_head = create_node(node_at_pos->data);
            new_list_tail = new_list_head;
        }
    }
    return new_list_head;
}
void swap(int position) {
    struct Node* node_at_pos = get_node_at_pos(position);
    struct Node* next_node = get_node_at_pos(position+1);
    if(!node_at_pos || !next_node) return;

    // 2 cases 
    if(node_at_pos == PythonListHead) {
        PythonListHead = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
    else {
        struct Node* prev_node = get_node_at_pos(position-1);
        prev_node->next = next_node;
        node_at_pos->next = next_node->next;
        next_node->next = node_at_pos;
    }
}
/*void sort() {
    int n = len();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            int x = get_node_at_pos(j)->data;
            int y = get_node_at_pos(j+1)->data;
            if(x > y) swap(j);
        }
    }
}*/
// The following is a employee in the organization, it has the pointer to two more employees a subordinate_1 and a subordinate_2


// The following function creates a employee and returns its pointer
struct Employee* create_employee(int x) {
    struct Employee* ptr = (struct Employee*) malloc(sizeof(struct Employee));
    ptr->emp_id = x;
    ptr->subordinate_1 = NULL;
    ptr->subordinate_2 = NULL;
    return ptr;
}

// The following code creates a organization from scanning the input file
struct Employee* create_organization() {
    int x;
    scanf("%d", &x);

    if(x == -1) return NULL; // -1 is used when there is a NULL pointer ie when no value is present
    struct Employee* par = create_employee(x);

    par->subordinate_1 = create_organization();
    par->subordinate_2 = create_organization();
    
    return par;
}

// The following function 
void print_organization_helper(struct Employee* ceo) {
    // take input
    if(!ceo) {
        printf("%d ", -1);
        return;
    }
    printf("%d ", ceo->emp_id);
    print_organization_helper(ceo->subordinate_1);
    print_organization_helper(ceo->subordinate_2);
    return;
}

void print_organization(struct Employee* ceo) {
    print_organization_helper(ceo);
    printf("\n");
    return;
} 
struct Employee* Organization = NULL;
int size(struct Employee* cur)
{
    if(cur==NULL)
    {
        return 0;
    }
    return size(cur->subordinate_1)+size(cur->subordinate_2)+1;
}
/*  In this function you have to print all the employees at a given level, Note that ceo is at level 0
In any of the functions which involve printing you need not print -1 for NULL pointers */
void EmployeesAtSameLevel(int level) {
    append(Organization);
    struct Node* rear;
    rear=PythonListHead;
    int l=1;
    int nodelo=1;
    int nodehi=0;
    int lolvl=0;
    if(level==0)
    {
        printf("%i", Organization->emp_id);
        return;
    }
    while(l!=0)
    {
        struct Employee* cur=getitem(0);
        if(cur->subordinate_1!=NULL)
        {
            l++;
            nodehi++;
            struct Node* rearn = create_node(cur->subordinate_1);
            rear->next=rearn;
            rear=rearn;
        }
        if(cur->subordinate_2!=NULL)
        {
            l++;
            nodehi++;
            struct Node* rearn = create_node(cur->subordinate_2);
            rear->next=rearn;
            rear=rearn;
        }
        erase(0);
        l--;
        nodelo--;
        if(nodelo==0)
        {
            nodelo=nodehi;
            nodehi=0;
            lolvl++;
            if(lolvl==level)
            {
                for(int i=0;i<nodelo;i++)
                {
                    struct Employee* cur1=getitem(0);
                    erase(0);
                    printf("%i ", cur1->emp_id);
                }
                clear();
                l=0;
                return;
            }
        }

    }
    clear();
}
// You have to print the employees as you search the organization look for the examples in the pdf and the input.txt and output.txt for details
// Note: You do not have to print -1 for NULL pointers
void get_emp_rec(struct Employee* cur)
{
    if(cur==NULL)
    {
        return;
    }
    else
    {
        printf("%i ",cur->emp_id);
        get_emp_rec(cur->subordinate_1);
        get_emp_rec(cur->subordinate_2);
    }
}
void get_employees() {
    get_emp_rec(Organization);
}
struct Employee* find_emp_by_id(int emp_id, struct Employee* cur)
{
    if(cur==NULL)
    {
        return NULL;
    }
    else if(cur->emp_id==emp_id)
    {
        return cur; 
    }
    else
    {
        struct Employee* k1=find_emp_by_id(emp_id, cur->subordinate_1);
        struct Employee* k2=find_emp_by_id(emp_id, cur->subordinate_2);
        if(k1==NULL)
        {
            return k2;
        }
        else
        {
            return k1;
        }
    }
}
/* In the following function you have to print the immediate team of a employee - it includes their boss and their subordinates
Note: You do not have to print -1 for NULL pointers */
struct Employee* get_boss(struct Employee* emp, struct Employee* cur)
{
    if(emp==Organization)
    {
        return Organization; //root node
    }
    if(cur==NULL)
    {
        return NULL;
    }
    if(cur->subordinate_1!=NULL)
    {
        if(cur->subordinate_1==emp)
        {
            return cur;
        }
    }
    if(cur->subordinate_2!=NULL)
    {
        if(cur->subordinate_2==emp)
        {
            return cur;
        }
    }
    struct Employee* k1=get_boss(emp, cur->subordinate_1);
    struct Employee* k2=get_boss(emp, cur->subordinate_2);
    if(k1!=NULL)
    {
        return k1;
    }
    else
    {
        return k2;
    }
    return NULL;
}
void ImmediateTeam(int emp_id) {
    struct Employee* cur= find_emp_by_id(emp_id, Organization);
    if(cur==NULL)
    {
        return;
    }
    else
    {
        struct Employee* boss=get_boss(cur, Organization);
        if(cur!=Organization)
        {
           printf("%i ", boss->emp_id); 
        }
        if(cur->subordinate_1!=NULL)
        {
            printf("%i ", cur->subordinate_1->emp_id);
        }
        if(cur->subordinate_2!=NULL)
        {
            printf("%i ", cur->subordinate_2->emp_id);
        }
    }
    return;
}
struct Employee* find_leaf(struct Employee* cur)
{
    if(cur==NULL)
    {
        return NULL;
    }
    if(cur->subordinate_1==NULL && cur->subordinate_2==NULL)
    {
        return cur;
    }
    else
    {
        if(cur->subordinate_1!=NULL)
        {
            return find_leaf(cur->subordinate_1);
        }
        if(cur->subordinate_2!=NULL)
        {
            return find_leaf(cur->subordinate_2);
        }
    }
    return NULL;
}
int find_distance(struct Employee* cur, struct Employee* emp2)
{
    if(cur==NULL)
    {
        return -1;
    }
    if(cur==emp2)
    {
        return 0;
    }
    int k1=find_distance(cur->subordinate_1, emp2);
    int k2=find_distance(cur->subordinate_2, emp2);
    if(k1==-1 && k2==-1)
    {
        return -1;
    }
    else if(k1==-1)
    {
        return 1+k2;
    }
    else if(k2==-1)
    {
        return 1+k1;
    }
    return 1+k2;
}
struct Employee* lca(struct Employee* cur, struct Employee* emp1, struct Employee* emp2)
{
    if(cur==NULL)
    {
        return NULL;
    }
    if(cur==emp1||cur==emp2)
    {
        return cur;
    }
    struct Employee* sub1 = lca(cur->subordinate_1, emp1, emp2);
    struct Employee* sub2 = lca(cur->subordinate_2, emp1, emp2);
    if(sub1==NULL)
    {
        return sub2;
    }
    else if(sub2==NULL)
    {
        return sub1;
    }
    return cur;
}
// The following function gives the distance between employees with emp_id1 and emp_id2
int Distance(int emp_id1, int emp_id2) {
    // If emp_id1 and emp_id2 are equal the distance is 0
    struct Employee* emp1=find_emp_by_id(emp_id1, Organization);
    struct Employee* emp2=find_emp_by_id(emp_id2, Organization);
    if(emp_id1==emp_id2)
    {
        return 0;
    }
    return find_distance(Organization, emp2)+find_distance(Organization, emp1)-2*find_distance(Organization, lca(Organization, emp1, emp2));
}
// The following function returns the level of a employee with the given emp_id
int Level(int emp_id) {
    // Note that ceo has level 0
    return Distance(Organization->emp_id, emp_id);
}

/* The following function takes an emp_id this will belong to a employee in the organisation and your task is to return the emp_id of its boss
Note: If the boss does not exit return -1 */
int Boss(int emp_id) {
    struct Employee* ret=get_boss(find_emp_by_id(emp_id, Organization), Organization);
    if(ret->emp_id==emp_id)
    {
        return -1;
    }
    else
    {
        return ret->emp_id;
    }
    return 0;
}
int dia=0;
int depth(struct Employee* cur)
{
    if(cur==NULL)
    {
        return 0;
    }
    int lh = depth(cur->subordinate_1);
    int rh = depth(cur->subordinate_2);
    if(dia<1+lh+rh)
    {
        dia=1+lh+rh;
    }
    if(lh>rh)
    {
        return lh+1;
    }
    else
    {
        return rh+1;
    }
}
int Diameter() {
    int k=depth(Organization);
    return dia-1;
}

/* The following function takes an emp_id of a employee and returns the number of employees directly connected to it.
NULL pointers are not included */
int TeamSize(int emp_id) {
    struct Employee* cur= find_emp_by_id(emp_id, Organization);
    int ans=0;
    struct Employee* boss=get_boss(cur, Organization);
    if(cur!=Organization)
    {
       ans++;
    }
    if(cur->subordinate_1!=NULL)
    {
        ans++;
    }
    if(cur->subordinate_2!=NULL)
    {
        ans++;
    }
    return ans;
}

// --------------------------------------------------- YOU CAN EDIT ABOVE THIS LINE -----------------------------------

/* The following driver code creates a organisation for you and based on the input file
it will call all the functions that are necessary, your job is to edit the functions
above the line. Their descriptions are in the pdf and in the comments in the code. */

int main(int argc, char const *argv[])
{
    Organization = create_organization();
    print_organization(Organization);

    int T; 
    scanf("%d", &T);

    char operation_type[50];

    while(T--) {
        scanf("%s", operation_type);

        if(strcmp(operation_type, "level") == 0) {
            int x;
            scanf("%d", &x);
            int d = Level(x);
            printf("%d\n", d);
        } 

        if(strcmp(operation_type, "distance") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            int d = Distance(x, y);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "employees_at_same_level") == 0) {
            int x;
            scanf("%d", &x);
            EmployeesAtSameLevel(x);
            printf("\n");
        }

        if(strcmp(operation_type, "get_employees") == 0) {
            get_employees();
            printf("\n");
        }

        if(strcmp(operation_type, "boss") == 0) {
            int x;
            scanf("%d", &x);
            int d = Boss(x);
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "diameter") == 0) {
            int d = Diameter();
            printf("%d\n", d);
        }

        if(strcmp(operation_type, "immediate_team") == 0) {
            int x;
            scanf("%d", &x);
            ImmediateTeam(x);
            printf("\n");
        }

        if(strcmp(operation_type, "team_size") == 0) {
            int x;
            scanf("%d", &x);
            int d = TeamSize(x);
            printf("%d\n", d);
        }
    }

    return 0;
}
