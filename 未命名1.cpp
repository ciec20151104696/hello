#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char *str;
	int flen;
	int i=0;
	fp=fopen("export.gpx","r+");
	if(fp==NULL)
	{
		printf("无法打开文件，文件错误\n");
		return(-1); 
	}
	fseek(fp,0,SEEK_END);
	flen=ftell(fp);
	str=(char *)malloc(1*flen);
	fread(str,1,flen,fp);
	while(!(str[i]='<'&&str[i+1]='g'&&str[i+2]='p'&&str[i+3]='x'&&str[i+4]='>'))
	{
		if(str[i]='l'&&str[i+1]='a'&&str[i+2]='t')
		{
			printf("纬度：");
			strncpy(lat,9); 
		}
	} 
	free(str);
	fclose(fp);
	return 0;
}
