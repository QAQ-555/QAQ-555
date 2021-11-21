#include "stdio.h"
#include "stdlib.h"
#include <Windows.h>
#define LENGTH 15

HANDLE hOutput, hOutBuf;//控制台屏幕缓冲区句柄
COORD coord = { 0,0 };//写入起始坐标
//双缓冲处理显示
DWORD bytes = 0;
char map[LENGTH][LENGTH];

void createbuffer(){
    //创建新的控制台缓冲区
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//定义进程可以往缓冲区写数据
        FILE_SHARE_WRITE,//定义缓冲区可共享写权限
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //隐藏两个缓冲区的光标
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = 0;
    cci.dwSize = 1;
    SetConsoleCursorInfo(hOutput, &cci);
    SetConsoleCursorInfo(hOutBuf, &cci);
}
void changemap() {
    int i, j;
    for (i = 0; i < LENGTH; i++)
    {
        for (j = 0; j < LENGTH; j++)
        {
            map[i][j] = '*';
        }
    }
}
void mapout() { //改一改循环次数   把地图数据存在map里就完事了

    for (int i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutBuf, map[i], LENGTH, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(hOutBuf);
    for (int i = 0; i < LENGTH; i++)
    {
        coord.Y = i;
        WriteConsoleOutputCharacterA(hOutput, map[i], LENGTH, coord, &bytes);
    }
    SetConsoleActiveScreenBuffer(hOutput);
}
int main() {
    createbuffer();
    
    while (1){
        //游戏操作输入
        changemap();//改变要输出的数据
        mapout();//输出数据
    }
    

}