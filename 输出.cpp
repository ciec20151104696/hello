#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char n;
	fp1=fopen("export.gpx","r+");   //以只读的方式打开文件，并用fp指向它
	fp2=fopen("export-result.gpx","w");
	if(fp1==NULL)
	{
		printf("打开文件错误，可能要打开的文件夹不存在！！"); 
		return(-1);
	} 
	else
	{

    	freopen( "export.gpx", "r", stdin );
 		while ( scanf( "%c", &n )!=EOF )
 		printf( "%c", n );
	}
	return 0;
} 
