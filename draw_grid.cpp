#include <curses.h>

void draw_grid(void)
{
    // draw vertical lines
    mvhline(0, 3, '|', 1);
    mvhline(0, 7, '|', 1);
    mvhline(2, 3, '|', 1);
    mvhline(2, 7, '|', 1);
    mvhline(4, 3, '|', 1);
    mvhline(4, 7, '|', 1);
    
    // draw horizontal lines
    mvhline(1, 0, '-', 3);
    mvhline(1, 4, '-', 3);
    mvhline(1, 8, '-', 3);
    mvhline(3, 0, '-', 3);
    mvhline(3, 4, '-', 3);
    mvhline(3, 8, '-', 3);
    
    // draw crossing lines
    mvhline(1, 3, '+', 1);
    mvhline(1, 7, '+', 1);
    mvhline(3, 3, '+', 1);
    mvhline(3, 7, '+', 1);
    
    // display additional info
    mvprintw(0, 15, "Current player:");
    mvprintw(2, 15, "Use \"arrows\" to select the spot on the grid");
    mvprintw(3, 15, "Use \"enter\" to place a symbol");
    mvprintw(4, 15, "Use \"q\" to exit the program");
}