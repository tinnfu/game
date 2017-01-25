#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>

#include <iostream>

#include "keyboard_clock/keyboard_clock.h"
#include "tetris/tetris.h"
#include "tetris_ui/tetris_ui.h"
#include "array_2D.h"
#include "timer.h"

using namespace std;

void goto_xy(int x, int y)
{
    if(x < 0 || y < 0)
    {
        cerr << "goto_xy: "
            << "( " << x << ", " << y << " )"
            << " : error point."
            << endl;
        return ;
    }

    char str[20] = {0};
    sprintf(str, "\033[%d;%dH", y, x);

    cout << str;
    cout.flush();
}

void clear_screen()
{
    cout << "\033[1;1H\033[2J";
    cout.flush();
}

void show_game_tetris(int x, int y,
                const tetris_ui & ui)
{
    int i = 0;
    int j = 0;
    int tetris_rows = ui.get_tetris_rows();
    int tetris_cols = ui.get_tetris_cols();

    for(i = 0; i < tetris_rows; ++i)
    {
        goto_xy(x, y+i);

        for(j = 0; j < tetris_cols; ++j)
        {
            cout <<
                (ui(i, j) > 0 ? '*' : ' ')
                << " ";
            cout.flush();
        }
    }
}

void show_game_map(int x, int y,
    const array_2D<int> & _map)
{
    int i = 0;
    int j = 0;
    int map_rows = _map.get_rows();
    int map_cols = _map.get_cols();

    for(i= 0; i < map_rows; ++i)
    {
        goto_xy(x, y+i);

        for(j = 0; j < map_cols; ++j)
        {
            cout <<
                (_map.value_at(i, j) > 0 ? '*' : ' ')
                << ' ';
            cout.flush();
        }
    }
}

struct game_info
{
    int coins;
    int pause_flg;
    int quit_flg;
    int over_flg;
};

void show_game_info(int x, int y,
                const game_info & g_info)
{
    goto_xy(x, y);
    cout << g_info.coins << " coins"; 
    cout.flush();

    goto_xy(x, y+1);
    cout << (g_info.pause_flg ?
                "pause ..." : 
                "         ");
    cout.flush();

    if(g_info.quit_flg)
    {
        goto_xy(x, y+1);
        cout << "bye-bye. &caft. ^!~.";
        cout.flush();
    }
    else if(g_info.over_flg)
    {
        goto_xy(x, y+1);
        cout << "game over.";
        cout.flush();
    }
}

void show_game( const tetris_controler & game,
                        const tetris_ui & ui,
                    const game_info & g_info)
{
    int map_rows = game.get_map().get_rows();
    int map_cols = game.get_map().get_cols();
    int tetris_cols = ui.get_tetris_cols();
    int x = 0;
    int y = 0;
    struct winsize size = {0};

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    x = (size.ws_col - 2*map_cols - 2*tetris_cols - 2) >> 1;
    y = (size.ws_row - map_rows + 2) >> 1;

    show_game_map( x, y, game.get_map() );
    show_game_tetris( x + 2*map_cols + 2, y, ui );
    show_game_info( x + 2*map_cols + 2,
                y + tetris_cols, g_info );

    goto_xy(0, y + 2*map_rows + 1);
}

void dispatch(tetris_controler & diamonds, int cmd)
{
    switch(cmd)
    {
        case 'i':// transfer
            diamonds.transfer();
            break;

        case 'j':// move left
            diamonds.move_left();
            break;

        case 'k':// move down
            diamonds.move_down();
            break;

        case 'l':// move right
            diamonds.move_right();
            break;

        default:
            // ignoring...
            break;
    }
}

void run(tetris_controler & controler)
{
    int tag = 0;
    char cmd = 0;
    game_info g_info = {0};

    tetris_ui ui(8,8);

    ui.set_shap_status(
        controler.get_next_shap(),
        controler.get_next_status() );

    clear_screen();

    while( 1 )
    {
        show_game(controler, ui, g_info);

        TIMER_DELAY(250);

        cmd = 0;
        read(0, &cmd, 1);
        tcflush(0, TCIFLUSH);

        if('p' == cmd)
        {
            g_info.pause_flg = !g_info.pause_flg;
        }
        else if('q' == cmd)
        {
            g_info.quit_flg = 1;
            show_game(controler, ui, g_info);
            break;
        }

        if(g_info.pause_flg)
        {
            show_game(controler, ui, g_info);

            continue;
        }
        else if( 0 != cmd )
        {
            dispatch(controler, cmd);

            show_game(controler, ui, g_info);
        }

        tag = !tag;

        if(tag)
        {
            continue;
        }

        if(  0 != controler.move_down() )
        {
            g_info.coins += controler.cut_down();

            if(controler.game_over())
            {
                g_info.over_flg = 1;
                show_game(controler, ui, g_info);
                break;
            }

            controler.set_next_tetris();

            ui.set_shap_status(
                controler.get_next_shap(),
                controler.get_next_status() );
        }
    }
}

int main()
{
    tetris_controler controler;

    keyboard_clock clock;

    run(controler);

    return 0;
}
