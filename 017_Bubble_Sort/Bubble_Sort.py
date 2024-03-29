class Solution:
    def bubble_sort(self, arr):
        n = len(arr)
        for i in range(n - 1):
            swapped = False
            for j in range(n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
                    swapped = True
            if not swapped:
                break
        return arr

# Example usage
solution = Solution()
example_array = [64, 34, 25, 12, 22, 11, 90]
sorted_array = solution.bubble_sort(example_array)

# Print original and sorted arrays
print("Original array:", *example_array)
print("Sorted array:", *sorted_array)
