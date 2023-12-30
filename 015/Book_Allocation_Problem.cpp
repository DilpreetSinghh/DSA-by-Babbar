#include <iostream>
#include <vector>
#include <algorithm>
#include <__numeric/accumulate.h>
using namespace std;

class Solution {
public:
    int splitArray(const std::vector<int>& array, int key) {
        auto requiredSplit = [&](int largest) {
            int currSum = 0;
            int splitCount = 0;

            for (int element : array) {
                if (currSum + element <= largest) {
                    currSum += element;
                } else {
                    currSum = element;
                    splitCount += 1;
                }
            }
            return splitCount + 1;
        };

        int left = *std::max_element(array.begin(), array.end());
        int right = std::accumulate(array.begin(), array.end(), 0);
        int answer = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (requiredSplit(mid) <= key) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};

int main() {
    std::vector<int> arr;
    int num;
    while (std::cin >> num) {
        arr.push_back(num);
    }

    int m;
    std::cin >> m;
    Solution ob;
    std::cout << ob.splitArray(arr, m) << std::endl;
    return 0;
}