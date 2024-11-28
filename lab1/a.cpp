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

    root = ptr;

    ptr = new node;
    strcpy(ptr->name, "Tonony");
    ptr->next = NULL;

    root->next = ptr;

    ptr = root;
    while(ptr != NULL){
        cout << "Name: " << ptr->name << "" << endl;
        ptr = ptr->next;
    }


    return 0;
}