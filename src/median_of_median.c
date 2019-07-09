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

// ソートによって中央値を求めてA[0]に移動させる
void smedian(int A[], int n){
    int i, j;
    for(i = n-1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(A[j] > A[j+1]) swap(A+j, A+j+1);
        }
    }
    swap(A, A+n/2);
}

// 適当に要素を入れ替えて中央値をA[0]に移動させる
void median(int A[], int n){
    if(n == 1) return;
    else {
        int s, i;
        s = (n-1)/5;
        for(i = 0; i < s; i++){smedian(A+i*5, 5);}
        smedian(A+s*5, n-s*5);
        for(i = 1; i <= s; i++){swap(A+i, A+i*5);}
        
        median(A, s+1);
    }
}

int quick_select(int A[], int n, int k){
    int i, j, pivot;

// 中央値をピボットとする
    median(A, n);
    pivot = A[0];
    for(i = j = 1; i < n; i++){
        if(A[i] <= pivot){
            swap(A+i, A+j);
            j++;
        }
    }

    if(j == k+1) return pivot;
    else if(j < k+1) return quick_select(A+j, n-j, k-j);
    else return quick_select(A+1, j-1, k);
}


int main(){
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("ERROR %d %d\n", i, quick_select(A, N, i));
//    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
