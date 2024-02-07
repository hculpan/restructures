# Linked List Project: Album Collection Management System

## Overview
Develop an album collection management system using a doubly linked list in C. This system will allow users to add, delete, and navigate through albums in the collection. The choice of a doubly linked list facilitates bidirectional navigation and effective management of the album list.

## Features & Functionalities
1. Add an Album:

* Input: Album details (e.g., title, artist, release year, genre).
* Action: Inserts the album into the collection. The insertion can be at the beginning, end, or a specific position in the list.

2. Delete an Album:

* Input: Album identifier (e.g., title or a unique ID).
* Action: Removes the album from the collection. Ensure proper handling when the album is not found.

3. Display Album Collection:

* Output: List all albums in the collection with details. Provide options to display in both forward and reverse order.

4. Navigate Through Albums:

* Action: Allow users to traverse to the next and previous albums in the collection.

5. Search for an Album:

* Input: A search query (e.g., album title, artist).
* Output: Display albums that match the query.

6. Album Sorting:

* Action: Sort the albums based on different criteria like release year, artist, or title.

## Technical Requirements
* Data Structure: Implement the album collection as a doubly linked list, with each node storing album details and pointers to both the next and previous nodes.
* Memory Management: Efficiently manage memory for adding and removing albums, ensuring no memory leaks.
* Error Handling: Robust error handling for cases such as deleting from an empty list or adding an album with missing details.
* User Interface: Create a simple text-based interface for album collection interactions (CLI - Command Line Interface).

## Expected Input/Output
* Input: User commands to add, delete, search, sort, and navigate albums, including necessary album details for these operations.
* Output: The current state of the album collection after each operation, along with any relevant details or error messages.

This modified project will deepen your understanding of doubly linked lists, particularly in managing collections of complex data structures. It also includes aspects of data sorting and searching, which are fundamental in many real-world applications.