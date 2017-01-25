#include "tetris_ui.h"

///////////////////////////////////////////////////////////
// classs ui_interface_factory
ui_interface * ui_interface_factory::create_ui_interface(
                                    tetris_shap shap)
{
    ui_interface * interface_p = NULL;

    switch(shap)
    {
        case TETRIS_X:
            interface_p = new ui_interface_X;
            break;

        case TETRIS_I:
            interface_p = new ui_interface_I_0;
            break;

        case TETRIS_Z:
            interface_p = new ui_interface_Z_0;
            break;

        case TETRIS_Z_M:
            interface_p = new ui_interface_Z_M_0;
            break;

        case TETRIS_L:
            interface_p = new ui_interface_L_0;
            break;

        case TETRIS_L_M:
            interface_p = new ui_interface_L_M_0;
            break;

        case TETRIS_T:
            interface_p = new ui_interface_T_0;
            break;
    }

    return interface_p;
}


///////////////////////////////////////////////////////////
// classs tetris_ui
void tetris_ui::_clear_ui()
{
    int i = 0;
    int row = m_ui.get_rows();
    int col = m_ui.get_cols();

    // clear all.
    m_ui.fill_array();

    // fill top and bottom.
    for( ; i < col; ++i)
    {
        m_ui.set_value_at(0, i, 1);
        m_ui.set_value_at(row-1, i, 1);
    }

    // fill leftest and rightest.
    for(i = 0; i < col; ++i)
    {
        m_ui.set_value_at(i, 0, 1);
        m_ui.set_value_at(i, col-1, 1);
    }
}
