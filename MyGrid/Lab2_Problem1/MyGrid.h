
// Remember your file headers and comments

#pragma once
#include <vector>
#include <string>
#include <fstream>
//#include <iostream>

using namespace std;

class MyGrid
{

public:
    MyGrid();
    MyGrid(long x, long y, long row, long col);
    bool loadGridFromFile(const string& filename);
    void zeroOutGrid();
    long getNumRows() const;
    long getNumCols() const;

    MyGrid operator+(MyGrid const& rhs) const;
    MyGrid operator-(MyGrid const& rhs) const;

    MyGrid operator+(long const& num) const;

    friend MyGrid operator+(long const& lhs, MyGrid const& rhs);

    // Addition assignment 
    MyGrid& operator+=(MyGrid const& rhs);
    // Increment
    MyGrid& operator++(); // Prefix
    MyGrid operator++(int); // Postfix

    MyGrid& operator--(); // Prefix
    MyGrid operator--(int); // Postfix

    MyGrid operator-() const;

    bool operator==(MyGrid const& rhs) const;

    friend fstream& operator<<(fstream& os, const MyGrid& gridIn);

private:
    long myX, myY;
    long NumRows, NumCols;
    vector<vector<long>> gridElements;
};

