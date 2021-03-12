#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<vector<int>> vec;
	sort(array.begin(), array.end()); // O(nlogn)
	unordered_map<int,int> ThreeSum;
	int n= 0;
	for (auto m: array){ //O(n)
		ThreeSum.insert(pair(m,n)); 
		n++;
	}
	for (int i = 0; i < array.size(); i++) {//O(n^2)
		for (int j = i+1; j < array.size(); j++){
			unordered_map<int,int>::iterator got = ThreeSum.find (targetSum - array[i] - array[j]);
			if (got != ThreeSum.end()) {
				if (ThreeSum[got->first] < i ){
				vector<int> arr = {array[i], array[j], got->first};
				sort (arr.begin(), arr.end());
				vec.push_back(arr);
				}
			}
		}
	}
	
	sort (vec.begin(), vec.end()); //O(nlogn)
  return vec;
}


