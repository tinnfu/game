#ifndef _POINT_H_
#define _POINT_H_

// Point class: base in 2D.
// X is more bigger when point move to right.
// Y is more bigger when point move down.
class point
{
public:
    point(): m_x(0), m_y(0) {}
    point(int x, int y): m_x(x), m_y(y)
    {}

    ~point() {}

public:
    inline void set_x(int x) { m_x = x; }
    inline void set_y(int y) { m_y = y; }
    inline int get_x() const { return m_x; }
    inline int get_y() const { return m_y; }

public:
    inline point & operator=(const point & tp)
    {
        m_x = tp.m_x;
        m_y = tp.m_y;

        return *this;
    }

public:
    inline void x_plus_plus() { ++m_x; }
    inline void x_minus_minus() { --m_x; }
    inline void y_plus_plus() { ++m_y; }

private:
    int m_x;
    int m_y;
};

#endif
