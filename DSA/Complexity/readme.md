#? What is Time Complexity?
	Time Complexity measures the efficiency of an algorithm in terms of input size (N).
	Defines how runtime grows as input increases.

-----------------------------------------------------------------------------------------
	Notation	Complexity	Example
-----------------------------------------------------------------------------------------	
	O(1)		Constant Time	return arr[0];
	O(log N)	Logarithmic	Binary Search
	O(N)		Linear		Looping through an array
	O(N log N)	Log-Linear	Merge Sort, Quick Sort
	O(N²)		Quadratic	Nested Loops
	O(2^N)		Exponential	Fibonacci (Recursion)
	O(N!)		Factorial	Traveling Salesman Problem

#? What is Space Complexity?

	Space Complexity refers to the amount of extra memory an algorithm needs in addition to the input data.
	Total space complexity = Input space + Auxiliary space
	Auxiliary Space is the extra memory used apart from input storage.


------------------------------------------------------------------------------------------
	Notation	Meaning			Example
------------------------------------------------------------------------------------------
	O(1)		Constant Space		Using only a few variables (int a, b, c;)
	O(N)		Linear Space		Storing an array of N elements
	O(N²)		Quadratic Space		Storing an N × N matrix
	O(log N)	Logarithmic Space	Recursive algorithms with logarithmic depth
