#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

void ceatre_character();                             //���ﴴ��
void ceatre_birth();                                 //����������ͼ
void move(char n);
void act();
void ceatre_maze();
void yourbag(unsigned char item);
void print_maze();

int srt,agi,wis,num,no,bag,dir;
unsigned char tem;                           //str���� agi���� wis���� num ��¼��ͼ���� n,m,i,j���������� no��¼��ǰ��ͼ
unsigned char BAG[20];
unsigned char (*map[20])[10];                              //tem��¼��ǰλ����Ϣ

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
    bag=0;
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
    if(!(n == '1'|| n =='2' || n == '3'))
        goto a;
    printf("��ȷ����(�����, �밴Y/y)"   );
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
    ceatre_birth();
    while(1)
    {
        n=getch();
        if(n=='e'||n=='E')
            act();
        if(n=='w'|| n=='W'||n=='a'||n=='A'||n=='s'|| n=='S'||n=='d'||n=='D')
            move(n);  
    }
    printf("\r");
    printf("\t\t\t\t                  ");
    num++;
    system("pause");
    
}
void ceatre_character()
{
    int n;
    receate:
    system("cls");
    srt=rand()%11;
    agi=rand()%11;
    wis=rand()%11;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    printf("���������������� %d\n",srt);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    printf("���ݡ����������� %d\n",agi);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
    printf("���������������� %d\n",wis);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED |FOREGROUND_GREEN |FOREGROUND_BLUE);
    printf("********��r�������********\n");
    printf("********��y��������********\n");
    retry:
    n=getch();
    if (n=='r'||n=='R')
        goto receate;
    if (!(n=='Y'||n=='y'))
        goto retry;
}
void ceatre_birth()
{
    int n;
    tem=220;
    static unsigned char brith[10][10]={{220,220,220,220,220,220,220,220,220,220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,233,' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,' ',' ',' ',' ',' ',' ',' ',' ',220},
                                        {220,220,220,220,220,220,220,220,220,220}};
    map[num]=brith;
    maze[num].no=num;
    maze[num].x=10;
    print_maze();
    SetConsoleOutputCP(936);
    printf("\t\t\t\t��ӭ����Wind0ws(������������Ի�)");
    n=getch();
    printf("\r");
    printf("\t\t\t\t����԰���t����ȡ�����˵�                  ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t��������ѧϰһЩ����֪ʶ��                  ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t�������");
    SetConsoleOutputCP(437);
    printf("%c",233);
    SetConsoleOutputCP(936);
    printf("����?����������Լ�                       ");
    n=getch();
    printf("\r");
    SetConsoleOutputCP(437);
    printf("\t\t\t\t%c",220);
    SetConsoleOutputCP(936);
    printf("��ǽ��,���޷�������ͨ��                       ");
    n=getch();
    printf("\r");
    printf("\t\t\t\t��w a s d�ƶ�,�����ߵ���������һ���ķ�����,�ٰ�e����\n");
}
void move(char n)
{
    int x,y;
    for (int i = 0; i < maze[num].x; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if((map[num])[i][j]==233)
            {
                x=i;
                y=j;
            }
        }
    }
    if(n=='w'|| n=='W')
    {
        if(x-1<0)
        {
            dir=1;
            ceatre_maze();
        }
        else
        if((map[num])[x-1][y] != 220)
        {    
            (map[num])[x][y]=tem;
            tem=(map[num])[x-1][y];
            map[num][x-1][y]=233;
        }
    }
    else
    if(n=='a'||n=='A')
    {
        if(y-1<0)
        {
            dir=2;
            ceatre_maze();
        }
        else 
        if((map[num])[x][y-1] != 220)
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x][y-1];
            map[num][x][y-1]=233;
        }       
    }
    else
    if(n=='s'||n=='S')
    {
        if(x+1>maze[num].x-1)
        {
            dir=3;
            ceatre_maze();
        }
        else            
        if((map[num])[x+1][y] != 220)
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x+1][y];
            map[num][x+1][y]=233;
        }  
    }
    else
    if(n=='d'||n=='D')
    {
        if(y+1>9)
        {
            dir=4;
            ceatre_maze();
        }
        else 
        if((map[num])[x][y+1] != 220)
        {
            (map[num])[x][y]=tem;
            tem=(map[num])[x][y+1];
            map[num][x][y+1]=233;
        }  
    }
    print_maze();
}
void act()
{
    char e;
    print_maze();
    if(tem==' ')
    {
        SetConsoleOutputCP(936);
        printf("\t\t\t\t\t\t������һƬ�յ�...");
    }
    else
    if(tem==179)
    {
        SetConsoleOutputCP(936);
        printf("\t\t\t\t\t\t����һ�ѽ�\n\t\t\t\t\t\t�ٴΰ�e������");
        e=getch();
        if(e=='e'|| e=='E')
        {
            yourbag(179);
            tem=' ';
        }
    }
    else
    if(tem==228)
    {
        SetConsoleOutputCP(936);
        printf("\t\t\t\t\t\t����һ�ѹ�\n\t\t\t\t\t\t�ٴΰ�e������");
        e=getch();
        if(e=='e'|| e=='E')
        {
            yourbag(228);        
            tem=' ';  
        }
    }
    else
    if(tem==159)
    {
        SetConsoleOutputCP(936);
        printf("\t\t\t\t\t\t����һ������\n\t\t\t\t\t\t�ٴΰ�e������");  
        e=getch();
        if(e=='e'|| e=='E')
        {
            yourbag(159);
            tem=' ';
        }
    }
}
void yourbag(unsigned char item)
{
    if(!(bag==20))
    {
    BAG[bag]=item;
    bag++;
    }
    else
        printf("��ı�������");
}
void ceatre_maze()
{
    tem=' ';
    int x=rand()%6+10;
    num++;
    map[num]=(unsigned char (*)[10])malloc(x* sizeof(unsigned char (*)[10]));
    maze[num].x=x;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            (map[num])[i][j]=220;
        }
    }
    switch (dir)
    {
    case 1:
        map[num][maze[num].x-1][rand()%8+1]=233;
        break;
    case 2:
        map[num][rand()%(maze[num].x-2)+1][9]=233;
        break;
    case 3:
        map[num][0][rand()%8+1]=233;
        break;
    case 4:
        map[num][rand()%(maze[num].x-2)+1][0]=233;
        break;    
    default:
        break;
    }
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
        for (int j = 0; j < 10; j++)
        {
            SetConsoleOutputCP(437);
            printf("%c ",(map[num])[i][j]);
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