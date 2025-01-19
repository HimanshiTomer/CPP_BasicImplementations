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
   void adjacency_matrix();

   //  dijkstra algorithm declaration
   void dijkstra_algorithm(char param);

   // destructor
   ~Graph()
   {
      delete[] points; // since new[] created dynamic array
      delete[] arc;    // since new[] created dynamic array
   }
};

// creating and displaying adjacency
void Graph::adjacency_matrix()
{
   int adj[p_count][p_count];

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

int main()
{
   // using file handling fo multiple data sets without having to add them manually
   ifstream infile("graph_data.txt");
   if (!infile)
      return 1; // error handling

   int total_graphs;
   infile >> total_graphs; // total number of graphs is stored in first line of th efile
   for (int g = 0; g < total_graphs; g++)
   {
      int point, arc;
      infile >> point >> arc; // read point and arc count for this graph

      Graph g1(point, arc);
      // reading points from the file
      for (int i = 0; i < point; i++)
      {
         char pointId;
         infile >> pointId;
         g1.insert_point(i, pointId);
      }

      // reading arcs from the file
      for (int i = 0; i < arc; i++)
      {
         char startId, endId;
         int weight;
         infile >> startId >> endId >> weight;
         g1.insert_arc(i, startId, endId, weight);
      }

      // Displaying and processing the graph
      cout << "\n-------------------------------------------" << endl;
      cout << "Processing Graph " << g + 1 << ":" << endl;
      cout << "-------------------------------------------" << endl;
      g1.adjacency_matrix();
      g1.dijkstra_algorithm(g1.points[0].id);
      // running Dijkstra for the first point
   }
   // clsoing the file
   infile.close();
   return 0;
}