#include "stdio.h"
#include "stdlib.h"
#include <Windows.h>
#define LENGTH 15

HANDLE hOutput, hOutBuf;//����̨��Ļ���������
COORD coord = { 0,0 };//д����ʼ����
//˫���崦����ʾ
DWORD bytes = 0;
char map[LENGTH][LENGTH];

void createbuffer(){
    //�����µĿ���̨������
    hOutBuf = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    hOutput = CreateConsoleScreenBuffer(
        GENERIC_WRITE,//������̿�����������д����
        FILE_SHARE_WRITE,//���建�����ɹ���дȨ��
        NULL,
        CONSOLE_TEXTMODE_BUFFER,
        NULL
    );
    //���������������Ĺ��
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
void mapout() { //��һ��ѭ������   �ѵ�ͼ���ݴ���map���������

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
        //��Ϸ��������
        changemap();//�ı�Ҫ���������
        mapout();//�������
    }
    

}