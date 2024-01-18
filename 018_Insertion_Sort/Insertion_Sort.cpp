#include <iostream>
#include <vector>

class Solution {
public:
    void insertionSort(std::vector<int>& arr) {

        for (size_t i = 1; i < arr.size(); ++i) {
            int key = arr[i];

            // Move elements of arr[0..i-1] that are greater than key
            // to one position ahead of their current position

            int j = i - 1;
            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> arr = {12, 11, 13, 5, 6};
    
    // Call the insertionSort method
    solution.insertionSort(arr);
    
    // Print the sorted array
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}