#include<stdio.h>
 int main(){
 FILE *fp;
 char *str;
 char s;

 fp=fopen("demo.txt","r");// demo.txt //:FirstSemesterMCA
 printf("fp: [%p]\n",fp);
//  while(fgets(str,6,fp)!=NULL)puts(str);
char line[100];
    while (fgets(line, 6, fp)) {
        // printf("%s", line);
        puts(line);
    }
 fclose(fp);

 int a[5]= {1, 2, 4, 5};
 printf("a: %d\n", a[7]);
 return 0;
 }