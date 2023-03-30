// Question: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// M-Coloring Problem

// Approach: Backtracking on all vertices

// Complexity : colors ^ vertices

bool canColor(bool graph[101][101], vector<int> &color, int v, int i, int j) {
    for (int k = 0; k < v; k ++) {
        if (graph[i][k] == 1 && color[k] == j)  return false;
    }
    return true;
}
bool check(bool graph[101][101], int m, int v, int i, vector<int> &color) {
    if (i == v) return true;
    for (int j = 0; j < m; j ++) {
        if (canColor(graph, color, v, i, j)) {
            color[i] = j;
            if (check(graph, m, v, i + 1, color)) return true;
            color[i] = -1;
        }
    }
    return false;

}
bool graphColoring(bool graph[101][101], int m, int v) {
    // your code here
    vector<int> color (v, -1); // color of n nodes : Range[0, m)
    return check(graph, m, v, 0, color);
}
