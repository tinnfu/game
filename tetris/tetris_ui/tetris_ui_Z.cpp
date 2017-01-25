#include "tetris_ui.h"

///////////////////////////////////////////////////////////
// classs ui_interface_Z
int ui_interface_Z_0::set_tetris_ui(tetris_ui & ui)
{
    int status = ui.get_status();

    if(0 == status)
    {
        int row = ui.get_tetris_rows();
        int col = ui.get_tetris_cols();

        // @ @
        //   # @
        ui.set_value_at(row/2 - 1, col/2 - 1, 1);
        ui.set_value_at(row/2 - 1, col/2, 1);
        ui.set_value_at(row/2,     col/2, 1);
        ui.set_value_at(row/2, col/2 + 1, 1);

        return 0;
    }

    if(status < 0)
    {
        cerr << "tetris_ui_Z hasn't "
            << status
            << "status.";
        return -1;
    }

    ui.set_ui_interface(new ui_interface_Z_1);
    return ui.set_tetris_ui();
}

int ui_interface_Z_1::set_tetris_ui(tetris_ui & ui)
{
    int status = ui.get_status();

    if(1 == status)
    {
        int row = ui.get_tetris_rows();
        int col = ui.get_tetris_cols();

        //   @
        // @ #
        // @
        ui.set_value_at(row/2-1, col/2, 1);
        ui.set_value_at(row/2, col/2-1, 1);
        ui.set_value_at(row/2, col/2,   1);
        ui.set_value_at(row/2+1, col/2-1, 1);

        return 0;
    }

    if(status > 1)
    {
        cerr << "tetris_ui_Z hasn't "
            << status
            << "status.";
        return -1;
    }

    ui.set_ui_interface(new ui_interface_Z_0);
    return ui.set_tetris_ui();
}
