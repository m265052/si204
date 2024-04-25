/******************************************
list.cpp

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/

#include <iostream>
using namespace std;
#include "list.h"

void deletelist(Node* L)
{
  if( L == NULL )
  {
    return;
  }
  else 
  {
    deletelist(L->next);
    delete L;
  }
}

Node* add2back(Character x, Node* L)
{
  // base case:
  //  L is an empty list
  //  Note: if L is lastnode->next, L will also be NULL
  if (L == NULL)
    return new Node{x, NULL};

  // recursive case:
  //  Tell the child list to add a node
  //  Make sure that L->next is correct (especially when L is the lastnode)
  L->next = add2back(x, L->next);
  return L;
}

void print(Node* L)
{
  if (L == NULL) {
    cout << endl;
  } else {
    cout << '[' << L->data.label << " (" << L->data.row << ',' << L->data.col << ")] ";
    print(L->next);
  }
}

void nodesLeftOf(Node* L, int col)
{
  for(Node* p = L; p != NULL; p = p->next)
  {
    if (p->data.col < col)
    {
      cout << '[' << p->data.label << " (" << p->data.row << ',' << p->data.col << ")] " << endl;
    }
  }
}

void removeThird(Node* L)
{
  Node* temp = L;
  temp = temp->next->next;
  L = L->next;
  L->next = temp->next;
  delete temp;
}