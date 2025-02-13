#include <iostream>
#include <cstring>
using namespace std;

typedef struct person{
    char name[10];

    struct person *next;
}node;

struct person *root = NULL;//node *root = NULL;


int main()
{
    node *ptr = new node;

    //ptr->name = "John";
    strcpy(ptr->name, "John");
    ptr->next = NULL;

    root = ptr; // root = pointer

    ptr = new node;
    strcpy(ptr->name, "Tonony");
    ptr->next = NULL; // ต่อ node1->node2

    root->next = ptr;

    ptr = new node;
    strcpy(ptr->name, "Bill");
    ptr->next = NULL;
    root->next->next = ptr; // ต่อ node2->node3

    ptr = root;
    while(ptr != NULL){
        cout << "Name: " << ptr->name << "" << endl;
        ptr = ptr->next;
    }


    return 0;
}