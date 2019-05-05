#include "head.h"
#include "manager.h"
#include "student.h"
#include "student_func.h"
#include "menu.h"
#include "save_load.h"
#include "other.h"

extern Book *Book_head;
extern Student *Student_head;
extern Manager *Manager_head;

/*随机获取字符串*/
void RandStr(int l, char* ch)
{
	int flag, i;
	srand((unsigned)time(NULL));
	for (i = 0; i < l; i++)
	{
		flag = rand() % 3;
		switch (flag)
		{
		case 0:
			ch[i] = 'A' + rand() % 26;
			break;
		case 1:
			ch[i] = 'a' + rand() % 26;
			break;
		case 2:
			ch[i] = '0' + rand() % 10;
			break;
		default:
			ch[i] = 'x';
			break;
		}
	}
	ch[l] = '\0';
}

/*密码的输入*/
void Password_Input(char *Password)
{
	char ch;
	int i;
	int len = 4;
	while (len < 6 || len>10) {
		for (i = 0; i < 20; i++) {
			ch = getch();
			if (ch == 8) {
				if ((i - 1) >= 0) {
					i -= 2;
					printf("\b \b");
				}
				else
					i--;
				continue;
			}
			if (ch == '\r')
				break;
			Password[i] = ch;
			printf("*");
		}
		Password[i] = '\0';
		len = strlen(Password);
		if (len < 6 || len>10)
			printf("\n\t\t输入错误，请输入长度为6的密码:");
	}
}
/*检测密码*/
int Password_Text(char *Password)
{
	char password_tem[20];
	int tem = 0;
	int n = 0;    //检测输入次数
	while (n != 3) {
		Password_Input(password_tem);
		if (strcmp(password_tem, Password) == 0) {
			tem = 1;
			break;
		}
		else {
			n++;
			if (n != 3) {
				printf("\n\t\t两次输入密码不一致，请重新输入,您还有%d次输入机会：", 3 - n);
			}
			else if (n == 3)
				printf("\n\t\t输入错误\n");
		}
	}
	return tem;
}
/*密码验证*/
int Password_Text_Find(char *Password)
{
	char password_tem[20], mp, c = 0;
	int tem = 0;
	int n = 0;    //检测输入次数
	while (n != 3) {
		Password_Input(password_tem);
		if (strcmp(password_tem, Password) == 0) {
			tem = 1;
			break;
		}

		else {
			n++;
			if (n == 3) {
				printf("\n\t\t您已输错三次,");
				system("pause");
			}
			else {
				printf("\n\n\t\t输入错误，请重新输入，你还有%d次机会\n", 3 - n);
				printf("\t\t1）按esc放弃输入  2）按其他键,重新输入6位密码\n\n\t\t");
				while (getch() == (27))  //ESC　退出 
				{
					return tem;
				}
			}
		}
	}
	return tem;
}



