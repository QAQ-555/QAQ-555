#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

void ceatre_character();
void ceatre_maze();

int srt,agi,wis;

int main()
{
    system("color 07");
    srand((unsigned) time(NULL));
    int n,m;
    printf("                     @@       @@@       @@       @@        @@@@@@          @@@@@@             @@@       @@@           @@@@@@@@\n");
    printf("                      @@     @@@@@     @@       @@       @@              @@      @@          @@@@@     @@@@@         @\n");
    printf("                       @@   @@   @@   @@       @@      @@@             @@@       @@@        @@   @@   @@   @@       @@@@@@@@\n");
    printf("                        @@@@@     @@@@@       @@       @@               @@      @@         @@     @@@@@     @@     @\n");
    printf("                         @@@       @@@       @@          @@@@@@           @@@@@@          @@       @@@       @@   @@@@@@@@\n\n");
    printf("                                                                @@@@@@@@@@              @@@@@@\n");
    printf("                                                                   @@                 @@      @@\n");
    printf("                                                                  @@                @@@       @@@\n");
    printf("                                                                 @@                  @@      @@\n");
    printf("                                                                @@                     @@@@@@\n");
    printf("\n");
    printf("                    @@@@@@@            @@          @@       @@           @@       @@@@@@@@@           @@@@@@@@@@        @@@@@@@@           @@           @@\n");
    printf("                   @@      @@         @@          @@       @@ @         @@      @@        @@         @@               @@         @@       @@ @         @@\n");
    printf("                  @@        @@       @@          @@       @@   @       @@      @@                   @@              @@             @@    @@   @       @@\n");
    printf("                 @@          @@     @@          @@       @@     @     @@      @@     @@@@@@@       @@@@@@@@@@@     @@              @@   @@     @     @@\n");
    printf("                @@        @@        @@         @@       @@       @   @@      @@        @@         @@                @@            @@   @@       @   @@\n");
    printf("               @@      @@            @@      @@        @@         @ @@       @@       @@         @@                  @@         @@    @@         @ @@\n");
    printf("              @@@@@@@@                 @@@@@          @@           @@         @@@@@@@@@         @@@@@@@@@@@@          @@@@@@@@@      @@           @@\n");
    printf("                                                               ##################################\n");
    printf("                                                               ##                              ##\n");
    printf("                                                               ##       Press 1 to start       ##\n");
    printf("                                                               ##       Press 2 to continue    ##\n");
    printf("                                                               ##       Press 3 to eixt        ##\n");
    printf("                                                               ##                              ##\n");
    printf("                                                               ##################################\n");
    a:
    printf("请输入\n");
    n=getch();
    if(!(n == '1'|| n =='2' || n == '3'))
        goto a;
    printf("你确定吗？(如果是, 请按Y/y)"   );
    m=getch();
    if(!(m=='y'||m=='Y'))
        goto a;
    if(n=='1')
    {
        ceatre_character();
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
    ceatre_maze();
    system("pause");
    
}
void ceatre_character()
{
    int n;
    receate:
    system("cls");
    srt=rand()%10;
    agi=rand()%10;
    wis=rand()%10;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    printf("力量—————— %d\n",srt);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    printf("敏捷—————— %d\n",agi);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    printf("智力—————— %d\n",wis);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    printf("********按r重新随机属性********\n");
    printf("********按y进行继续创建********\n");
    retry:
    n=getch();
    if (n=='r'||n=='R')
        goto receate;
    if (!(n=='Y'||n=='y'))
        goto retry;
}