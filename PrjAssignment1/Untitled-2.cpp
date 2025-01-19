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

// Define Point class and an Arc class.
class Point
{
public:
   // holds unique id for identificatio of point
   char id;
   // constructor
   Point()
   {
      id = '-';
   }
   Point(int identifier)
   {
      id = identifier;
   }
   // destructor
   ~Point() {} // static deallocation carried out
};

class Arc
{
public:
   int weight;
   Point *start, *end;
   // default constructor
   Arc()
   {
      weight = 0;
      start = end = 0;
   }
   // parameterized constructor
   Arc(Point *beg, Point *last, int weigh)
   {
      weight = weigh;
      start = beg;
      end = last;
   }

   // destructor
   ~Arc() {} // static deallocation carried out
};

// Define a graph class which represents graph as collection
// of Point Objects and collection of Arc objects.
class Graph
{
public:
   Point *points;
   Arc *arc;
   int p_count, a_count;
   // constructor
   Graph(int point_count, int arc_count)
   {
      p_count = point_count;
      a_count = arc_count;
      points = new Point[p_count];
      arc = new Arc[a_count];
   }

   // inserting points
   void insert_point(int index, char id)
   {
      if (index < p_count)
         points[index] = Point(id); // point obj in arr
   }

   // insertinf arcs
   void insert_arc(int index, char startId, char endId, int weight)
   {
      // using null pointer since using 0 or anothe int may be conflicting
      Point *start = nullptr;
      Point *end = nullptr;
      // initializing start and end by right val
      for (int i = 0; i < p_count; i++)
      {
         if (points[i].id == startId)
            start = &points[i];
         if (points[i].id == endId)
            end = &points[i];
      }
      // array of arcs
      if (start && end)
         if (index < a_count)
            arc[index] = Arc(start, end, weight);
      // contacts parameterized constructor
   }

   // display graph as adjacency matrix
   void adjacency_matrix()
   {
      int adj[26][26];

      // initializing to zeroooo-o-o-oo-o
      for (int i = 0; i < p_count; i++)
         for (int j = 0; j < p_count; j++)
            adj[i][j] = 0;

      // adding in actual values per edges
      for (int i = 0; i < a_count; i++)
      {
         // access values

         // adding 1 to represent existence of edge
         // adj[arc[i].start->id - 'A'][arc[i].end->id - 'A'] = 1;
         // adj[arc[i].end->id - 'A'][arc[i].start->id - 'A'] = 1;

         // adding weight in matrix
         adj[arc[i].start->id - 'A'][arc[i].end->id - 'A'] = arc[i].weight;
         adj[arc[i].end->id - 'A'][arc[i].start->id - 'A'] = arc[i].weight;

         /*
         subtracting A to get index value, since sarre are char
         uppercase alphabet - first uppercase alphabet
         should technically lie between [1-26]
         */
      }
      cout << "Adjacency Matrix:" << endl;
      for (int i = 0; i < p_count; i++)
      {
         for (int j = 0; j < p_count; j++)
            cout << adj[i][j] << "\t";
         cout << endl;
      }
   }

   //  dijkstra algorithm declaration
   void dijkstra_algorithm(char param);

   // destructor
   ~Graph()
   {
      delete[] points; // since new[] created dynamic array
      delete[] arc;    // since new[] created dynamic array
   }
};

// defining dijkstra algorithm
void Graph::dijkstra_algorithm(char param)
{
   int index = param - 'A';
   int *cost = new int[p_count];
   char *visit_status = new char[p_count];
   /*
   step-1:
      intializing all paths as infinity
      (or placeholder of some meaning to user)
   step-2:
      mark every node as unvisited
   */
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

   // Output shortest distances
   cout << "\nShortest distances from " << index << ":" << endl;
   for (int i = 0; i < p_count; i++)
   {
      cout << "\tTo Point " << (char)('A' + i) << ": " << cost[i] << endl;
   }

   delete[] cost;
   delete[] visit_status;
}

int main() {
    int total_graphs = 1; // Assuming you want to test one graph here
    int point = 12, arc = 44;
    Graph g1(point, arc);

    // Points
    for (int i = 0; i < point; i++) {
        g1.insert_point(i, 'A' + i);
    }

    // Arcs
    g1.insert_arc(0, 'A', 'B', 0);
    g1.insert_arc(1, 'A', 'D', 0);
    g1.insert_arc(2, 'B', 'G', 0);
    g1.insert_arc(3, 'B', 'F', 0);
    g1.insert_arc(4, 'C', 'E', 0);
    g1.insert_arc(5, 'E', 'L', 0);
    g1.insert_arc(6, 'H', 'J', 0);
    g1.insert_arc(7, 'G', 'A', 0);
    g1.insert_arc(8, 'J', 'C', 0);
    g1.insert_arc(9, 'I', 'E', 0);
    g1.insert_arc(10, 'D', 'C', 0);
    g1.insert_arc(11, 'E', 'B', 0);
    g1.insert_arc(12, 'C', 'L', 0);
    g1.insert_arc(13, 'D', 'G', 0);
    g1.insert_arc(14, 'E', 'B', 0);
    g1.insert_arc(15, 'G', 'A', 0);
    g1.insert_arc(16, 'B', 'C', 0);
    g1.insert_arc(17, 'A', 'G', 0);
    g1.insert_arc(18, 'L', 'F', 0);
    g1.insert_arc(19, 'E', 'A', 0);
    g1.insert_arc(20, 'C', 'B', 0);
    g1.insert_arc(21, 'I', 'D', 0);
    g1.insert_arc(22, 'A', 'E', 0);
    g1.insert_arc(23, 'G', 'J', 0);
    g1.insert_arc(24, 'A', 'D', 0);
    g1.insert_arc(25, 'B', 'I', 0);
    g1.insert_arc(26, 'A', 'F', 0);
    g1.insert_arc(27, 'L', 'C', 0);
    g1.insert_arc(28, 'I', 'D', 0);
    g1.insert_arc(29, 'C', 'E', 0);
    g1.insert_arc(30, 'D', 'E', 0);
    g1.insert_arc(31, 'E', 'F', 0);
    g1.insert_arc(32, 'F', 'G', 0);
    g1.insert_arc(33, 'G', 'A', 0);
    g1.insert_arc(34, 'A', 'B', 0);
    g1.insert_arc(35, 'A', 'C', 0);
    g1.insert_arc(36, 'B', 'C', 0);
    g1.insert_arc(37, 'B', 'D', 0);
    g1.insert_arc(38, 'C', 'D', 0);
    g1.insert_arc(39, 'C', 'E', 0);
    g1.insert_arc(40, 'D', 'E', 0);
    g1.insert_arc(41, 'E', 'F', 0);
    g1.insert_arc(42, 'F', 'G', 0);
    g1.insert_arc(43, 'G', 'A', 0);

    g1.adjacency_matrix();
    g1.dijkstra_algorithm('A'); // Running Dijkstra for point A
    return 0;
}
