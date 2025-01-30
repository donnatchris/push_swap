# PROJECT PUSH_SWAP FOR 42
By chdonnat (Christophe Donnat from 42 Perpignan, France)

## AIM OF THE PROJECT:

The Push swap project is a simple and efficient algorithmic exercise:
you need to sort data.
You have at your disposal a set of integers, two stacks,
and a set of instructions to manipulate them.
Your goal? Write a C program named push_swap that calculates
and displays on the standard output the smallest program,
made of Push swap language instructions, that sorts the integers passed as parameters.

## SOME COMMANDS YOU CAN USE:

compile the push_swap program

	make

compile the checker program

	make bonus

remove all .o files generated by the make command

	make clean

generate a list of 500 integers (without doubles) separated by spaces
and assign the list to the variable ARG
(you can choose anothe number like 100 or 5 for exemple)
 
	ARG=$(<put here your list of numbers to sort>)

count the number of steps used by push_swap to sort the numbers in ARG

	./push_swap "$ARG" | wc -l
 
for Mac:
verifiy the output of push_swap by using the 42 tester:
returns OK if the output of push_swap sorts the numbers in ARG
or returns KO if not
returns error if there was an error

	./push_swap "$ARG" | ./tests/checker_Mac "$ARG"

same as above but for linux

	./push_swap "$ARG" | ./tests/checker_linux "$ARG"

same as above but using my own tester (made for the bonus of the project)

	./push_swap "$ARG" | ./checker "$ARG"

 ---

## About My Algorithm
I used a fairly standard sorting algorithm for a push_swap (compared to what you'll find online). Essentially, the program pushes all the values to sort onto stack B, leaving only 3 values on stack A, which it sorts directly.
From there, the program identifies the value to bring back to the correct position in stack A (similar to insertion sort) by choosing the one that requires the fewest moves. It then moves that value to the correct position in stack A and repeats the process until stack B is empty.
Finally, it performs a rotation on stack A to place the smallest value at the top.

If you'd like to see a much more original sorting approach (which requires fewer calculations, even if it needs more moves), I coded a push_swap that uses three recursive functions. It was a real puzzle to implement, but the result is very satisfying. Unfortunately, I didn’t use this version for the 42 project because it couldn’t achieve the best score for sorting 100 values. It takes over 700 moves for 100 values but stays under 5500 moves for 500 values.
You can find this algorithm in my other repository:

[recursive_push_swap.
](https://github.com/donnatchris/recursive_push_swap)

---

## DOCUMENTATION

### Complexity

The concept of time complexity refers to the amount of time an algorithm takes to complete as a function of the input size.
It is typically expressed using Big O notation, which provides an upper bound on the number of operations the algorithm will perform in relation to the size of the input.
This allows us to estimate how the algorithm will scale as the input size grows.

For example, an algorithm with a time complexity of O(n) means that the number of operations will increase linearly with the size of the input.
An algorithm with O(n^2) time complexity, like bubble sort, will see its running time increase quadratically as the input size grows.
The goal of understanding time complexity is to evaluate how efficiently an algorithm performs as the input size increases, especially when dealing with large datasets.

Similarly, space complexity refers to the amount of memory an algorithm requires relative to the input size. Both time and space complexity help us understand the efficiency of algorithms in terms of both computation and memory usage.

### Common sorting algorithms:

#### Bubble Sort:
Bubble sort is a simple comparison-based sorting algorithm.
It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
This process continues until no swaps are needed, which means the list is sorted.
Despite its simplicity, bubble sort is inefficient for large datasets due to its time complexity of O(n^2).

#### Selection Sort:
Selection sort divides the list into a sorted and an unsorted part.
It repeatedly selects the smallest (or largest) element from the unsorted part and swaps it with the first element of the unsorted portion,
moving the boundary between the two parts until the entire list is sorted.
Its time complexity is O(n^2).

#### Insertion Sort:
Insertion sort builds the sorted list one element at a time.
It takes each element from the unsorted part and inserts it at the correct position in the sorted portion by shifting elements as needed.
It works efficiently for small or nearly sorted datasets with a time complexity of O(n^2).

#### Merge Sort:
Merge sort is a divide-and-conquer algorithm that splits the list into smaller sublists until each sublist contains only one element.
Then it merges these sublists in sorted order to form the final sorted list.
Its time complexity is O(n log n), making it efficient for large datasets.

#### Quick Sort:
Quick sort is also a divide-and-conquer algorithm.
It selects a pivot element, partitions the list into two parts (elements smaller than the pivot and elements larger than the pivot), and recursively sorts the sublists.
Its average time complexity is O(n log n), but it can degrade to O(n^2) in the worst case.

#### Heap Sort:
Heap sort uses a binary heap data structure to sort the list.
It builds a max heap from the input and repeatedly extracts the largest element, placing it at the end of the list, then reconstructs the heap.
It has a time complexity of O(n log n) and is efficient for large datasets.

#### Counting Sort:
Counting sort is a non-comparison-based sorting algorithm that works well for integer datasets within a limited range.
It counts the occurrences of each element, then calculates their positions in the sorted list.
Its time complexity is O(n + k), where k is the range of input values.

#### Radix Sort:
Radix sort sorts integers by processing individual digits from the least significant to the most significant.
It uses a stable sorting algorithm like counting sort for each digit position.
Its time complexity is O(nk), where k is the number of digits in the largest number.
