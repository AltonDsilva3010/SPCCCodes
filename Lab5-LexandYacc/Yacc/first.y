%{
/* Definition Section*/
#include<stdio.h>
%}

%token NUMBER ID
//setting the precedence and associativity of operators
%left '+' '-'
%left '*' '/'

/* Rule Section */

%%
E : T { printf("Result = %d\n", $$); return 0; }

T : T '+' T { $$ = $1 + $3; }
| T '-' T { $$ = $1 - $3; }
| T '*' T { $$ = $1 * $3; }
| T '/' T { $$ = $1 / $3; }
| NUMBER { $$ = $1; }

%%

int main()
{
printf("Enter the Expression\n");
yyparse();
}

/* For printing Error Messages */
int yyerror(char* s)
{
prntf("\nExpression is invalid\n")
}
