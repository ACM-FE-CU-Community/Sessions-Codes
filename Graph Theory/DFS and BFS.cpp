#include <bits/stdc++.h>
using namespace std;


/**
 * * Practice Problems:   
 * 
 * ^ [1] Dfs: 
 * ^ 1-connected component (dfs)
 * & Problem: https://cses.fi/problemset/task/1192
 * & Solution: https://www.ideone.com/b76j2z
 * 
 * ^ [2] 2-bfs 
 * & Problem: https://codeforces.com/contest/242/problem/C
 * & Solution: https://www.ideone.com/Z3OiwY
 * 
 * ^  [3] 3-check bipartite graph (bfs)
 * & Problem: https://cses.fi/problemset/task/1668
 * & Solution: https://www.ideone.com/vmiIyy
 */


/*
? adjacent list vs adjacent matrix
Adjacency List: An Adjacency list is an array consisting of the address of all the linked lists.
Adjacency Matrix: Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. 

!example:https://www.geeksforgeeks.org/comparison-between-adjacency-list-and-adjacency-matrix-representation-of-graph/

int adjmatrix[][3]={{0,0,0},
                    {0,1,0},
                    {0,1,1}};

vector<int> adjlist[100];

?Depth First Search (DFS)
Depth-first search is an algorithm for traversing or searching tree or graph data structures.

!cool simulation:https://www.cs.usfca.edu/~galles/visualization/DFS.html

?implementation:    Time Complexity: O(V+E)
*/

vector<int>adjlist[100];
bool vis[100];

void dfs(int cur)       
{
    vis[cur]=1;
    for(int i=0;i<adjlist[cur].size();i++)
    {
        if(vis[adjlist[cur][i]]==0)
            dfs(cur);
    }
}

/*
?Breadth First Search (BFS)
Breadth-first search is an algorithm for traversing or searching tree or graph data structures (level by level).

!cool simulation:https://www.cs.usfca.edu/~galles/visualization/BFS.html

?implementation:    Time Complexity: O(V+E)
*/

vector<int>adjlist[100];
bool vis[100];

void bfs(int cur)
{
    queue<int>queue;
    queue.push(cur);
    while(queue.size()!=0)
    {
        int node =queue.front();
        queue.pop();
        for(int i=0;i<adjlist[node].size();i++)
        {
            if(vis[adjlist[node][i]]==0)
            {
                vis[adjlist[node][i]]=1;
                queue.push(adjlist[node][i]);
            }
        }
    }
}

