class Solution {
    func minDays(_ bloomDay: [Int], _ m: Int, _ k: Int) -> Int {
        func requiredSplit(_ largest: Int) -> Int {
            var currSum = 0
            var splitCount = 0

            for element in bloomDay {
                if currSum + element <= largest {
                    currSum += element
                } else {
                    currSum = element
                    splitCount += 1
                }
            }
            return splitCount + 1
        }

        var left = bloomDay.max() ?? 0
        var right = bloomDay.reduce(0, +)
        var answer = right

        while left <= right {
            let mid = left + (right - left) / 2
            if requiredSplit(mid) <= k {
                answer = mid
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return answer
    }
}