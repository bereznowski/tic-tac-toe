#include <curses.h>

void choose_square(int *py, int *px, int *prow, int *pcol, int *pkey)
{
    switch (*pkey)
    {
        case KEY_UP:
            if(*py > 0)
            {
                *py = *py - 2;
                *prow = *prow - 1;
            }
            break;
        
        case KEY_DOWN:
            if(*py < 4)
            {
                *py = *py + 2;
                *prow = *prow + 1;
            }
            break;

        case KEY_LEFT:
            if(*px > 1)
            {
                *px = *px - 4;
                *pcol = *pcol - 1;
            }
            break;

        case KEY_RIGHT:
            if(*px < 9) {
                *px = *px + 4;
                *pcol = *pcol + 1;
            }
            break;       
    }
}