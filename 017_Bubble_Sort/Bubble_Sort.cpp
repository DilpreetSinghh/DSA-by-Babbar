#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> exampleArray = {64, 34, 25, 12, 22, 11, 90};
    std::vector<int> sortedArray = solution.bubbleSort(exampleArray);

    // Print original and sorted arrays
    std::cout << "Original array:";
    for (int num : exampleArray) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::cout << "Sorted array:";
    for (int num : sortedArray) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    return 0;
}

// command to run code
// g++ -std=c++17 017_Bubble_Sort/Bubble_Sort.cpp