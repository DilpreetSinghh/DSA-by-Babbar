func reverseList(_ Array: inout [Int], start: Int, end: Int) {
    var start = start
    var end = end
    
    // Loop until 'start' index is less than 'end' index
    while start < end {
        // Swap elements at 'start' and 'end' indices
        Array.swapAt(start, end)
        start += 1 // Move 'start' index towards the center
        end -= 1 // Move 'end' index towards the center
    }
}

// Main driver code
var Array = [1, 2, 3, 4, 5, 6]
print(Array) // Print the original array

// Call 'reverseList' to reverse the array from index 0 to 5
reverseList(&Array, start: 0, end: 5)

// Print the result after reversal
print("Reversed list is")
print(Array)
