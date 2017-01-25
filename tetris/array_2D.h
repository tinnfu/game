#ifndef _ARRAY_2D_H
#define _ARRAY_2D_H

#include <stdlib.h>
#include <iostream>

using namespace std;

template <typename type>
class array_2D
{
public:
    typedef type    value_type;

public:
    array_2D(int row = 1,
                int col = 1): m_row(row), m_col(col)
    {
        m_array_pp = new int*[row];

        while(row--)
        {
            m_array_pp[row] = new int[col];
        }

        fill_array();
    }

    virtual ~array_2D()
    {
        while(m_row--)
        {
            delete [](m_array_pp[m_row]);
        }

        delete []m_array_pp;
    }

public:
    virtual void fill_array(value_type value = 0)
    {
        int i = 0;
        int j = 0;

        for(i = 0; i < m_row; ++i)
        {
            for(j = 0; j < m_col; ++j)
            {
                m_array_pp[i][j] = value;
            }
        }
    }

public:
    virtual int get_rows() const
    {
        return m_row;
    }

    virtual int get_cols() const
    {
        return m_col;
    }

public:
    virtual value_type value_at(int row,
                                int col) const
    {
        if(row >= 0 && row < m_row
            && col >= 0 && col < m_col )
        {
            return m_array_pp[row][col];
        }

        cerr << "array_2D::value_at: "
            << "( " << row << ", " << col << " )"
            << " : index out of range" << endl;

        exit(-1);
    }

    virtual void set_value_at(int row, int col,
                            value_type value)
    {
        if(row >= 0 && row < m_row
            && col >= 0 && col < m_col )
        {
            m_array_pp[row][col] = value;

            return ;
        }

        cerr << "array_2D::value_at: "
            << "( " << row << ", " << col << " )"
            << " : index out of range" << endl;

        exit(-1);
    }

protected:
    value_type ** m_array_pp;
    int m_row;
    int m_col;
};

#endif
