#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char n;
	fp1=fopen("export.gpx","r+");   //��ֻ���ķ�ʽ���ļ�������fpָ����
	fp2=fopen("export-result.gpx","w");
	if(fp1==NULL)
	{
		printf("���ļ����󣬿���Ҫ�򿪵��ļ��в����ڣ���"); 
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
