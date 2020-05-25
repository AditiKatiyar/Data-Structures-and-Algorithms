#include <iostream>
#include <cmath>

using namespace std;

int lis(int* arr, int n) {
	int* storage = new int[n]();
	for (int i=0 ; i<n ; i++) {
		storage[i] = 1;
	}

	for (int i=1 ; i<n ; i++) {
		for (int j=0 ; j<i ; j++) {
			if (arr[j] < arr[i]) {
				int t = storage[j] + 1;
				storage[i] = max(storage[i], t);
			}
		}
	}
	int MAX = INT_MIN;

	for (int i=0 ; i<n ; i++) {
		MAX = max(MAX, storage[i]);
	}

	return MAX;
}

int main() {

	int n;
	cin >> n;
	int* arr = new int[n]();
	for (int i=0 ; i<n ; i++) {
		cin >> arr[i];
	}

	cout << lis(arr, n) << endl;

	return 0;
}