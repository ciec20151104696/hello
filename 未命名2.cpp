#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
int main()
{
	FILE *fp,*fp1;
	char *str;
	int flen;
	int i=0;
	char lon[50];
	char lat[50];
	char date[50];
	char time[50];
	fp=fopen("export.gpx","r");
	fp1=fopen("export.csv","w");
	if(fp==NULL)
	{
		printf("无法打开文件，文件错误\n");
		return(-1); 
	}
	fseek(fp,0,SEEK_END);
 	flen=ftell(fp);
	str=(char *)malloc(1*flen); 
	fseek(fp,0,SEEK_SET);
	fread(str,1,flen,fp);
	str[flen]='\0';	
	fprintf(fp1,"经度,纬度,日期,时间\n");
	while(!(str[i]=='<'&&str[i+1]=='/'&&str[i+2]=='g'&&str[i+3]=='p'&&str[i+4]=='x'&&str[i+5]=='>'))
	{
		if(str[i]==' '&&str[i+1]=='l'&&str[i+2]=='a'&&str[i+3]=='t')
		{
			strncpy(lat,&str[i+6],9);
			strncpy(lon,&str[i+22],10);
			strncpy(date,&str[i+44],10);
			strncpy(time,&str[i+55],8);
			lat[9]='\0';
			lon[10]='\0';
			date[10]='\0';
			time[8]='\0';
			printf("lat:%s  ",lat);
			printf("lon:%s  ",lon);
			printf("date:%s  ",date);
			printf("time:%s\n",time);
			fprintf(fp1,"%s,%s,%s,%s\n",lat,lon,date,time);
		}
		i++;
	}
	free(str);
	fclose(fp1);
	fclose(fp);
	return 0;
}
