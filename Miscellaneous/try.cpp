#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int A) {
	vector<vector<int> > v( A , vector<int> (A, 0));
	int top = 0;
	int bottom = A-1;
	int left = 0;
	int right = A-1;
	int count = 1;

	while (top <= bottom || left <= right) {
		for (int col = left ; col <= right ; col++) {
			v[top][col] = count;
			count++;
		}
		top++;

		for (int row=top ; row<=bottom ; row++) {
			v[row][right] = count;
			count++;
		}
		right--;

		for (int col=right ; col>=left ; col--) {
			v[bottom][col] = count;
			count++;
		}
		bottom--;

		for (int row=bottom ; row>=top ; row--) {
			v[row][left] = count;
			count++;
		}
		left++;
	}

	return v;
}

int main() {
	
	int arr[] = {1, 2, 3, 4};

	for (int i=0 ; i<5 ; i++) {
		cout << arr[i] << " ";
		arr++;
	}


	return 0;
}