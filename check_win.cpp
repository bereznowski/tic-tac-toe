#include "board_t.h"

bool check_win(board_t currentboard[3][3])
{
    if(currentboard[0][0] != board_t::empty && currentboard[0][0] == currentboard[0][1] && currentboard[0][0] == currentboard[0][2] ||
       currentboard[1][0] != board_t::empty && currentboard[1][0] == currentboard[1][1] && currentboard[1][0] == currentboard[1][2] || \
       currentboard[2][0] != board_t::empty && currentboard[2][0] == currentboard[2][1] && currentboard[2][0] == currentboard[2][2] || \
       currentboard[0][0] != board_t::empty && currentboard[0][0] == currentboard[1][0] && currentboard[0][0] == currentboard[2][0] || \
       currentboard[0][1] != board_t::empty && currentboard[0][1] == currentboard[1][1] && currentboard[0][1] == currentboard[2][1] || \
       currentboard[0][2] != board_t::empty && currentboard[0][2] == currentboard[1][2] && currentboard[0][2] == currentboard[2][2] || \
       currentboard[0][0] != board_t::empty && currentboard[0][0] == currentboard[1][1] && currentboard[0][0] == currentboard[2][2] || \
       currentboard[0][2] != board_t::empty && currentboard[0][2] == currentboard[1][1] && currentboard[0][2] == currentboard[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
}