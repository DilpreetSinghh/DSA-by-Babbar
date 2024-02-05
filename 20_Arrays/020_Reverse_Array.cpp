#include <iostream>
#include <vector>
#include <stack>

// Function to print the contents of an array
void printArray(const std::vector<int>& array, const std::string& message) {
    std::cout << message;
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Function to reverse the entire list using simple swapping
void reverseEntireList(std::vector<int>& array) {
    int start = 0; // Initialize 'start' index to the beginning of the array
    int end = array.size() - 1; // Initialize 'end' index to the end of the array

    while (start < end) {
        std::swap(array[start], array[end]);
        start++; // Move 'start' index towards the center
        end--; // Move 'end' index towards the center
    }
}

// Function to reverse an array using a stack
std::vector<int> reverseArrayUsingStack(const std::vector<int>& arr) {
    std::stack<int> stack; // Initialize an empty stack
    std::vector<int> reversedArr; // Initialize an empty vector for the reversed elements

    for (int element : arr) {
        stack.push(element); // Push element onto stack
    }

    while (!stack.empty()) {
        reversedArr.push_back(stack.top()); // Append the top element from the stack
        stack.pop(); // Remove the top element from the stack
    }

    return reversedArr;
}

int main() {
    // Demonstrate Simple Swapping Method
    std::vector<int> array = {1, 2, 3, 4, 5, 6};
    printArray(array, "Original array (Simple Swap): ");
    reverseEntireList(array);
    printArray(array, "Reversed array (Simple Swap): ");

    // Demonstrate Stack Method
    std::vector<int> originalArray = {1, 2, 3, 4, 5};
    printArray(originalArray, "Original array (Stack Method): ");
    std::vector<int> reversedArray = reverseArrayUsingStack(originalArray);
    printArray(reversedArray, "Reversed array (Stack Method): ");

    return 0;
}
