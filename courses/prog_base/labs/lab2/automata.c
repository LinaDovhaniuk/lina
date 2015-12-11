#include<math.h>
#include<stdio.h>
#include<stdlib.h>
enum state{EMPTY, BREAK, RETURN, POP, CONTINUE, REPEAT};
int run(int moves[], int movesLen, int res[], int resLen);

int main(){
int moves[] = {106,11,106,7};
int i;
int movesLen = sizeof(moves)/sizeof(int);
int resLen=movesLen, order;
int res[resLen];
order=run(moves, movesLen, res, resLen);
for (i = 0; i < movesLen; i++){
printf("%d ", moves[i]);}
printf("\n");
for (i = 0; i < resLen; i++){
printf("%d ", res[i]);}
printf("\n");
printf("%d ", order);


return 0;
}
int run(int moves[],int movesLen, int res[], int resLen){

int i, j;
for (i = 0; i < resLen; i++)
res[i] = 0;
i=0;
j=0;
int curState=0;
int curMove;
int fault;
int resNumbers=0;
    int arrayFirst[4][4]={{CONTINUE,REPEAT,CONTINUE,777},
                           { 7,     BREAK,  BREAK,  BREAK},
                           { BREAK, POP,     POP,    77},
                            {BREAK,  13,    BREAK,  7777}};
    int arraySecond[4][4]={{0,2,1,3},
                           {2,EMPTY,EMPTY,EMPTY},
                           {EMPTY,3,3,1},
                           {EMPTY,0,EMPTY,0}};


while (1){
        printf("");
switch(moves[j]){
    case 7: curMove = 0; break;
    case 11: curMove = 1;break;
    case 16: curMove = 2; break;
    case 106: curMove= 3; break;
    default : fault = -1;break;
}
if (fault == -1)return resNumbers;
switch (arrayFirst[curState][curMove]){
    case BREAK: return resNumbers;break;
    case POP:
        if (i>0){
            res[i-1] = 0;
            i--;
            j++;
            resNumbers--;
            curState=arraySecond[curState][curMove];
         }
         else return resNumbers;
         break;
        if (fault=1){break;}
    case REPEAT:curState=arraySecond[curState][curMove];break;
    case CONTINUE: j++;curState=arraySecond[curState][curMove];break;
    default:
res[i] = arrayFirst[curState][curMove];
i++;
j++;
resNumbers++;
curState = arraySecond[curState][curMove];
break;
        }
}
return resNumbers;

 }

