#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>

#include "../array_2D.h"
#include "../point.h"

using namespace std;

class map: public array_2D<int>
{
public:
    map(int map_row = 20,
        int map_col = 10):
            array_2D(map_row+2+2, map_col+2)
            ,m_top_line(map_row+2+2-1)
    {
        fill_array();
    }

    ~map() {}

public:
    void fill_array(int value = 0);

private:
    // Just only for parent-class.
    int value_at(int row, int col) const;

public:
    int get_rows() const
    {
        return (m_row - get_map_top() );
    }

    int get_cols() const
    {
        return m_col;
    }

public:
    int & operator()(int row, int col);

    void remove_line_at_height(int height);

public:
    void update_top_line(int new_top);
    int get_top_line() const
    {
        return m_top_line;
    }
     
public:
    int get_map_top() const
    {
        return 2;
    }

    int get_map_bottom() const
    {
        return (m_row - 1);
    }

private:
    int m_top_line;
};

#endif
