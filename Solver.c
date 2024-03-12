#include <stdio.h>
#include <stdlib.h>
#define N 9

int SaveMove(int T[N][N] , int row , int col ,int num){
    for(int i=0 ; i<N ; i++){
        if(T[row][i] == num || T[i][col] == num){
            return 0;
        }
    }
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(T[i+row - row % 3][j+col - col % 3] == num){
                return 0;
            }
        }
    }
    return 1;
}

int GetUserInput(int T[N][N]) {
    printf("Enter your Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            do {
                printf("Enter value for cell (%d, %d): ", i + 1, j + 1);
                scanf("%d", &input);

                if (input < 0 || input > 9) {
                    printf("Invalid input. Please enter a number between 0 and 9.\n");
                }
            } while (input < 0 || input > 9);

            T[i][j] = input;
        }
    }
    return 1;
}

int Solver (int T[N][N]){
    for(int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            if(T[i][j] == 0){
                for(int num=1 ; num<=9 ;num++){
                    if(SaveMove(T , i , j , num)){
                        T[i][j]=num;
                        if(Solver(T)){
                            return 1;
                        }else{T[i][j] = 0;}
                    }
                }
            return 0;
            }
        }
    }
    return 1;
}

void Print(int T[N][N]){
    for (int i=0 ; i<N ; i++){
        for(int j=0 ; j<N ; j++){
            printf(" %d " , T[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int T[N][N];

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Enter your Sudoku puzzle\n");
        printf("2. Solve the current puzzle\n");
        printf("3. Quit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                GetUserInput(T);
                printf("Your Sudoku puzzle:\n");
                Print(T);
                break;

            case 2:
                printf("Solving the puzzle...\n");
                if (Solver(T)) {
                    printf("Solution found:\n");
                    Print(T);
                } else {
                    printf("No solution exists.\n");
                }
                break;

            case 3:
                printf("Quitting the program.\n");
                return 0;

            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}