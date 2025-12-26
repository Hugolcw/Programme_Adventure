在这里给出函数被调用进行测试的例子。例如：
#include "stdio.h"
#define N 100
#define M 200

int my_strcpy_s(char str1[],int x,char str2[]);

void readline(char a[])  //题目保证输入字符串长度在数组长度范围内
{
  char ch;
  int i=0;
  while((ch=getchar())!='\n' )
   a[i++]=ch;
  a[i]='\0';
  return ;   
}

int main()
 {char a[N],b[M];
 int x;
 readline(a);
 readline(b);
 scanf("%d",&x);
  if(!my_strcpy_s(a,x,b))
    puts("error!");
  puts(a);
  return 0;
 }

int my_strcpy_s(char str1[],int x,char str2[])
{
        /* 请在这里填写答案。提示：只需写出函数体(不包括"{" "}")*/

    /* 请在这里填写答案。提示：只需写出函数体(不包括"{" "}")*/
    if (x <= 0) return 0;                 // 无空间可写

    // 拷贝最多 x-1 个字符，预留 '\0'
    int i = 0;
    for (; i < x - 1 && str2[i] != '\0'; ++i) {
        str1[i] = str2[i];
    }
    str1[i] = '\0';

    // 若 str2 未被截断则返回 1，否则返回 0
    return str2[i] == '\0' ? 1 : 0;

}