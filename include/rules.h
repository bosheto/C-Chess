#ifndef _RULES_H
#define _RULES_H

#include <stdbool.h>
#include "pieces.h"
#include "hashmap.h"

// bool check_path(int start_x, int start_y, int end_x, int end_y);

int *get_valid_moves(int board[]);

bool check_pawn(int start_x, int start_y, int end_x, int end_y, enum PIECE_COLOR color, int board[]);

#endif 