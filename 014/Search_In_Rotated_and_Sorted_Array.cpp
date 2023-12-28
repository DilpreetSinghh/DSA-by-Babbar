#include <iostream>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int pivot = findPivotIndex(nums, 0, nums.size() - 1);
        int ans = binarySearch(nums, 0, pivot, target);
        if (ans == -1) {
            ans = binarySearch(nums, pivot + 1, nums.size() - 1, target);
        }
        return ans;
    }

    int findPivotIndex(const std::vector<int>& nums, int low, int high) {
        int mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[low] <= nums[high]) {
                return high;
            } else if (nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] < nums[mid - 1]) {
                return mid - 1;
            } else if (nums[mid] > nums[0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return mid;
    }

    int binarySearch(const std::vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = solution.search(nums, target);
    std::cout << "Index of " << target << " in ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << ": " << result << std::endl;

    return 0;
}

// g++ -std=c++20 014/Search_In_Rotated_and_Sorted_Array.cpp