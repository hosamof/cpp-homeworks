#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int max = 0;
class GraphNode
{
public:
    char name;
    vector <GraphNode*> childs;        
    GraphNode(char n = '/0') {
        this->name = n;
    }
    
    // find node in graph
    GraphNode* find(char name) {
        // check if same of current
        if (name == this->name) return this;
        
        // check children
        for (int i = 0; i < childs.size() ; i++)
        {            
            if (name == childs[i]->name) return childs[i];
        }

        // not found check children of children
        for (int i = 0; i < childs.size(); i++)
        {
            return childs[i]->find(name);
        }

        // not found
        return NULL;
    }

    // insert node to graph
    void insertChild(GraphNode& graph , char newNode) {
        // check if node exist in its childs
        GraphNode* found = graph.find(newNode);
        
        // cout << "newNode = " << newNode << endl;
        if (found == NULL) {
            found = new GraphNode(newNode);
        }
        
        // not found add it to children
        this->childs.push_back(found);
    }    
};

void print(string& str, GraphNode& source, int current = 0) {    
    // check max
    if (current >= max) return;

    // print node
    str += source.name;
    cout << str  <<  endl;    
    if (source.childs.size() == 0) {
        str = str.substr(0, str.size() - 1);
        return;
    }

    for (int i = 0; i < source.childs.size(); i++) {
        print(str, *source.childs[i] , current + 1);
    }
    str = str.substr(0, str.size() - 1);
}

int main(int argc, char* argv[])
{
    // test
    // argc = 2;
    // char argv[2][50] = { "asdsd" , "5ABCD1BCD1CDE1EDF" };
    // test
    // check graph
    if (argc <= 1) {
        cout << "\n graph info missing";
        return 0;
    }
    string graphInfo = argv[1];

    // get max number of letters        
    int index;
    for (index = 0; index < graphInfo.size(); index ++) {
        if (isdigit(graphInfo[index])) {
            max = (max * 10) + (graphInfo[index] - '0');
        }
        else {
            break;
        }
    }// index now is point to the first node

    // initialize graph         
    GraphNode graph ,
        *currentNode = new GraphNode();;
    bool startOfNodePath = true;
    for (int i = index; i < graphInfo.size(); i++)
    {
        if (graphInfo[i] != '1' && startOfNodePath) {
            if (i == index) {
                currentNode = &graph;
                currentNode->name = (char)graphInfo[i];
            }
            else {
                currentNode = graph.find((char)graphInfo[i]);                
                if (currentNode == NULL) {                    
                    currentNode = new GraphNode((char)graphInfo[i]);
                }
            }
            startOfNodePath = false;
        }
        else if (graphInfo[i] != '1') {               
            currentNode->insertChild(graph , (char)graphInfo[i]);
        }
        else {
            startOfNodePath = true;
        }
    }

    // print graph
    string s = "";
    print(s , graph);    


}
