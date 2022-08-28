#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // as it's gonna store the address of the type Node itself
};

void push(Node **head_ref, int new_val)

{
    Node *new_node = new Node();
    new_node->data = new_val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    // now make the head points towards the newz-node, basic shit!
}

void insertAt(Node *prev_node, int new_val)
{
    if (prev_node == NULL)
    {
        cout << "Previous Node seems to be NULL!";
        return;
    }

    // default Step: Create a node to be inserted!
    Node *new_node = new Node();
    new_node->data = new_val;

    // Step 1: Make it point to the node that's gotta be dragged and has to make space for new_node
    new_node->next = prev_node->next; // *new_node.next = *prev_node.next
    // --> now, the new_node is pointing towards the node next to the prev_node.

    // Step 2: Now, make the prev_node points towards the node to be inserted i.e. new_node
    prev_node->next = new_node;
}

void append(Node **head_ref, int new_val)
{
    Node *new_node = new Node();
    new_node->data = new_val;
    new_node->next = NULL; // since our new_node is gonna be the last element of the linkedlist

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        // ..means if the ll contains only one element i.e. head then just push and return
        return;
    }

    // Creating a traverser that's gonna traverse the whole linkedlist and returns the address of the last ele.
    Node *last = *head_ref;

    // At the absolute beginning, our last is the head.
    while (last->next != NULL)
    {
        last = last->next;
    }
    // at the very end last is literally the last node of the ll.
    last->next = new_node;
    return;
}

void printLinkedlist(Node *node)
// make a traverser, make it traverse through and make it return the values at hand.
{
    if (node == NULL)
    {
        cout << "The LinkedList doesn't even exist!" << endl;
        return;
    }
    while (node->next != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << endl; // because we gotta print the value at the last node too.
    return;
}

void deleteNode(Node **head_ref, int key)
// key is the val contained by the node to be deleted
{
    Node *temp = *head_ref; // address of head
    // temp is to store the address of the data that needs to be deleted
    // eventually by looping we'll get to it.
    // right now at this exact moment, temp is storing the address of the head
    Node *prev;

    // Case 1: When the head itself contains the `key`
    if (temp != NULL && temp->data == key)
    {
        // Note: If the head's gonna be deleted, we gotta change the head.
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Case 2: Traversing to find the key
    while (temp != NULL && temp->data != key)
    {
        prev = temp; // keep updating the prev
        temp = temp->next;
    }
    // Case 3: Head contains null
    if (temp == NULL)
    {
        cout << "The linkedlist doesn't even exist!" << endl;
        return;
    }
    // step 1: Change the next of the prev
    prev->next = temp->next;
    // step 2: free up the memory of the temp
    free(temp);
}

void deleteEntireList(Node **head_ref)
{
    Node *current = *head_ref; // what's the value at the address of the head? obviously the address of the first node!
    // now, the current has become the first node.

    Node *next_node;

    while (current != NULL)
    {
        // next_node holds the address while the current is being freed up!
        // that's its sole purpose.
        next_node = current->next;

        free(current);

        // now make the current holds the address of the next_node
        current = next_node;
    }
    // Now do not forget to free up the head
    *head_ref = NULL;
}

void countNodes(Node *head)
{
    int count = 0;
    Node *trav = head;

    if (trav == NULL)
    {
        cout << "The linkedlist doesn't contain any nodes yet!" << endl;
        return;
    }

    while (trav != NULL)
    {
        trav = trav->next;
        count += 1;
    }
    cout << "The number of the nodes in the desired linkedlist: " << count << endl;
}

void reverseList(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev; // Arrow reversed!

        // Now, updation:
        prev = current;
        current = next;
    }

    // Last step: Updating the head
    head = prev; // since, prev is now our first node; and current and next are pointing towards NULL.
}

int main()
{
    Node *head = NULL;
    cout << head << endl;

    push(&head, 26);

    append(&head, 11);
    append(&head, 1999);
    append(&head, 15);
    append(&head, 9);
    append(&head, 1972);
    append(&head, 17);
    append(&head, 8);
    append(&head, 1976);
    append(&head, 2011);
    append(&head, 2004);
    append(&head, 10);
    append(&head, 18);
    append(&head, 12);

    printLinkedlist(head);
    // countNodes(head);

    reverseList(head);
    

    return 0;
}