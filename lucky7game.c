#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int getDiceRoll(int diceRollType) {
 
int number;
scanf("%d",&number);
 
    return number;
}
 
int getPlayerChoice() {
 
int choice,r;
scanf("%d",&choice);
if(choice==1)
r=1;
else if(choice==2)
r=2;
else if(choice==3)
r=3;
    return r;
}
 
int getPlayerBetInput(int playerNumber, int currentCoins) {
 
int pbet;
scanf("%d",&pbet);
 
    if(pbet>currentCoins)
    {
      while(pbet>currentCoins)
      {
        printf("Player%d InvalidBet : %d CoinsLeft : %d\n",playerNumber,pbet,currentCoins);
    scanf("%d",&pbet);
      } 
    }
    return pbet;
}
 
int playBet(int coins, int choice, int bet, int roll) {
 
if(choice==1)
    {
        if(roll<7)
        {
          coins=coins+bet;
        }
        else
        coins=coins-bet;
    }
     if(choice==2)
    {
        if(roll==7)
        {
          coins=coins+(2*bet);
        }
        else
        coins=coins-bet;
    }
     if(choice==3)
    {
        if(roll>7)
        {
          coins=coins+bet;
        }
        else
        coins=coins-bet;
    }
 
    return coins;
}
 
void printTurnStats(int player1Coins, int player2Coins, int currentTurn, int finalTurn) {
 
if(finalTurn==0)
    printf("Turn:%d\n",currentTurn);
else if(finalTurn==1)
    printf("Final Stats\n");
printf("Coins Left for Player 1 : %d\n",player1Coins);
printf("Coins Left for Player 2 : %d\n",player2Coins);
    return ;
}
 
void playGame(int diceRollType, int player1Coins, int player2Coins, int maxTurns) {
 
int currentDiceRolls=0;
while(currentDiceRolls<maxTurns && player1Coins!=0 && player2Coins!=0)
{
    int choice1 = getPlayerChoice();
    int bet1 = getPlayerBetInput(1, player1Coins);
    int choice2 = getPlayerChoice();
    int bet2 = getPlayerBetInput(2, player2Coins);
    int roll = getDiceRoll(diceRollType);
    currentDiceRolls++;
    player1Coins = playBet(player1Coins, choice1, bet1, roll);
    player2Coins = playBet(player2Coins, choice2, bet2, roll);    printTurnStats(player1Coins,player2Coins,currentDiceRolls,0);
}
if(currentDiceRolls>=maxTurns || player1Coins==0 || player2Coins==0)
    printTurnStats(player1Coins,player2Coins,currentDiceRolls,1);
findAndPrintWinner(player1Coins, player2Coins);
    return ;
}
 
void findAndPrintWinner(int player1Coins, int player2Coins) {
 
if(player1Coins>player2Coins)
printf("Player1 Won\n");
else if(player1Coins<player2Coins)
printf("Player2 Won\n");
else
printf("Draw\n");
    return ;
}
 
void takeInputAndPlay() {
 
int diceRollType = 0;
int player1Coins = 0;
int player2Coins = 0;
int diceRollsMax = 0;
scanf("%d",&diceRollType);
scanf("%d",&player1Coins);
scanf("%d",&player2Coins);
scanf("%d",&diceRollsMax);
playGame(diceRollType, player1Coins, player2Coins, diceRollsMax);
 
    return ;
}



Program 2 without using functions===================================================
 
#include <stdio.h>
 
int main() {
  //Write your code here. 
 
    int c,p1,p2,t=0,ch1,ch2,c1,c2,d,x=1;
    printf("Dice Roll : 1)Manual 2)Random\n");
    scanf("%d",&c);
    if(c==1)
    {
    printf("Player 1 Initial Coins :\n");
    scanf("%d",&p1);
    printf("Player 1 Initial Coins :\n");
    scanf("%d",&p2);
    printf("Number of Turns: \n");
    scanf("%d",&t);
    while((x<=t) && (p1>0) && (p2>0))
    {
    printf("Enter Player1 choice: 1 (<7), 2 (=7) or 3 (>7) and coins betting [Choice <space> Coins]\n");
    scanf("%d%d",&ch1,&c1);
    if(c1>p1)
    {
      while(c1>p1)
      {
        printf("===>Player1 InvalidBet : %d CoinsLeft : %d\n",c1,p1);
     printf("Enter Player1 choice: 1 (<7), 2 (=7) or 3 (>7) and coins betting [Choice <space> Coins]\n");
    scanf("%d",&c1);
      }
    }
    
    p1=p1-c1;
    printf("Enter Player2 choice: \n");
    scanf("%d%d",&ch2,&c2);
    if(c2>p2)
    {
      while(c2>p2)
      {
        printf("===>Player2 InvalidBet : %d CoinsLeft : %d\n",c2,p2);
    printf("Enter Player1 choice: \n");
    scanf("%d",&c2);
      }
    }
    
    p2=p2-c2;
    printf("Enter Dice Roll :\n");
    scanf("%d",&d);
    printf("Dice Rolled : %d\n",d);
    if(ch1==1)
    {
        if(d<7)
        {
            p1=p1+(2*c1);
        }
        else
        p1=p1;
    }
     if(ch1==2)
    {
        if(d==7)
        {
            p1=p1+(3*c1);
        }
        else
        p1=p1;
    }
     if(ch1==3)
    {
        if(d>7)
        {
            p1=p1+(2*c1);
        }
        else
        p1=p1;
    }
    if(ch2==1)
    {
        if(d<7)
        {
            p2=p2+(2*c2);
        }
        else
        p2=p2;
    }
     if(ch2==2)
    {
        if(d==7)
        {
            p2=p2+(3*c2);
        }
        else
        p2=p2;
    }
     if(ch2==3)
    {
        if(d>7)
        {
            p2=p2+(2*c2);
        }
        else
        p2=p2;
    }
    printf("===>Turn:%d\n",x);
    printf("===>Coins Left for Player 1 : %d\n",p1);
    printf("===>Coins Left for Player 2 : %d\n",p2);
    x++;
    }
    }
    printf("===>Final Stats\n");
    printf("===>Coins Left for Player 1 : %d\n",p1);
    printf("===>Coins Left for Player 2 : %d\n",p2);
    if(p1>p2)
    {
        printf("===>Player1 Won\n");
    }
    else if(p2>p1)
    {
        printf("===>Player2 Won\n");
    }
    else
    printf("===>Draw\n");
 
    return 0;
}
 
