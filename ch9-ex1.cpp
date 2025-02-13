#include <iostream>
using namespace std;

bool seqSearch(int list[], int last, int target, int& locn){
    int looker = 0;
    while (looker <= last && target != list[looker])
    {
        looker++;
    }
    locn = looker;
    bool found;
    if (target == list[looker])
        found = true;
    else
        found = false;
    return found;
}

int main() {
    int myData[] = { 5, 7, 15, 8, 4, 11};
    int index;
    bool result = seqSearch(myData, 6, 1, index);

    if (result){
        cout << "found data: " << 15 << "index: " << index;
    }else{
        cout << "not found";
    }

    return 0;
}