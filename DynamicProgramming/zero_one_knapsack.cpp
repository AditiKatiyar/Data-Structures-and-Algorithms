#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Item {
public:

	int weight;
	int val;

	Item() {}

	Item(int w, int v) {
		weight = w;
		val = v;
	}
};

bool comparator(const Item& i1, const Item& i2) {
	if (i1.weight <= i2.weight) {
		return true;
	}
	return false;
}

int knapsack(Item* arr, int len, int w) {
	int** storage = new int*[len];
	for (int i=0 ; i<len ; i++) {
		storage[i] = new int[w+1]();
	}

	for (int i=0 ; i<1 ; i++) {
		int j=1;
		while (j<=w && arr[i].weight > j) {
			j++;
		}
		while (j<=w) {
			storage[0][j] = arr[i].val;
			j++;
		}
	}

	for (int i=1 ; i<len ; i++) {
		int j=1;
		while (j<=w && arr[i].weight > j) {
			storage[i][j] = storage[i-1][j];
			j++;
		}
		while (j<=w) {
			storage[i][j] = max(storage[i-1][j], arr[i].val+storage[i-1][j-arr[i].weight]);
			j++;
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<len ; i++) {
		for (int j=0 ; j<w+1 ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[len-1][w];
}

int main() {
	
	int n;
	cin >> n;

	Item* arr = new Item[n]();
	for (int i=0 ; i<n ; i++) {
		cin >> arr[i].weight >> arr[i].val;
	}

	sort(arr, arr+n, comparator);

	for (int i=0 ; i<n ; i++) {
		cout << arr[i].weight << " " << arr[i].val << endl;
	}

	cout << "enter weight ";
	int w;
	cin >> w;

	cout << knapsack(arr, n, w) << endl;

	return 0;
}