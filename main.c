#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void UDDA();
void ihop();
void addNr();
void sortBird();
void konto();
void reg();
void login();

void main(){


    //UDDA();
    //ihop();
    //addNr();
    //sortBird();
    konto();
}

void konto(){


    while(true){

        int choice = 0;

        GetInputInt("1. LOGIN\n2. NEW ACCOUNT\n", &choice);
        
        if(choice == 1){
            printf("LOGIN\n");
            login();
        }
        else if(choice == 2){
            printf("----NEW ACCOUNT-----\n");
            reg();
        }
        else 
            break;
    }
}

void login(){

    FILE *fResult = fopen("account.txt", "r");

    if(fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(fResult);
        return;
    }

    char username[250] = "";
    char password[250] = "";
    char line[250] = "";

    GetInput("Enter username: ", username, sizeof(username));
    GetInput("Enter password: ", password, sizeof(password));

    fgets(line,250,fResult); //READ FIRST LINE -> USERNAME

    int lastChar = strlen(line);
    line[lastChar-1] = '\0';
        
    if(strcmp(line, username) == 0){
        printf("USERNAME CORRECT\n");
    }
    else
        printf("USERNAME NOT CORRECT\n");

    fgets(line,250,fResult); //READ SECOND LINE -> PASS

    if(strcmp(line, password) == 0){
        printf("PASSWORD CORRECT\n");
    }
    else
        printf("PASSWORD NOT CORRECT\n");
    

    fclose(fResult);
}


void reg(){

    FILE *fResult = fopen("account.txt", "w");
    if(fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(fResult);
        return;
    }

    char username[250] =  "";
    char password[250] = "";

    GetInput("Enter username: ", username, sizeof(username));
    GetInput("Enter password: ", password, sizeof(password));
    
    fputs(username,fResult);
    fprintf(fResult, "\n"); 
    //fputs("\n", fResult);
    fputs(password,fResult);

    fclose(fResult);
}


void sortBird(){

    FILE *fResult = fopen("alpabirds.txt", "w");
    FILE *f1 = fopen("birds.txt", "r");

    if(f1 == NULL  || fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f1);
        fclose(fResult);
        return;
   }

    char line[250];
    char toSort[250] = "";
   
    while(fgets(line,250,f1)){
        
        if(line[0] != '\n' )
            strcat(toSort,line);      
    }

    fputs(toSort,fResult);
    fclose(f1);
    fclose(fResult);

}



void addNr(){

    FILE *fResult = fopen("resultat2.txt", "w");
    FILE *f1=fopen("namn.txt", "r");

     if(f1 == NULL  || fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f1);
        fclose(fResult);
        return;
   }

   char line[250];
   int row = 1;

   while(fgets(line,250,f1)){
        
        fprintf(fResult, "%d ", row); 
        fputs(line,fResult);
        row++;
    }

    fclose(f1);
    fclose(fResult);
}


void ihop(){

    FILE *fResult = fopen("resultat.txt", "w");
    FILE *f1=fopen("namn.txt", "r");
    FILE *f2=fopen("namn2.txt", "r");
    if(f1 == NULL  || f2 == NULL || fResult == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(f1);
        fclose(f2);
        fclose(fResult);
        return;
   }
    
    char line[250];
    while(fgets(line,250,f1)){
        fputs(line,fResult);
    }
    fclose(f1);

    fputs("\n", fResult);

    while(fgets(line,250,f2)){
        fputs(line,fResult);
    }
    fclose(f2);

    fclose(fResult);
}

void UDDA(){

    FILE *f = fopen("namn.txt", "r");

    if(f == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        return;
    }

    char line[250];
    bool odd = true;

    while(fgets(line,250,f)){
        line[strcspn(line, "\r\n")] = 0;
        if(odd) printf("%s\n",line);
        odd = !odd;
    }

    fclose(f);
}