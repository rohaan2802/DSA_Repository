#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class AdjList
{
public:
    Node* head;
    AdjList()
    {
        head = nullptr;
    }

    void insert(Node* node)
    {
        node->next = head;
        head = node;
    }

    void display()
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << " -> " << current->data;
            current = current->next;
        }
    }

};

class Graph
{
public:
    int max_ver;
    AdjList* list;

    Graph(int x)
    {
        max_ver = x;
        list = new AdjList[x];
    }

    Node* create_vertex(int data)
    {
        return new Node(data);
    }

    void insert_edge(int src, int dest)
    {
        if (src < 0 || src > max_ver || dest < 0 || dest > max_ver)
        {
            return;
        }

        Node* temp1 = create_vertex(dest);
        list[src].insert(temp1);

        Node* temp2 = create_vertex(src);
        list[dest].insert(temp2);
    }

    ~Graph()
    {
       delete[] list;
    }

    void show_graph_structure()
    {
        for (int i = 1; i < max_ver; i++)
        {
            cout << i;
            list[i].display();
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(6);
    graph.insert_edge(2, 5);
    graph.insert_edge(1, 5);
    graph.insert_edge(2, 4);
    graph.insert_edge(3, 4);
    graph.insert_edge(2, 3);
    graph.insert_edge(1, 2);
    graph.insert_edge(4, 5);

    graph.show_graph_structure();

    return 0;
}

