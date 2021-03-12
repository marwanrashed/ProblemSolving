#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
Author: Marwan Abdellattif
Solution Complexity:
Time Complexity: O(n)
Space Complexity: O(n)
This is the mid performance scenario. It utilizes Hash Tables with a single for loop.
*/

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	// Define a hashtable where you will put the array values inside it as keys, and the indices as values.
	unordered_map<int,int> TwoSum; 
	vector<int> ReturnNums; // Intialize a vector of integers to save the output two numbers sum
	for (int i =0; i < array.size(); i++){ // loop over the whole array O(n)
		std::unordered_map<int,int>::const_iterator got = TwoSum.find (targetSum - array[i]); // O(1) Search for a key which have a valye equal to the difference between target and the current elemnt in the array
		if (got == TwoSum.end()) { // If you didn't find any, add the current element to the hash map
		std::pair<int,int> entry (array[i],i); // Insert key, value pairs
		TwoSum.insert(entry);
		}
		else { // If you found the corresponding element push it in the REturnNums vector along with the current elment in the array
			ReturnNums.push_back(got->first);
			ReturnNums.push_back(array[i]);
			return ReturnNums;
		}
		
	}
	
  return ReturnNums;
}
