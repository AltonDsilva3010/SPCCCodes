%{
#include <stdio.h>
int operand = 0, operator = 0;
%}

%%
[\+\-\*\/^] {operator++;}
[0-9A-Za-z] {operand++;}
%%

int yywrap(){
return 1;
}

int main()
{
printf("Enter String: ");
yylex();
printf("Number of operators is: %d \n", operator);
printf("Number of operands is: %d \n", operand);

}

