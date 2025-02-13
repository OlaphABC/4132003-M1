#include <iostream>
#include <cstring>
using namespace std;
/* กำหนดโหนดสำหรับเก็บข้อมูลพนักงาน */
typedef struct node {
   
   int  id;
   char  name[45];
   double  price;
   struct node *next;
} product;

/* function prototypes */
product * initnode( char *, int );
void printnode( product * );
void printlist( product * );
void add( product * );
product * searchname( product *ptr, char *name );
void insertNode(product *newnode);
void deleteNode(product *delNode);

/* ตัวแปรพอยเตอร์ head ชี้โหนดแรก, ตัวแปร endList ชี้ที่โหนดสุดท้าย */
/* กำหนดค่าเริ่มต้นให้กับตัวแปรทั้งสองเป็น NULL */
product *head =  NULL;
product *endList = NULL;

/* ฟังก์ชัน initnode สำหรับจัดสรรหน่วยความจำสำหรับโหนดใหม่   */
/* และส่งตำแหน่งของโหนดใหม่กลับคืน */
product * initnode( int id, char *name, double price )
{
   product *ptr;
   ptr = new product;
   if( ptr == NULL )                       
       return(NULL);        
   else {                                
       ptr->id = id;   
       strcpy( ptr->name, name );  
       ptr->price = price;          
       return(ptr);
   }
}

/* ฟังก์ชัน printnode พิมพ์รายละเอียดของโหนดที่ต้องการ  */
void printnode( product *ptr )
{
   cout << "ID   : " << ptr->id << endl;
   cout << "Name : " << ptr->name << endl;
   cout << "Price   : " << ptr->price <<endl;
}

/* ฟังก์ชัน printlist พิมพ์รายละเอียดโหนดปัจจุบัน จนถึงโหนดสุดท้ายในลิสต์    */
void printlist( product *ptr )
{
   cout << "---------------------------------------------" << endl;
   cout << "List all node" << endl;
   cout << "---------------------------------------------" << endl;
   while( ptr != NULL )  
   {
      printnode( ptr );  
      ptr = ptr->next;  
   }
   cout << "---------------------------------------------" << endl;
}

/* ฟังก์ชัน add ใช้เพิ่มโหนดใหม่ต่อท้ายลิสต์ (จะต้องสร้าง และใส่ค่าให้เรียบร้อยก่อน)  */
void add( product *newprt ) 
{
   if( head == NULL )  
   {
       head = newprt; 
       endList = newprt;   
   }
   endList->next = newprt;
   newprt->next = NULL; 
   endList = newprt;       
}

product * searchname( product *ptr, char *name )
{
    if(ptr == NULL) return(NULL);
    while( strcmp( name, ptr->name ) != 0 ) { 
       ptr = ptr->next; 
       if( ptr == NULL )   
          break;           
    }
    
    return(ptr);     
}   


void insertNode(product *newnode){
   product *tmp, *prev;
   if(head == NULL){
      head = newnode;
      endList = newnode;
      return;
   }
   tmp = head;
   while(strcmp(tmp->name, newnode->name) < 0){
      tmp = tmp->next;
      if(tmp == NULL)
         break;
   }
   if(tmp == head){
      newnode->next = head;
      head = newnode;
   }else{
      prev = head;
      while(prev->next != tmp){
         prev = prev->next;
      }
      prev->next = newnode;
      newnode->next = tmp;
      if(endList == prev)
         endList = newnode;
   }
}

void deleteNode(product *delNode){
   product *tmp, *prev;
   tmp = delNode;
   prev = head;

   if(tmp == head){
      head = head->next;
      if(endList == tmp){
         endList = endList->next;
      }
     
   }else{
      while(prev->next != tmp){
         prev = prev->next;
      }
      prev->next = tmp->next;
      if(endList == tmp){
         endList = prev;
      }
   }
   free(tmp);
}

int main()
{
   int id; char name[20]; double price;
   int ch = 1;
   product *ptr;
   system("cls");
   while( ch != 0 ) {
      cout << "1 add a name" << endl ;
      cout << "2 list all names" << endl;
      cout << "3 search for name" << endl;
      cout << "4 insert a name" << endl;
      cout << "5 delete a name" << endl;
      cout << "0 quit" << endl;
      cout << "Selet [0 - 5] : ";
      cin >> ch;
      switch( ch )
      {
          case 1:  /* เพิ่มโหนดใหม่ต่อท้ายลิสต์ */
                   cout << "Enter in id : ";
                   cin >> id;
                   cout << "Enter in name : ";
                   cin >> name;
                   cout << "Enter in price : ";
                   cin >> price;
                   ptr = initnode( id, name, price );
                   add( ptr );
                   break;
          case 2:  /* ท่องลิสต์ (แสดงข้อมูลทุกโหนด) */
                   printlist( head );
                   break;
          case 3:  /* ค้นหา ชื่อ (ข้อความ อาร์เรย์) */
                   cout << "Enter in name : ";
                   cin >> name;
                   ptr = searchname( head, name );
                   cout << "-----------Search-------------" << endl;
                   if( ptr ==NULL ) {
                       cout << "Name " << name << " not found\n";
                   }
                   else
                      printnode( ptr );
                  cout << "-------------------------------" << endl;
                   break;
          case 4:  /* เพิ่มโหนดใหม่จัดเรียงลำดับตามชื่อ */
                   cout << "Enter in id : ";
                   cin >> id;
                   cout << "Enter in name : ";
                   cin >> name;
                   cout << "Enter in price : ";
                   cin >> price;
                   ptr = initnode( id, name, price );
                   insertNode( ptr );
                   break;
         case 5:  /* ลบโหนด */
                   cout << "Enter in name : ";
                   cin >> name;
                   ptr = searchname( head, name );
                   cout << "-----------Delete-------------" << endl;
                   if( ptr ==NULL ) {
                       cout << "Name " << name << " not found\n";
                   }
                   else{
                        deleteNode( ptr );
                        cout << "Delete success"<< endl;
                   }
                  cout << "-------------------------------" << endl;
                   break;
      }
   }
   return 0;
}