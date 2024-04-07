#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ucompare(const void *first, const void *second)
{
return (*(int*)first - *(int*)second);
}

int dcompare(const void *first, const void *second)
{
return (*(int*)second - *(int*)first);
}
 

void sortArray(int A[] , int B[],int listSz){
    
    qsort(A, listSz, sizeof(int), ucompare);
    qsort(B, listSz, sizeof(int), dcompare);
}

int solution(int A[], int B[], int listSz){
    sortArray(A,B, listSz);
    int sum=0;
    
    for(int i = 0 ; i< listSz; i++){
        sum += A[i]*B[i];
    }
    
    return sum;
}



int main(){
    int a = 0;
    int A[3] = {1, 4, 2};
    int B[3] = {5, 4, 4};
    int listSz = sizeof(A) / sizeof(A[0]);
    int ans = solution(A, B, listSz);

    printf("Answer: %d\n", ans);

    return 0;
}