#include<iostream> 
#include<string.h>
using namespace std;
void CharCount(char path[]);  //�ַ�ͳ�ƺ���
void WordCount(char path[]);  //����ͳ�ƺ���
void LineCount(char path[]);  //����ͳ�ƺ���
void Muiltiple(char path[]);  //�ۺ�ͳ�ƺ��������������У����У�ע����
int main()
{
    char input[100],path[50];
    gets(input);
    int count=strlen(input);
    strncpy(path, input + 10,  count - 10);
    path[count - 9] = '\0';
    //cout << path << endl;
    int check = 1;
    while (check)
    {
        int i = 7;
        if ((input[i] == '-') && (input[i + 1] == 'c'))
        {
            CharCount(path);
            break;
        }
        if ((input[i] == '-') && (input[i + 1] == 'w'))
        {
            WordCount(path);
            break;
        }
        if ((input[i] == '-') && (input[i + 1] == 'l'))
        {
            LineCount(path);
            break;
        }
        if ((input[i] == '-') && (input[i + 1] == 'a'))
        {
            Muiltiple(path);
            break;
        }//��ȡ�ļ���
    }
    system("pause");
    return 0;
}
void CharCount(char path[]) //�ַ�ͳ�ƺ���
{
    FILE *fp=NULL;
    int c = 0;
    char ch;
    cout << path<<endl;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k-1) = '\0';
    //cout << path3<<endl;
    if ((fp = fopen(path3 , "r")) == NULL)
    {
        printf("file read failure.");
        exit(0);
    }
    ch = fgetc(fp);
    while (ch != EOF)
    {
        c++;
        ch = fgetc(fp);
    }
    cout << "char count is ��" << c << endl;
    c--;
    fclose(fp);
}

void WordCount(char path[]) //����ͳ�ƺ���
{
    FILE *fp;
    int w = 0;
    char ch;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k - 1) = '\0';
    if ((fp = fopen(path3, "r")) == NULL)
    {
        printf("file read failure.");
        exit(0);
    }
    //fgetc()�᷵�ض�ȡ�����ַ���������EOF���ʾ�����ļ�β��������˴���
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))
        {
            while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9') || ch == '_')
            {
                ch = fgetc(fp);
            }
            w++;
            ch = fgetc(fp);
        }
        else
        {
            ch = fgetc(fp);
        }
    }
    printf("word count is ��%d.\n", w);
    fclose(fp);

}

void LineCount(char path[]) //����ͳ�ƺ���
{
    FILE *fp;
    int l = 1;
    char ch;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k - 1) = '\0';
    if ((fp = fopen(path3, "r")) == NULL)
    {
        printf("file read failure.");
        exit(0);
    }
    //fgetc()�᷵�ض�ȡ�����ַ���������EOF���ʾ�����ļ�β��������˴���
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            l++;
            ch = fgetc(fp);
        }
        else
        {
            ch = fgetc(fp);
        }
    }
    l--;
    printf("line count is ��%d.\n", l);
    fclose(fp);
}

void Muiltiple(char path[])  //�ۺ�ͳ�ƺ��������������У����У�ע����
{
    FILE *fp;
    char ch;
    char *path3 = path;
    int k = strlen(path);
    *(path3 + k - 1) = '\0';
    int c = 0, e = 0, n = 0;
    if ((fp = fopen(path3, "r")) == NULL)
    {
        printf("file read failure.");
        exit(0);
    }
    //fgetc()�᷵�ض�ȡ�����ַ���������EOF���ʾ�����ļ�β��������˴���
    ch = fgetc(fp);
    while (ch != EOF)
    {
        if (ch == '{' || ch == '}')
        {
            e++;
            ch = fgetc(fp);
        }
        else if (ch == '\n')
        {
            ch = fgetc(fp);
            while (ch == '\n')
            {
                e++;
                ch = fgetc(fp);
            }
        }
        else if (ch == '/')
        {
            ch = fgetc(fp);
            if (ch == '/')
            while (ch != '\n')
            {
                ch = fgetc(fp);
            }
            n++;
            ch = fgetc(fp);
        }
        else
        {
            c++;
            while (ch != '{'&&ch != '}'&&ch != '\n'&&ch != '/'&&ch != EOF)
            {
                ch = fgetc(fp);
            }
        }

    }
    printf("code line count is ��%d.\n", c);
    printf("empt line count is ��%d.\n", e);
    printf("note line count is ��%d.\n", n);
    fclose(fp);
}

