#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int lps_length(string str) {
	int len = str.length();
	int** storage = new int*[len];
	for (int i=0 ; i<len ; i++) {
		storage[i] = new int[len]();
	}

	for (int i=0 ; i<len ; i++) {
		storage[i][i] = 1;
	}

	int col;
	for (int l=2 ; l<=len ; l++) {
		for (int row=0 ; row<=len-l ; row++) {
			col = row+l-1;

			if (str[row] == str[col]) {
				storage[row][col] = 2 + storage[row+1][col-1];
			} else {
				storage[row][col] = max(storage[row][col-1], storage[row+1][col]);
			}
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<len ; i++) {
		for (int j=0 ; j<len ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	return storage[0][len-1];
}

int main() {

	string str;
	cin >> str;

	cout << lps_length(str) << endl;
	return 0;
}