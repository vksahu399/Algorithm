#include <bits/stdc++.h> 

using namespace std;

vector<int> getSpanArray(vector<int> arr) {

	vector<int> ans;	

	/* Creating Stack to put span & price */

	stack<int> prices;

	stack<int> span;

	prices.push(arr[0]);

	span.push(1);

	ans.push_back(1);

	for(int i = 1; i < arr.size(); i++) {

		int count = 1;

		while(!prices.empty() && prices.top() < arr[i]) {

			count += span.top();

			prices.pop();

			span.pop();

		}

		span.push(count);

		prices.push(arr[i]); 

		ans.push_back(count);

	}

	return ans;

}

int main(int argc, char const *argv[]) {

		

	vector<int> arr = {10, 4, 5, 90, 120, 80};

	vector<int> ans = getSpanArray(arr);

	for(int i: ans) {

		cout << i << " ";

	}

	return 0;

}
