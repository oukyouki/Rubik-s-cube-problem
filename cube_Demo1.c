#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

#define W 0
#define B 1
#define G 2
#define R 3
#define N 4
#define Y 5

void printCube(char cb[6][3][3])
{
    printf("\n\t         %c  %c  %c\n", cb[W][0][0], cb[W][0][1], cb[W][0][2]);
    printf("\t         %c  %c  %c\n", cb[W][1][0], cb[W][1][1], cb[W][1][2]);
    printf("\t         %c  %c  %c\n", cb[W][2][0], cb[W][2][1], cb[W][2][2]);
    printf("\t%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", cb[B][0][0], cb[B][0][1], cb[B][0][2], cb[G][0][0], cb[G][0][1], cb[G][0][2], cb[R][0][0], cb[R][0][1], cb[R][0][2], cb[N][0][0], cb[N][0][1], cb[N][0][2]);
    printf("\t%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", cb[B][1][0], cb[B][1][1], cb[B][1][2], cb[G][1][0], cb[G][1][1], cb[G][1][2], cb[R][1][0], cb[R][1][1], cb[R][1][2], cb[N][1][0], cb[N][1][1], cb[N][1][2]);
    printf("\t%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", cb[B][2][0], cb[B][2][1], cb[B][2][2], cb[G][2][0], cb[G][2][1], cb[G][2][2], cb[R][2][0], cb[R][2][1], cb[R][2][2], cb[N][2][0], cb[N][2][1], cb[N][2][2]);
    printf("\t         %c  %c  %c\n", cb[Y][0][0], cb[Y][0][1], cb[Y][0][2]);
    printf("\t         %c  %c  %c\n", cb[Y][1][0], cb[Y][1][1], cb[Y][1][2]);
    printf("\t         %c  %c  %c\n\n", cb[Y][2][0], cb[Y][2][1], cb[Y][2][2]);
}

void fun(char cb[6][3][3], int flag)
{
    char temp[6][3][3];
    memcpy(temp, cb, sizeof(char) * 54);
    for (int i = 0; i < 3; i++)
    {
        switch (flag)
        {
        case 0:
            for (int j = 0; j < 4; j++)
                temp[j + 1][0][2 - i] = cb[(j + 1) % 4 + 1][0][2 - i];
            break;
        case 5:
            for (int j = 0; j < 4; j++)
                temp[(j + 1) % 4 + 1][2][i] = cb[j + 1][2][i];
            break;
        case 1:
            temp[W][i][0] = cb[N][2 - i][2];
            temp[G][i][0] = cb[W][i][0];
            temp[Y][i][0] = cb[G][i][0];
            temp[N][2 - i][2] = cb[Y][i][0];
            break;
        case 2:
            temp[W][2][i] = cb[B][2 - i][2];
            temp[R][i][0] = cb[W][2][i];
            temp[Y][0][2 - i] = cb[R][i][0];
            temp[B][2 - i][2] = cb[Y][0][2 - i];
            break;
        case 3:
            temp[W][2 - i][2] = cb[G][2 - i][2];
            temp[N][i][0] = cb[W][2 - i][2];
            temp[Y][2 - i][2] = cb[N][i][0];
            temp[G][2 - i][2] = cb[Y][2 - i][2];
            break;
        case 4:
            temp[W][0][2 - i] = cb[R][i][2];
            temp[B][i][0] = cb[W][0][2 - i];
            temp[Y][2][i] = cb[B][i][0];
            temp[R][i][2] = cb[Y][2][i];
            break;
        }

        for (int j = 0; j < 3; j++)
            temp[flag][i][j] = cb[flag][2 - j][i];
    }
    memcpy(cb, temp, sizeof(char) * 54);
    printCube(cb);
}

void main()
{
    system("chcp 65001\n");
    char cube[6][3][3];
    char flag;

    char ch[6] = {'W', 'B', 'G', 'R', 'N', 'Y'};
    for (int i = 0; i < 6; i++)
        memset(cube[i], ch[i], sizeof(cube[i]));
    printf("\t★ キューブの初期状態★\n");
    printCube(cube);
    while (scanf("%c", &flag) != EOF)
        for (int i = 0; i < sizeof(ch); i++)
            if (ch[i] == flag || ch[i] == (char)(flag - 32))
                fun(cube, i);
}