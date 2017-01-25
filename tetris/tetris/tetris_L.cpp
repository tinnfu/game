#include "tetris.h"

///////////////////////////////////////////////////////////
// class tetris_L_0
//  @
//  #
//  @ @
int tetris_L_0::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        return handler.update_map_top_line(
                handler.get_key_point_y() - 1 );
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;

        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.update_map_top_line();
}

int tetris_L_0::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //     @
        // @ # @
        return (
            handler.map_value_at(y, x-1)
            ||
            handler.map_value_at(y, x+1)
            ||
            handler.map_value_at(y-1, x+1)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.hit_test_transfer();
}

int tetris_L_0::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    y-1, x-1
        // #    y  , x-1
        // @ @  y+1, x-1
        return (
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y, x-1)
            ||
            handler.map_value_at(y-1, x-1)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.hit_test_left();
}

int tetris_L_0::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    
        // #    
        // @ @  y+1 +1, x | y+1 +1, x+1
        return (
            handler.map_value_at(y+2, x)
            ||
            handler.map_value_at(y+2, x+1)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.hit_test_down();
}

int tetris_L_0::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    y-1, x+1
        // #    y,   x+1
        // @ @  y+1, x+1 +1
        return (
            handler.map_value_at(y+1, x+2)
            ||
            handler.map_value_at(y, x+1)
            ||
            handler.map_value_at(y-1, x+1)
                );
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.hit_test_right();
}

int tetris_L_0::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(0 == status)
    {
        // @    
        // #   
        // @ @
        return handler.cut_down(3,
            handler.get_key_point_y()+1);
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.cut_down();
}

int tetris_L_0::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(0 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    
        // #   
        // @ @
        handler.set_map_value_at(y+1, x, value);
        handler.set_map_value_at(y+1, x+1, value);
        handler.set_map_value_at(y, x, value);
        handler.set_map_value_at(y-1, x, value);

        return 0;
    }

    if(status < 0)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.redraw_tetris(value);
}

int tetris_L_0::set_next_status(
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
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_1);
    return handler.set_next_status();
}

///////////////////////////////////////////////////////////
// class tetris_L_1
//      @
//  @ # @
int tetris_L_1::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        return handler.update_map_top_line(
                handler.get_key_point_y() - 1);
    }

    handler.set_tetris(new tetris_L_2);
    return handler.update_map_top_line();
}

int tetris_L_1::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y-1, x-1 | y-1, x
        //   #
        //   @  y+1, x
        return (
            handler.map_value_at(y+1, x)
            ||
            handler.map_value_at(y-1, x-1)
            ||
            handler.map_value_at(y-1, x)
                );
    }

    handler.set_tetris(new tetris_L_2);
    return handler.hit_test_transfer();
}

int tetris_L_1::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //     @    y-1, x
        // @ # @    y,   x-1 -1
        return (
            handler.map_value_at(y, x-2)
            ||
            handler.map_value_at(y-1, x)
                );
    }

    handler.set_tetris(new tetris_L_2);
    return handler.hit_test_left();
}

int tetris_L_1::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //     @
        // @ # @    y+1, x-1 | y+1, x | y+1, x+1
        return (
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y+1, x)
            ||
            handler.map_value_at(y+1, x+1)
                );
    }

    handler.set_tetris(new tetris_L_2);
    return handler.hit_test_down();
}

int tetris_L_1::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //     @    y-1, x+1 +1
        // @ # @    y,   x+1 +1
        return (
            handler.map_value_at(y-1, x+2)
            ||
            handler.map_value_at(y, x+2)
                );
    }

    handler.set_tetris(new tetris_L_2);
    return handler.hit_test_right();
}

int tetris_L_1::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        //     @
        // @ # @
        return handler.cut_down(2,
            handler.get_key_point_y() );
    }

    handler.set_tetris(new tetris_L_2);
    return handler.cut_down();
}

int tetris_L_1::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(1 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        //     @
        // @ # @
        handler.set_map_value_at(y,   x-1, value);
        handler.set_map_value_at(y,   x, value);
        handler.set_map_value_at(y,   x+1, value);
        handler.set_map_value_at(y-1, x+1, value);

        return 0;
    }

    handler.set_tetris(new tetris_L_2);
    return handler.redraw_tetris(value);
}

int tetris_L_1::set_next_status(
            tetris_handler & handler)
{
    int status = handler.get_status();
    if(1 == status)
    {
        handler.set_status(2);
        return 0;
    }

    handler.set_tetris(new tetris_L_2);
    return handler.set_next_status();
}

///////////////////////////////////////////////////////////
// class tetris_L_2
//  @ @
//    # 
//    @
int tetris_L_2::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        //  @ @
        //    # 
        //    @
        return handler.update_map_top_line(
                handler.get_key_point_y() - 1);
    }

    handler.set_tetris(new tetris_L_3);
    return handler.update_map_top_line();
}

int tetris_L_2::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ # @
        // @
        return (
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y, x-1)
            ||
            handler.map_value_at(y, x+1)
                );
    }

    handler.set_tetris(new tetris_L_3);
    return handler.hit_test_transfer();
}

int tetris_L_2::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y-1, x-1 -1
        //   #  y,   x-1
        //   @  y+1, x-1
        return (
            handler.map_value_at(y+1, x-1)
            ||
            handler.map_value_at(y, x-1)
            ||
            handler.map_value_at(y-1, x-2)
                );
    }

    handler.set_tetris(new tetris_L_3);
    return handler.hit_test_left();
}

int tetris_L_2::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y,   x-1
        //   #
        //   @  y+1 +1, x
        return (
            handler.map_value_at(y+2, x)
            ||
            handler.map_value_at(y, x-1)
                );
    }

    handler.set_tetris(new tetris_L_3);
    return handler.hit_test_down();
}

int tetris_L_2::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @  y-1, x+1
        //   #  y,   x+1
        //   @  y+1, x+1
        return (
            handler.map_value_at(y+1, x+1)
            ||
            handler.map_value_at(y, x+1)
            ||
            handler.map_value_at(y-1, x+1)
                );
    }

    handler.set_tetris(new tetris_L_3);
    return handler.hit_test_right();
}

int tetris_L_2::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        // @ @
        //   # 
        //   @
        return handler.cut_down(3,
            handler.get_key_point_y()+1 );
    }

    handler.set_tetris(new tetris_L_3);
    return handler.cut_down();
}

int tetris_L_2::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(2 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ @
        //   # 
        //   @
        handler.set_map_value_at(y+1, x, value);
        handler.set_map_value_at(y,   x, value);
        handler.set_map_value_at(y-1, x-1, value);
        handler.set_map_value_at(y-1, x, value);

        return 0;
    }

    handler.set_tetris(new tetris_L_3);
    return handler.redraw_tetris(value);
}

int tetris_L_2::set_next_status(
            tetris_handler & handler)
{
    int status = handler.get_status();
    if(2 == status)
    {
        handler.set_status(3);
        return 0;
    }

    handler.set_tetris(new tetris_L_3);
    return handler.set_next_status();
}

///////////////////////////////////////////////////////////
// class tetris_L_3
// @ #  @
// @
int tetris_L_3::update_map_top_line(
                    tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        // @ # @
        // @
        return handler.update_map_top_line(
                handler.get_key_point_y() );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.update_map_top_line();
}

int tetris_L_3::hit_test_transfer(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @    y-1, x
        // #
        // @ @  y+1, x | y+1, x+1
        return (
            handler.map_value_at(y+1, x)
            ||
            handler.map_value_at(y+1, x+1)
            ||
            handler.map_value_at(y-1, x)
                );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.hit_test_transfer();
}

int tetris_L_3::hit_test_left(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ # @ // y,   x-1 -1
        // @     // y+1, x-1 -1
        return (
            handler.map_value_at(y, x-2)
            ||
            handler.map_value_at(y+1, x-2)
                );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.hit_test_left();
}

int tetris_L_3::hit_test_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ # @ // y+1,    x   | y+1, x+1
        // @     // y+1 +1, x-1
        return (
            handler.map_value_at(y+2, x-1)
            ||
            handler.map_value_at(y+1, x)
            ||
            handler.map_value_at(y+1, x+1)
                );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.hit_test_down();
}

int tetris_L_3::hit_test_right(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ # @ // y,   x+1 +1
        // @     // y+1, x
        return (
            handler.map_value_at(y, x+2)
            ||
            handler.map_value_at(y+1, x)
                );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.hit_test_right();
}

int tetris_L_3::cut_down(
                tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        // @ # @
        // @
        return handler.cut_down(2,
            handler.get_key_point_y()+1 );
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.cut_down();
}

int tetris_L_3::redraw_tetris(
                tetris_handler & handler,
                                int value)
{
    int status = handler.get_status();
    if(3 == status)
    {
        int x = handler.get_key_point_x();
        int y = handler.get_key_point_y();

        // @ # @
        // @
        handler.set_map_value_at(y+1, x-1, value);
        handler.set_map_value_at(y,   x-1, value);
        handler.set_map_value_at(y,   x,   value);
        handler.set_map_value_at(y,   x+1, value);

        return 0;
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.redraw_tetris(value);
}

int tetris_L_3::set_next_status(
            tetris_handler & handler)
{
    int status = handler.get_status();
    if(3 == status)
    {
        handler.set_status(0);
        return 0;
    }

    if(status > 3)
    {
        cerr << "tetris_L hasn't the status: "
            << status
            << endl;
        return -1;
    }

    handler.set_tetris(new tetris_L_0);
    return handler.set_next_status();
}
