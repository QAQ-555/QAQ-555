#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

#define LENTH 16

void ceatre_character();                             //���ﴴ��
void ceatre_birth();                                 //����������ͼ
int move(char n);
void act();
void ceatre_maze();
void yourbag(unsigned char item);
void print_maze();

int srt,agi,wis,num,no,bag,dir,x,y;
unsigned char tem;                           //str���� agi���� wis���� num ��¼��ͼ���� n,m,i,j���������� no��¼��ǰ��ͼ
unsigned char (*map[20])[LENTH],TEM[14][LENTH];
unsigned char S,W,Y,P;                            //tem��¼��ǰλ����Ϣ

struct maze
{
    int x;
    int no;
}maze[20];

int main()
{

    srand((unsigned) time(NULL));
    SetConsoleOutputCP(437);
    num=0;
    Y=0;
    W=1;
    int n,m;
    printf("                     @@       @@@       @@       @@        @@@@@@          @@@@@@             @@@       @@@           @@@@@@@@\n");
    printf("                      @@     @@@@@     @@       @@       @@              @@      @@          @@@@@     @@@@@         @\n");
    printf("                       @@   @@   @@   @@       @@      @@@             @@@       @@@        @@   @@   @@   @@       @@@@@@@@\n");
    printf("                        @@@@@     @@@@@       @@       @@               @@      @@         @@     @@@@@     @@     @\n");
    printf("                         @@@       @@@       @@          @@@@@@           @@@@@@          @@       @@@       @@   @@@@@@@@\n");
    printf("                                                                @@@@@@@@@@              @@@@@@\n");
    printf("                                                                   @@                 @@      @@\n");
    printf("                                                                  @@                @@@       @@@\n");
    printf("                                                                 @@                  @@      @@\n");
    printf("                                                                @@                     @@@@@@\n");
    for(int j = 0;j < 10;j++)
    {  
        printf("\t\t\t\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
        for ( int i = 0; i < 20; i++)
        {
            printf("%c",219);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
        for ( int i = 0; i < 20; i++)
        {
            printf("%c",219);
        }
        printf("\n");
    }
    for(int j = 0;j < 10;j++)
    {  
        printf("\t\t\t\t\t\t\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
        for ( int i = 0; i < 20; i++)
        {
            printf("%c",219);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_RED);
        for ( int i = 0; i < 20; i++)
        {
            printf("%c",219);
        }
        printf("\n");
    }
    printf("\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE);
    printf("                                                            ##################################\n");
    printf("                                                            ##                              ##\n");
    printf("                                                            ##       Press 1 to start       ##\n");
    printf("                                                            ##       Press 2 to continue    ##\n");
    printf("                                                            ##       Press 3 to eixt        ##\n");
    printf("                                                            ##                              ##\n");
    printf("                                                            ##################################\n");
    a:
    n=getch();
    SetConsoleOutputCP(936);
    if(!(n == '1'|| n =='2' || n == '3'))
        goto a;
    printf("����Ҫ�������ֽ̳�����(�����, �밴Y/y)(�������)"   );
    m=getch();
    if(!(m=='y'||m=='Y'))
        goto a;
    if(n=='1')
    {
        goto bagin;
    }
    if(n=='2')
       ;
    if(n=='3')
    {
        system("pause");
        exit(0);
    }
    fflush(stdin);
    bagin:
    ceatre_birth();
    while(1)
    {
        n=getch();
        if(n=='w'|| n=='W'||n=='a'||n=='A'||n=='s'|| n=='S'||n=='d'||n=='D')
            move(n);
        if(Y==W||tem==W)
            printf("pwn��");
    }
    printf("\r");
    printf("\t\t\t\t                  ");
    num++;
    system("pause");
    
}
void ceatre_birth()
{
    int n;
    tem=' ';
    static unsigned char brith[14][LENTH]={{'?',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?'},
                                           {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ','b','=','Y',' ','f','=','W',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',220,220,220,220,220,220,220,220,220,220,' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',232,' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',232,' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',233,' ',' ',232,' ',' ',213,' ',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',232,' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',220,220,220,220,220,220,220,220,220,220,' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ','w','=','S',' ','s','=','P',' ',' ',' ',' '},
                                           {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                                           {'?',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','?'},};
    map[num]=brith;
    maze[num].no=num;
    maze[num].x=14;
    for (int i = 0; i < maze[num].x; i++)
    {
        for (int j = 0; j < LENTH; j++)
        {
            TEM[i][j]==' ';
        }
    }
    
    print_maze();
    SetConsoleOutputCP(936);
    printf("\t\t\t\t��ӭ����Wind0ws(������������Ի�)");
    n=getch();
    printf("\r");
    printf("\t\t\t\t����һ���ɱ仯�����ͼ��������,���������baba              ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t��������ѧϰһЩ����֪ʶ��                            ");
    n=getch();
    printf("\r");
    printf("\t\t\t\tb��baba��Ӧͼ����");
    SetConsoleOutputCP(437);
    printf("%c                                ",233);
    n=getch();
    printf("\r");
    SetConsoleOutputCP(936);
    printf("\t\t\t\tf��flag��Ӧͼ����");
    SetConsoleOutputCP(437);
    printf("%c                                ",213);
    n=getch();
    printf("\r");
    SetConsoleOutputCP(936);
    printf("\t\t\t\tw��wall��Ӧͼ����");
    SetConsoleOutputCP(437);
    printf("%c                                ",220);
    n=getch();
    printf("\r");
    SetConsoleOutputCP(936);
    printf("\t\t\t\ts��stone��Ӧͼ����");
    SetConsoleOutputCP(437);
    printf("%c                                ",232);
    n=getch();
    printf("\r");
    SetConsoleOutputCP(936);
    printf("\t\t\t\t�������");
    printf("%c",89);
    printf("����?������˼��YOU                                           ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t�������");
    printf("%c",80);
    printf("����?������˼��PULL������ƶ���                                ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t%c",83);
    printf("��STOP,���޷�������ͨ��                                       ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t%c",'H');
    printf("��HACK,��ͨ���������vvind0vv5                                 ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t\t������ƶ���ʾ����                                         ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t��w a s d�ƶ�,�����ߵ�����vvind0vv5�ɣ�\n");
}
int move(char n)
{
    int jojo,a_switch;
    a_switch=0;
    for (int i = 0; i < maze[num].x; i++)                         
    {
        for (int j = 0; j < LENTH; j++)
        {
            if((map[num])[i][j]=='S')
            {
                if((map[num])[i+1][j]=='=')
                {
                    if(((map[num])[i+2][j]>65 && (map[num])[i+2][j]<91) ||((map[num])[i+2][j]>96 && (map[num])[i+2][j]<123))
                        if((map[num])[i+2][j]=='f')
                            S=213;
                        else
                        if((map[num])[i+2][j]=='w')
                            S=220;
                        else
                        if((map[num])[i+2][j]=='s')
                            S=232;
                        else
                        if((map[num])[i+2][j]=='b')
                            S=233;
                }
                if((map[num])[i-1][j]=='=')
                {
                    if(((map[num])[i-2][j]>65 && (map[num])[i-2][j]<91) ||((map[num])[i-2][j]>96 && (map[num])[i-2][j]<123))
                        if((map[num])[i-2][j]=='f')
                            S=213;
                        else
                        if((map[num])[i-2][j]=='w')
                            S=220;
                        else
                        if((map[num])[i-2][j]=='s')
                            S=232;
                        else
                        if((map[num])[i-2][j]=='b')
                            S=233;
                }
                if((map[num])[i][j+1]=='=')
                {
                    if(((map[num])[i][j+2]>65 && (map[num])[i][j+2]<91) ||((map[num])[i][j+2]>96 && (map[num])[i][j+2]<123))
                        if((map[num])[i][j+2]=='f')
                            S=213;
                        else
                        if((map[num])[i][j+2]=='w')
                            S=220;
                        else
                        if((map[num])[i][j+2]=='s')
                            S=232;
                        else
                        if((map[num])[i][j+2]=='b')
                            S=233;
                }
                if((map[num])[i][j-1]=='=')
                {
                    if(((map[num])[i][j-2]>65 && (map[num])[i][j-2]<91) ||((map[num])[i][j-2]>96 && (map[num])[i][j-2]<123))
                        if((map[num])[i][j-2]=='f')
                            S=213;
                        else
                        if((map[num])[i][j-2]=='w')
                            S=220;
                        else
                        if((map[num])[i][j-2]=='s')
                            S=232;
                        else
                        if((map[num])[i][j-2]=='b')
                            S=233;
                }
            }
        }
    }
    for (int i = 0; i < maze[num].x; i++)                         
    {
        for (int j = 0; j < LENTH; j++)
        {
            if((map[num])[i][j]=='P')
            {
                if((map[num])[i+1][j]=='=')
                {
                    if(((map[num])[i+2][j]>65 && (map[num])[i+2][j]<91) ||((map[num])[i+2][j]>96 && (map[num])[i+2][j]<123))
                        if((map[num])[i+2][j]=='f')
                            P=213;
                        else
                        if((map[num])[i+2][j]=='w')
                            P=220;
                        else
                        if((map[num])[i+2][j]=='s')
                            P=232;
                        else
                        if((map[num])[i+2][j]=='b')
                            P=233;
                }
                if((map[num])[i-1][j]=='=')
                {
                    if(((map[num])[i-2][j]>65 && (map[num])[i-2][j]<91) ||((map[num])[i-2][j]>96 && (map[num])[i-2][j]<123))
                        if((map[num])[i-2][j]=='f')
                            P=213;
                        else
                        if((map[num])[i-2][j]=='w')
                            P=220;
                        else
                        if((map[num])[i-2][j]=='s')
                            P=232;
                        else
                        if((map[num])[i-2][j]=='b')
                            P=233;
                }
                if((map[num])[i][j+1]=='=')
                {
                    if(((map[num])[i][j+2]>65 && (map[num])[i][j+2]<91) ||((map[num])[i][j+2]>96 && (map[num])[i][j+2]<123))
                        if((map[num])[i][j+2]='f')
                            P=213;
                        else
                        if((map[num])[i][j+2]='w')
                            P=220;
                        else
                        if((map[num])[i][j+2]='s')
                            P=232;
                        else
                        if((map[num])[i][j+2]='b')
                            P=233;
                }
                if((map[num])[i][j-1]=='=')
                {
                    if(((map[num])[i][j-2]>65 && (map[num])[i][j-2]<91) ||((map[num])[i][j-2]>96 && (map[num])[i][j-2]<123))
                        if((map[num])[i][j-2]=='f')
                            P=213;
                        else
                        if((map[num])[i][j-2]=='w')
                            P=220;
                        else
                        if((map[num])[i][j-2]=='s')
                            P=232;
                        else
                        if((map[num])[i][j-2]=='b')
                            P=233;
                }
            }
        }
    }
    for (int i = 0; i < maze[num].x; i++)                         
    {
        for (int j = 0; j < LENTH; j++)
        {
            if((map[num])[i][j]=='W')
            {
                if((map[num])[i+1][j]=='=')
                {
                    if(((map[num])[i+2][j]>65 && (map[num])[i+2][j]<91) ||((map[num])[i+2][j]>96 && (map[num])[i+2][j]<123))
                        if((map[num])[i+2][j]=='f')
                            W=213;
                        else
                        if((map[num])[i+2][j]=='w')
                            W=220;
                        else
                        if((map[num])[i+2][j]=='s')
                            W=232;
                        else
                        if((map[num])[i+2][j]=='b')
                            W=233;
                }
                if((map[num])[i-1][j]=='=')
                {
                    if(((map[num])[i-2][j]>65 && (map[num])[i-2][j]<91) ||((map[num])[i-2][j]>96 && (map[num])[i-2][j]<123))
                        if((map[num])[i-2][j]=='f')
                            W=213;
                        else
                        if((map[num])[i-2][j]=='w')
                            W=220;
                        else
                        if((map[num])[i-2][j]=='s')
                            W=232;
                        else
                        if((map[num])[i-2][j]=='b')
                            W=233;
                }
                if((map[num])[i][j+1]=='=')
                {
                    if(((map[num])[i][j+2]>65 && (map[num])[i][j+2]<91) ||((map[num])[i][j+2]>96 && (map[num])[i][j+2]<123))
                        if((map[num])[i][j+2]=='f')
                            W=213;
                        else
                        if((map[num])[i][j+2]=='w')
                            W=220;
                        else
                        if((map[num])[i][j+2]=='s')
                            W=232;
                        else
                        if((map[num])[i][j+2]=='b')
                            W=233;
                }
                if((map[num])[i][j-1]=='=')
                {
                    if(((map[num])[i][j-2]>65 && (map[num])[i][j-2]<91) ||((map[num])[i][j-2]>96 && (map[num])[i][j-2]<123))
                        if((map[num])[i][j-2]=='f')
                            W=213;
                        else
                        if((map[num])[i][j-2]=='w')
                            W=220;
                        else
                        if((map[num])[i][j-2]=='s')
                            W=232;
                        else
                        if((map[num])[i][j-2]=='b')
                            W=233;
                }
            }
        }
    }
    for (int i = 0; i < maze[num].x; i++)                         
    {
        for (int j = 0; j < LENTH; j++)
        {
            if((map[num])[i][j]=='Y')
            {
                if((map[num])[i+1][j]=='=')
                {
                    if(((map[num])[i+2][j]>65 && (map[num])[i+2][j]<91) ||((map[num])[i+2][j]>96 && (map[num])[i+2][j]<123))
                        if((map[num])[i+2][j]=='f')
                            Y=213;
                        else
                        if((map[num])[i+2][j]=='w')
                            Y=220;
                        else
                        if((map[num])[i+2][j]=='s')
                            Y=232;
                        else
                        if((map[num])[i+2][j]=='b')
                            Y=233;
                }
                if((map[num])[i-1][j]=='=')
                {
                    if(((map[num])[i-2][j]>65 && (map[num])[i-2][j]<91) ||((map[num])[i-2][j]>96 && (map[num])[i-2][j]<123))
                        if((map[num])[i-2][j]=='f')
                            Y=213;
                        else
                        if((map[num])[i-2][j]=='w')
                            Y=220;
                        else
                        if((map[num])[i-2][j]=='s')
                            Y=232;
                        else
                        if((map[num])[i-2][j]=='b')
                            Y=233;
                }
                if((map[num])[i][j+1]=='=')
                {
                    if(((map[num])[i][j+2]>65 && (map[num])[i][j+2]<91) ||((map[num])[i][j+2]>96 && (map[num])[i][j+2]<123))
                        if((map[num])[i][j+2]=='f')
                            Y=213;
                        else
                        if((map[num])[i][j+2]=='w')
                            Y=220;
                        else
                        if((map[num])[i][j+2]=='s')
                            Y=232;
                        else
                        if((map[num])[i][j+2]=='b')
                            Y=233;
                }
                if((map[num])[i][j-1]=='=')
                {
                    if(((map[num])[i][j-2]>65 && (map[num])[i][j-2]<91) ||((map[num])[i][j-2]>96 && (map[num])[i][j-2]<123))
                        if((map[num])[i][j-2]=='f')
                            Y=213;
                        else
                        if((map[num])[i][j-2]=='w')
                            Y=220;
                        else
                        if((map[num])[i][j-2]=='s')
                            Y=232;
                        else
                        if((map[num])[i][j-2]=='b')
                            Y=233;
                }
            }
        }
    }
    for (int i = 0; i < maze[num].x; i++)
    {
        for (int j = 0; j < LENTH; j++)
        {
            if((map[num])[i][j]==Y)
            {
                x=i;
                y=j;
            }
        }
    }
    if(n=='w'|| n=='W')
    {
        if((map[num])[x-1][y] != S)
        {    
            if ((map[num])[x-1][y] != S)
            {
                (map[num])[x][y]=tem;
                tem=(map[num])[x-1][y];
                map[num][x-1][y]=Y;
            }   
        }
    }
    else
    if(n=='a'||n=='A')
    {

        if((map[num])[x][y-1] != S)
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x][y-1];
            map[num][x][y-1]=Y;
        }     
    }
    else
    if(n=='s'||n=='S')
    {
        if((map[num])[x+1][y] != S)
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x+1][y];
            map[num][x+1][y]=Y;
        }  
    }
    else
    if(n=='d'||n=='D')
    {
        if((map[num])[x][y+1] == P)
        {
            for (int i = 0; i < LENTH-y; i++)
            {
                if ((map[num])[x][y+1+i] == S)
                    return 0;
                if ((map[num])[x][y+1+i] != P)
                {
                    jojo=y+1+i;
                    break;
                }    
            }
            for (int i = jojo; i >y; i--)
            {
                if((map[num])[x][i] == 32)
                {
                    (map[num])[x][i]=(map[num])[x][i-1];
                    (map[num])[x][i-1]=TEM[x][i-1];
                    print_maze();
                }
                else
                {
                    TEM[x][i]=(map[num])[x][i];
                    (map[num])[x][i]=(map[num])[x][i-1];
                    (map[num])[x][i-1]=TEM[x][i-1];
                    print_maze();
                }
            }
            a_switch=1;
        }
        if((map[num])[x][y+1] != S && a_switch!=1) 
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x][y+1];
            map[num][x][y+1]=Y;
        }
    }
    print_maze();
    return 0;
}

void print_maze()
{
    system("cls");
    SetConsoleOutputCP(437);
    printf("%c",201);
    for (int i = 0; i < 154; i++)
    {
        printf("%c",205);
    }
    printf("%c",187);
    for (int i = 0; i < maze[num].x; i++)
    {
        printf("%c",186);
        printf("\t\t\t\t\t\t\t\t\t");
        for (int j = 0; j < LENTH; j++)
        {
            SetConsoleOutputCP(437);
            printf("%c  ",(map[num])[i][j]);
        }
        printf("\t\t\t\t\t\t\t\t\t%c",186);
        printf("\n");
        if(i==maze[num].x-1)
            printf("%c\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%c",186,186);
    }
    printf("\n%c",200);
    for (int i = 0; i < 154; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);
}