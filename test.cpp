//
// Created by Vong Ho on 28/03/2021.
//

#include<iostream>
using namespace std;


/**
 * This function create an array b, which be full fill 0
 * @param b pass reference address of pointer b to this function
 * @param n number of elements in array b
 */
void init(int *&b,int n) // pointer b
{
    b=new int[n+1]; // khoi tao array co n+1 gia tri => b[0,2,-3,23,-2,5,1,2,4]
    for(int i=1;i<=n;i++) b[i]=0; // Gan toan bo gia tri cua b = 0 => b[0,0,0,0,0,0,0,0,0,0]
}


/**
 * This function for checking, does this array b is palindrome
 * @param b: pass value of pointer b - array b
 * @param n: number of sizes in b array
 * @return set: if set == 1, this array is palindrome else this array is not.
 */
bool ktratn(int *b,int n) // n = 9
{
    int set=1;
                             //   1,2,3,4,5,6,7,8,9         1,2,3
    for(int i=1;i<=n/2;i++) // b1=[1,2,3,4,0,4,3,2,1] - b2=[1,3,2]
    {
        if(b[i] != b[n-i+1]) set=0;
    }

    return set;
}

/**
 * This function for move bit 1 from tail to head.
 * @param b: pass value of poiter b
 * @param n: size of array
 * @param OK: does this array is valid
 */
void daybit(int *b,int n,int &OK) // lay vung o nho OK
{                            // n = 9
    int i=n;                //      1 2 3 4 5 6 7 8 9
    while(i>0 && b[i]==1)  // b1 = [0,0,0,0,0,0,0,1,1] => [0,0,0,0,0,0,0,1,0] => ... => [?]
    {
        b[i]=0;
        i--;
    }

             // i = 7
    b[i]=1; // b1 = [0,0,0,0,0,0,1,0,0]
    if(i<=0) OK=0; // ok

    // da thay doi gia tri cua array b ~~ return b
}

/**
 * This function is print out all case of palindrome in n bit
 * @param n: size of bit
 */
void xuattn(int n){
    int *b; // Con tro b
    int OK=1;

    init(b,n); // => b [0,0,0,0,0,0,0,0,0]

    while(OK==1){
        if(ktratn(b,n)==1){ // Kiem tra array b co phai la chuoi doi xung. ktratn() [0,1]. 1->doi xung, 0->ko doi xung
            for(int i=1;i<=n;i++) // Do something? => print chuoi b.
                cout<<"\t"<<b[i];
            cout<<"\n";
        }

        daybit(b,n,OK); //
    }
    delete[]b; // xoa vung nho b
}

// Viet lai ham nay khong dung *b, *&b

int main(){
    int n;
    cin>>n;
    xuattn(n);
    return 0;
}