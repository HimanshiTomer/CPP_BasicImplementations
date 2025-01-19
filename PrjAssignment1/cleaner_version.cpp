/*
BCA, Second Year, Shift-1
Programmer Names:
   Pragya (02014002023)
   Himanshi Tomer (05214002023)
Problem Statement:
   Define Point class and an Arc class.
   Define a graph class which represents graph as collection of Point Objects and collection of Arc objects.
   Find the shortest distance between any two points (use Dijiksta’s algorithm).
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Point
{
public:
   char id;
   Point()
   {
      id = '-';
   }
   Point(int identifier)
   {
      id = identifier;
   }
   ~Point() {}
};

class Arc
{
public:
   int weight;
   Point *start, *end;
   Arc()
   {
      weight = 0;
      start = end = 0;
   }
   Arc(Point *beg, Point *last, int weigh)
   {
      weight = weigh;
      start = beg;
      end = last;
   }
   ~Arc() {}
};

class Graph
{
public:
   Point *points;
   Arc *arc;
   int p_count, a_count;
   Graph(int point_count, int arc_count)
   {
      p_count = point_count;
      a_count = arc_count;
      points = new Point[p_count];
      arc = new Arc[a_count];
   }

   void insert_point(int index, char id)
   {
      if (index < p_count)
         points[index] = Point(id);
   }

   void insert_arc(int index, char startId, char endId, int weight)
   {
      Point *start = nullptr;
      Point *end = nullptr;
      for (int i = 0; i < p_count; i++)
      {
         if (points[i].id == startId)
            start = &points[i];
         if (points[i].id == endId)
            end = &points[i];
      }
      if (start && end)
         if (index < a_count)
            arc[index] = Arc(start, end, weight);
   }

   void adjacency_matrix();
   void dijkstra_algorithm(char param);

   ~Graph()
   {
      delete[] points;
      delete[] arc;
   }
};

void Graph::adjacency_matrix()
{
   int adj[p_count][p_count];
   for (int i = 0; i < p_count; i++)
      for (int j = 0; j < p_count; j++)
         adj[i][j] = 0;

   for (int i = 0; i < a_count; i++)
   {
      adj[arc[i].start->id - 'A'][arc[i].end->id - 'A'] = arc[i].weight;
      adj[arc[i].end->id - 'A'][arc[i].start->id - 'A'] = arc[i].weight;
   }
   cout << "Adjacency Matrix:" << endl;
   for (int i = 0; i < p_count; i++)
   {
      for (int j = 0; j < p_count; j++)
         cout << adj[i][j] << "\t";
      cout << endl;
   }
}

void Graph::dijkstra_algorithm(char param)
{
   int index = param - 'A';
   int *cost = new int[p_count];
   char *visit_status = new char[p_count];

   for (int i = 0; i < p_count; i++)
   {
      cost[i] = 999999;
      visit_status[i] = 'N';
   }
   cost[index] = 0;
   for (int i = 0; i < p_count; i++)
   {
      int min_cost = 999999, min_node;
      for (int j = 0; j < p_count; j++)
      {
         if (visit_status[j] == 'N' && cost[j] < min_cost)
         {
            min_cost = cost[j];
            min_node = j;
         }
      }
      visit_status[min_node] = 'Y';

      for (int i = 0; i < a_count; i++)
      {
         int beg = arc[i].start->id - 'A';
         int last = arc[i].end->id - 'A';
         int weight = arc[i].weight;

         if ((beg == min_node) && (visit_status[last] == 'N') && (cost[beg] + weight < cost[last]))
         {
            cost[last] = cost[beg] + weight;
         }

         if ((last == min_node) && (visit_status[beg] == 'N') && ((cost[last] + weight) < cost[beg]))
         {
            cost[beg] = cost[last] + weight;
         }
      }
   }

   cout << "\nShortest distances from " << index << ":" << endl;
   for (int i = 0; i < p_count; i++)
   {
      cout << "\tTo Point " << (char)('A' + i) << ": " << cost[i] << endl;
   }

   delete[] cost;
   delete[] visit_status;
}

int main()
{
   ifstream infile("graph_data.txt");
   if (!infile)
      return 1;

   int total_graphs;
   infile >> total_graphs;
   for (int g = 0; g < total_graphs; g++)
   {
      int point, arc;
      infile >> point >> arc;

      Graph g1(point, arc);
      for (int i = 0; i < point; i++)
      {
         char pointId;
         infile >> pointId;
         g1.insert_point(i, pointId);
      }

      for (int i = 0; i < arc; i++)
      {
         char startId, endId;
         int weight;
         infile >> startId >> endId >> weight;
         g1.insert_arc(i, startId, endId, weight);
      }

      cout << "\n-------------------------------------------" << endl;
      cout << "Processing Graph " << g + 1 << ":" << endl;
      cout << "-------------------------------------------" << endl;
      g1.adjacency_matrix();
      g1.dijkstra_algorithm(g1.points[0].id);
   }
   infile.close();
   return 0;
}
