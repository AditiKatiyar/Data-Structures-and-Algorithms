/*
Given N and M find all stepping numbers in range N to M.
N = 10, M = 20
all stepping numbers are 10 , 12 
*/
#include <queue>
#include <iostream>

using namespace std;

vector<int> stepnum(int A, int B) {
    queue<int> q;
    vector<int> v;
    if (0 >= A && 0 <= B) {
        v.push_back(0);
    }
    
    for (int i=1 ; i<= 9 ; i++) {
        q.push(i);
    }
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        
        if (num < A) {
            int lastDigit = num % 10;
            int p1 = lastDigit - 1;
            int p2 = lastDigit + 1;
            
            if (p1 >= 0) {
                q.push(num*10 + p1);
            }
            
            if (p2 <= 9) {
                q.push(num*10 + p2);
            }
        } else if (num >= A && num <= B) {
            v.push_back(num);
            
            int lastDigit = num % 10;
            int p1 = lastDigit - 1;
            int p2 = lastDigit + 1;
            
            if (p1 >= 0) {
                q.push(num*10 + p1);
            }
            
            if (p2 <= 9) {
                q.push(num*10 + p2);
            }
        }
    }
    
    return v;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> ans = stepnum(n, m);
    for (int i=0 ; i<ans.size() ; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
