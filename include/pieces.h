#ifndef _PIECES_H
#define _PIECES_H
#include <stdio.h>
#include <stdlib.h>

enum PIECE_TYPE {
    PAWN = 1,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

enum PIECE_COLOR {
    PIECE_WHITE,
    PIECE_BLACK = 6
};

typedef struct Piece {
    enum PIECE_TYPE type;
    enum PIECE_COLOR color;
    int tile_x;
}Piece;

Piece pieces[12];

Piece *get_piece(int id);
void init();

void set_position(Piece *piece, int x, int y);

#endif