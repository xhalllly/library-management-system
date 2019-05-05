#include "head.h"
#include "manager.h"
#include "student.h"
#include "student_func.h"
#include "menu.h"
#include "save_load.h"
#include "other.h"

Book *Book_head;
Student *Student_head;
Manager *Manager_head;

int main(void)
{
	int d = 0;

	Mp mmr;
	St stut;

	Book_head = (Book *)malloc(sizeof(Book));
	Student_head = (Student *)malloc(sizeof(Student));
	Manager_head = (Manager *)malloc(sizeof(Manager));

	Book_head->next = Book_load();
	Student_head->next = Student_load();
	Manager_head->next = Manager_load();

	char ma = '1';

	while (ma != '0')
	{
		show_main();
		printf("\t\t\t：");
		scanf("%c", &ma);
		while (getchar() != '\n');
		switch (ma)
		{
		case '1':stut.Student_Port(); break;//学生端
		case '2':mmr.Manager_Port(); break;//管理员端
		case '0':Massage_Save(); break;//退出程序，保存链表数据至文件中
		default:printf("\t\t输入错误，请重新输入\n"); Sleep(3000); break;
		}
	}
	system("PAUSE");
	return 0;
}