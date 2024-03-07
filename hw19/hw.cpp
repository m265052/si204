//Will Pitkin (it came unindented from copying from file)
// hw.cpp
#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes
string get_names(&string, &string);
bool update_counts(string, string, string, &int, string, &int);
void display_results(string, int, string, int);

// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}


// TO DO: Give function definitions


