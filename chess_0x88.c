#include <stdio.h>

// piece encoding
enum {e, P, N, B, R, Q, K, p, n, b, r, q, k, o};

// ascii pieces
char ascii_pieces[] = ".PNBRQKpnbrqk";

// unicode pieces
char *unicode_pieces[] = {".", "♙", "♘", "♗", "♖", "♕", "♔", "♟", "♞", "♝", "♜", "♛", "♚"};

// chess board representation
int board[128] = {
    r, n, b, q, k, b, n, r,  o, o, o, o, o, o, o, o,
    p, p, p, p, p, p, p, p,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    e, e, e, e, e, e, e, e,  o, o, o, o, o, o, o, o,
    P, P, P, P, P, P, P, P,  o, o, o, o, o, o, o, o,
    R, N, B, Q, K, B, N, R,  o, o, o, o, o, o, o, o
};

// print board
void print_board() {
    
    printf("\n");
    // loop over board ranks
    for(int rank = 0; rank < 8; rank++) {
        for(int file = 0; file < 16; file++) {
            // init square
            int square = rank * 16 + file;

            // print ranks
            if (file == 0) 
                printf("%d ",  8 - rank);

            // if square is on board
            if ((square & 0x88) == 0) 
                printf("%c ", ascii_pieces[board[square]]);
                // printf("%s ", unicode_pieces[board[square]]);
        }
        printf("\n"); // print new line for every rank
    }

    // print files
    printf("\n  a b c d e f g h\n\n"); 
}

int main() {

    print_board();

    return 0;
}