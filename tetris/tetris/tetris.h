#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <iostream>

#include "../point.h"
#include "../array_2D.h"
#include "../map/map.h"

using namespace std;

class tetris_handler;

///////////////////////////////////////////////////////////
// class tetris
class tetris
{
public:
    virtual ~tetris() {}

public:
    virtual int update_map_top_line(
            tetris_handler & handler) = 0;
    virtual int hit_test_transfer(
            tetris_handler & handler) = 0;
    virtual int hit_test_left(
            tetris_handler & handler) = 0;
    virtual int hit_test_down(
            tetris_handler & handler) = 0;
    virtual int hit_test_right(
            tetris_handler & handler) = 0;

    virtual int cut_down(
            tetris_handler & handler) = 0;
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0) = 0;
    virtual int set_next_status(
            tetris_handler & handler) = 0;
};

///////////////////////////////////////////////////////////
// class tetris_x
class tetris_X: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_I
class tetris_I_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_I_1: public tetris
{

public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_Z
class tetris_Z_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_Z_1: public tetris
{

public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_Z_M
class tetris_Z_M_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_Z_M_1: public tetris
{

public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_L
class tetris_L_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_1: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_2: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_3: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_L_M
class tetris_L_M_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_M_1: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_M_2: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_L_M_3: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_T
class tetris_T_0: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_T_1: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_T_2: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

class tetris_T_3: public tetris
{
public:
    virtual int update_map_top_line(
            tetris_handler & handler);
    virtual int hit_test_transfer(
            tetris_handler & handler);
    virtual int hit_test_left(
            tetris_handler & handler);
    virtual int hit_test_down(
            tetris_handler & handler);
    virtual int hit_test_right(
            tetris_handler & handler);

    virtual int cut_down(
            tetris_handler & handler);
    virtual int redraw_tetris(
            tetris_handler & handler,
                        int value = 0);
    virtual int set_next_status(
            tetris_handler & handler);
};

///////////////////////////////////////////////////////////
// class tetris_handler
class tetris_handler
{
public:
    tetris_handler(tetris * tetris_p = NULL,
                        int status = 0):
                        m_status(status),
                    m_tetris_p(tetris_p),
                    m_map(20, 10)
    {
        reset_key_point();
    }

    ~tetris_handler()
    {
        delete m_tetris_p;
    }

public:
    void reset_key_point()
    {
        m_key_point.set_x(m_map.get_cols() / 2);
        m_key_point.set_y(3);
    }

    int get_key_point_x()
    {
        return m_key_point.get_x();
    }
    int get_key_point_y()
    {
        return m_key_point.get_y();
    }

public:
    const array_2D<int> & get_map() const
    {
        return m_map;
    }

    int map_value_at(int x, int y)
    {
        return m_map(x, y);
    }

    void set_map_value_at(int x, int y, int value)
    {
        m_map(x, y) = value;
    }

public:
    void key_point_shift_left(int step = 1);
    void key_point_shift_right(int step = 1);
    void key_point_shift_down(int step = 1);

public:
    int get_status()
    {
        return m_status;
    }
    void set_status(int new_status)
    {
        m_status = new_status;
    }

public:
    int update_map_top_line(int new_top)
    {
        m_map.update_top_line(new_top);
        return 0;
    }

    int cut_down(int diamonds_high, int height);

public:
    int update_map_top_line();

    int hit_test_transfer();
    int hit_test_left();
    int hit_test_down();
    int hit_test_right();

    int cut_down();
    
    int redraw_tetris(int value);

    int set_next_status();

public:
    void set_tetris(tetris * tetris_p)
    {
        delete m_tetris_p;
        m_tetris_p = tetris_p;
    }

public:
    int game_over()
    {
        return (m_map.get_top_line()
                <= (m_map.get_map_top()+1) );
    }

private:
    tetris * m_tetris_p;
    point m_key_point;
    int m_status;
    map m_map;
};

typedef enum
{
    TETRIS_X = 0,   // 1

    TETRIS_I,       // 2
    TETRIS_Z,       // 2
    TETRIS_Z_M,     // 2

    TETRIS_L,       // 4
    TETRIS_L_M,     // 4
    TETRIS_T,       // 4
}tetris_shap;

///////////////////////////////////////////////////////////
// class tetris_factory
class tetris_factory
{
public:
    static tetris * create_tetris(tetris_shap);
};

class tetris_controler
{
public:
    tetris_controler()
    {
        create_next_tetris();
        set_next_tetris();
    }

    ~tetris_controler()
    {}

public:
    int get_next_status()
    {
        return m_next_status;
    }
    void set_next_status(int next_status)
    {
        m_next_status = next_status;
    }

    tetris_shap get_next_shap()
    {
        return m_next_shap;
    }
    void set_next_shap(tetris_shap next_shap)
    {
        m_next_shap = next_shap;
    }

    void set_next_tetris();

public:
    void create_next_tetris();

private:
    void _erase_self()
    {
        m_tetris_handler.redraw_tetris(0);
    }
    void _draw_self()
    {
        m_tetris_handler.redraw_tetris(1);
    }

public:
    int transfer();

    int move_left();
    int move_down();
    int move_right();

    int cut_down()
    {
        return m_tetris_handler.cut_down();
    }

public:
    int game_over()
    {
        return m_tetris_handler.game_over();
    }

    const array_2D<int> & get_map() const
    {
        return m_tetris_handler.get_map();
    }


private:
    tetris_handler m_tetris_handler;
    tetris_shap m_next_shap;
    int m_next_status;
};

#endif
