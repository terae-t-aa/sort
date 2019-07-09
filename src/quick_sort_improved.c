#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q){
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}


/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort(int A[], int n){
    if(n == 0 || n == 1) return;
    int i1, j1, i2, j2, pivot;
    
// 真ん中の要素をピボットとする
    pivot = A[n/2];
    for(i1 = j1 = 0; i1 < n; i1++){
        if(A[i1] <= pivot){
            swap(A+i1, A+j1);
            j1++;
        }
    }
    for(i2 = j2 = 0; i2 < j1; i2++){
        if(A[i2] < pivot){
            swap(A+i2, A+j2);
            j2++;
        }
    }
    
    quick_sort(A, j2);
    quick_sort(A+j1, n-j1);
    
    return;
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
  }
}
