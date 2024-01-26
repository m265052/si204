    #include <iostream>
    using namespace std;

    int main()
    {
        int k;
        cout << "Enter positive integer that divides 1155: ";
        cin >> k;
        if (k > 0 && 1155 % k == 0)
          cout << "Good input" << endl;
        else
          cout << "Bad input" << endl;
        return 0;
    }