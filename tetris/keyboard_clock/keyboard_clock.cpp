#include "keyboard_clock.h"

void keyboard_clock::_clock_on()
{
    struct termios ntermios;

    if(-1 == tcgetattr(0, &m_termios) )
    {
        perror("tcgetattr");
        exit(-1);
    }

    ntermios = m_termios;
    ntermios.c_lflag &= ~ECHO;
    ntermios.c_lflag &= ~ICANON;
    ntermios.c_cc[VMIN] = 0;
    ntermios.c_cc[VTIME] = 0;

    if(-1 == tcsetattr(0, TCSANOW, &ntermios) )
    {
        perror("tcsetattr");
        exit(-1);
    }
}

void keyboard_clock::_clock_off()
{
    if(-1 == tcsetattr(0, TCSANOW, &m_termios) )
    {
        perror("tcsetattr");

        exit(-1);
    }
}
