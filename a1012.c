// ???[?r?b?N?E?L???[?u?@?V?~?????[?^
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int printCube(char cb[]){
    printf("\n");
    printf("\t         %c  %c  %c\n",cb[32],cb[33],cb[34]);
    printf("\t         %c  W  %c\n",cb[39],cb[35]);
    printf("\t         %c  %c  %c\n",cb[38],cb[37],cb[36]);
    printf("\t%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n",
        cb[24],cb[25],cb[26],cb[0],cb[1],cb[2],cb[8],cb[9],cb[10],cb[16],cb[17],cb[18]);
    printf("\t%c  B  %c  %c  G  %c  %c  R  %c  %c  N  %c\n",
        cb[31],cb[27],cb[7],cb[3],cb[15],cb[11],cb[23],cb[19]);
    printf("\t%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n",
        cb[30],cb[29],cb[28],cb[6],cb[5],cb[4],cb[14],cb[13],cb[12],cb[22],cb[21],cb[20]);
    printf("\t         %c  %c  %c\n",cb[40],cb[41],cb[42]);
    printf("\t         %c  Y  %c\n",cb[47],cb[43]);
    printf("\t         %c  %c  %c\n\n",cb[46],cb[45],cb[44]);
}

void main(){
    system("chcp 65001\n"); // ???{??\???????????R?[?h?y?[?W???X
    char cube[48]="GGGGGGGGRRRRRRRRNNNNNNNNBBBBBBBBWWWWWWWWYYYYYYYY";
    printf("\t?? ?L???[?u?????????\n");
    printCube(cube); // ?L???[?u?????????\??????
    // ???????????V?~?????[?V????


}
