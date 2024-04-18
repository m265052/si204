    //Will Pitkin   m265052
    //hw31          16APR24

    #include <iostream>
    using namespace std;

    struct Node
    {
        string data;
        Node* next;
    };

    Node* add2front(Node* L, string s);
    void search(Node*, char);
    Node* deletefront(Node* L);

    int main()
    {
        cout << "Enter words followed by END:" << endl;
        string s = "hehehaha";

        Node* L = NULL;

        //make list to store the words in
        while (s != "END")
        {
            cin >> s;
            //add2front so that they next function reads normally
            L = add2front(L, s);
        }
        //the last entry was end, so the "next" created needs nullified
        

        cout << "What letter? ";
        char c;
        cin >> c;

        search(L, c);

        //delete the list
        while (L != NULL)
            L = deletefront(L);

        return 0;
    }

    Node* add2front(Node* L, string s)
    {
        Node* temp = new Node;
        temp->data = s;
        temp->next = L;
        return temp;
    }

    void search(Node *L, char c)
    {
        //go through the list and output anything starting with letter
        for (Node* p = L; p != NULL; p = p->next)
        {
            if (p->data[0] == c)
                cout << p->data << endl;
        }
    }

    Node* deletefront(Node* L)
    {
        if (L == NULL)
            return NULL;

        Node* nex = L->next;
        delete L;
        return nex;
    }