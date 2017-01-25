#include "tetris.h"
#include <stdlib.h>
#include <time.h>

///////////////////////////////////////////////////////////
// class tetris_handler
void tetris_handler::key_point_shift_left(int step)
{
    while(step--)
    {
        m_key_point.x_minus_minus();
    }
}

void tetris_handler::key_point_shift_right(int step)
{
    while(step--)
    {
        m_key_point.x_plus_plus();
    }
}

void tetris_handler::key_point_shift_down(int step)
{
    while(step--)
    {
        m_key_point.y_plus_plus();
    }
}

int tetris_handler::update_map_top_line()
{
    if(NULL != m_tetris_p)
    {
        return m_tetris_p->update_map_top_line(*this);
    }

    cerr << "tetris_handler::update_map_top_line:"
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::hit_test_transfer()
{
    if(NULL != m_tetris_p)
    {
        return m_tetris_p->hit_test_transfer(*this);
    }

    cerr << "tetris_handler::hit_test_transfer: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::hit_test_left()
{
    if(NULL != m_tetris_p)
    {
        return m_tetris_p->hit_test_left(*this);
    }

    cerr << "tetris_handler::hit_test_left: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::hit_test_down()
{
    if(NULL != m_tetris_p)
    {
        return m_tetris_p->hit_test_down(*this);
    }

    cerr << "tetris_handler::hit_test_down: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::hit_test_right()
{
    if(NULL != m_tetris_p)
    {
        return m_tetris_p->hit_test_right(*this);
    }

    cerr << "tetris_handler::hit_test_right: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::cut_down()
{
    if(NULL != m_tetris_p)
    {
        m_tetris_p->update_map_top_line(*this);
        return m_tetris_p->cut_down(*this);
    }

    cerr << "tetris_handler::cut_down: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::redraw_tetris(int value)
{
    if(NULL != m_tetris_p)
    {
        m_tetris_p->redraw_tetris(*this, value);
        return 0;
    }

    cerr << "tetris_handler::redraw_tetris: "
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::set_next_status()
{
    if(NULL != m_tetris_p)
    {
        m_tetris_p->set_next_status(*this);
        return 0;
    }

    cerr << "tetris_handler::set_next_status:"
        << "m_tetris_p is null" << endl;
    return -1;
}

int tetris_handler::cut_down(int diamonds_high, int height)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int map_col = m_map.get_cols();

    for(; i < diamonds_high; ++i)
    {
        for(j = 1; j < (map_col-1)
                && m_map(height, j); ++j)
        {
            ;
        }

        // cut this line.
        if( (map_col-1) == j)
        {
            m_map.remove_line_at_height(height);
            ++count;
        }
        else
        {
            --height;
        }
    }

    return count;
}

///////////////////////////////////////////////////////////
// class tetris_factory
tetris * tetris_factory::create_tetris(tetris_shap shap)
{
    tetris * tetris_p = NULL;

    switch(shap)
    {
        case TETRIS_X:
            tetris_p = new tetris_X;
            break;

        case TETRIS_I:
            tetris_p = new tetris_I_0;
            break;

        case TETRIS_Z:
            tetris_p = new tetris_Z_0;
            break;

        case TETRIS_Z_M:
            tetris_p = new tetris_Z_M_0;
            break;

        case TETRIS_L:
            tetris_p = new tetris_L_0;
            break;

        case TETRIS_L_M:
            tetris_p = new tetris_L_M_0;
            break;

        case TETRIS_T:
            tetris_p = new tetris_T_0;
            break;
    }

    return tetris_p;
}

///////////////////////////////////////////////////////////
// class tetris_controler
void tetris_controler::create_next_tetris()
{
    srand( clock() );

    m_next_shap = (tetris_shap)(rand() % 7);

    int n = 0;

    switch(m_next_shap)
    {
        case TETRIS_X:
            n = 1;
            break;

        case TETRIS_I:
        case TETRIS_Z:
        case TETRIS_Z_M:
            n = 2;
            break;

        case TETRIS_L:
        case TETRIS_L_M:
        case TETRIS_T:
            n = 4;
            break;
    }

    m_next_status = (rand() % n);
}

void tetris_controler::set_next_tetris()
{
    m_tetris_handler.set_tetris(
            tetris_factory::create_tetris(m_next_shap) );

    m_tetris_handler.set_status(m_next_status);

    m_tetris_handler.reset_key_point();

    _draw_self();

    create_next_tetris();
}

int tetris_controler::transfer()
{
    if( 0 == m_tetris_handler.hit_test_transfer() )
    {
        _erase_self();

        m_tetris_handler.set_next_status();

        _draw_self();

        return 0;
    }

    return -1;
}

int tetris_controler::move_left()
{
    if( 0 == m_tetris_handler.hit_test_left() )
    {
        _erase_self();

        m_tetris_handler.key_point_shift_left();

        _draw_self();

        return 0;
    }

    return -1;
}

int tetris_controler::move_down()
{
    int res = m_tetris_handler.hit_test_down();

    if(0 == res)
    {
        _erase_self();

        m_tetris_handler.key_point_shift_down();

        _draw_self();
    }

    return res;
}

int tetris_controler::move_right()
{
    if( 0 == m_tetris_handler.hit_test_right() )
    {
        _erase_self();

        m_tetris_handler.key_point_shift_right();

        _draw_self();

        return 0;
    }

    return -1;
}
