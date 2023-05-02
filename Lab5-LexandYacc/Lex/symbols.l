%{
#include <stdio.h>
int identifier = 0, keyword = 0, newLine = 0, space = 0, sp_sym = 0;
%}

%%
[;] {sp_sym++;}
[(int)(float)(double)(for)(if)] {keyword++;}
[ ] {space++;}
[\n] {newLine++;}
[_a-zA-Z][0-9A-Za-z]* {identifier++;}

%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter String: ");
yylex();
printf("Number of identifiers is: %d\n", identifier);
printf("Number of keywords is: %d\n", keyword);
printf("Number of spaces is: %d\n", space);
printf("Number of new line characters is: %d\n", newLine);
printf("Number of speacial symbols is: %d\n", sp_sym);
}
