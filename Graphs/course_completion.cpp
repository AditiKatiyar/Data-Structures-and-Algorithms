#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int canCompleteAllCourses(vector<vector<int> > graph, int A) {
	vector<int> status(A, 0);
    int UNVISITED = 0;
    int VISITED = 1;
    int IN_STACK = 2;
    
    for (int n = 0 ; n<A ; n++) { // check if any unvisited node exists in order to cover all connected components
        if (status[n] == 0) {
            stack<int> s;
            s.push(n);
            status[n] = IN_STACK;
            while(!s.empty()) {
                int node = s.top();
                bool flag = true;
                
                for (int j=0 ; j<graph[node].size() ; j++) {
                    if (status[graph[node][j]] == UNVISITED) { // if the neighbour is unvisited, put in stack, and continue for DFS
                        s.push(graph[node][j]);
                        status[graph[node][j]] = IN_STACK;
                        flag = false;
                        break;
                    } else if (status[graph[node][j]] == IN_STACK) { // if neighbour is already in stack, visited twice hence a loop exists.
                        return 0;
                    } 
                }
                
                if (flag) { // if no option to move forward, pop the current node from stack.
                    s.pop();
                    status[node] = VISITED;
                }
            }
        }
    }
    
    return 1;
}

void printGraph(vector<vector<int> > graph) {
	for (int i=0 ; i<graph.size() ; i++) {
		cout << i << " : ";
		for (int j=0 ; j<graph[i].size() ; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	int n; // number of vertices
	cin >> n;
	vector<vector<int> > graph;
	for (int i=0 ; i<n ; i++) {
		vector<int> v;
		graph.push_back(v);
	}

	int e; // number of edges
	cin >> e;
	while (e--) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1].push_back(n2); // directed graph
	}

	printGraph(graph);

	cout << "canCompleteAllCourses " << canCompleteAllCourses(graph, n) << endl;

	return 0;
}