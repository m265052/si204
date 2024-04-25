    #pragma once
    #include <iostream>
    using namespace std;

    struct Node{
        int data;
        Node* next;
    };

    Node* add2back(int d, Node* L);
    void print(Node* L);
    void enter_after(int d, int x, Node* L); 
    Node* remove(int d, Node* L);
    Node* deletefront(Node* L);
    void deletelist(Node* L);