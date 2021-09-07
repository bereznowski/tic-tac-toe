#include <curses.h>
#include "board_t.h"

void draw_grid(void);
void choose_square(int *py, int *px, int *prow, int *pcol, int *pkey);
bool check_win(board_t currentboard[3][3]);

int main()
{
    board_t board[3][3] = {{}, {}, {}}; // create a scoring board
    int player; // define an active player
    int y = 2, x = 5; // define a starting position in a grid
    int row = 1, col = 1; // define a starting position in the scoring board
    int key = 0; // define a starting value for a key
    const int key_enter = 10; //define the value for the ENTER key

    // initialize curses

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    clear();

    // draw the grid
    
    draw_grid();

    // simulate a game

    for(int i = 0; i < 9; i++)
    {
        player = i % 2;

        // display the current player

        if(player == 0)
        {
            mvprintw(0, 31, "%c", 'X');
        }
        else
        {
            mvprintw(0, 31, "%c", 'O');
        }

        // let player place a mark

        while(key != key_enter || board[row][col] != board_t::empty)
        {
            // place the cursor on the grid and get input

            move(y, x);
            key = getch();

            if(key != 'q')
            {
                choose_square(&y, &x, &row, &col, &key);
            }
            else
            {
                clear();
                endwin();
                return 0;
            }
        }
        
        // add player's mark to the grid

        if(player == 0)
        {
            mvaddch(y, x, 'X');
        }
        else
        {
            mvaddch(y, x, 'O');
        }

        // add player's mark to the scoring board

        board[row][col] = static_cast<board_t>(player + 1);
        
        // check win

        if(check_win(board))
        {
            mvprintw(6, 15, "Player %i won!", player + 1);
            break;
        }

        // check draw

        if(i == 8)
        {
            mvprintw(6, 15, "Draw!");
            break;
        }
    }
    getch();
    endwin();
    return 0;
}