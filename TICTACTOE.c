// TIC-TAC TOE USING C
#include <stdio.h>

void display(char graph[][3],int row,int col,int playermove)
{
    int i,j=0;
    if(playermove==1)
    {
        graph[row][col]='X';
    }
    else if(playermove==2)
    {
        graph[row][col]='O';
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%c ",graph[i][j]);
        }
        printf("\n");
    }
}

int checkresult(char graph[][3])
{
    int i;
    
    //CHECK ROWS
    for(i=0;i<3;i++)
    {
       if(graph[i][0]=='X' && graph[i][1]=='X' && graph[i][2]=='X')
       {
           return 1;
       }
    }
    for(i=0;i<3;i++)
    {
       if(graph[i][0]=='O' && graph[i][1]=='O' && graph[i][2]=='O')
       {
           return 2;
       }
    }
    
    //CHECK COLUMNS
    for(i=0;i<3;i++)
    {
        if(graph[0][i]=='X' && graph[1][i]=='X' && graph[2][i]=='X')
        {
            return 1;
        }
    }
     for(i=0;i<3;i++)
    {
        if(graph[0][i]=='O' && graph[1][i]=='O' && graph[2][i]=='O')
        {
            return 2;
        }
    }
    
    //CHECK DIAGONALS
    if(graph[0][0]=='X' && graph[1][1]=='X' && graph[2][2]=='X')
    {
        return 1;
    }
    else if(graph[0][2]=='X' && graph[1][1]=='X' && graph[2][0]=='X')
    {
        return 1;
    }
    else if(graph[0][0]=='O' && graph[1][1]=='O' && graph[2][2]=='O')
    {
        return 2;
    }
    else if(graph[0][2]=='O' && graph[1][1]=='O' && graph[2][0]=='O')
    {
        return 2;
    }
    return 0;
}

int main()
{
    char graph[3][3]={(' ',' ',' '),(' ',' ',' '),(' ',' ',' ')};
    int row,col;
    int playermove = 1;
    int n=1;
    int result=0;
    int check = 1 ;
    
    while(n<10)
    {
    printf("Player_%d: Enter the row and column \n",playermove);
    scanf("%d %d",&row,&col);
    if(row>=3 || col>=3)
    {
        printf("Invalid Choice \n");
    }
    display(graph,row,col,playermove);
    if(playermove==1)
    {
        playermove=2;
    }
    else
    {
        playermove=1;
    }
    result=checkresult(graph);
    if(result!=0)
    {
        n=10;
    }
    n++;
    }
    
    if(result==0)
    {
        printf("Its a DRAW !! \n");
    }
    else if(result==1)
    {
        printf("Player 1 WINS !! \n");
    }
    else
    {
        printf("Player 2 WINS !! \n");
    }
    printf("Thank You !!\n");
    return 0;
}