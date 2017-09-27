#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *cp;
char fname[20],buf[100];
int num;

struct key{
       char word[10];
       int count;
}keyword[]={"if",0,"char",0,"int",0,"else",0,"while",0,"return",0};

char *getword(FILE *fp){
     int i=0;
     char c;
     c=fgetc(fp);
     if(c==EOF)
         return NULL;
     while(c!=EOF && c!=' ' && c!='\t' && c!='\n'){
                  buf[i++]=c;
                  c=fgetc(fp);
     }
     buf[i]='\0';
     return (buf);
}

void find(char *p){
     int i;
     char *q;
     for(i=0;i<num;i++){
         q=keyword[i].word;
         if(strcmp(p,q)==0){
             keyword[i].count++;
             return;
         }
     }
}

int main(int argc, char *argv[])
{
    int i;
    char *word;
    clrscr();
    printf("Input file name:");
    scanf("%s",fname);
    if((cp=fopen(fname,"r"))==NULL){
        printf("File open error:%s\n",fname);
        exit(0);
    }
    num=sizeof(keyword)/sizeof(struct key);
    while(!feof(cp))
        if((word=getword(cp))!=NULL)
            find(word);
    fclose(cp);
    for(i=0;i<num;i++)
        printf("keyword:%-20s count=%d\n", keyword[i].word,keyword[i].count);
 
    return 0;
}
