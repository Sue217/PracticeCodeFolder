//Delete all '#'
#include<stdio.h>
void fun(char * s){
    int i,j = 0;
    for(i=0;s[i]!='\0';i++){
        if(s[i] != '#')s[j++] = s[i];
    }
    s[j] = '\0';
}
int main(){
    char str[81];
    int i;
    for(i=0;(str[i] = getchar())!='\n';i++);
    if(str[i] == '\n')str[i] = '\0';
    fun(str);
    //puts(str);
    printf("%s\n",str);
    return 0;
}
//In:##w#el#c#om#e###!
//Out:welcome!