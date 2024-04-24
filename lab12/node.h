    #pragma once
    #include <iostream>
    using namespace std;

    //did not see that I had to make this one too, but it can be here too
    struct Pair
    {
        string w;       //word
        int n;          //number
    };

    struct Node
    {
        Pair data;
        Node* next;
    };

    Node* add2front(string word, int val, Node* L);
    void printListRec(Node* L);
    int length(Node* L);
    Node* deletefront(Node* L);
    void deletelist(Node* L);
    int tally(int score, Node* p);
    Node* deleteNode(Node* L, Node* p);