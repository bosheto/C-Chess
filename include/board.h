#ifndef _BOARD_H
#define _BOARD_H

#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "pieces.h"
#include "rules.h"

Texture2D texture;

int board[64];
enum PIECE_COLOR side;
bool selected;

typedef struct SELECTED_PIECE{
    int id;
    int x;
    int y;
    enum PIECE_TYPE type;
}SELECTED_PIECE;

SELECTED_PIECE piece_selected;

typedef struct Position {
    int x;
    int y;
}Position; 

void b_init(enum PIECE_COLOR player);
void b_cleanup();

void add_to_board(enum PIECE_TYPE type, enum PIECE_COLOR color, int x, int y);
void move_piece(int new_x, int new_y);

bool verify_move(int x, int y);
bool isFriendly(int x, int y);


void b_draw();
void draw_board();
void draw_pieces();
void draw_piece(Piece *type, int x, int y);

void click(Vector2 pos);
void select_piece(int x, int y);

#endif