#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <queue>
using namespace std;
map<int, int> colored;
bool solve(map<int, vector<int> > &graph)
{
  queue<int> q;
  map<int, vector<int> >::iterator iter;
  iter = graph.begin();
  /* find out first node in graph */
  int start = iter->first;
  colored[start] = 1;
  /* push into queue for bfs */
  q.push(start);
  while(!q.empty())
  {
    int top = q.front();
    q.pop();
    int size = graph[top].size();
    for (int i = 0; i < size; ++i)
    {
      int next = graph[top][i];
      if(!colored.count(next))
      {
        colored[next] = 1 - colored[top];
        q.push(next);
      }
      else
      {
        if( colored[next] == colored[top])
          return false;
      }
    }
  }
  return true;
}

int main()
{
  ifstream infile;
  infile.open("./sample.txt");
  int num, cases = 0;
  while(infile >> num)
  {
    if (!num) break;
    infile.ignore();

    int edges;
    infile >> edges;
    int node_a, node_b;
    /* un-directed graph, both nodes will have refrences to each other */
    map<int, vector<int> > graph;
    while(edges--)
    {
      infile >> node_a >> node_b;
      graph[node_a].push_back(node_b);
      graph[node_b].push_back(node_a);
    }
    if(solve(graph)) 
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
    graph.clear();
    colored.clear();
  }
  return 0;
}
