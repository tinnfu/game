#ifndef _TETRIS_UI_H
#define _TETRIS_UI_H

#include "../array_2D.h"
#include "../tetris/tetris.h"

class tetris_ui;

///////////////////////////////////////////////////////////
// class ui_interface
class ui_interface
{
public:
    virtual ~ui_interface() {};
public:
    virtual int set_tetris_ui(tetris_ui & ui) = 0;
};

///////////////////////////////////////////////////////////
// class ui_interface_X
class ui_interface_X: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_I
class ui_interface_I_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_I_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_Z
class ui_interface_Z_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_Z_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_Z_M
class ui_interface_Z_M_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_Z_M_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_L
class ui_interface_L_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_2: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_3: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_L_M
class ui_interface_L_M_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_M_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_M_2: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_L_M_3: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_T
class ui_interface_T_0: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_T_1: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_T_2: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

class ui_interface_T_3: public ui_interface
{
public:
    int set_tetris_ui(tetris_ui & ui);
};

///////////////////////////////////////////////////////////
// class ui_interface_factory
class ui_interface_factory
{
public:
    static ui_interface * create_ui_interface(tetris_shap shap);
};

///////////////////////////////////////////////////////////
// class tetris_ui
class tetris_ui
{
public:
    tetris_ui(int rows = 8, int cols = 8):
                            m_ui(rows, cols),
                                    m_status(0),
                        m_ui_interface_p(NULL)
    {
        _clear_ui();
    }

    ~tetris_ui()
    {
        delete m_ui_interface_p;
    }

private:
    void _clear_ui();

public:
    void set_shap_status(tetris_shap shap, int status)
    {
        set_ui_interface(
            ui_interface_factory::create_ui_interface(shap)
                        );

        m_status = status;

        set_tetris_ui();
    }

    int get_status() const
    {
        return m_status;
    }

public:
    void set_ui_interface(ui_interface * ui_interface_p)
    {
        delete m_ui_interface_p;
        m_ui_interface_p = ui_interface_p;
    }

    int set_tetris_ui()
    {
        if(NULL != m_ui_interface_p)
        {
            _clear_ui();

            return m_ui_interface_p->set_tetris_ui(*this);
        }

        cerr << "interface_ui::set_tetris_ui:"
            << "m_ui_interface_p is null"
            << endl;
        return -1;
    }

public:
    int get_tetris_rows() const
    {
        return m_ui.get_rows();
    }

    int get_tetris_cols() const
    {
        return m_ui.get_cols();
    }

    int operator()(int x, int y) const
    {
        return m_ui.value_at(x, y);
    }

    void set_value_at(int x, int y, int value)
    {
        m_ui.set_value_at(x, y, value);
    }

private:
    array_2D<int> m_ui;
    ui_interface * m_ui_interface_p;
    int m_status;
};

#endif
