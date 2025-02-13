#include <iostream>
using namespace std;

bool binarySearch(int list[], int last, int target, int& locn){
    int begin = 0;
    int end = last - 1;
    int mid;
    while (begin <= end ){
        mid = (begin + end) / 2;
        if (target < list[mid])
            begin= (mid + 1);
        else if (target > list[mid])
            end = mid - 1;
        else
           locn = mid;
           return true;
    }
    locn = mid;
    bool found;
    if (target == list[mid]){
        found = true;
    }else{
        found = false;
    }
    return found;
}

int main() {
    int myData[] = { 5, 7, 9, 15, 19, 25};
    int index;
    bool result = binarySearch(myData, 6, 15, index);

    if (result){
        cout << "found data: " << 15 << "index: " << index;
    }else{
        cout << "not found";
    }

    return 0;
}