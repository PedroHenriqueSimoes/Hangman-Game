/**/
/*Create by Pedro Henrique Simões
/*Criado por Pedro Henrique Simões
/*ATTENTION:
/*=> I'm from another country, so please, if you find an English error, forgive me <=
/*let's program?
/**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void){
    //Random numbers with:
    srand(time(NULL));
    //Declaring functions
    void systemPause();
    int randomChoice();
    int letterInWord(char l, char w[]);
    int repeatedLetter(char l, char aux[]);
    char wordList[12][50] = {"banana",
                             "orange",
                             "apple",
                             "pear",
                             "computer",
                             "cellphone",
                             "television",
                             "videgame",
                             "pig",
                             "turtle",
                             "dog",
                             "cat"};
    
    int choice = 0;
    choice = randomChoice();
    
    char word[50];
    strcpy(word, wordList[choice]);

    char head, body, rarm, larm, rleg, lleg;
    
    char check[50] = {' '};
    char usesLetters[200] = {' '};
    char letter;
    int letterWon = 0, letterLose = 6;
    int append = 0;
    char continuePlay = 'o';
    char theme[50] = {' '};
    while (1 == 1){
        choice = randomChoice();
        if (choice <= 3){
            strcpy(theme, "fruit");
        }
        else if (choice <= 7){
            strcpy(theme, "eletronic");
        }
        else if (choice <= 11){
            strcpy(theme, "animals");
        }


        head = body = rarm = larm = rleg = lleg = ' ';
        strcpy(word, wordList[choice]);

        for (int i = 0; i < strlen(check); i++){
            check[i] = ' ';
        }
        for (int i = 0; i < strlen(usesLetters); i++){
            usesLetters[i] = ' ';
        }

        letterWon = 0;
        letterLose = 6;
     
        while (5 == 5){
            printf("\n==== Theme: %s ====\n", theme);
            printf("___________\n");
            printf("|\t |\n");
            printf("|\t %c\n", head);
            printf("|\t%c%c%c\n", rarm, body, larm);
            printf("|\t%c %c\n\n", rleg, lleg);
            
            for (int i = 0; i < strlen(word); i++){
                printf(" [%c] ", check[i]);
            }

            printf("\nPlease, type one letter: ");
            scanf("%c", &letter);
            setbuf(stdin, NULL);



            if (repeatedLetter(letter, usesLetters) == 1){
                printf("\n\nWoow, that letter are used in the past!\n");
            }
            else{
                usesLetters[append] = letter;
                ++ append;


                
                if (letterInWord(letter, word) == 1){
                    for (int i = 0; i < strlen(word); i++){
                        if (letter == word[i]){
                            ++ letterWon;
                            check[i] = letter;
                        }
                    }
                }
                else {
                    -- letterLose;
                    switch (letterLose)
                    {
                    case 5:
                        head = 'o';
                        break;
                    case 4:
                        body = '|';
                        break;
                    case 3:
                        rarm = '/';
                        break;
                    case 2:
                        larm = '\\';
                        break;
                    case 1:
                        rleg = '/';
                        break;
                    case 0:
                        lleg = '\\';
                        break;
                    default:
                        break;
                    }
                }


            }





            if (letterWon == strlen(word)){
                printf("\n\nYou Won, the word are %s!!!\n\n", word);
                break;
            }
            if (letterLose == 0){
                printf("\n\nYou Lose, the word are %s!!!\n\n", word);
                break;
            }
        }

        continuePlay = 'o';
        while (continuePlay != 'y' && continuePlay != 'n'){
            printf("You wuant play one more time [y/n] >>> ");
            scanf("%c", &continuePlay);
            setbuf(stdin, NULL);
        }

        if (continuePlay == 'n'){
            break;
        }
    }
    systemPause();
    return 0;
}

void systemPause(){
    printf("\npress 'enter'...");
    getch();
}

int randomChoice(){
    int number = 0;
    number = rand() % 12;
    return number;
}

int letterInWord(char l, char w[]){
    for (int i = 0; i < strlen(w); i++){
        if (l == w[i]){
            return 1;
        }
    }
    return 0;
}

int repeatedLetter(char l, char aux[]){
    for (int i = 0; i < strlen(aux); i++){
        if (aux[i] == l){
            return 1;
        }
    }
    return 0;
}
