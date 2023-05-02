#include<stdio.h>
#include<string.h>
#include <ctype.h>

int main(){
   
    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7;
    fp1 = fopen("INPUT.txt","r");
    fp2 = fopen("st.txt","r");
    fp3 = fopen("out.txt","r");
    fp4 = fopen("MOT.txt","r");
    fp5 = fopen("MOT.txt","r");
    fp6 = fopen("BT.txt","w");
    fp7 = fopen("outTable.txt","w");

    char label[10],opcode[10],operand[10],mnemonic[10],MOTlabel[10];
    int locctr = 0;

    fscanf(fp1,"%s %s %s",label,opcode,operand);

    if(strcmp(opcode,"START") == 0){
        fscanf(fp1,"%s %s %s",label,opcode,operand);
    }
    else
    {
        locctr= 0;
    }

    while(strcmp(opcode,"END") !=0){
        fscanf(fp4,"%s",mnemonic);
        fscanf(fp5,"%s",MOTlabel);
        while(strcmp(MOTlabel,opcode)!=0 && strcmp(MOTlabel,"END") !=0){
            
        }

    }

    
    return 0;
}