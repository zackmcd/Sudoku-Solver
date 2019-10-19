#include <fstream>
#include <iostream>
#include "solver.h"

using namespace std;

int main(int argc, char **argv)
{
  char c;
  int size;

  ifstream inf(argv[1]);

  cout << "Do you want me to solve this sudoku puzzle for you? (y/n) : ";
  cin >> c;

  if (c == 'y')
  {
    cout << "What is the size of the puzzle? : ";
    cin >> size;
    cout << endl;
    cout << "Problem :" << endl;
    Solver solver(size);
    inf >> solver;

    if(solver.solve())
    {
      cout << "Solution :" << endl;
      solver.print();
    }
    else 
      cout << "No solution exists." << endl;
  } // if
  else
    cout << "Goodluck :)" << endl;

  return 0;
} // main()
