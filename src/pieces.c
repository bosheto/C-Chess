#include "pieces.h"



Piece *get_piece(int id){
    Piece *ret;
    ret = &pieces[id-1];
    return ret;
}

void init(){
    // WHITE
    // PAWN    
    Piece pawn;
    pawn.tile_x = 5;
    pawn.type = PAWN;
    pawn.color = PIECE_WHITE;

    // KNIGHT
    Piece knight;
    knight.tile_x = 3;
    knight.type = KNIGHT;
    knight.color = PIECE_WHITE;

    // BISHOP
    Piece bishop;
    bishop.tile_x = 2;
    bishop.type = BISHOP;
    bishop.color = PIECE_WHITE;

    // ROOK
    Piece rook;
    rook.tile_x = 4;
    rook.type = ROOK;
    rook.color = PIECE_WHITE;

    // QUEEN
    Piece queen;
    queen.tile_x = 1;
    queen.type = QUEEN;
    queen.color = PIECE_WHITE;

    // KING
    Piece king;
    king.tile_x = 0;
    king.type = KING;
    king.color = PIECE_WHITE;

    // BLACK
    // PAWN 
    Piece b_pawn;
    b_pawn.tile_x = 5;
    b_pawn.type = PAWN;
    b_pawn.color = PIECE_BLACK;

    // KNIGHT
    Piece b_knight;
    b_knight.tile_x = 3;
    b_knight.type = KNIGHT;
    b_knight.color = PIECE_BLACK;

    // BISHOP 
    Piece b_bishop;
    b_bishop.tile_x = 2;
    b_bishop.type = BISHOP;
    b_bishop.color = PIECE_BLACK;

    // ROOK
    Piece b_rook;
    b_rook.tile_x = 4;
    b_rook.type = ROOK;
    b_rook.color = PIECE_BLACK;

    // QUEEN
    Piece b_queen;
    b_queen.tile_x = 1;
    b_queen.type = QUEEN;
    b_queen.color = PIECE_BLACK;

    // KING
    Piece b_king;
    b_king.tile_x = 0;
    b_king.type = KING;
    b_king.color = PIECE_BLACK;


    pieces[0] = pawn;
    pieces[1] = knight;
    pieces[2] = bishop;
    pieces[3] = rook;
    pieces[4] = queen;
    pieces[5] = king;
    pieces[6] = b_pawn;
    pieces[7] = b_knight;
    pieces[8] = b_bishop;
    pieces[9] = b_rook;
    pieces[10] = b_queen;
    pieces[11] = b_king;

}

void set_position(Piece *piece, int x, int y){
    if (x < 0 || x > 8 || y < 0 || y > 8){
        printf("Piece position out of range!");
        exit(1);
    }


}