#include "map.h"

void map::fill_array(int value)
{
    int i = 0;
    int j = 0;

    // Fill map bottom.
    for(i = 0; i < m_col; ++i)
    {
        m_array_pp[m_row-1][i] = 1;
    }

    // Fill map leftest and rightest.
    for(i = 0; i < m_row; ++i)
    {
        m_array_pp[i][0] = 1;
        m_array_pp[i][m_col-1] = 1;
    }
}

// Just only for parent-class.
int map::value_at(int row, int col) const
{
    if(0 == row)
    {
        return 1;
    }

    return array_2D::value_at(
        row + get_map_top(), col);
}

int & map::operator()(int row, int col)
{
    if(row >= 0 && row < m_row
        && col >= 0 && col < m_col)
    {
        return m_array_pp[row][col];
    }

    cerr << "map::value_at: index out of range."
        << endl;
    exit(-1);
}

void map::remove_line_at_height(int height)
{
    if(height <= get_map_top()+1
        || height >= get_map_bottom() )
    {
        return ;
    }

    int i = 0;

    for( ; height >= m_top_line; --height)
    {
        for(i = 1; i < m_col-1; ++i)
        {
            m_array_pp[height][i] =
                m_array_pp[height-1][i];
        }
    }
    
    ++m_top_line;
}

void map::update_top_line(int new_top)
{
    if(m_top_line > new_top)
    {
        m_top_line = new_top;
    }
}
