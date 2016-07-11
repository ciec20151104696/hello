#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *str;
	int len;
	int i=0;
	char lon[10];
	char lat[15];
	char time[20];
	fp=fopen("export.gpx","r");
	if(fp==NULL)
	{
		printf("文件打开失败，文件错误！\n");
		return(-1);
	}
	fseek(fp,0,SEEK_END);
	len=ftell(fp);
	str=(char *)malloc(len);
	fseek(fp,0,SEEK_SET);
	fread(str,1,len,fp);
	while(!(str[i]=='<'&&str[i+1]=='g'&&str[i+2]=='p'&&str[i+3]=='x'&&str[i+4]=='>'))
	{
		if(str[i]==' '&&str[i+1]=='l'&&str[i+2]=='a'&&str[i+3]=='t')
		{
			strncpy(lat,&str[i+6],9);
			strncpy(lon,&str[i+22],10);
			strncpy(time,&str[i+55],20);
			lat[9]='\0';
			lon[10]='\0';
			time[20]='\0';
			printf("%s %s %s",lat,lon,time);
		}
	}
	free(str);
	fclose(fp);
	return 0;
}
