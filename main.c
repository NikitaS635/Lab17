#include <stdio.h>
#include "C:\Users\User2\CLionProjects\untitled\libs\data_structures\matrix\matrix.h"
#include <windows.h>
#include <assert.h>
#include <stdlib.h>
void test1()
{
    int val[3][3]={
            {2,4,6},
            {3,1,5},
            {8,9,4}
    };
    matrix m = createMatrixFromArray((int *)val,3,3);

    position minm = getMinValuePos(m);
    position maxm = getMaxValuePos(m);
    swapRows(m, minm.rowIndex, maxm.rowIndex);
    assert(m.values[minm.rowIndex][0] == 8);
    assert(m.values[minm.rowIndex][1] == 9);
    assert(m.values[minm.rowIndex][2] == 4);

    assert(m.values[maxm.rowIndex][0] == 3);
    assert(m.values[maxm.rowIndex][1] == 1);
    assert(m.values[maxm.rowIndex][2] == 5);

}
void test2()
{
    int val[3][3]={
            {7,1,2},
            {1,8,1},
            {3,2,3}
    };
    matrix m = createMatrixFromArray((int *)val,3,3);
    sortRowsByMaxElement(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 3);

    assert(m.values[1][0] == 7);
    assert(m.values[1][1] == 1);
    assert(m.values[1][2] == 2);

    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 8);
    assert(m.values[2][2] == 1);
}
void test3()
{
    int val[3][4]={
            {2,3,3,4},
            {2,1,8,2},
            {6,4,4,8}
    };
    matrix m = createMatrixFromArray((int *)val,3,4);
    sortColsByMinElement(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 4);
    assert(m.values[0][2] == 2);
    assert(m.values[0][3] == 3);

    assert(m.values[1][0] == 1);
    assert(m.values[1][1] == 2);
    assert(m.values[1][2] == 2);
    assert(m.values[1][3] == 8);

    assert(m.values[2][0] == 4);
    assert(m.values[2][1] == 8);
    assert(m.values[2][2] == 6);
    assert(m.values[2][3] == 4);
}
void test4()
{
    int val[3][3]={
            {1,4,2},
            {4,3,6},
            {2,6,5}
    };
    matrix m = createMatrixFromArray((int *)val,3,3);
    assert(isSymmetricMatrix(&m) == 1);
}
void test5()
{
    int val[3][3]={
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    matrix m = createMatrixFromArray((int *)val,3,3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 4);
    assert(m.values[0][2] == 7);

    assert(m.values[1][0] == 2);
    assert(m.values[1][1] == 5);
    assert(m.values[1][2] == 8);

    assert(m.values[2][0] == 3);
    assert(m.values[2][1] == 6);
    assert(m.values[2][2] == 9);
}
void test6()
{
    int val[2][2]={
            {1,2},
            {3,5},
    };
    matrix m = createMatrixFromArray((int *)val,2,2);

    int val1[2][2]={
            {-5,2},
            {3,-1},
    };
    matrix m1 = createMatrixFromArray((int *)val1,2,2);
    assert(isMutuallyInverseMatrices(m, m1) == 1);
}
void test7()
{
    int val[3][4]={
            {3,2,5,4},
            {1,3,6,3},
            {3,2,1,2}
    };
    matrix m = createMatrixFromArray((int *)val,3,4);
    long long sum = findSumOfMaxesOfPseudoDiagonal(m);
    assert(sum == 20);
}
void test8()
{
    int val[3][4]={
            {10,7,5,6},
            {3,11,8,9},
            {4,1,12,2}
    };
    matrix m = createMatrixFromArray((int *)val,3,4);
    int startRow = 0;
    int endRow = 0;
    int startCol = 0;
    int endCol = 3;
    int minn = getMinInArea(m,startRow,startCol,endRow,endCol);
    int startRow1 = 1;
    int endRow1 = 1;
    int startCol1 = 1;
    int endCol1 = 3;
    int minn1 = getMinInArea(m,startRow1,startCol1,endRow1,endCol1);
    int startRow2 = 2;
    int endRow2 = 2;
    int startCol2 = 2;
    int endCol2 = 2;
    int minn2 = getMinInArea(m,startRow2,startCol2,endRow2,endCol2);
    int rez = min(minn,minn1);
    int rez2 = min(rez,minn2);

    assert(rez2 == 5);
}
void test9()
{
    int val[5][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {3, 2, 1},
            {0, 0, 0}
    };
    matrix m = createMatrixFromArray((int *) val, 5, 3);
    sortByDistances(m);
    assert(m.values[0][0] == 0);
    assert(m.values[0][1] == 0);
    assert(m.values[0][2] == 0);

    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 2);
    assert(m.values[1][2] == 1);

    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 3);

    assert(m.values[3][0] == 4);
    assert(m.values[3][1] == 5);
    assert(m.values[3][2] == 6);

    assert(m.values[4][0] == 7);
    assert(m.values[4][1] == 8);
    assert(m.values[4][2] == 9);
}
void test10()
{
    int val[6][2]={
            {7,1},
            {2,7},
            {5,4},
            {4,3},
            {1,6},
            {8,0}
    };
    matrix m = createMatrixFromArray((int *)val,6,2);
    int viv = countEqClassesByRowsSum(m);
    assert(viv == 3);
}
void test11()
{
    int val[3][4] = {
            {3, 5,  5,  4},
            {2,  3, 6,  7},
            {12,  2,  1, 2}
    };
    matrix m = createMatrixFromArray((int *) val, 3, 4);
    int viv = getNSpecialElement(m);
    assert(viv == 2);
}
void test12()
{
    int val[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 1},
    };
    matrix m = createMatrixFromArray((int *) val, 3, 3);
    position A = getLeftMin(m);
    swapPenultimateRow(m,A.colIndex);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 3);

    assert(m.values[1][0] == 1);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 7);

    assert(m.values[2][0] == 7);
    assert(m.values[2][1] == 8);
    assert(m.values[2][2] == 1);
}
void test13()
{
    matrix ms[4];
    int val1[2][2]={
            {7,1},
            {1,1}
    };
    int val2[2][2]={
            {1,6},
            {2,2}
    };
    int val3[2][2]={
            {5,4},
            {2,3}
    };
    int val4[2][2]={
            {1,3},
            {7,9}
    };
    ms[0] = createMatrixFromArray((int *)val1,2,2);
    ms[1] = createMatrixFromArray((int *)val2,2,2);
    ms[2] = createMatrixFromArray((int *)val3,2,2);
    ms[3] = createMatrixFromArray((int *)val4,2,2);
    int col = countNonDescendingRowsMatrices(ms,4);
    assert(col == 2);
}
void test14()
{
    matrix ms[5];
    int val1[3][2]={
            {0,1},
            {1,0},
            {0,0}
    };
    int val2[3][2]={
            {1,1},
            {2,1},
            {1,1}
    };
    int val3[3][2]={
            {0,0},
            {0,0},
            {4,7}
    };
    int val4[3][2]={
            {0,0},
            {0,1},
            {0,0}
    };
    int val5[3][2]={
            {0,1},
            {0,2},
            {0,3}
    };
    ms[0] = createMatrixFromArray((int *)val1,3,2);
    ms[1] = createMatrixFromArray((int *)val2,3,2);
    ms[2] = createMatrixFromArray((int *)val3,3,2);
    ms[3] = createMatrixFromArray((int *)val4,3,2);
    ms[4] = createMatrixFromArray((int *)val5,3,2);
    printMatrixWithMaxZeroRows(ms,5);
    assert(sizeof(ms)/sizeof(ms[0]) > 0);
}
void test15()
{
    matrix matrices[5];

    int values1[3][3] = {
            {0, 1, 1},
            {1, 0, 0},
            {0, 0, 0}
    };
    int values2[3][3] = {
            {1, 1, 1},
            {2, 1, 1},
            {1, 1, 1}
    };
    int values3[3][3] = {
            {0, 0, 0},
            {0, 0, 0},
            {4, 7, 0}
    };
    int values4[3][3] = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
    int values5[3][3] = {
            {0, 1, 0},
            {0, 2, 0},
            {0, 3, 0}
    };

    matrices[0] = createMatrixFromArray(values1, 3, 3);
    matrices[1] = createMatrixFromArray(values2, 3, 3);
    matrices[2] = createMatrixFromArray(values3, 3, 3);
    matrices[3] = createMatrixFromArray(values4, 3, 3);
    matrices[4] = createMatrixFromArray(values5, 3, 3);
    size_t count = sizeof(matrices) / sizeof(matrices[0]);

    matrix minNormMatrix = findMatrixWithMinNorm(matrices, count);
    assert(minNormMatrix.values[0][0] == 0);
    assert(minNormMatrix.values[0][1] == 1);
    assert(minNormMatrix.values[0][2] == 1);

    assert(minNormMatrix.values[1][0] == 1);
    assert(minNormMatrix.values[1][1] == 0);
    assert(minNormMatrix.values[1][2] == 0);

    assert(minNormMatrix.values[2][0] == 0);
    assert(minNormMatrix.values[2][1] == 0);
    assert(minNormMatrix.values[2][2] == 0);
}

void alltest()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    printf("все тесты пройдены");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    alltest();
    return 0;
}
