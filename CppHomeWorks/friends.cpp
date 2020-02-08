/*#include <iostream>
using namespace std;

int graph[256][256];
int max , firstNode;

void printWord(int node, int parentNodes[], int degree) {    
    if (degree >= max) return;    
    if (degree > 0) {
        for (int i = 0; i < degree ; i++)
        {
            cout << (char)parentNodes[i];
        }
    }
    cout << (char)node << endl;    
    parentNodes[degree++] = node;    
    for (int i = 0; i < 256; i++)
    {
        if (graph[node][i] == 1) {
            printWord(i, parentNodes , degree);
        }
    }
}
int main(int argc, char* argv[])
{
    if (argc <= 1) {
        cout << "\n graph info missing";
        return 0;
    }    
    string graphInfo = argv[1];

    // read the graph   
    int x = 0;
    max = 0;
    while (isdigit(graphInfo[x])) {
        max = (max * 10) + (graphInfo[x] - '0');
        x++;
    }    
    firstNode = graphInfo[x];        
    graph[256][256] = { 0 };    
    int startNode = 0;
    for (int i = x; i < graphInfo.size(); i++)
    {        
        if (graphInfo[i] != '1' && startNode == 0) {
            startNode = graphInfo[i];
        }        
        else if (graphInfo[i] != '1') {
            graph[startNode][graphInfo[i]] = 1;
        }        
        else {
            startNode = 0;
        }

    }

    // print posible words
    int *parentNodes = new int[max];
    printWord(firstNode, parentNodes , 0);

    return 0;
}
*/