#include<stdio.h>
//String Copy
void str_cpy(char * dest_str,char * src_str){
    char * stmp = src_str;
    char * dtmp = dest_str;
    while(*stmp != '\0'){
        *dtmp = *stmp;
        stmp++;
        dtmp++;
    }
    *dtmp = '\0';
}
//String Concatenate
void str_cat(char * dest_str,const char * src_str){
    char * stmp = src_str;
    char * dtmp = dest_str;
    while(*dtmp != '\0')dtmp++;
    while(*stmp != '\0'){
        *dtmp = *stmp;
        stmp++;
        dtmp++;
    }
    *dtmp = '\0';
}