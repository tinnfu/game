#include "tetris.h"

///////////////////////////////////////////////////////////
// class tetris_X
// @ @
// @ #
int tetris_X::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        return handler.update_map_top_line(
                handler.get_key_point_y() - 1);
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::hit_test_transfer(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        return 0;
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::hit_test_left(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y-1, x-1 -1
        // @ #  y,   x-1 -1
        return (
                handler.map_value_at(y-1, x-2)
                ||
                handler.map_value_at(y, x-2)
               );
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::hit_test_down(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @
        // @ #  y+1, x-1 | y+1, x
        return (
                handler.map_value_at(y+1, x-1)
                ||
                handler.map_value_at(y+1, x)
               );
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::hit_test_right(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y-1, x+1
        // @ #  y,   x+1
        return (
                handler.map_value_at(y-1, x+1)
                ||
                handler.map_value_at(y, x+1)
               );
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::cut_down(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        // @ @
        // @ #
        return handler.cut_down(2,
                handler.get_key_point_y() );
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::redraw_tetris(
        tetris_handler & handler,
        int value)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @
        // @ #
        handler.set_map_value_at(y-1, x-1, value);
        handler.set_map_value_at(y-1, x, value);
        handler.set_map_value_at(y, x-1, value);
        handler.set_map_value_at(y, x, value);

        return 0;
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}

int tetris_X::set_next_status(
        tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        return 0;
    }

    cerr << "tetris_X hasn't the status: "
        << status
        << endl;

    return -1;
}
