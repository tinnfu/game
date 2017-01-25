#include "tetris.h"

///////////////////////////////////////////////////////////
// class tetris_Z_M_0
//   @ @    y-1, x-1
// @ #      y,   x-1 -1
int tetris_Z_M_0::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        return handler.update_map_top_line(
            handler.get_key_point_y() - 1);
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;

        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.update_map_top_line();
}

int tetris_Z_M_0::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    y-1, x-1
        // @ #
        //   @  y+1, x
        return (
            handler.map_value_at(y-1, x-1)
            ||
            handler.map_value_at(y+1, x)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.hit_test_transfer();
}

int tetris_Z_M_0::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //   @ @    y-1, x-1
        // @ #      y,   x-1 -1
        return (
            handler.map_value_at(y-1, x-1)
            ||
            handler.map_value_at(y, x-2)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.hit_test_left();
}

int tetris_Z_M_0::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //   @ @    y,   x+1
        // @ #      y+1, x-1 | y+1, x
        return (
            handler.map_value_at(y, x+1)
            ||
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y+1, x)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.hit_test_down();
}

int tetris_Z_M_0::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //   @ @    y-1, x+1 +1
        // @ #      y,   x+1
        return (
            handler.map_value_at(y-1, x+2)
            ||
            handler.map_value_at(y, x+1)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.hit_test_right();
}

int tetris_Z_M_0::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        //   @ @
        // @ #
        return handler.cut_down(2,
            handler.get_key_point_y() );
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.cut_down();
}

int tetris_Z_M_0::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //   @ @
        // @ #
        handler.set_map_value_at(y-1, x, value);
        handler.set_map_value_at(y-1, x+1, value);
        handler.set_map_value_at(y, x, value);
        handler.set_map_value_at(y, x-1, value);

        return 0;
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.redraw_tetris(value);
}

int tetris_Z_M_0::set_next_status(
            tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        handler.set_status(1);
        return 0;
    }

    if(status < 0)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_1);
    return handler.set_next_status();
}

///////////////////////////////////////////////////////////
// class tetris_Z_M_1
//  @
//  @ #
//    @ 
int tetris_Z_M_1::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        return handler.update_map_top_line(
            handler.get_key_point_y() - 1);
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;

        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.update_map_top_line();
}

int tetris_Z_M_1::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //    @ @   y-1, x | y-1, x+1
        //  @ #
        return (
            handler.map_value_at(y-1, x)
            ||
            handler.map_value_at(y-1, x+1)
                );
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.hit_test_transfer();
}

int tetris_Z_M_1::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //  @    y-1, x-1 -1
        //  @ #  y,   x-1 -1
        //    @  y+1, x-1
        return (
            handler.map_value_at(y-1, x-2)
            ||
            handler.map_value_at(y, x-2)
            ||
            handler.map_value_at(y+1, x-1)
                );
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.hit_test_left();
}

int tetris_Z_M_1::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //  @    
        //  @ #  y+1,    x-1
        //    @  y+1 +1, x
        return (
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y+2, x)
                );
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.hit_test_down();
}

int tetris_Z_M_1::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //  @    y-1, x
        //  @ #  y,   x+1
        //    @  y+1, x+1
        return (
            handler.map_value_at(y-1, x)
            ||
            handler.map_value_at(y, x+1)
            ||
            handler.map_value_at(y+1, x+1)
                );
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.hit_test_right();
}

int tetris_Z_M_1::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        //  @
        //  @ #
        //    @
        return handler.cut_down(3,
            handler.get_key_point_y()+1 );
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.cut_down();
}

int tetris_Z_M_1::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //  @
        //  @ #
        //    @
        handler.set_map_value_at(y-1, x-1, value);
        handler.set_map_value_at(y, x-1, value);
        handler.set_map_value_at(y, x, value);
        handler.set_map_value_at(y+1, x, value);

        return 0;
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.redraw_tetris(value);
}

int tetris_Z_M_1::set_next_status(
            tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        handler.set_status(0);
        return 0;
    }

    if(status > 1)
    {
        cerr << "tetris_Z_M hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_Z_M_0);
    return handler.set_next_status();
}
