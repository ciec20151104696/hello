#include "stdio.h"
#include <stdlib.h>

main()
{
   FILE *fp1;//定义文件流指针，用于打开读取的文件
   FILE *fp2;//定义文件流指针，用于打开写操作的文件
   char text[1024];//定义一个字符串数组，用于存储读取的字符
   char *str;
   int flen=0;
   fp1 = fopen("export.gpx","r");//只读方式打开文件export.gpx
   fp2 = fopen("export2.txt","w");//写方式打开文件export-rest.txt
   while(fgets(text,1024,fp1)!=NULL)//逐行读取fp1所指向文件中的内容到text中
   {
        puts(text);//输出到屏幕
        fputs(text,fp2);//将内容写到fp2所指向文件中
   }
   fseek(fp1,0,SEEK_END);
   flen=ftell(fp1);
   str=(char *)malloc(1*flen);
   fread(str,1,flen,fp1);
   printf("len=%d    %c\n",flen,str[0]);
   printf("%s\n",&str[10]);
   fclose(fp1);//关闭文件a.txt，有打开就要有关闭
   fclose(fp2);//关闭文件b.txt
}
