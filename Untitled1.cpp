#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char n;
	fp1=fopen("export.txt","r");   //��ֻ���ķ�ʽ���ļ�������fpָ����
	fp2=fopen("export-result.txt","w");
	if��fp1==NULL) 
	{
		printf("���ļ��д��󣬿���Ҫ�򿪵��ļ������ڣ�")��
		exit(-1));
	}
	else
	{
		n=fgetc(fp1);   //ʹ��fgetc������ȡfp�ļ��е�һ���ַ� 
		while(n!=EOF)   //EOF�����ж��ļ��Ƿ��Ѿ������ļ�β 
		{
			printf("%c",n);
			fputc(n,fp2);  //��n����������д��fp2ָ�����ļ�export-result.text�� 
			n=fgetc("fp1");		//������ȡ��һ���ַ� 
		}
		fclose(fp1);   //�ر��ļ� 
		fclose(fp2);
	}
	return 0;
} 
