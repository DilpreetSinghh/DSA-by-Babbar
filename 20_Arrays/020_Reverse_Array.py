# Simple Swapping Method
def reverse_entire_list(array):
    start, end = 0, len(array) - 1  # Initialize 'start' and 'end' indices

    # Loop until 'start' index is less than 'end' index
    while start < end:
        array[start], array[end] = array[end], array[start]  # Swap elements
        start += 1  # Move 'start' index towards the center
        end -= 1  # Move 'end' index towards the center

# Main driver code
array = [1, 2, 3, 4, 5, 6]  # Original array
print("Simple original example array is:", array)

# Call 'reverse_entire_list' to reverse the entire array
reverse_entire_list(array)

# Print the result after reversal
print("Reversed of simple array is:", array)


# Stack Method
def reverse_array_using_stack(arr):
    stack = []  # Initialize an empty stack
    reversed_arr = []  # Initialize an empty array for the reversed elements

    # Push all elements of the input array onto the stack
    for element in arr:
        stack.append(element)  # Push element onto stack

    # Pop all elements from the stack to form the reversed array
    while stack:
        top_element = stack.pop()  # Pop the top element from the stack
        reversed_arr.append(top_element)  # Append the popped element to the reversed array

    return reversed_arr

# Main driver code
original_array = [1, 2, 3, 4, 5]
print("Stack Original array:", original_array)

# Call 'reverse_array_using_stack' to reverse the array and get a new reversed array
reversed_array = reverse_array_using_stack(original_array)

# Print the reversed array
print("Stack Reversed array using stack:", reversed_array)

