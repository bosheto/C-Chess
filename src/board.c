#include "board.h"
#include "rules.h"

void setup_standard_board(){
    
    for(int i = 0; i < 8; i ++){
        add_to_board(PAWN, PIECE_WHITE, i, 6);
        add_to_board(PAWN, PIECE_BLACK, i, 1);
    }

    add_to_board(ROOK, PIECE_WHITE, 0, 7);
    add_to_board(ROOK, PIECE_WHITE, 7, 7);
    add_to_board(ROOK, PIECE_BLACK, 0, 0);
    add_to_board(ROOK, PIECE_BLACK, 7, 0);

    add_to_board(KNIGHT, PIECE_WHITE, 1, 7);
    add_to_board(KNIGHT, PIECE_WHITE, 6, 7);
    add_to_board(KNIGHT, PIECE_BLACK, 1, 0);
    add_to_board(KNIGHT, PIECE_BLACK, 6, 0);

    add_to_board(BISHOP, PIECE_WHITE, 2, 7);
    add_to_board(BISHOP, PIECE_WHITE, 5, 7);
    add_to_board(BISHOP, PIECE_BLACK, 2, 0);
    add_to_board(BISHOP, PIECE_BLACK, 5, 0);
    
    add_to_board(QUEEN, PIECE_WHITE, 3, 7);
    add_to_board(QUEEN, PIECE_BLACK, 3, 0);

    add_to_board(KING, PIECE_WHITE, 4, 7);
    add_to_board(KING, PIECE_BLACK, 4, 0);
}

void b_draw(){
    draw_board();
    draw_pieces();
}

void draw_board(){
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            Color color;
            if ((x+y) % 2 == 0){
                color = LIGHTGRAY;
            }else{
                color = DARKGRAY;
            }

            DrawRectangle(x * 100, y * 100, 100, 100, color);
        }
    }
}

void draw_piece(Piece *piece, int x, int y){
    Rectangle rec;
    rec.x = piece->tile_x * 100;
    if(piece->color == PIECE_WHITE){
        rec.y = 0;
    }else{
        rec.y = 100;
    }
    rec.height = 100;
    rec.width = 100;
    Vector2 pos;
    pos.x = x * 100;
    pos.y = y * 100;
    DrawTextureRec(texture, rec, pos, WHITE);
}

void draw_pieces(){
    for(int y = 0; y < 8; y++){
        for(int x = 0; x < 8; x++){
            int i = x + (y * 8);
            if(board[i] != 0){
                Piece *piece = get_piece(board[i]);
                draw_piece(piece, x, y);
            }
        }
    }

}

void click(Vector2 pos){
    int x = (int)((pos.x / 100));
    int y = (int)((pos.y / 100));
    if(!selected){
        select_piece(x, y);
    }else{
        move_piece(x, y);
    }
}

void select_piece(int x, int y){
    int index = x + (y * 8);
    if(board[index] != 0){
        Piece *temp = get_piece(board[index]);
        if (temp->color != side){
            return;
        }
        piece_selected.id = board[index];
        piece_selected.x = x;
        piece_selected.y = y;
        piece_selected.type = temp->type;
        selected = true;
    }
}

void move_piece(int x, int y){
    if(verify_move(x, y)){
        int piece_index = piece_selected.x + (piece_selected.y * 8);
        int new_piece_index = x + (y * 8);
        board[new_piece_index] = board[piece_index];
        board[piece_index] = 0;
        selected = false;
   }else{
        TraceLog(LOG_INFO, "Illegal move!");
   }
}

bool verify_move(int x, int y){
    if(isFriendly(x, y)){
        return false;
    }
    switch (piece_selected.type)
    {
    case PAWN:
        return check_pawn(piece_selected.x, piece_selected.y, x, y, side, board);
        break;
    
    default:
        break;
    }
    return true;
}

bool isFriendly(int x, int y){
    int index = x + (y * 8);
    Piece *temp = get_piece(board[index]);
    if(temp->color == side){
        return true;
    }
    return false;
}

void add_to_board(enum PIECE_TYPE type, enum PIECE_COLOR color, int x, int y){
    // Piece *piece = get_piece(type + color);
    int index = x + (y * 8);
    board[index] = type + color;
}

void b_init(enum PIECE_COLOR player){
    side = player;
    piece_selected.id = -1;
    piece_selected.x = -1;
    piece_selected.y = -1;
    piece_selected.type = -1;
    texture = LoadTexture("Pieces.png");
    init();
    TraceLog(LOG_INFO, "Board class init start");

    for(int y = 0; y < 8; y ++){
        for(int x = 0; x < 8; x++){
            board[y+x] = 0;
        }
    }

    // setup_standard_board();
    add_to_board(PAWN, PIECE_WHITE, 4, 6);

    add_to_board(PAWN, PIECE_BLACK, 3, 5);


    TraceLog(LOG_INFO, "Board class init end");

}

void b_cleanup(){
    UnloadTexture(texture);
}