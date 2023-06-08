#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int arr[] = {14,45,2,17,1, 2, 3, 4, 5};
    
    int length = sizeof(arr) / sizeof(arr[0]);
    int newArray[9];
         
    int i = 0;
    for (i; i < length; i++) {
        cout << arr[i] << " ";
    }
    sort(begin(arr),end(arr)); 
    copy(begin(arr),end(arr),begin(newArray));
    cout << "\n";
    int newArrayLength = sizeof(newArray) / sizeof(newArray[0]);
    for (int j = 0; j < newArrayLength; j++)
    {
        cout << newArray[j] << " ";
    }
    int *found = find(begin(arr),end(arr),2);
    cout << "\n";
    if(found != end(arr)){
        cout << "Found: " << *found << "\n";
    }else{
        cout << "Not found\n";
    }
    return 0;
}