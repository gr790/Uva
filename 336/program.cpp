#include <iostream>
#include <queue>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

map<int, int> visited;

int solve(int start, map<int, vector<int> > &graph)
{
  queue<int> q;
  q.push(start);
  visited[start] = 0;
  while(q.empty() == false)
  {
    int front = q.front();
    q.pop();
    /* get the size of [start] entry in graph, which is vector ofcourse */
    /* e.g [10] = std::vector of length 2, capacity 2 = {15, 30}, */
    int size = graph[front].size();
    for(int i = 0; i < size; ++i)
    {
      /* get the next element from {15, 30} */
      int next = graph[front][i];
      /* if not visited yet */
      if(!visited.count(next))
      {
        /* calculate distance from front, which is at zero */
        visited[next] = visited[front] + 1;
        q.push(next);
      }
    }
  } 
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
    int t = num;
    int node_a, node_b;
    /* un-directed graph, both nodes will have refrences to each other */
    map<int, vector<int> > graph;
    while(t--)
    {
      infile >> node_a >> node_b;
      graph[node_a].push_back(node_b);
      graph[node_b].push_back(node_a);
    }
    infile.ignore();
    int s_node, ttl;
    while(infile >> s_node >> ttl)
    {
      if ( !s_node  && !ttl)
        break;

      visited.clear();
      cases++;

      solve(s_node, graph);
      map<int, int>::iterator iter;
      int result = 0;
      for(iter = visited.begin(); iter != visited.end(); ++iter)
      {
        if(iter->second > ttl)
          ++result;
      }
      result += graph.size() - visited.size();
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases, result, s_node, ttl);
    }
    graph.clear();
  }
  return 0;
}
