// Humam alayad
// Ogrenci Numara : 1306180155
// Date : 06.12.2019
// Development Environment: Visual Studio 2019

#include <iostream> 
using namespace std;

int graph[256][256];
int max , firstNode;

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
    // check if has second arguments or not
    if (argc <= 1) {
        cout << "\nPlease enter the application name - the graph info";
        return 0;
    }
       
    
    // init graphInfo string variable
    string graphInfo = argv[1];

    // check if the graph empty
    if (graphInfo.size()== 0 ) {
        cout << "graph info must not be empty";
        return 0;
    }

    // check if first char is number
    if (!isdigit(graphInfo[0])) {
        cout << "graph must start with max letters count";
        return 0;
    }

    // init max and graph
    int x = 0;
    max = 0;
    while (isdigit(graphInfo[x])) {        
        max = (max * 10) + (graphInfo[x] - '0'); // ((int)graphInfo[0]) - ((int)'0')        
        x++;
    }    
    cout << "max = " << max << endl;
    cout << "x = " << x << endl;
      
    firstNode = graphInfo[x];
    graph[256][256] = { 0 }; //int graph[256][256] = { 0 };

    int startNode = -1;
    // initialize graph array by looping on graphInfo string
    for (int i = x; i < graphInfo.size() ; i++)
    {
        /*
        // Test Section
        graph[graphInfo[i]][graphInfo[i]] = 1;
        cout << "index is " << i << endl;
        cout << "char is " << ((char)graphInfo[i]) << endl;
        cout << "char with out brackets is " << (char)graphInfo[i] << endl;
        cout << "value is " << (int) graphInfo[i] << endl ;
        cout << " graph " << graph[(int)graphInfo[i]][(int)graphInfo[i]] << endl;
        cout << " graph int " << graph[(int)graphInfo[i]][(int)graphInfo[i]] << endl;
        cout << endl << endl;
        continue;
        */
        // start of word
        if ( graphInfo[i] != '1' && startNode == -1)  {     
            startNode = graphInfo[i];                
        }
        // continue on word
        else if (graphInfo[i] != '1' ) {
            graph[startNode][graphInfo[i]] = 1;
        }
        // end of word
        else {
            startNode = -1;            
        }        

    }    
    // print result from array    
    int *parentNodes = new int[max];
    printGraph(firstNode, parentNodes , 0);
    /*int temp = 0;
    for (int i = 0; i < 256 ; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            temp = graph[i][j];
            if (temp != 0) {
                cout << (char)i << " to " << (char)j << " = " << temp << endl;
            }
            
        }        
    }*/
    
    return 0;
}


/*
// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/
