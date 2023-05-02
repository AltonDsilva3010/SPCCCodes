%{
#include<stdio.h>
int p_i = 0, p_f = 0, n_i = 0, n_f = 0;
%}

%%
[-][0-9]+ {n_i++;}
[-][0-9]+\.[0-9]+ {n_f++;}
[+]?[0-9] {p_i++;}
[+]?[0-9]\.[0-9]+ {p_f++;}
%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter number: ");
yylex();
printf("Number of positive integers: %d \n", p_i);
printf("Number of positive floating numbers: %d \n", p_f);
printf("Number of negative integers: %d \n", n_i);
printf("Number of negative floating numbers: %d \n", n_f);
}
