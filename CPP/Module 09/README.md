# C++ - Module 09
Standard Template Library (STL): <br>
&nbsp; &nbsp; &nbsp; &nbsp; How to choose the right container to use? <br>
<br><br>
## ex02 - Merge-Insertion Sort
Let us say we are sorting the numbers {8, 3, 10, 1, 5, 4, 7, 6, 2, 9}.
The process follows these steps:
1. Pair elements → {(8,3), (10,1), (5,4), (7,6), (2,9)}
	- Take the larger of each pair as the initial sorted list: {8, 10, 5, 7, 9}
	- The smaller elements ({3, 1, 4, 6, 2}) are "pending" insertions.
2. Insert "pending" elements using the Jacobsthal sequence
	- The insertion order follows J(n): {1, 3, 5, 11, ...}
	- This means we insert in this order:
		- First pending element goes into position 1
		- Second pending element goes into position 3
		- Third pending element goes into position 5
		- And so on...
By spacing out insertions this way, we preserve sorted order efficiently
	rather than doing a lot of unnecessary shifting.

Summary <br>
	1. Jacobsthal sequence spaces out insertions to reduce the number of shifts and comparisons needed. <br>
	2. Binary insertion makes each insertion efficient by using binary search instead of scanning one-by-one. <br>
	3. Combining both techniques leads to an efficient sorting method! <br>
 <br><br>
- [`Reference`](https://github.com/48d31kh413k/1337-CPP-42/tree/main/CPP09)
- [`Introduction on intra`](https://elearning.intra.42.fr/notions/piscine-c-d08-stl/subnotions)
- [`Reference - Tsunghao`](https://github.com/Tsunghao-C/Common-Course/tree/main/CPP_Module/Module09)
- [`ex02: Ford-Johnson merge-insertion sort`](https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort)
