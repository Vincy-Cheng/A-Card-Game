/**
* ENGG1110 Problem Solving by Programming
*
* Course Project
*
* I declare that the project here submitted is original
* except for source material explicitly acknowledged,
* and that the same or closely related material has not been
* previously submitted for another course.
* I also acknowledge that I am aware of University policy and
* regulations on honesty in academic work, and of the disciplinary
* guidelines and procedures applicable to breaches of such
* policy and regulations, as contained in the website.
*
* University Guideline on Academic Honesty:
* https://www.cuhk.edu.hk/policy/academichonesty/
*
* Student Name : Cheng Wing Lam<your name>
* Student ID : 1155125313<your student ID>
* Class/Section : J<your class/section>
* Date : 20190410<date>
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef struct card {
    char suit;   // 'S'pade / 'H'eart / 'C'lub / 'D'iamond
    int  rank;   // A (1) / 2 - 10 / J (11) / Q (12) / K (13);
    int  status; // covered (0) or flipped (1) or chosen (-1), etc.
} TypeCard;/* given TypeCard structure definition */
void printCard( TypeCard   aCard )
{
    if (aCard.status == 0)
        printf("XXX");
    else
    {
        /* display suit of a card */
        switch (aCard.suit) {
            case 'S':
            case 'H':
            case 'C':
            case 'D':
                printf("%c", aCard.suit);
                break;
            default:
                printf("?");
        }
        if(aCard.rank==1)
        {
            printf(" A");
        }
        else if (aCard.rank==11)
        {
            printf(" J");
        }
        else if(aCard.rank==12)
        {
            printf(" Q");
        }
        else if (aCard.rank==13)
        {
            printf(" K");
        }
        else
        {
            printf("%2d",aCard.rank);
        }
    }
    return;
}
void randomdis(TypeCard   desktop[4][14])
{
    int i,j,randomrow,randomcol;
    srand(time(NULL));
    for(i=1;i<14;i++)
    {
        for(j=0;j<4;j++)
        {
            randomrow=(rand()%4);
            randomcol=(rand()%13)+1;
            desktop[0][0]=desktop[j][i];
            desktop[j][i]=desktop[randomrow][randomcol];
            desktop[randomrow][randomcol]=desktop[0][0];
        }
    }
    return;
}
void showDesktop( TypeCard   desktop[4][14] )
{
    /* show all 4 x 13 cards in the desktop 2D TypeCard array */
    int row,col;
    for(row=0;row<4;row++)
    {
        for(col=1;col<14;col++)
        {
            printCard(desktop[row][col]);
            if(col==13)
            {
                printf("\n");
            }
            else
            {
                printf("  ");
            }
        }
    }
}
void ranknumber(TypeCard aCard)
{
    if(aCard.rank==1)
        {
            printf(" A\n");
        }
        else if (aCard.rank==11)
        {
            printf(" J\n");
        }
        else if(aCard.rank==12)
        {
            printf(" Q\n");
        }
        else if (aCard.rank==13)
        {
            printf(" K\n");
        }
        else
        {
            printf("%2d\n",aCard.rank);
        }
}
int main(void)
{
    TypeCard desktop[4][14] = {
        /* the first element (column 0) of each row is UNUSED */
        {{}, {'S', 1}, {'S', 2}, {'S', 3}, {'S', 4}, {'S', 5}, {'S', 6}, {'S', 7}, {'S', 8}, {'S', 9}, {'S', 10, 1 }, {'S', 11}, {'S', 12}, {'S', 13}},
        {{}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9}, {'H', 10, 1 }, {'H', 11}, {'H', 12}, {'H', 13}},
        {{}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9}, {'C', 10, 1 }, {'C', 11}, {'C', 12}, {'C', 13}},
        {{}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9}, {'D', 10, 1 }, {'D', 11}, {'D', 12}, {'D', 13}}
    };
    int row, col,x;
    int player=0,computer=0;
    int a,b,c,d;
    int ca,cb,cc,cd;
    int pwin,cwin;
    int a1,b1,c1,d1;
    int a2,b2,c2,d2;
    int Com1=0,Com2=0;
    int C1win,C2win;
    int round1=0,round2=0;
    for(row=0;row<4;row++)
    {
    for (col = 1; col <= 13; col++)
        desktop[row][col].status = 0;
    }
    printf("*****************************\n");
    printf("* Welcome to Concentration! *\n");
    printf("*****************************\n");
    while(1)
    {
        printf("Please choose a mode of the game:\n");
        printf("1. Human vs. Computer\n");
        printf("2. Computer vs. Computer\n");
        printf("0. Quit\n");
        printf("Your choice:");
        scanf("%d",&x);
        randomdis(desktop);
        if(x==1)
        {
            showDesktop(desktop);
            srand(time(NULL));
            while (1)
            {
                if(cwin==1)
                {
                    showDesktop(desktop);
                    printf("\nFlipped cards: %d; You: %d; Computer: %d;\n\n",player+computer,player,computer);
                    printf("***End of game!***\n");
                    printf("%d turns played\n",round1);
                    if(computer==player)
                    {
                        printf("A tie\n");
                    }
                    else
                    {
                        printf("Computer wins!\n");
                    }
                    break;
                };
                if(pwin==1)
                {
                    showDesktop(desktop);
                    printf("\nFlipped cards: %d; You: %d; Computer: %d;\n\n",player+computer,player,computer);
                    printf("***End of game!***\n");
                    printf("%d turns played\n",round1);
                    if(computer==player)
                    {
                        printf("A tie\n");
                    }
                    else
                    {
                        printf("You win!\n");
                    }
                    break;
                }
                printf("Please input 1st card:");
                scanf("%d%d",&a,&b);
                if(a<0||a>3||b<1||b>13)
                {
                    printf("Row and column must be within 0 - 3 and 1 - 13\n");
                    continue;
                }
                if(desktop[a][b].status == 1)
                {
                    printf("The card must not be flipped\n");
                    continue;
                }
                printf("\nYou chose 1st card (%d, %d) and it is %c",a,b,desktop[a][b].suit);
                ranknumber(desktop[a][b]);
                printf("\n");
                printf("\nPlease input 2nd card:");
                scanf("%d%d",&c,&d);
                if(c<0||c>3||d<1||d>13)
                {
                    printf("Row and column must be within 0 - 3 and 1 - 13\n");
                    continue;
                }
                while(desktop[c][d].status == 1)
                {
                    printf("The card must not be flipped\n");
                    printf("\nPlease input 2nd card:");
                    scanf("%d%d",&c,&d);
                }
                printf("\nYou chose 2nd card (%d, %d) and it is %c",c,d,desktop[c][d].suit);
                ranknumber(desktop[c][d]);
                printf("\n");
                if(desktop[a][b].rank==desktop[c][d].rank&&desktop[a][b].suit==desktop[c][d].suit)
                {
                    printf("The second card cannot be the same as first\n");
                    continue;
                }
                if(desktop[a][b].rank==desktop[c][d].rank)
                {
                    desktop[a][b].status = 1;
                    desktop[c][d].status = 1;
                    printf("You got a matched pair!\n");
                    player+=2;
                    if(player+computer==52)
                {
                    if(player>computer)
                    {
                     pwin=1;
                    }
                    continue;
                }
                }
                showDesktop(desktop);
                round1++;
                printf("\nFlipped cards: %d; You: %d; Computer: %d;\n\n",player+computer,player,computer);
                ca=rand()%4;
                cb=rand()%13+1;
                while(desktop[ca][cb].status == 1)
                {
                    ca=rand()%4;
                    cb=rand()%13+1;;
                }
                printf("\nComputer chose 1st card (%d, %d) and it is %c",ca,cb,desktop[ca][cb].suit);
                ranknumber(desktop[ca][cb]);
                printf("\n");
                cc=rand()%4;
                cd=rand()%13+1;
                while(desktop[cc][cd].status == 1)
                {
                    cc=rand()%4;
                    cd=rand()%13+1;;
                }
                while(ca==cc&&cb==cd)
                {
                    cc=rand()%4;
                    cd=rand()%13+1;
                }
                printf("\nComputer chose 2nd card (%d, %d) and it is %c",cc,cd,desktop[cc][cd].suit);
                ranknumber(desktop[cc][cd]);
                printf("\n");
                if(desktop[ca][cb].rank==desktop[cc][cd].rank)
                {
                    desktop[ca][cb].status = 1;
                    desktop[cc][cd].status = 1;
                    printf("Computer got a matched pair!\n");
                    computer+=2;
                    if(player+computer==52)
                {
                    if(computer>player)
                    {
                       cwin=1;
                    }
                    continue;
                }
                }
                showDesktop(desktop);
                printf("\nFlipped cards: %d; You: %d; Computer: %d;\n\n",player+computer,player,computer);
                round1++;
            }
            for(row=0;row<4;row++)
            {
                for (col = 1; col <= 13; col++)
                desktop[row][col].status = 0;
            }
            player=0;
            computer=0;
            pwin=0;
            cwin=0;
            round1=0;
        }
        if(x==2)
        {
            srand(time(NULL));
            while(1)
            {
                if(C1win==1)
                {
                    showDesktop(desktop);
                    printf("\nFlipped cards: %d; Computer 1: %d; Computer 2: %d;\n\n",Com1+Com2,Com1,Com2);
                    printf("***End of game!***\n");
                    printf("%d turns played\n",round2);
                    if(Com1==Com2&&Com1!=0&&Com2!=0)
                    {
                        printf("A tie\n\n");
                    }
                    else
                    {
                        printf("Computer 1 wins!\n\n");
                    }
                    break;
                }
                if(C2win==1)
                {
                    showDesktop(desktop);
                    printf("\nFlipped cards: %d; Computer 1: %d; Computer 2: %d;\n\n",Com1+Com2,Com1,Com2);
                    printf("***End of game!***\n");
                    printf("%d turns played\n",round2);
                    if(Com1==Com2&&Com1!=0&&Com2!=0)
                    {
                        printf("Draw\n\n");
                    }
                    else
                    {
                        printf("Computer 2 wins!\n\n");
                    }
                    break;
                }
                a1=rand()%4;
                b1=rand()%13+1;
                c1=rand()%4;
                d1=rand()%13+1;
                while(desktop[a1][b1].status == 1)
                {
                    a1=rand()%4;
                    b1=rand()%13+1;
                }
                while(desktop[c1][d1].status == 1)
                {
                    c1=rand()%4;
                    d1=rand()%13+1;
                }
                while(a1==c1&&b1==d1)
                {
                    c1=rand()%4;
                    d1=rand()%13+1;
                }
                printf("Computer 1 chose 1st card (%d, %d) and it is %c",a1,b1,desktop[a1][b1].suit);
                ranknumber(desktop[a1][b1]);
                printf("Computer 1 chose 2nd card (%d, %d) and it is %c",c1,d1,desktop[c1][d1].suit);
                ranknumber(desktop[c1][d1]);
                if(desktop[a1][b1].rank==desktop[c1][d1].rank)
                {
                  desktop[a1][b1].status=1;
                  desktop[c1][d1].status=1;
                  printf("Computer 1 got a matched pair!\n");
                  Com1+=2;
                  if(Com1+Com2==52)
                  {
                      if(Com1>Com2)
                      {
                          C1win=1;
                      }
                      else C2win=1;
                      continue;
                  }
                }
                printf("\nFlipped cards: %d; Computer 1: %d; Computer 2: %d;\n\n",Com1+Com2,Com1,Com2);
                round2++;
                a2=rand()%4;
                b2=rand()%13+1;
                c2=rand()%4;
                d2=rand()%13+1;
                while(desktop[a2][b2].status == 1)
                {
                    a2=rand()%4;
                    b2=rand()%13+1;;
                }
                while(desktop[c2][d2].status == 1)
                {
                    c2=rand()%4;
                    d2=rand()%13+1;;
                }
                while(a2==c2&&b2==d2)
                {
                    c2=rand()%4;
                    d2=rand()%13+1;
                }
                printf("Computer 2 chose 1st card (%d, %d) and it is %c",a2,b2,desktop[a2][b2].suit);
                ranknumber(desktop[a2][b2]);
                printf("Computer 2 chose 2nd card (%d, %d) and it is %c",c2,d2,desktop[c2][d2].suit);
                ranknumber(desktop[c2][d2]);
                if(desktop[a2][b2].rank==desktop[c2][d2].rank)
                {
                  desktop[a2][b2].status=1;
                  desktop[c2][d2].status=1;
                  printf("Computer 2 got a matched pair!\n");
                  Com2+=2;
                  if(Com1+Com2==52)
                  {
                      if(Com2>Com1)
                      {
                          C2win=1;
                      }
                      else C1win=1;
                      continue;
                  }
                }
                printf("\nFlipped cards: %d; Computer 1: %d; Computer 2: %d;\n\n",Com1+Com2,Com1,Com2);
                round2++;
            }
            for(row=0;row<4;row++)
            {
                for (col = 1; col <= 13; col++)
                desktop[row][col].status = 0;
            }
            C1win=0;
            C2win=0;
            Com1=0;
            Com2=0;
            round2=0;
        }
        if(x==0)
        {
            break;
        }
    }
    return 0;
}
