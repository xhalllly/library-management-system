#include "head.h"
#include "menu.h"

extern Book *Book_head;
extern Student *Student_head;
extern Manager *Manager_head;

void show_main(void)
{
	system("CLS");
	printf("\n\n\n\n\t\t\t��ӭ�������ͼ���|��Q ��Q)��");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)ѧ����\n");
	printf("\t\t\t\t2)����Ա��\n");
	printf("\t\t\t\t0)�˳�\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_stu(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t ѧ����");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)��¼\n");
	printf("\t\t\t\t2)ע��\n");
	printf("\t\t\t\t3)�һ�����\n");
	printf("\t\t\t\t4)ע��\n");
	printf("\t\t\t\t0)����\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_stu_enter(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t ѧ��ҳ");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)����\n");
	printf("\t\t\t\t2)����\n");
	printf("\t\t\t\t3)����\n");
	printf("\t\t\t\t4)����������\n");
	printf("\t\t\t\t5)�޸�����\n");
	printf("\t\t\t\t6)����Ƽ��鼮\n");
	printf("\t\t\t\t0)����\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_manager(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t ����Ա��");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)��¼\n");
	printf("\t\t\t\t0)����\n");
	printf("\n\t\t\t*************************\n\n");
}
void show_manager_enter(void)
{
	system("CLS");
	printf("\n\n\n\t\t\t\t ����Աҳ");
	printf("\n\t\t\t*************************\n\n");
	printf("\t\t\t\t1)�ϼ��鼮\n");
	printf("\t\t\t\t2)�¼��鼮\n");
	printf("\t\t\t\t3)������\n");
	printf("\t\t\t\t4)����ѧ���˺�\n");
	printf("\t\t\t\t5)�޸�����\n");
	printf("\t\t\t\t0)�˳�\n");
	printf("\n\t\t\t*************************\n\n");
}
