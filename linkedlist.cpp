#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
};
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
};
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
};
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
};
void deletion(node *&head, int val)
{
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
};

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
};
node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    int count = 0;
    while (currptr != NULL && count < k)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }

    return prevptr;
}

void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startnode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startnode = temp;
        };
        temp = temp->next;
        count++;
    }

    temp->next = startnode;
}

//Floyd's Algorithm or hare and tortoise algorithm
// If both the pointers meet at a point then the given link list has a cycle
bool detectcycle(node *&head)
{
    node *slow = head; // moves by one block at a time
    node *fast = head; // moves by two blocks at a time

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}



node *kappend(node *&head, int k)
{
    node *newtail;
    node *newhead;
    node *tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == k)
        {
            newtail = tail;
        }

        if (count == k + 1)
        {
            newhead = tail;
        }
        tail = tail->next;
        count++;
    }

    newtail->next = NULL;
    tail->next = head;

    return newhead;
}


void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }

    node* temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    
    
}

int intersectionpt(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }else{
        d = l2- l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1; 
        }
        
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        
    }

    return -1;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 5);
    insertAthead(head, 10);
    insertAtTail(head, 8);
    insertAtTail(head, 32);
    // insertAtTail(head, 6);
    // insertAtTail(head, 465);
    // insertAtTail(head, 564);
    //makecycle(head, 3);

    //cout << detectcycle(head) << endl;
    //removeCycle(head);
    //cout << detectcycle(head) << endl;
    display(head);
    // node *newhead = reversek(head, 2);
    // display(newhead);

    // deletion(head, 1);

    // cout << length(head);

     node *newhead = kappend(head, 2);
    display(newhead);
    return 0;
}