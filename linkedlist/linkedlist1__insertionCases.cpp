#include <iostream>
using namespace std;

/* Node: A block containing two sub-blocks outta which one is to contain the data and other is to store the
address of the next node.

HEAD: Reference to the first node. Not to be treated as the node itself.
*/

class Node
{
public:
    int data;
    Node *next; // as it's gonna store the address of the type Node itself
};

void allaboutHead(Node **head_ref)
{
    cout << "\nhead_ref (address stored): " << head_ref << endl;
    cout << "*head_ref: (value at the address stored): " << *head_ref << "\n" << endl;
    // cout << "**head_ref: " << **head_ref << endl;
}

void push(Node **head_ref, int new_val)
// head is kinda default node that points to the null.
// head_ref is the reference of the head i.e. points to the head i.e. contains the address of the head.
// *head_ref contains the address of the head.
// **head_ref is the pointer that points to the address of the pointer head_ref.
{
    Node *new_node = new Node();  // dynamically created a node using pointer.
    new_node->data = new_val;     // (*new_node).data
    new_node->next = (*head_ref); // (*new_node).next // Now it's pointing towards whatever the head was pointing to.

    (*head_ref) = new_node;
    // now make the head points towards the newz-node, basic shit!
}
// if the head was pointing towards null, new_node will point towards null,
// and if the head's pointing towards some next_val, then likewise the new_node is gonna point to the same.


void insertAt(Node *prev_node, int new_val)
{
    if (prev_node == NULL) // what if prev_node->next == NULL
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
    while (node->next != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << endl; // because we gotta print the value at the last node too.
    return;

}

int main()
{
    Node *head = NULL;
    cout << head << endl;
    // cout << head->data << endl;
    // cout << head->next << endl;

    allaboutHead(&head);

    push(&head, 26);
    // head is itself an address essentially, and we are even passing its address
    // so its obvious pointer of pointer will do the needful

    // cout << "head: " << head << endl;
    // cout << "&head: " << &head << endl;
    // cout << "*head: " << *head << endl;
    // cout << "head->data: " << head->data << endl;
    // cout << "head->next: " << head->next << endl;

    append(&head, 11);
    append(&head, 1999);
    append(&head, 15);
    append(&head, 9);
    append(&head, 1972);
    append(&head, 17);
    append(&head, 8);
    append(&head, 1976);

    cout << "\n(head->next)->data: " << (head->next)->data << endl;
    cout << "(head->next)->next->data: " << (head->next)->next->data << endl;
    cout << "(head->next)->next->next->data: "
         << (head->next)->next->next->data << endl;

    push(&head, 2004);

    printLinkedlist(head);
    
    // Inserting a value at a certain position
    insertAt(head->next->next, 1990);

    printLinkedlist(head);

    return 0;
}