#include <iostream>
#include <math.h>
#include "solver.h"

using namespace std;

Solver::Solver() : size(0), puzzle(NULL) {}

Solver::Solver(int s) : size(s)
{
  puzzle = new int*[size];

  for(int i = 0; i < size; i++)
    puzzle[i] = new int[size];

} //Solver()

Solver::~Solver()
{
  for(int i = 0; i < size; i++)
    delete [] puzzle[i];

  delete [] puzzle;

} //~Solver()

istream& operator>> (istream &is, Solver &solver)
{
  char n[80];
  int row = 0, col = 0;;
  double d = (double) solver.size;

  while(is.good())
  {
    is.getline(n, 80);

    if(row != 0 && (row % (int) sqrt(d)) == 0)
      is.getline(n, 80);
    
    for(int i = 0; i < strlen(n); i++)
    {
      if(isdigit(n[i]))
      {
	if (n[i] != 0)
	  solver.insert(row, col, n[i], solver);
        col++;
      } // if its a digit
    } // loops through line
    row++;
    col = 0;
  } // loops through txt file

  solver.print();
  return is; 
} //operator>>

void Solver::insert(int row, int col, int num, Solver &solver)
{
  solver.puzzle[row][col] = num - 48;
} // insert()

void Solver::print() const
{
  double d = (double) size;
  int domain = (int) sqrt(d);

  for(int i = 0; i < size; i++)
  {  
    for(int j = 0; j < size; j++)
    {
      if(j != 0 && (j % domain == 0))
        cout << "|";
      cout << puzzle[i][j];
    }
    cout << endl;
    if(i != 0 && i != size - 1 && ((i + 1) % domain == 0))
    {
      for(int p = 0; p < domain; p++)
      {
        for(int k = 0; k < domain; k++)
          cout << "-";
        if(p < domain - 1)
          cout << "|";
      } // loop
      cout << endl;
    } // if
  } // loops through array
  cout << endl;

} // print()

bool Solver::solve()
{
  int row = 0, col = 0;

  if(!openSpot(row, col))
    return true;

  for(int num = 1; num <= size; num++)
  {
    if(rules(row, col, num))
    {
      puzzle[row][col] = num;

      if(solve() == true)
        return true;

      puzzle[row][col] = 0;
    }
  }

  return false;
} //solve() 

bool Solver::rules(int r, int c, int num)
{
  return !numInRow(r, num) && !numInCol(c, num)
                           && !numInBox(r - (r % (int) sqrt(size)), c - (c % (int) sqrt(size)), num);

} // rules()

bool Solver::numInRow(int r, int num)
{
  for(int c = 0; c < size; c++)
    if(puzzle[r][c] == num)
      return true;
  
  return false;
} // numInRow()

bool Solver::numInCol(int c, int num)
{
  for(int r = 0; r < size; r++)
    if(puzzle[r][c] == num)
      return true;

  return false;
} // numInCol

bool Solver::numInBox(int bsr, int bsc, int num) // boxStartRow
{
  for(int r = 0; r < (int) sqrt(size); r++)
    for(int c = 0; c < (int) sqrt(size); c++)
      if(puzzle[r + bsr][c + bsc] == num)
        return true;

  return false;
} // numInBox()

bool Solver::openSpot(int &r, int &c)
{
  for(r = 0; r < size; r++)
    for(c = 0; c < size; c++)
      if(puzzle[r][c] == 0)
        return true;
  
  return false;
} // emptyCell()
