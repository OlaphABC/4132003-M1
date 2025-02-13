#include <iostream>
#include <cstring>
using namespace std;

/* กำหนดโหนดสำหรับเก็บข้อมูลพนักงาน */
typedef struct node {
    int id;
    char name[45];
    double price;
    struct node *next;
} product;

/* function prototypes */
product *initnode(int, char *, double);
void printnode(product *);
void printlist(product *);
void add(product *);
void searchByName(product *, const char *);

/* ตัวแปรพอยเตอร์ head ชี้โหนดแรก, ตัวแปร endList ชี้ที่โหนดสุดท้าย */
product *head = NULL;
product *endList = NULL;

/* ฟังก์ชัน initnode สำหรับจัดสรรหน่วยความจำสำหรับโหนดใหม่ */
product *initnode(int id, char *name, double price) {
    product *ptr;
    ptr = new product;
    if (ptr == NULL)
        return (NULL);
    else {
        ptr->id = id;
        strcpy(ptr->name, name);
        ptr->price = price;
        return (ptr);
    }
}

/* ฟังก์ชัน printnode พิมพ์รายละเอียดของโหนดที่ต้องการ */
void printnode(product *ptr) {
    cout << "ID   : " << ptr->id << endl;
    cout << "Name : " << ptr->name << endl;
    cout << "Price: " << ptr->price << endl;
}

/* ฟังก์ชัน printlist พิมพ์รายละเอียดโหนดปัจจุบัน จนถึงโหนดสุดท้ายในลิสต์ */
void printlist(product *ptr) {
    cout << "---------------------------------------------" << endl;
    cout << "List all nodes" << endl;
    cout << "---------------------------------------------" << endl;
    while (ptr != NULL) {
        printnode(ptr);
        ptr = ptr->next;
    }
    cout << "---------------------------------------------" << endl;
}

/* ฟังก์ชัน add ใช้เพิ่มโหนดใหม่ต่อท้ายลิสต์ */
void add(product *newprt) {
    if (head == NULL) {
        head = newprt;
        endList = newprt;
    } else {
        endList->next = newprt;
        endList = newprt;
    }
    newprt->next = NULL;
}

/* ฟังก์ชัน searchByName สำหรับค้นหาข้อมูลโดยใช้ชื่อ */
void searchByName(product *ptr, const char *name) {
    bool found = false;
    cout << "---------------------------------------------" << endl;
    cout << "Search results for: " << name << endl;
    cout << "---------------------------------------------" << endl;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) { // เปรียบเทียบชื่อ
            printnode(ptr);
            found = true;
        }
        ptr = ptr->next;
    }
    if (!found) {
        cout << "No product found with the name \"" << name << "\"." << endl;
    }
    cout << "---------------------------------------------" << endl;
}

int main() {
    int id;
    char name[20];
    double price;
    int ch = 1;
    product *ptr;

    system("cls");

    while (ch != 0) {
        cout << "1 add a name" << endl;
        cout << "2 list all names" << endl;
        cout << "3 search by name" << endl; // เพิ่มตัวเลือกค้นหา
        cout << "0 quit" << endl;
        cout << "Select [0 - 3] : ";
        cin >> ch;

        switch (ch) {
            case 1: // เพิ่มโหนดใหม่ต่อท้ายลิสต์
                cout << "Enter in id : ";
                cin >> id;
                cout << "Enter in name : ";
                cin >> name;
                cout << "Enter in price : ";
                cin >> price;
                ptr = initnode(id, name, price);
                add(ptr);
                break;
            case 2: // ท่องลิสต์ (แสดงข้อมูลทุกโหนด)
                printlist(head);
                break;
            case 3: // ค้นหาชื่อ
                cout << "Enter name to search: ";
                cin >> name;
                searchByName(head, name);
                break;
        }
    }

    return 0;
}