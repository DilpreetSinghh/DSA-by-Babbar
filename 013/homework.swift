// Find Pivot Index 

func pivotIndex(_ nums: [Int]) {
    var sum = 0 //used for prefix sum array computation
    var pivot = -1 //represents leftmost pivot index
    let lastIndex = nums.count - 1

    /// Calculate the prefix sum array
    var prefixSum = [Int](repeating: 0, count: lastIndex + 1)
    for i in 0...lastIndex {
        sum += nums[i]
        prefixSum[i] = sum
    }

    //current index = pivot + 1, since i initialized pivot = -1

    while pivot < lastIndex {
        let diff = prefixSum[lastIndex] - prefixSum[pivot + 1]
        //if first index is pivot, then left subarray sum is 0
        if pivot < 0 && (0 == diff){
            pivot += 1
            break
        } else if pivot >= 0 && prefixSum[pivot] == diff {
            pivot += 1
            break
        } else if pivot + 1 >= lastIndex {//if no pivot found and we traversed array.
            pivot = -1
            break
        } else {//move to next index to check for pivot.   
            pivot += 1
        }
    }

    print(pivot)
}


let numbs = [1,7,3,6,5,6]
pivotIndex(numbs)