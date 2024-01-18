class Solution:
    def insertion_sort(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]
            # Move elements of arr[0..i-1] that are greater than key
            # to one position ahead of their current position
            
            j = i - 1
            while j >= 0 and key < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key

solution = Solution()
arr = [12, 11, 13, 5, 6]

# Call the insertion_sort method
solution.insertion_sort(arr)

# Print the sorted array
print("Sorted array:", *arr)