#include <iostream>
using namespace std;

bool SentinelSearch(int list[], int last, int target, int& locn){
    list[last] = target;
    int looker = 0;
    while (target != list[looker])
    {
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
    int myData[] = { 5, 7, 15, 8, 4, 11};
    int index;
    bool result = SentinelSearch(myData, 7, 1, index);

    if (result){
        cout << "found data: " << 15 << "index: " << index;
    }else{
        cout << "not found";
    }

    return 0;
}