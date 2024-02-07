# Hash Table Project in C: In-Memory Key-Value Store

## Objective:
Develop an in-memory key-value store using a hash table in C. This project will help you understand the implementation of hash tables and their application in efficiently storing and retrieving data based on keys.

## Project Description:

I've included the ChatGPT description of the project below, but I've decided to change the specifics. I'm going to write a program to count the number of instances of strings in a text file. I've generated a random file of 3-letter strings (```data.txt```), and my program for this project will count the number of instances of each 3-letter combination. 

I will do a simple implementation first, using a linked list to store each string and it's instance count. As I read through the file, I will have to walk the linked list to find the node for the string, or, if not found, insert at the end (or maybe make it a sorted linked list). This is, of course, a slow approach, but has the advantage of being easy to code and also unlikely to have bugs. This will give me my baseline of instance counts, so that I will have a "correct" solution to validate my hash table approach to.

Then I will create my hash table and perform the process doing that. By timing both, I should see how much improvement the hash table has over the linked list (which should be a lot, unless my hash function sucks).

### Understanding Hash Tables:

Hash tables store data in an array format, where each data value has a unique key.
A hash function is used to compute an index into an array of buckets, from which the desired value can be found.

### Key-Value Store:

The goal is to create a simple yet efficient key-value store, where you can insert, delete, and retrieve values based on keys.

### Core Components to Implement:

* Hash Function: Implement a suitable hash function for keys.
* Collision Resolution Mechanism: Handle collisions using methods like chaining (linked lists) or open addressing (linear probing, quadratic probing, etc.).
* Key-Value Pair Structure: Define a structure for storing key-value pairs.

### Functionality:

* void insert(char* key, char* value): Add a new key-value pair to the hash table.
* char* get(char* key): Retrieve the value associated with the given key.
* void delete(char* key): Remove the key-value pair associated with the given key.
* void displayHashTable(): Display the current contents of the hash table.

### Advanced Features (Optional):

* Implement Dynamic Resizing: Allow the hash table to expand when it reaches a certain load factor.
* Add functionality to handle different data types as keys or values.

### Input/Output for Testing:

* Input: A series of operations like insertions, deletions, and retrievals with various keys and values.
* Output: The status of the hash table after each operation and the results of retrieval operations.

### Testing and Validation:

* Test each function, particularly focusing on edge cases like handling collisions and dealing with non-existent keys.
* Validate that the hash function distributes keys evenly across the buckets to avoid clustering.

### Considerations:

* Hash Function Efficiency: The hash function should minimize collisions and distribute keys uniformly.
* Memory Management: Efficiently manage memory, especially if you're using dynamic arrays or linked lists for collision resolution.
* Error Handling: Implement robust error handling, particularly for memory allocation failures and invalid operations.

### Expected Learning Outcome:

* Comprehensive understanding of hash tables, including hash functions, collision resolution, and key-value pair management.
* Enhanced skills in memory management and complex data structure implementation in C.
Practical experience in developing a system for efficient data retrieval.