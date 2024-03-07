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
    //test printSpaced function
    cout << "Testing printSpaced..." << endl;
    cout << "["; 
    printSpaced("wash"); 
    cout << "]" << endl;

    cout << "["; 
    printSpaced("HelloWorld!"); 
    cout << "]" << endl;

  
    //test mkShadowString function
    cout << endl << "Testing mkShadowString..." << endl;
    string s1 = "food";
    string s2 = mkShadowString(s1);
    cout << "original: " << s1 << endl;
    cout << "  shadow: " << s2 << endl;
    string s3 = "require";
    string s4 = mkShadowString(s3);
    cout << "original: " << s3 << endl;
    cout << "  shadow: " << s4 << endl;

    //test uncover function   
    cout << endl << "Testing uncover..." << endl;
    string u1 = "housepet";
    string u2 = "________";
    cout << u1 << endl << u2 << endl;
  
    string u3 = uncover(u1,u2,'e');
    if( u2 == u3 )
      cout << u3 << " there were not e's!"  << endl;
    else
      cout << u3 << " there were e's!"  << endl;
    u2 = u3;
 
    u3 = uncover(u1,u2,'q');
    if( u2 == u3 )
      cout << u3 << " there were not q's!"  << endl;
    else
      cout << u3 << " there were q's!"  << endl;

    //test crossOut function
    cout << endl << "Testing crossOut..." << endl;
    string t1 = "Go get good food!";
    cout << t1 << endl;
    t1 = crossOut('o',t1);
    cout << t1 << endl;
    t1 = crossOut('g',t1);
    cout << t1 << endl;
   
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