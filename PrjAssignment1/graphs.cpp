#include<iostream>
//for using vectors
#include<vector>
#include<cstring>

using namespace std;


//without vectors: using adjacency matrix: static
void static_graph(){
   int n, m;
   int adjacency_matrix[n+1][m+1];

}

//with vectors: using adjacency list: dynamic
void vector_graph(){
   vector <int> adj[3];

}

int main(){
   cout << "Static: "<<endl;
   static_graph();
   cout << "Dynamic"<<endl;
   vector_graph();
}
