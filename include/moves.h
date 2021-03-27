#ifndef MOVES_H
#define MOVES_H

#include "simpleboard.h"

struct move{
    int start_index;
    int end_index;
    Board * origin_board;
    move * next_move;
};



#endif