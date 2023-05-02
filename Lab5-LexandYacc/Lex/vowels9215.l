%{
#include <stdio.h>
int vow = 0;
%}

%%
[aeiouAEIOU] {vow++;}
. ;
%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter String: ");
yylex();
printf("Number of vowels is: %d \n", vow);
}



