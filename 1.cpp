#include "stdio.h"
#include <stdlib.h>

main()
{
   FILE *fp1;//�����ļ���ָ�룬���ڴ򿪶�ȡ���ļ�
   FILE *fp2;//�����ļ���ָ�룬���ڴ�д�������ļ�
   char text[1024];//����һ���ַ������飬���ڴ洢��ȡ���ַ�
   char *str;
   int flen=0;
   fp1 = fopen("export.gpx","r");//ֻ����ʽ���ļ�export.gpx
   fp2 = fopen("export2.txt","w");//д��ʽ���ļ�export-rest.txt
   while(fgets(text,1024,fp1)!=NULL)//���ж�ȡfp1��ָ���ļ��е����ݵ�text��
   {
        puts(text);//�������Ļ
        fputs(text,fp2);//������д��fp2��ָ���ļ���
   }
   fseek(fp1,0,SEEK_END);
   flen=ftell(fp1);
   str=(char *)malloc(1*flen);
   fread(str,1,flen,fp1);
   printf("len=%d    %c\n",flen,str[0]);
   printf("%s\n",&str[10]);
   fclose(fp1);//�ر��ļ�a.txt���д򿪾�Ҫ�йر�
   fclose(fp2);//�ر��ļ�b.txt
}
