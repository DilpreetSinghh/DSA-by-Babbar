def binary_search(arr, size, key):
   start = 0
   end = size - 1

   while start <= end:
       mid = start + (end-start)//2  # Integer division for mid index

       if arr[mid] == key:
           return mid

       elif key > arr[mid]:  # Search in the right half
           start = mid + 1

       else:  # key < arr[mid], search in the left half
           end = mid - 1

   return -1  # Key not found

if __name__ == "__main__":
   even = [2, 4, 6, 8]
   odd = [1, 3, 5, 7, 9]

   even_index = binary_search(even, len(even), 6)
   print("Index of 6 is", even_index)

   odd_index = binary_search(odd, len(odd), 14)
   print("Index of 14 is", odd_index)