#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char n;
	fp1=fopen("export.txt","r");   //以只读的方式打开文件，并用fp指向它
	fp2=fopen("export-result.txt","w");
	if（fp1==NULL) 
	{
		printf("打开文件夹错误，可能要打开的文件不存在！")；
		exit(-1));
	}
	else
	{
		n=fgetc(fp1);   //使用fgetc函数读取fp文件中的一个字符 
		while(n!=EOF)   //EOF用来判断文件是否已经读到文件尾 
		{
			printf("%c",n);
			fputc(n,fp2);  //把n变量的内容写到fp2指定的文件export-result.text中 
			n=fgetc("fp1");		//继续读取下一个字符 
		}
		fclose(fp1);   //关闭文件 
		fclose(fp2);
	}
	return 0;
} 
