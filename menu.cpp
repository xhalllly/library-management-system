#include "head.h"
#include "menu.h"

extern Book *Book_head;
extern Student *Student_head;
extern Manager *Manager_head;

void show_main(void)
{
	system("CLS");
	printf("\n\n\n\n\t\t\t欢迎来到青大图书馆|。Q ωQ)っ");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)学生端\n");
	printf("\t\t\t\t2)管理员端\n");
	printf("\t\t\t\t0)退出\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_stu(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t 学生端");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)登录\n");
	printf("\t\t\t\t2)注册\n");
	printf("\t\t\t\t3)找回密码\n");
	printf("\t\t\t\t4)注销\n");
	printf("\t\t\t\t0)返回\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_stu_enter(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t 学生页");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)借书\n");
	printf("\t\t\t\t2)还书\n");
	printf("\t\t\t\t3)查书\n");
	printf("\t\t\t\t4)浏览借阅情况\n");
	printf("\t\t\t\t5)修改密码\n");
	printf("\t\t\t\t6)随机推荐书籍\n");
	printf("\t\t\t\t0)返回\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_manager(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t 管理员端");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)登录\n");
	printf("\t\t\t\t0)返回\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_manager_enter(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t 管理员页");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)上架书籍\n");
	printf("\t\t\t\t2)下架书籍\n");
	printf("\t\t\t\t3)浏览书架\n");
	printf("\t\t\t\t4)管理学生账号\n");
	printf("\t\t\t\t5)修改密码\n");
	printf("\t\t\t\t0)退出\n");
	printf("\n\t\t\t*************************\n\n");
}
