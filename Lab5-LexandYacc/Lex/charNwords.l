%{
#include <stdio.h>
int chars = 0, word = 0, newLine = 0, space = 0;
%}

%%
[a-zA-Z]{1} {chars++;}
[a-zA-Z]{2,} {word++;}
[ ] {space++;}
[\n] {newLine++;}

%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter String: ");
yylex();
printf("Number of characters is: %d\n", chars);
printf("Number of words is: %d\n", word);
printf("Number of spaces is: %d\n", space);
printf("Number of new line characters is: %d\n", newLine);

}
