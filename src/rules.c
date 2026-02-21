#include "rules.h"
#include <raylib.h>

bool check_pawn(int start_x, int start_y, int end_x, int end_y, enum PIECE_COLOR color, int board[]){
    bool ret = true;
    enum PIECE_COLOR opnonent;

    int end_index = end_x + (end_y * 8);

    opnonent = PIECE_BLACK;
    
    if (end_y >= start_y){
        ret = false;
    }
    
    if (start_y - end_y > 1){
        if(start_y == 6 && start_y - end_y < 3){
            if(board[end_index + 8] != 0){
                ret = false;
            }else{
                ret =  true;
            }
        }else{
            ret =  false;
        }
    }

    // Capture piece 
    if(start_x != end_x){
        if(end_x == start_x - 1 || end_x == start_x + 1){
            if(board[end_index] > 5){
                return true;
            }else{
                ret = false;
            }
        }else{
            ret = false;
        }
    }

    if(board[end_index] != 0 ){
        ret = false;
    }
    
    return ret;
}
