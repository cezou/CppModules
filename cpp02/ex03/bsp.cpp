#include "Point.hpp"

// Pour connaitre l'aire d'un triangle.
float area(Point const a, Point const b, Point const c)
{
    float x1 = a.getX().toFloat();
    float y1 = a.getY().toFloat();
    float x2 = b.getX().toFloat();
    float y2 = b.getY().toFloat();
    float x3 = c.getX().toFloat();
    float y3 = c.getY().toFloat();

    return (std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
}

bool is_on_edge(Point const a, Point const b, Point const point)
{
    return (area(a, b, point) == 0);
}

bool is_on_vertex(Point const a, Point const point)
{
    return (point.getX() == a.getX() && point.getY() == a.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    if (is_on_vertex(a, point) || is_on_vertex(b, point) || is_on_vertex(c, point))
        return false;

    if (is_on_edge(a, b, point) || is_on_edge(b, c, point) || is_on_edge(c, a, point))
        return false;

    return (area(a, b, c) == area(point, a, b) + area(point, b, c) + area(point, c, a));
}

void print_graph(Point const a, Point const b, Point const c, Point const point)
{
    std::string graph[10];
    for (int i = 0; i < 10; ++i)
    {
        graph[i] = "          ";
    }
    graph[a.getY().toInt()][a.getX().toInt()] = 'a';
    graph[b.getY().toInt()][b.getX().toInt()] = 'b';
    graph[c.getY().toInt()][c.getX().toInt()] = 'c';
    graph[point.getY().toInt()][point.getX().toInt()] = 'P';

    std::cout << "  0 2 4 6 8 10" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << " " << graph[i] << std::endl;
    }
}