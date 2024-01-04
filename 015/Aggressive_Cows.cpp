#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isPossible(const std::vector<int>& stalls, int minDist, int k) {
        int cows = 1;
        int lastCowPosition = stalls[0];

        for (int i = 1; i < stalls.size(); ++i) {
            if (stalls[i] - lastCowPosition >= minDist) {
                cows += 1;
                lastCowPosition = stalls[i];
                if (cows >= k) {
                    return true;
                }
            }
        }
        return false;
    }

    int solve(int n, int k, const std::vector<int>& stalls) {
        std::vector<int> sortedStalls = stalls;
        std::sort(sortedStalls.begin(), sortedStalls.end());
        int low = 1;
        int high = sortedStalls.back() - sortedStalls.front();
        int res = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(sortedStalls, mid, k)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};

int main() {
    // Input
    int t = 1;
    int n = 5;
    int k = 3;
    std::vector<int> stalls = {1, 2, 8, 4, 9};

    Solution solution;
    int result = solution.solve(n, k, stalls);
    std::cout << result << std::endl;

    return 0;
}
