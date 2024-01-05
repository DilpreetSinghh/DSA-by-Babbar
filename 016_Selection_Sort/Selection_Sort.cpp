// https://leetcode.com/problems/sort-an-array/description/


#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortArray(const std::vector<int>& nums) {
        std::vector<int> sortedNums = nums;

        // Selection sort algorithm
        for (size_t i = 0; i < sortedNums.size() - 1; ++i) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < sortedNums.size(); ++j) {
                if (sortedNums[j] < sortedNums[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(sortedNums[minIndex], sortedNums[i]);
        }

        return sortedNums;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {64, 25, 12, 22, 11};
    std::vector<int> sortedNums = solution.sortArray(nums);

    // Print sorted array
    for (int num : sortedNums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}