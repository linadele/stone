#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define  STONE    0
#define  SCISSORS 1
#define  CLOTH    2
#define  USERWIN  0
#define  USERDRAW 1
#define  USERLOSE 2

int numplay;
int numwin;
int numdraw;
int numlose;


int isplayagain(void)
{
  char line[128];
  printf("还玩吗？\n");
  printf("不玩了请输入no,继续玩按任意键: ");
  fgets(line,127,stdin);
  fgets(line,127,stdin);
  if(strcmp(line,"no\n")==0) return 0;
  else return 1;
}


int getcomputermove(void)
{
  return rand()%3;
}

int getusermove(void)
{
  int um;
  int count;
  char line[128];
  do{
    printf("该你了！请输入0代表石头，1代表剪刀，2代表布： ");
    count=scanf("%d",&um);
    if(count==0) fgets(line,127,stdin);
  }while(count!=1||um<0||um>2);
  return um;
}

void printmove(int cm,int um)
{
  char moves[][10]={"石头","剪刀","布"};
  printf("computer: %s VS user: %s\n",moves[cm],moves[um]);
}

int judge(int cm,int um)
{
  if(cm == um) return USERDRAW;
  else if(cm ==STONE&&um == SCISSORS
        ||cm == SCISSORS&&um == CLOTH
	||cm == CLOTH&&um == STONE) return USERLOSE;
  else return USERWIN;
}

void printresult(int r)
{
  if(r==USERWIN) printf("You win!\n");
  else if(r==USERDRAW) printf("Draw!\n");
  else printf("Sorry,you lose.\n");
}

void playonetime(void)
{
  int cmove,umove;
  int result;
  
  
  numplay++;
  printf("第%d轮开始了!\n",numplay);

  cmove = getcomputermove();
  umove = getusermove();
  printmove(cmove,umove);
  result = judge(cmove,umove);
  printresult(result);
  if(result == USERWIN) numwin++;
  else if(result ==USERDRAW) numdraw++;
  else numlose++;
}

void printscores(void)
{
  printf("numplay = %d,numwin = %d, numdraw = %d,numlose = %d.\n",
	 numplay,numwin,numdraw,numlose);
}


int main(void)
{
  srand((unsigned int)time(NULL));
  printf("欢迎来玩石头！剪刀！布！！！\n");
  numplay=0;
  numwin=0;
  numdraw=0;
  numlose=0;
  
  do {
     playonetime();
  } while(isplayagain());
  printscores();
  printf("Goodbye!\n");
  return 0;
}
