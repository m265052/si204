  //Will Pitkin     m265052
  //lab08 pt1       07Mar24

  #include <iostream>
  #include <fstream>
  #include <string>
  #include <cstdlib>
  using namespace std;

  void printSpaced(string s);
  string mkShadowString(string s);
  string uncover(string original, string covered, char c);
  string crossOut(char c, string s);

  int main()
  {
    cout << "Welcome to String Guess!" << endl
         << "Enter a seed value: ";
    int seed;
    cin >> seed;
    //use the seed to choose a random word from the words07.txt
    srand(seed);
    int n = rand() % 1466;
    
    //fin from the words07.txt
    string word;
    ifstream fin("words07.txt");
    //the for loop must start at i=-1 bc n can = 0
    for(int i=-1; i < n; i++)
        fin >> word;
    //this loop should continue to replace word for as many times fin happens
    //the last fin should be the word
    //cover word
    string wordS = mkShadowString(word);


    //string for letters that can be used
    string letters = "abcdefghijklmnopqrstuvwxyz";
    //guesses char guess
    char g;

    //begin to make the game and the counter for guesses
    for(int guesses = 8; guesses > 0; guesses--)
    {
        cout << "Wrong guesses remaining: " << guesses << "\t";

        cout << letters << endl;

        //print the shadow (covered mystery) word with spaces
        printSpaced(wordS);
        cout << endl << ": ";

        cin >> g;
        string tempWord = wordS;
        wordS = uncover(word, wordS, g);
        //see if the letter existed in the word by comparing the temporary
        //word initialized above remains the same as the shadow word
        if(wordS == tempWord)
            cout << "There were no " << g << "'s!" << endl;
        //added the guesses++ to counteract the counter in the for loop
        //to give back a guess for when the player is correct, effectively
        //cancelling out the wrong guess counter
        else guesses++;
        letters = crossOut(g, letters);

        //determine if person has won. If so, exit loop
        if(wordS == word)
        {
            cout << "You win!!!! The word was " << word << endl;
            return 0;
        }
    }
    cout << "You lose!!!! The word was " << word << endl;
    return 0;
  }

  void printSpaced(string s)
  {
    //simple loop that continues for function string length
    for(int i=0; i < s.length(); i++)
    {
      if(i == s.length() - 1)
        cout << s[i];
      else cout << s[i] << ' ';
    }
  }

  string mkShadowString(string s)
  {
    //do not forget to make the string to return and initialize it
    string shadow = s;
    //just give out a set of underscores for the length of the word
    for(int i=0; i < s.length(); i++)
      shadow[i] = '_';
    return shadow;
  }

  string uncover(string original, string covered, char c)
  {
    //make uncover string
    string uncovered = original;
    for(int i=0; i < original.length(); i++)
    {
      //begin to output '_', but if the ouput matches c, output c
      if(original[i] == c)
        uncovered[i] = c;
      else uncovered[i] = covered[i];
    }
    return uncovered;
  }

  string crossOut(char c, string s)
  {
    //same steps but with some comparison
    string crossOut = s;
    for(int i=0; i < s.length(); i++)
    {
      if(s[i] == c)
      {
        crossOut[i] = '*';
      }
      else
      { 
        crossOut[i] = s[i];
      }
    }
    return crossOut;
  }