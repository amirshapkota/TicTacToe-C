#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//Function for Banner
void 
banner()
{
    printf("\n*****************************************");
    printf("\n*       Author : Amir Shapkota          *");
    printf("\n*   https://www.amirshapkota.com.np     *");
    printf("\n*****************************************\n\n");

}

void
mainMenu()
{
    printf("\n*************** MAIN MENU ***************");
    printf("\n*                                       *");
    printf("\n*              TIC TAC TOE              *");
    printf("\n*       ______            _    _        *");
    printf("\n*      |  __  |    ___    \\ \\/ /        *");
    printf("\n*      | |  | |   |___|    \\  /         *");
    printf("\n*      | |__| |            /  \\         *");
    printf("\n*      |______|           /_/\\_\\        *");
    printf("\n*                 GAME                  *");
    printf("\n*****************************************");
    printf("\n*                                       *");
    printf("\n*           1. PLAY GAME                *");
    printf("\n*           2. HOW TO PLAY              *");
    printf("\n*           3. EXIT GAME                *");
    printf("\n*                                       *");
    printf("\n*****************************************");
}

//Function for Board
void showBoard(
    char board[10]
)
{
    printf("\n __________________________");
    printf("\n|        |        |        |");
    printf("\n|   %c    |   %c    |   %c    |", board[0], board[1], board[2]);
    printf("\n|________|________|________|");
    printf("\n|        |        |        |");
    printf("\n|   %c    |   %c    |   %c    |", board[3], board[4], board[5]);
    printf("\n|________|________|________|");
    printf("\n|        |        |        |");
    printf("\n|   %c    |   %c    |   %c    |", board[6], board[7], board[8]);
    printf("\n|________|________|________|");
}

void
howToPlay(){
    char board[10] = "123456789";
    #ifdef _WIN32
    system("cls");
    #else 
    system("clear");
    #endif
    printf("\n\n\n1. Enter the Choice Number when it's your turn.");
    printf("\n2. The Choice Numbers are as follows:");
    showBoard(board);
}


//Checks Value in Board
bool 
alreadyInBoard(
    int choices[9], 
    int c){
    for (int i = 0; i < 9; i++){
        if (choices[i] == c){
            return true;
        }
    }
    return false;
}

bool checkWin(
    char board[10]
){
    if (
        //Horizontal Win        
        (board[0] == board[1] && board[0] == board[2] && board[0] != '-') || 
        (board[3] == board[4] && board[3] == board[5] && board[3] != '-') ||
        (board[6] == board[7] && board[6] == board[8] && board[6] != '-') ||

        //Vertical Win
        (board[0] == board[3] && board[0] == board[6] && board[0] != '-') || 
        (board[1] == board[4] && board[1] == board[7] && board[1] != '-') ||
        (board[2] == board[5] && board[2] == board[8] && board[2] != '-') || 
        
        //Diagonal Win
        (board[0] == board[4] && board[0] == board[8] && board[0] != '-') ||
        (board[2] == board[4] && board[2] == board[6] && board[2] != '-')
        )
        {
            return true;
        }
    return false;

}

void 
firstToUpperCase(char *string){
    int temp = (int) string[0];

    if (temp > 96 && temp < 123){
        temp = temp - 32;
        string[0] = (char) temp;
    } 
}


void 
gameSystem()
{
    bool wrong = false;
    char board[10];
    char player[2] = {'X', 'O'};
    char players[2][16];
    int previous_choices[9];
    int choice;
    char c;
    do {
        #ifdef _WIN32
        system("cls");
        #else 
        system("clear");
        #endif
        strcpy(board, "---------");
        for (int i = 0; i < 9; i++){
            previous_choices[i] = -1;
        }
        printf("Player 1's Name (X) : ");
        scanf("%s", players[0]);
        printf("Player 2's Name (O) : ");
        scanf("%s", players[1]);
        firstToUpperCase(players[0]);
        firstToUpperCase(players[1]);
        for (int i = 0; i < 9; i++){
            #ifdef _WIN32
            system("cls");
            #else 
            system("clear");
            #endif
            banner(); 
            showBoard(board);
            if (checkWin(board)){
                printf("\n\n%s has Won...!!!!", players[(i - 1) % 2]);
                break;
            }
            if (wrong){
                printf("\n\nInvalid Choice !");
                wrong = false;
            }
            printf("\n\n\n%s's turn, Enter your choice (%c) : ", players[i % 2], player[i % 2]);
            scanf("%d", &choice);

            if (choice > 9 || choice < 0 || alreadyInBoard(previous_choices, choice)){
                wrong = true;
                i--;
                continue;
            }           
            else {
                board[choice - 1] = player[i % 2];
                previous_choices[i] = choice;
            }
        }
        printf("\n\nDo you want to Play Again (Y/N) ? ");
        scanf("%s", &c); 
        
    }while ((int)c != 110 && (int)c != 78);
}

int main(){
    bool invalid = false;
    int c;
    int prompt;
    while (1)
    {
        #ifdef _WIN32
        system("cls");
        #else 
        system("clear");
        #endif
        banner();
        mainMenu();
        if (invalid)
        {
            printf("\n\nInvalid Choice !");
            invalid = false;
        }
        printf("\n\nEnter your Choice (1/2/3) :");
        scanf("%d", &c);
    

        if (c == 1){
            gameSystem();

        }else if (c == 2){
            howToPlay();
            do
            {
                printf("\n\nPress enter to continue ");
                prompt = getchar();
            } while( prompt != '\n' && prompt != EOF );
            getchar();
        }else if (c == 3){
            exit(0);
        }else{
            invalid = true;
        }
    }
    return 0;
}
