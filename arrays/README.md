# Arrays and Dynamic Arrays Project in C

## Objective:
Implement a dynamic array in C, a language that doesn't have built-in dynamic array functionality like higher-level languages. This will deepen your understanding of memory management, pointers, and array resizing logic.

## Project Description:

### Understanding Static Arrays in C:

Arrays in C are static, meaning they have a fixed size determined at compile-time.
Familiarize yourself with basic array operations in C.
Dynamic Array Implementation:

You will manually manage memory using functions like malloc, realloc, and free.
Implement functions to add, remove, and access elements in a dynamically resizable array.
Core Functions to Implement:

* void addElement(int element): Adds a new element at the end. If the array is full, increase its size.
* void removeElement(int index): Removes the element at the specified index, optionally resizing the array down.
* int getElement(int index): Returns the element at the specified index.
* void setElement(int index, int element): Sets the element at the specified index.
* int size(): Returns the number of elements in the array.
* int capacity(): Returns the current capacity of the array.

### Key Considerations:

* Memory Allocation and Resizing Strategy: Determine how the array grows (e.g., doubling its size) and shrinks.
* Error Handling: Safely handle memory allocation errors and invalid operations (e.g., accessing out-of-bounds indices).
* Performance: Understand the cost of resizing, especially when using realloc.

### Input/Output for Testing:

* Input: A series of operations like add, remove, get, and set.
* Output: The dynamic array's response to each operation, including any size and capacity changes.

### Testing:

* Test each function extensively, especially edge cases.
* Validate memory management (no leaks or invalid accesses).

### Optional Extensions:

* Implement a generic dynamic array that can hold any data type using void pointers.
* Enhance the dynamic array to be thread-safe.

### Expected Learning Outcome:

* Proficiency in manual memory management in C.
* Understanding the internal workings of dynamic arrays, including resizing algorithms and efficiency considerations.
* Enhanced problem-solving skills in a low-level programming context.