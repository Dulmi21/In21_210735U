#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    //2. a int type list called neighbours
    int lable;
    list<int> neighbours;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=8;
    Node * nodes = new Node[n]; // an array of type Node




    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=1;i<=n;i++){
            nodes[i-1].lable=i;



        }
    }




    void addedge(int u, int v){


        (nodes[u-1].neighbours).push_back(v);
         (nodes[v-1].neighbours).push_back(u);




    }

    void print(){
        //lets iterate through each node and print its neighbours
        for(int i=0;i<n;i++){

         Node node3= nodes[i];
            cout<<node3.lable <<" -->" ;

             for(int i: (node3.neighbours)){
                cout<<i<<" ";

                }
                cout<<" "<<endl;


            //(nodes[i])->neighbours;
        }
        //print

    }
};


int main() {
    Graph * g = new Graph;
    g->intializenodes();

    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,5);
    g->addedge(1,4);
    g->addedge(2,3);

    g->addedge(2,6);
    g->addedge(4,6);

   // g->addedge(4,6);

    g->addedge(4,8);
 //   g->addedge(4,5);

    g->addedge(4,7);
    g->addedge(5,6);
    g->addedge(5,7);
    g->addedge(5,8);


    //add edges for the graphs here.


    //print the graph adjaceny list
    g->print();
}
