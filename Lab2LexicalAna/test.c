#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *keywords[] = {
    "int","else","float","if","char"
};

int lengthkeywords = sizeof(keywords)/sizeof(keywords[0]);

int get_token_type(char *token){
    int i;
    //check if keyword
    for(i = 0;i < lengthkeywords;i++){
       if(strcmp(token,keywords[i]) ==0){
           printf("KEYWORD:%s\n",token);
           return;
       }
    }
    //check if identifier
    if(isalpha(token[0]) || strchr("$",token[0])!= NULL){
        printf("IDENTIFIER:%s\n",token);
        return;
    }
    //check if constant
    if(isdigit(token[0])){
        printf("CONSTANT:%s\n",token);
        return;
    }
    //check if operator
    if(strchr("+-*/=%<>!",token[0])!=NULL){
        printf("OPERATOR:%s\n",token);
        return;
    }
    //check if specialsymbol
    if(strchr("{}(),;",token[0])!=NULL){
        printf("SPECIALSYMBOL:%s\n",token);
        return;
    }
    //check if literal
    printf("LITERAL:%s\n",token);
        return;
}

int main(){
    FILE *file = fopen("INPUT.txt","r");
    if(file ==NULL){
        printf("Error reading the file");
        return 1;
    }
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),file)){
        char *token = strtok(buffer," ");
        while(token != NULL){
            // printf("%s\n",token);
            get_token_type(token);
            token = strtok(NULL," \n");
        }
    }
   
    return 0;
}