//递归 分而治之
#include <iostream>
using namespace std;

const int Len = 66;
const int Divs = 6;
void subdivide(char arr[],int low,int high,int level);

int main(){
    char ruler[Len];
    for(int i=1;i<Len-2;++i){
        ruler[i] = ' ';
    }
    ruler[Len - 1] = '\0';
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << '\n';
    for(int i=0;i<=Divs;++i){
        subdivide(ruler,min,max,i);
        cout << ruler << '\n';

        for(int j=1;j<Len-2;++j){
            ruler[j] = ' ';//reset to blank ruler
        }
    }
    return 0;
}

void subdivide(char arr[],int low,int high,int level){
    if(level == 0)return;
    int mid = (low + high) >> 1;
    arr[mid] = '|';
    subdivide(arr,low,mid,level-1);
    subdivide(arr,mid,high,level-1);
}
/*
|                                                               |
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
*/
