#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_NAME_SIZE 255

void HatONames(FILE *foo);

int main(int argc, char *argv[]) {
    FILE *myFile = fopen(argv[1], "r");
    HatONames(myFile);
}

void HatONames(FILE *foo){
    int i = 0;
    char names[30][MAX_NAME_SIZE];
    char myBuffer[MAX_NAME_SIZE];

    while (fgets(myBuffer, MAX_NAME_SIZE, foo) != NULL){
        strcpy(names[i],myBuffer);
        i++;
    }
    int num;
    time_t t;
    char choice;

    while (i != 0){
        setbuf(stdin, NULL);
        printf(">");
        choice = fgetc(stdin);
        if (choice == 'p')
        {
            srand((unsigned) time(&t));
            num = rand() % i;
            printf("%s", names[num]);
            for (; num < i; ++num) {
                strcpy(names[num], names[num + 1]);
            }
            i--;
        } else
        {
            printf("Opcion invalida\n");
        }
    }

}


