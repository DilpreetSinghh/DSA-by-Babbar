#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    int peakIndex = peakIndexInMountainArray(arr);
    cout << "Peak index in the array: " << peakIndex << endl;
    return 0;
}

// g++ -std=c++20 filename.cpp 
// use above command where vector is in use
// vscode
