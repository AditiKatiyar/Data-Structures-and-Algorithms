#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string longestCommonSubstring(string a, string b) {
	int len1 = a.length();
	int len2 = b.length();

	string** storage = new string*[len2+1]();
	for (int i=0 ; i<=len2 ; i++) {
		storage[i] = new string[len1+1]();
	}

	string ans = "";

	for (int i=0 ; i<len2 ; i++) {
		for (int j=0 ; j<len1 ; j++) {
			if (b[i] == a[j]) {
				storage[i+1][j+1] = storage[i][j] + b[i];
				if (ans.length() < storage[i+1][j+1].length()) {
					ans = storage[i+1][j+1];
				}
				// ans = max(maximum, storage[i+1][j+1]);
			} else {
				storage[i+1][j+1] = "";
			}
		}
	}

	cout << "--- DP storage ------------" << endl;
	for (int i=0 ; i<=len2 ; i++) {
		for (int j=0 ; j<=len1 ; j++) {
			cout << storage[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;

	// if (maximum == INT_MIN) {
	// 	return 0;
	// }
	return ans;
}

int main() {

	string a, b;
	cin >> a >> b;
	cout << longestCommonSubstring(a, b) << endl;

	return 0;
}