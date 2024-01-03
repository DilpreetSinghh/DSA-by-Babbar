#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool possible(const std::vector<int>& arr, int day, int m, int k) {
        int count = 0;
        int bouquetCount = 0;

        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] <= day) {
                count += 1;
            } else {
                bouquetCount += (count / k);
                count = 0;
            }
        }

        bouquetCount += (count / k);
        return bouquetCount >= m;
    }

    int minDays(const std::vector<int>& bloomDay, int m, int k) {
        int value = m * k;
        if (value > bloomDay.size()) {
            return -1;
        }

        auto minIt = std::min_element(bloomDay.begin(), bloomDay.end());
        auto maxIt = std::max_element(bloomDay.begin(), bloomDay.end());

        int low = *minIt;
        int high = *maxIt;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    std::vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3;
    int k = 1;

    // Call the minDays method
    int result = solution.minDays(bloomDay, m, k);

    // Print the result
    if (result == -1) {
        std::cout << "It is not possible to make " << m << " bouquets with " << k << " flowers each." << std::endl;
    } else {
        std::cout << "Minimum number of days to make " << m << " bouquets with " << k << " flowers each: " << result << std::endl;
    }

    return 0;
}

/*
It uses std::min_element and std::max_element from the <algorithm> header 
for finding the minimum and maximum values in the bloomDay vector.

The input is read from the console, and the output is printed using std::cout.
*/