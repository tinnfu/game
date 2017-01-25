#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream>

using namespace std;

class keyboard_clock
{
public:
    keyboard_clock()
    {
        _clock_on();
    }

    ~keyboard_clock()
    {
        _clock_off();
    }

private:
    void _clock_on();
    void _clock_off();

private:
    struct termios m_termios;
};

#endif
