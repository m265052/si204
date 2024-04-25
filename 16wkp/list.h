/******************************************
list.h

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/

#pragma once
#include <iostream>
using namespace std;

struct Character
{
  char label;
  int row, col;
};

struct Node
{
  Character data;
  Node* next;
};


void deletelist(Node* L);
Node* add2back(Character x, Node* L);
void print(Node* L);
void nodesLeftOf(Node* L, int col);
void removeThird(Node* L);