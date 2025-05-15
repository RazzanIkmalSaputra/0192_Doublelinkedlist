#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;


private:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addnode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        //step 1: allocate memory for new code
        Node *newnode = new Node();

        //step 2: assign value to the data fields
        newnode->noMhs = nim;

        //step 3: insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim<= START->noMhs)
        {
            if (START !=NULL && nim == START->noMhs )
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            //step 4: newNode.next = start
            newnode->next = START;

            //step 5: START.prev == newNode (if START exists)
            if (START != NULL)
                START->prev = newnode;
            
            // step 6: newNode,prev = NULL
            newnode->prev = NULL;

            //step 7: START = newNode
            START = newnode;
            return;
        }

        //insert in between node
        //step 8: locate position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // step 9: insert between current and current->next
        newnode->next == current->next; //step 9a: newNode.next = current.next
        newnode->prev = current; // step 9b: newNode.prev = current

        //insert last node
        if (current->next != NULL)
            current->next->prev = newnode; // step 9c: current.nex.prev = newNode

        current->next = newnode; // step 9d: current.next = newNode
    }

    void hapus ()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollno;
        cin >> rollno;

        Node *current =START;

        // step 1: traverse the list to find the node
        while (current != NULL && current->noMhs != rollno)
            current = current->next;

        if (current == NULL)
        {
            cout << "record not found" << endl;
            return;
        }

        //step 2: if node is at the beginning
        if (current == START)
        {
            START = current->next; // step 2a: START = START.next
            if (START  != NULL)
                START->prev = NULL; //step 2b START.prev = NULL
        }
        else
        {
            //step 3: link previous node to next of current
            current->prev->next = current->next;

            //step 4: if current is not the last node 
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        //step 5: delete the node 
        delete current;
        cout << "record with roll number " << rollno << "deleted" << endl; 
    }

 