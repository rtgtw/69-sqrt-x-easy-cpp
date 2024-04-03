/*

69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.


Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.




Solution:
Our result should return the floor value of the square root of interger x

In order to achieve this we need to perform a binary search

For our base case, we know the sqrt of 0 is 0 and the sqrt of 1 is 1,

meaning for all other non-negative integers, we start our left binary search node at 2

our right binary searach node will be at x/2 
this is because the largest number a sqrt can be is x/2

next we will perform a binary search with our 'pivot' variable representing 
the middle number

in order to determine the floor of the sqrt of x we need to do the following:

square our pivot and compare to x, if the value is higher than x, then we need to decrease
our right node

if the value is lower than x, than we need to increase our left node

when they are equal to each other, return pivot

if we do not find a value within the binary search, return right

this is because we are going to be using a while loop to iterate through 
while left < right and once right < left, right would represent the lower value so we can
return right

*/

#include <iostream>


class Solution {
public:
	int mySqrt(int x);
};

int Solution::mySqrt(int x) {

	//First lets account for our base case, if x is 0 or 1, we can just return 0 or 1 respectively
	if (x < 2) {
		return x;
	}

	//Now we need to create our variables 
	//Let our left pointer = 2 as the smallest value 
	int left = 2;

	//Let our right pointer be equal to x/2 since this represents the largest value that the square root of x can be
	int right = x / 2;

	// int pivot;
	// long num;

	//Now we need to create a while loop that will continue until left is greater than the right
	//This is b/c if the left ever becomes greater than the right then we know we couldnt not find a value, which means we need to exit
	//include equals to confirms that right is less than left, if there were no equal to
	//then when left == right, the while loop would end, but to get the floor value, right needs
	//to be less than left so the equal to is included to allow that to happen
	while (left <= right) {

		//Our pivot will represent the middle value which we will compare to x to see if we have found the correct value
		//I brought the pivot inside of the loop to reset after each iteration
		int pivot = left + (right - left) / 2;

		//Once inside our while loop, now we need to compare our pivot with x
		//First we multiply our pivot by itself and compare this value to x, if the pivot is larger than x
		//Then we need to decrease the right side
		//if the pivot is smaller than x, then we need to increase the left side
		long num = static_cast<long>(pivot) * static_cast<long>(pivot);


		if (num > x) {
			right = pivot - 1;
		}
		else if (num < x) {
			left = pivot + 1;
		}
		else {
			return pivot;
		}

	}

	//if we exit the while loop without returning the pivot, then we could 
	//not find our answer which means left and right crossed
	//so the right value will represent our floor value which is our result
	//so we can just return the right pointer

	return right;

}



int main() {

	Solution solution;


	int sqrt = 167;

	std::cout << solution.mySqrt(sqrt);

	/*
	Time = O(logn) since we are performing a binary search
	Space = O(1) constant time, just included some variables


	Time taken: 1:30h
	*/



	return 0;
}