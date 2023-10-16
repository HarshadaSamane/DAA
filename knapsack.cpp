#include <iostream>
using namespace std;

int main() {
    int i,j,wt,n;

    int profit[] = {0,10,12,15} ;
    int weight [] = {0,4,6,10} ;
    wt=10;
    n=3;

    int matrix [n+1][wt+1];
    for(i=0; i<n; i++) {
        for(j=0; j<=wt; j++)
        if(i==0 || j==0) {
            matrix[i][j]=0;
        } else {
            if(weight[i]<=j) {
                matrix[i][j] = max(matrix[i-1][j],profit[i]+matrix[i-1][j-weight[i]]);
            } else {
                matrix[i][j] = matrix [i-1][j]; 
            }
        }
    }

    for(i=0; i<=n; i++)
    {
        for (j=0; j<=wt; j++) {
            cout<<matrix[i][j]<<" ";
        
        }
        cout<<endl;
    }


}