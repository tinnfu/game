#include "tetris_ui.h"

///////////////////////////////////////////////////////////
// classs ui_interface_X
int ui_interface_X::set_tetris_ui(tetris_ui & ui)
{
    int status = ui.get_status();

    if(0 == status)
    {
        int row = ui.get_tetris_rows();
        int col = ui.get_tetris_cols();

        // @ @
        // @ #
        ui.set_value_at(row/2-1, col/2-1, 1);
        ui.set_value_at(row/2-1, col/2, 1);
        ui.set_value_at(row/2, col/2-1, 1);
        ui.set_value_at(row/2, col/2, 1);

        return 0;
    }

    cerr << "tetris_ui_I hasn't "
        << status
        << "status.";

    return -1;
}
