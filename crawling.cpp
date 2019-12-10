// Humam alayad
// Ogrenci Numara : 1306180155
// Date : 06.12.2019
// Development Environment: Visual Studio 2019

#include <iostream> 
using namespace std;

int graph[256][256];
int max , firstNode;

// read graph function
void readGraph(string graphInfo) {
    // ### init max , firstNode and graph ###
    // 1- max : 
    int x = 0;
    max = 0;
    while (isdigit(graphInfo[x])) {
        max = (max * 10) + (graphInfo[x] - '0'); // ((int)graphInfo[0]) - ((int)'0')        
        x++;
    }
    cout << "max = " << max << endl;

    // 2- First Node  
    firstNode = graphInfo[x];
    cout << "x = " << x << endl;

    // 3- Graph
    graph[256][256] = { 0 }; //int graph[256][256] = { 0 };


    // ### initialize graph array by looping on graphInfo string ###
    int startNode = -1;
    for (int i = x; i < graphInfo.size(); i++)
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
void printGraph(int node, int parentNodes[], int degree) {
    // First : check current degree if more than allowed length of path (word letters)
    if (degree >= max) return;
    
    // print parent nodes if found
    if (degree > 0) {
        for (int i = 0; i < degree ; i++)
        {
            cout << (char)parentNodes[i];
        }
    }
    
    // print current node
    cout << (char)node << endl;

    // save current node increase degree
    parentNodes[degree++] = node;

    // search if has childs to continue the path
    for (int i = 0; i < 256; i++)
    {
        if (graph[node][i] == 1) {           
            printGraph(i, parentNodes , degree);
        }
    }
}
int main(int argc, char* argd[])
{
    // TODO : DELETE
    argc = 2;   
    char argv[2][40] = { "My App" , "3ABCD1BCD1CDE" }; // 1EFGH1DFGH
    // TODO : DELETE

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
    if (graphInfo.size()== 0 ) {
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
    int *parentNodes = new int[max];
    printGraph(firstNode, parentNodes , 0);    
    
    return 0;
}
