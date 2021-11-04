#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char flag[3][8];
    int key[4][8]={{19,30,16,29,25,25,24,23,},{55,23,37,54,21,37,23,51,},{29,13,61,5,61,61,12,24,},{33,31,33,50,47,3,51,52}};
    for (int i = 0; i < 8; i++)
    {
        flag[2][i]=key[3][i] | (key[2][i]<<6);
        flag[1][i]=((key[2][i]>>2)) | (key[1][i]<<4);
        flag[0][i]=(key[0][i]<<2) | ((key[1][i]>>4)&3);
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c",flag[j][i]);
        }
    }
    printf("\n");
    system("pause");
}