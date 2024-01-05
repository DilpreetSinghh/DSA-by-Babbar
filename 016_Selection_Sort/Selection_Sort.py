# https://leetcode.com/problems/sort-an-array/description/


class Solution:
    def sortArray(self, nums):
        sorted_nums = nums.copy()

        # Selection sort algorithm
        for i in range(len(sorted_nums) - 1):
            min_index = i
            for j in range(i + 1, len(sorted_nums)):
                if sorted_nums[j] < sorted_nums[min_index]:
                    min_index = j
            sorted_nums[i], sorted_nums[min_index] = sorted_nums[min_index], sorted_nums[i]

        return sorted_nums

# Example usage
solution = Solution()
nums = [64, 25, 12, 22, 11]
sorted_nums = solution.sort_array(nums)
print(sorted_nums)
