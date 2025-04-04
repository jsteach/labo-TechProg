#include <stdio.h>n
#include <string.h>

size_t strlen(char* str){//O(n)
    size_t i = 0;
    while(str[i] != '\0'){
        ++i;
    }
    return i;//i = 21
}

//Main fourni à titre d'exemple
int main()
{
   char* str = "Hello this is a test";
   char* find = "test";
   static char sub[128] = {0};//O(1)
    size_t len = strlen(str);//O(n)
   while(1){
       int i = 0;
       while(str[i] != ' '){
           sub[i] = str[i];
           if(strlen(sub) >= len){//O(n)
               break;
           }
           ++i;
       }
       str = &str[i];
       if(strcmp(sub,find) == 0){//O(n)
           printf("Found\n");
       }
       if(i > len || str[1] == '\0'){
           break;
       }
   }
    return 0;
}
//O(n)