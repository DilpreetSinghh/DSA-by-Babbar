class Solution {
    func mergeSort(_ nums: [Int]) -> [Int] {
        guard nums.count > 1 else {
            return nums
        }
        
        let middle = nums.count / 2
        let leftArray = Array(nums[..<middle])
        let rightArray = Array(nums[middle...])
        
        let sortedLeft = mergeSort(leftArray)
        let sortedRight = mergeSort(rightArray)
        
        return merge(sortedLeft, sortedRight)
    }
    
    func merge(_ left: [Int], _ right: [Int]) -> [Int] {
        var result = [Int]()
        var leftIndex = 0
        var rightIndex = 0
        
        while leftIndex < left.count && rightIndex < right.count {
            if left[leftIndex] < right[rightIndex] {
                result.append(left[leftIndex])
                leftIndex += 1
            } else {
                result.append(right[rightIndex])
                rightIndex += 1
            }
        }
        
        result += left[ leftIndex... ]
        result += right[ rightIndex... ]
        
        return result
    }
}

// Example usage
let solution = Solution()
let nums = [64, 25, 12, 22, 11]
let sortedNums = solution.mergeSort(nums)
print(sortedNums)
