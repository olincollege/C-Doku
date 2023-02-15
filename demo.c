
//Test general game function
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
const int answer[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
int board[3][3];
int moves = 0;
int mistakes = 0;

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();

int main()
{   
      resetBoard();
      printBoard();
      while(checkFreeSpaces() != 0)
      {
         playerMove();
         printBoard();
      }
      printf("Congrats you win with %d moves and %d mistakes.\n", moves, mistakes);
      return 0;
}

void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = 0;
      }
   }
}
void printBoard()
{
   printf(" %d | %d | %d ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %d | %d | %d ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %d | %d | %d ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != 0)
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}
void playerMove()
{
   int x;
   int y;
   int n;

   do
   {
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;
      printf("Enter number #(1-9): ");
      scanf("%d", &n);
      if(board[x][y]  != 0)
      {
         printf("Invalid move!\n");
      }
      if(answer[x][y] != n) 
      {
        mistakes++;
        printf("Incorrect move! You have %d mistakes.\n", mistakes);
      } else {
         board[x][y] = n;
         moves++;
         printf("Correct move! You made %d moves.\n", moves);
         break;
      }
   } while (board[x][y] != 0);
   
}


