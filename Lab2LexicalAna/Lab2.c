#include <stdio.h>
#include <string.h>
#include <ctype.h>

enum TokenType {
    SYMBOL,
    KEYWORD,
    LITERAL,
    IDENTIFIER,
    OPERATOR,
    CONSTANT
};

const char *keywords[] ={
    "int","float","char","if","else"
};

const int num_keywords = sizeof(keywords)/sizeof(keywords[0]); //length of keywords


enum TokenType get_token_type(const char *token){
    int i; 
    //Check if keyword
    for(i = 0; i< num_keywords;i++){
       if(strcmp(token,keywords[i]) == 0){
        printf("KEYWORD: %s\n",token);
        return KEYWORD;
       }
    }

    //Check if identifier
    if(isalpha(token[0])){
        printf("IDENTIFIER: %s\n",token);
        return IDENTIFIER;
    }

    //Check if constant
    if(isdigit(token[0])){
        for(i=1;token[i];i++){
            if(!isdigit(token[i])){
                break;
            }
        }
        printf("CONSTANT:%s\n",token);
        return CONSTANT;
    }

    //Check if OPERATOR
    if(strchr("+-*/%=<>!",token[0]) != NULL){
        printf("OPERATOR:%s\n",token);
        return OPERATOR;
    }

    //Check if SYMBOL
    if(strchr("{}();,",token[0])!= NULL){
        printf("SYMBOL:%s\n",token);
        return SYMBOL;
    }

    if(!isdigit(token[i]) && (i != 0 || token[i] != '-'|| token[i] != "' '")){
        printf("LITERAL:%s\n",token);
        return LITERAL;
    }


}


int main(){
    char filename[] = "INPUT.txt";
    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("Error reading file");
        return 1;
    }
    char buffer[1024];
    while(fgets(buffer,sizeof(buffer),file)){
        char *token = strtok(buffer, " \t\n");
        while(token != NULL){
            get_token_type(token);
            // printf("%s\n",token);
            token = strtok(NULL," \t\n");
        }
    }

    fclose(file);
    return 0;
}