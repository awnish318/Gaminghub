#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <iostream> 
#include <cstdlib>
//#include <ncurses.h>
#include <unistd.h>
using namespace std; 

int checkforwin();
void board();
int choose(char,int);
int generaterandomnumber(int);
int greaterfun(char,char );
void tictactoe();
void rps();
void snake();
void print1();
void print2();
//void print3();
//void Draw();
void Input();
void Logic();
int main()
{

    int i,j;
    for(i=0;i<2;i++)
    {
        for(j=0;j<150;j++)
        {
            if(i==0 || j==0)
            {
                printf("^");
            } 
            else if(i%2==0 &&j%2==0)
            {
                printf("^");
            }
             else if(i==1 ||j==149)
            {
                printf("^");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
     printf("\n\n");
    printf(" _____________________________________ \n");
    printf(" |   * * *       * * *    *       *   * * *    *      *     * * *             *       *   *       *  * * *    |\n");
    printf(" |  *          *       *  *       *     *      *      *    *                  *       *   *       *  *     *  | \n");
    printf(" | *           *       *  * *   * *     *      **     *   *                   *       *   *       *  *     *  |   \n");
    printf(" | *           *       *  *  * *  *     *      * *    *   *                   *       *   *       *  *     *  |    \n");
    printf(" | *   * * *   * * * * *  *   *   *     *      *  *   *   *  * * *            * * * * *   *       *  * * *    |   \n");
    printf(" | *        *  *       *  *       *     *      *   *  *   *       *           *       *   *       *  *     *  |    \n");
    printf(" | *        *  *       *  *       *     *      *    * *   *       *           *       *   *       *  *     *  |    \n");
    printf(" | *       *   *       *  *       *     *      *     **    *      *           *       *   *       *  *     *  |   \n");
    printf(" |   * * *     *       *  *       *   * * *    *      *     * * *             *       *    * * * *   * * *    |   \n");
    printf(" |____________________________________|\n");
    printf("\n\n");
     
   
    printf("\n\n");
   for(i=0;i<2;i++)
    {
        for(j=0;j<150;j++)
        {
            if(i==0 || j==0)
            {
                printf("*");
            } 
            else if(i%2==0 &&j%2==0)
            {
                printf("-");
            }
             else if(i==1 ||j==149)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");

    }
    int ch;
    for(;;)
    {
        printf("1.TIC-TAC-TOE\n2.ROCK-PAPER-SCISSOR\n4.EXIT\n");
        printf("ENTER CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: print1();
                    sleep(2);
                    tictactoe();
                    break;
            case 2:  print2();
                     sleep(2);
                     rps();
                    break;
            default: exit(0);           
        }

    }

}
// MAIN ENDS



////  TIC TAC TOE  BEGINS
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
void print1(){
    printf(" * * * * *     *      * * * *       * * * * *      * * *       * * * *      * * * * *     * * * *     * * * *\n");
    printf("     *         *    *                   *        *      *    *                  *       *         *   *      \n");
    printf("     *         *    *                   *       *        *   *                  *       *         *   *      \n");
    printf("     *         *    *                   *       *        *   *                  *       *         *   *      \n");
    printf("     *         *    *                   *       * * * *  *   *                  *       *         *   * * *  \n");
    printf("     *         *    *                   *       *        *   *                  *       *         *   *      \n");
    printf("     *         *    *                   *       *        *   *                  *       *         *   *      \n");
    printf("     *         *    *                   *       *        *   *                  *       *         *   *      \n");
    printf("     *         *      * * * *           *       *        *    * * * *           *         * * * *     * * * *\n");
    printf("\n\n");
    
}

void tictactoe()
{
    int player = 1, i, choice;

    char mark;
    do
    {
        board();  // function to print board
        player = (player % 2) ? 1 : 2;  // logic for switching players

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';    // we are giving X to player1 and O to player2

        int invalidmove=choose(mark,choice);
        if(invalidmove==1){
            player--;
        }
        i = checkforwin();
    
        player++;
    }while (i ==  - 1);
    
    board();
    
    if (i == 1)
        printf("====>>\aPlayer %d win\n ", --player);
    else
        printf("====>>\aGame draw\n");
    
}

int choose(char mark,int choice){
        int flag=0;

        if (choice == 1 && square[1] == '1')
            square[1] = mark;    
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;    
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;    
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;    
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;    
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;    
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;    
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;   
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;   
        else
        {
            printf("Invalid move ");
            flag=1;
        }
    return flag;
 }
int checkforwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;    
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;   
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;    
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;    
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;  
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;   
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;    
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;    
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return  - 1;
}


void board()
{
    system("clear");
    // clear();
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("__|_|__\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("__|_|__\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}
// Tic tac toe ends


//// RPS BEGINS
void print2(){
    printf(" * * *        * * *        * * *    \n");
    printf(" *     *      *     *     *     *   \n");
    printf(" *     *      *      *    *         \n");
    printf(" *     *      *      *    *         \n");
    printf(" * * *        *     *      * * *    \n");
    printf(" *  *         * * *             *   \n");
    printf(" *   *        *                 *   \n");
    printf(" *    *       *                 *   \n");
    printf(" *     *      *            * * *    \n");
    printf("\n\n");

}
int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greaterfun(char c1, char c2)
{
    if (c1 == c2){
        return -1;
    }    
    else if (c1 == 'R' && c2 == 'S')
        return 1;
    else if (c1 == 'S' && c2 == 'R')
        return 0;
    else if (c1 == 'P' && c2 == 'S')
        return 0;
    else if (c1 == 'S' && c2 == 'P')
        return 1;
    else if (c1 == 'R' && c2 == 'P')
        return 1;
    else 
    //(c1 == 'P' && c2 == 'R')
        return 0;
}
void rps()
{
    printf("Welcome to ROCK, PAPER and SCISSOR\n");
    char nm[20];
    printf("Enter you name: ");
    scanf("%s", nm);
    char pchar, compchar;
    int pscore = 0, compscore = 0, temp;
    char dict[] = {'R', 'P', 'S'};
    for (int i = 0; i < 3; i++)
    {
        printf("%s's turn:\n", nm);
        printf("Choose 1.for Rock, 2.for Paper, 3.for Scissor\n");
        scanf("%d", &temp);
        getchar();
        pchar = dict[temp - 1];
        printf("%s chose %c\n", nm, pchar);
        printf("Computer's turn:\n");
        printf("Choose 1.for Rock, 2.for Paper, 3.for Scissor\n");
        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];
        printf("Computer chose %c\n", compchar);
        int checkval=greaterfun(compchar, pchar);
        if (checkval == 1)
        {
            printf("Computer wins this round\n");
            compscore += 1;
        }
        else if (checkval == 0)
        {
            printf("%s wins this round\n", nm);
            pscore += 1;
        }
        else
        {
            printf("This round is drawn\n");
            compscore += 1;
            pscore += 1;
        }
        printf("Current Score is: %s score is: %d   Computer score is: %d\n", nm, pscore, compscore);
    }
    printf("Game Ended\n");
    if (pscore > compscore)
    {
        printf("%s WINS THE GAME!!\n", nm);
    }
    else if (pscore < compscore)
    {
        printf("COMPUTER WINS THE GAME!!\n");
    }
    else
    {
        printf("GAME DRAWN!!\n");
    }
    
}
// RPS ends



// Snake begins
void print3(){
    printf(" * * *    *     *     * * *    *    *  * * * *      * * *      * * *    *       *   * * * *\n");
    printf("*     *   *    *    *     *   *   *   *          *           *     *   *     **   *      \n");
    printf("*         * *   *   *       *  *  *    *         *           *       *  * *   * *   *      \n");
    printf("*         * *   *   *       *  * *     *         *           *       *  *  * *  *   *      \n");
    printf(" * * *    *  *  *   * * * * *  **      * * *     *   * * *   * * * * *  *   *   *   * * *  \n");
    printf("      *   *   * *   *       *  * *     *         *        *  *       *  *       *   *      \n");
    printf("      *   *   * *   *       *  *  *    *         *        *  *       *  *       *   *      \n");
    printf("      *   *    **   *       *  *   *   *          *       *  *       *  *       *   *      \n");
    printf(" * * *    *     *   *       *  *    *  * * * *      * * *    *       *  *       *   * * * *\n");
    printf("\n\n");
}

#define KEY_UP 0403 
#define KEY_DOWN 0402 
#define KEY_LEFT 0404 
#define KEY_RIGHT 0405 
bool gameOver;
const int width = 20, height = 20;
int x, y, FruitX, FruitY, score;
enum eDirection         // this is special data type which enables variables to be set of predefined constants
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

eDirection dir;

int TailX[100], TailY[100];
int nTail = 0;
void Setup()
{
    initscr();   // it creates the first refresh option in terminal
    clear();    // removes all the elements from container


    gameOver = false;
    dir = STOP;
    x = width / 2;//setting the intial head position of snake position(x).
    y = height / 2;//setting the intial head position of snake position(x).

    FruitX = (rand() % width) + 1;
    FruitY = (rand() % height) + 1;

    score = 0;
}

void Draw()
{
    clear();       // used to remove all the elements from the screen
    for (int i = 0; i < width + 2; i++)//this loop is used to draw top boundary with"+"and first is yvalue and then "x"anf then character
        mvprintw(0, i, "+");      // this is a special function which adds morefuncitonality to printf
                                      // this is used to move the cursor and then print the value
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == 21)

                mvprintw(i, j, "+");

            else if (j == 0 || j == 21)

                mvprintw(i, j, "+");

            else if (i == y && j == x)

                mvprintw(i, j, "O");

            else if (i == FruitY && j == FruitX)

                mvprintw(i, j, "Q");

            else
            {
                for (int k = 0; k < nTail; k++)

                {
                    if (TailX[k] == j && TailY[k] == i)

                    {
                        mvprintw(i, j, "o");
                    }
                }
            }
        }
    }
    mvprintw(23, 0, "Score %d", score);
    refresh();  // this refreshes screen continuously in real time
}

void Input()
{
    keypad(stdscr, true);        // this function returns value is the key is pressed
    halfdelay(1);             // this creates delay in movement so that user can play
    int c = getch();
    switch (c)                   // cases for navigation of snake
    {
    case KEY_LEFT:
        dir = LEFT;
        break;

    case KEY_RIGHT:
        dir = RIGHT;
        break;

    case KEY_UP:
        dir = UP;
        break;

    case KEY_DOWN:
        dir = DOWN;
        break;

    case 'Q':        // to quit game
        gameOver = true;
        break;
    }
}

void Logic()
{
    int prevX = TailX[0];//store the first position of tail.
    int prevY = TailY[0];//store the first position of tail.
    int prev2X, prev2Y;
    TailX[0] = x;
    TailY[0] = y;

    for (int i = 1; i < nTail; i++)  // this  loop is for snake structuring and size incrementing
    {
        prev2X = TailX[i];
        prev2Y = TailY[i];
        TailX[i] = prevX;
        TailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x > width || x < 1 || y < 1 || y > height)  // boundary condition to end game

        gameOver = true;

    if (x == FruitX && y == FruitY)
    {
        score++;
        FruitX = (rand() % width) + 1;

        FruitY = (rand() % height) + 1;
        nTail++;                        // size of tail increases after snake eats the fruit
    }

    for (int i = 0; i < nTail; i++)
        if (TailX[i] == x && TailY[i] == y)
        {
            gameOver = true;
        }
}

void snake()
{
    Setup();
    Draw();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    getch();
    endwin();   // this restores the terminal after curses headerfile activity
}