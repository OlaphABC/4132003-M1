#include <iostream>
using namespace std;

bool OrderedListSearch(int list[], int last, int target, int& locn){
    list[last] = target;
    int looker = 0;
    while (target != list[looker])
    {
        if (target > list[looker])
        exit;
        looker++;
    }
    bool found;
    if (target == list[looker]){
        found = true;
        locn = looker;
    }else{
        found = false;
        locn = last;
    }
    return found;
}

int main() {
    int myData[] = { 5, 7, 9, 15, 19, 25};
    int index;
    bool result = OrderedListSearch(myData, 6, 1, index);

    if (result){
        cout << "found data: " << 1 << "index: " << index;
    }else{
        cout << "not found";
    }

    return 0;
}