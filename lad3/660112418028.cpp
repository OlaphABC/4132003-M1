#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

/** โครงสร้างโหนด **/
typedef struct datanode {
    int id;
    char name[25];
    struct datanode *next;
}datanode;

typedef struct headnode {
    int count;
    datanode *front;
    datanode *rear;
}headnode;


headnode *createQueue(void);
headnode *destroyQueue(headnode *queue, int id, char *name);
bool enqueue(headnode *queue, int id, char *name);
bool dequeue(headnode *queue, int id, char *name);
bool queueFront(headnode *queue, int id, char *name);
bool queueRear(headnode *queue, int id, char *name);
int queueCount(headnode *queue);
void printQueue(headnode* queue);

headnode *MyQueue = NULL;
headnode * createQueue(void) {
    headnode *queue;
    queue = new headnode;
    queue->count = 0;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;

}

bool enqueue(headnode *queue, int id, char *name){
    datanode *ptr;
    ptr = new datanode;
    if(!ptr){
        return false;
    }

    ptr->id = id;
    strcpy(ptr->name, name);
    ptr->next = NULL;
    if(queue->count == 0)
        queue->front = ptr;
    else
        queue->rear->next = ptr;
    
    queue->rear = ptr;
    (queue->count)++;
    return true;
}

bool dequeue(headnode *queue, int id, char *name){
    datanode *delData;
    cout << "\n Dequeue Success\n";
    cout << " ID\tName\n";
    cout << " ---\t-----\n";
    cout << MyQueue->front->id<< "\t" << MyQueue->front->name << "\n\n";

    if(queue->count == 0)
        return false;
    
    id = queue->front->id;
    name = queue->front->name;
    delData = queue->front;
    if(queue->count == 1)
        queue->front = NULL;
    else
        queue->front = queue->front->next;

    (queue->count)--;
    free(delData);
    return true; 
}

bool queueFront(headnode *queue, int id, char *name){
    if (queue->count == 0)
        return false;
    
    id = queue->front->id;
    name = queue->front->name;
    return true;
}

bool queueRear(headnode *queue, int id, char *name){
    if (queue->count == 0){
        return false;
    
    id = queue->front->id;
    name = queue->rear->name;
    return true;
}
}

int queueCount(headnode *queue){
    cout << queue->count;
    return(queue->count);
}

headnode *destroyQueue(headnode *queue, int id, char *name){
    datanode *deletePtr;
    if(queue != NULL){
       
        while(queue->front != NULL){
            deletePtr = queue->front;
            queue->front = queue->front->next; 
            free (deletePtr);
        }
    }
	free(queue);
	queue = NULL;
	return(queue);
}

void printQueue(headnode* queue){
    datanode* node = queue->front;
    cout << "\tData in Queue\n\n";
    cout << " \tID\t\tName\n";
    cout << " \t---\t\t-----\n";
    cout << "Front=>";
    while(node){
        cout << "\t" << node->id;
        cout << "\t\t" << node->name << endl;
        node = node->next;
        } 
        cout << "\b<=Rear\n";
    return;
}

int main(){
    char name[20];
    int id, ch = 1;
    struct datanode *ptr;


    while(ch!=0){
        system("cls");
        cout << " \n**Struct Queue Program Test** \n";
        cout << " \n 1 Create Queue \n";
        cout << " 2 Enqueue \n";
        cout << " 3 Dequeue \n";
        cout << " 4 Queue Front \n";
        cout << " 5 Queue Rear \n";
        cout << " 6 Queue Count \n";
        cout << " 7 Destroy Queue \n";
        cout << " 8 Print List Queue \n";
        cout << " 0 Quit \n";

        cout << "\n Please Select Your Function Number [0-8]: ";

        cin >> ch;
        switch(ch){
            case 1:
                system("cls");
                MyQueue = createQueue();
                if(MyQueue != NULL){
                    cout << "\n Create Queue Complete \n\n";
                    cout << " Please any key to continue..."; 
                    }
                else {
                    cout << "\n Can't Create Queue \n\n";
                    cout << " Please any key to continue..."; 
                    }
                getch();
                break;
                
            case 2:
                system("cls");
                cout << "\n Enter Your ID : ";
                cin >> id;
                cout << " Enter Your name : ";
                cin >> name;

                if(enqueue(MyQueue,id,name)){
                    cout << "\n Enqueue Success \n\n";
                    cout << " ID\tName\n";
                    cout << " ---\t-----\n";
                    cout << MyQueue->rear->id << "\t" << MyQueue->rear->name << endl << endl;
                    cout << " Please any key to continue..."; 
                    }
                else {
                    cout << "\n Can't Enqueue \n\n";
                    cout << " Please any key to continue..."; 
                    }
                getch();
                break;
            case 3:
                system("cls");
                if(dequeue(MyQueue,id,name)){
                    cout << " Please any key to continue...";
                    }
                else {
                    cout << "\n Can't Dequeue, because it's underflow \n\n";
                    cout << " Please any key to continue..."; 
                    }
                getch();
                break;
            case 4:
                system("cls");
                if(queueFront(MyQueue,id,name)){
                    cout << "\nQueueFront Success\n\n";
                    cout << " ID\tName\n";
                    cout << " ---\t-----\n";
                    cout << MyQueue->front->id <<"\t" << MyQueue->front->name << endl << endl;
                    cout << " Please any key to continue...";
                    }
                else {
                    cout << "\n Can't QueueFornt \n\n";
                    cout << " Please any key to continue..."; 
                    }
                getch();
                break;
            case 5:
                system("cls");
                if(queueRear(MyQueue,id,name)){
                    cout << "\nQueueRear Success \n\n";
                    cout << " ID\tName\n";
                    cout << " ---\t-----\n";
                    cout << MyQueue->rear->id << "\t" << MyQueue->rear->name << endl << endl;
                    cout << " Please any key to continue...";
                    }
                else {
                    cout << "\n Can't QueueRear \n\n";
                    cout << " Please any key to continue..."; 
                    }
                getch();
                break;
            case 6:
                system("cls");
                cout << "\nData in Queue count : ";
                queueCount(MyQueue);
                cout << " \n\nPlease any key to continue...";
                getch();
                break;
            case 7:
                system("cls");
                
                if(MyQueue != NULL){
                    cout << "\n Destroy Queue Complete \n\n";
                    cout << " Please any key to continue...";
                    destroyQueue(MyQueue,id,name);
                     }
                else {
                    cout << "\n Can't Destroy Queue \n\n";
                    cout << " Please any key to continue..."; 
                    }
                    getch();
                break;
            case 8:
                system("cls");
                printQueue(MyQueue);
                cout << " \n\nPlease any key to continue...";
                getch();
                break;
        }
    }
    return(0);
}