/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Pair{
    public:
        int x;
        int y;
        Pair(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

void markVisited(vector<vector<char> > A, vector<vector<bool> >& visited, int x, int y) {
    queue<Pair> q;
    Pair t(x, y);
    visited[x][y] = true;
    q.push(t);
    int n = A.size();
    int m = A[0].size();
    
    while(!q.empty()) {
        Pair node = q.front();
        q.pop();
        
        if (node.x-1 >= 0 && A[node.x-1][node.y] == 'O' && !visited[node.x-1][node.y]) {
            Pair p(node.x-1, node.y);
            q.push(p);
            visited[node.x-1][node.y] = true;
        }
        if (node.x+1 < n && A[node.x+1][node.y] == 'O' && !visited[node.x+1][node.y]) {
            Pair p(node.x+1, node.y);
            q.push(p);
            visited[node.x+1][y] = true;
        }
        if (node.y+1 < m && A[node.x][node.y+1] == 'O' && !visited[node.x][node.y+1]) {
            Pair p(node.x, node.y+1);
            q.push(p);
            visited[node.x][node.y+1] = true;
        }
        if (node.y-1 >= 0 && A[node.x][node.y-1] == 'O' && !visited[node.x][node.y-1]) {
            Pair p(node.x, node.y-1);
            q.push(p);
            visited[node.x][node.y-1] = true;
        }
    }
}
void solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool> > visited;
    for (int i=0 ; i<n ; i++) {
        vector<bool> v(m, false);
        visited.push_back(v);
    }
    
    for (int row=0 ; row<n ; row++) {
        if (A[row][0] == 'O' && !visited[row][0]) {
            markVisited(A, visited, row, 0);
        }
        if (A[row][m-1] == 'O' && !visited[row][m-1]) {
            markVisited(A, visited, row, m-1);
        }
    }
    
    for (int col = 1 ; col<m-1 ; col++) {
        if (A[0][col] == 'O' && !visited[0][col]) {
            markVisited(A, visited, 0, col);
        }
        if (A[n-1][col] == 'O' && !visited[n-1][col]) {
            markVisited(A, visited, n-1, col);
        }
    }
    
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (!visited[i][j]) {
                A[i][j] = 'X';
            }
        }
    }
}

void printGraph(vector<vector<char> > graph) {
    for (int i=0 ; i<graph.size() ; i++) {
        for (int j=0 ; j<graph[i].size() ; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
}

int main() {

	int n;
	cin >> n;
	vector<vector<char> > image; // create image of X's & O's.
	for (int i=0 ; i<n ; i++) {
		string line;
		cin >> line;
        vector<char> v(line.begin(), line.end());
		image.push_back(v);
	}

	solve(image);

    printGraph(image);

	return 0;
}