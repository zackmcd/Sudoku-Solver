#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>

using namespace std;

class Solver
{
    int size;
    int **puzzle;
  public :
    Solver();
    Solver(int s);
    ~Solver();
    friend istream& operator>> (istream&is, Solver &solver);
    void insert(int row, int col, int num, Solver &solver);
    void print() const;
    bool solve();
    bool numInRow(int r, int num);
    bool numInCol(int c, int num);
    bool numInBox(int r, int c, int num);
    bool rules(int r, int c, int num);
    bool openSpot(int &r, int &c);
}; // class Solver

#endif
