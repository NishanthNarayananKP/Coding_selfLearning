# Array Insertion and Deletion - Static Array (C Language)

* Author: Nishanth Narayanan Kp  
* Date: 2025-04-06  
* Language: C  
* Structure: Static Array (No Pointers, No Dynamic Memory)

# Time Complexity Analysis

## Insertion - Sorted Array

* Insert at Beginning: O(n)
* Insert at End: O(1)
* Insert at Position k: O(n - k + 1), which is approximately O(n)

## Deletion - Sorted Array

* Delete at Beginning: O(n)
* Delete at End: O(1)
* Delete at Position k: O(n - k), which is approximately O(n)

# Optimized Insert and Delete for Unsorted Arrays

If the order of elements does not matter, we can perform insertion and deletion in constant time.

## Insert at Position (Unsorted Array)

Instead of shifting all elements to the right, perform:

* Copy the element at position (pos - 1) to the end of the array.
* Insert the new element at (pos - 1).
* Increment the array size.

Example:

    array[size] = array[pos - 1];
    array[pos - 1] = new_element;
    size++;

* Time Complexity: O(1)

## Delete at Position (Unsorted Array)

Instead of shifting all elements to the left, perform:

* Overwrite the element at (pos - 1) with the last element.
* Decrement the array size.

Example:

    array[pos - 1] = array[size - 1];
    size--;

* Time Complexity: O(1)

# Space Complexity

* Static array uses fixed memory: int arr[MAX_SIZE]
* Each int typically takes 4 bytes
* Regardless of how many elements are in use, memory is preallocated

Additional variables like counters (size, pos, value) use constant space: O(1)

* Total Space Complexity: O(n), where n is the number of elements in use

