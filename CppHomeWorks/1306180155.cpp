// Humam alayad
// Ogrenci Numara : 1306180155
// Date : 06.12.2019
// Development Environment: Visual Studio 2019

#include <iostream> 
using namespace std;

int graph[256][256];
int max, firstNode;

// read graph function
void readGraph(string graphInfo) {
    // ### init max , firstNode and graph ###
    // 1- max : 
    int index = 0;
    max = 0;
    while (isdigit(graphInfo[index])) {
        max = (max * 10) + (graphInfo[index] - '0'); // ((int)graphInfo[0]) - ((int)'0')        
        index++;
    }
    cout << "max = " << max << endl;

    // 2- First Node  
    firstNode = graphInfo[index];
    cout << "firstNode = " << (char)firstNode << endl
        << "-------------" << endl << endl;

    // 3- Graph
    graph[256][256] = { 0 };


    // ### initialize graph array by looping on graphInfo string ###
    int startNode = -1;
    for (int i = index; i < graphInfo.size(); i++)
    {
        // start of word
        if (graphInfo[i] != '1' && startNode == -1) {
            startNode = graphInfo[i];
        }
        // continue on word
        else if (graphInfo[i] != '1') {
            graph[startNode][graphInfo[i]] = 1;
        }
        // end of word
        else {
            startNode = -1;
        }

    }
}
// print graph
void printGraph(int node, string parentNodes, int degree) {
    // First : check current degree if more than allowed length of path (word letters)
    if (degree >= max) return;

    // if first node print it first
    if (degree == 1) cout << (char)node << endl;

    // add this node to parents
    parentNodes += (char)node;

    // init node children
    string children = "";

    // search if has children print them then move to the next degree
    for (int i = 0; i < 256; i++)
    {
        if (graph[node][i] == 1) {
            // print child node
            cout << parentNodes << (char)i << endl;

            // save child
            children += i;
        }
    }

    // call print for childres    
    for (int i = 0; i < children.size(); i++)
    {
        printGraph(children[i], parentNodes, degree + 1);
    }
}
int main(int argc, char* argv[])
{    
    ///
    /// 1- ### Check Inputs ###
    ///

    // check if has second arguments or not
    if (argc <= 1) {
        cout << "\nPlease enter the application name - the graph info";
        return 0;
    }

    // check if the graph empty
    string graphInfo = argv[1];
    if (graphInfo.size() == 0) {
        cout << "graph info must not be empty";
        return 0;
    }

    // ### check if first char is number ###
    if (!isdigit(graphInfo[0])) {
        cout << "graph must start with max letters count";
        return 0;
    }

    ///
    /// 2- ### Read Graph and save it in graph array ###
    ///
    readGraph(graphInfo);



    ///
    /// 3- ### print result from the graph array ###
    ///    
    printGraph(firstNode, "", 1);

    return 0;
}