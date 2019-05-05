#include "head.h"
#include "manager.h"
#include "student.h"
#include "student_func.h"
#include "menu.h"
#include "save_load.h"
#include "other.h"

extern int a;
extern Book *Book_head;
extern Student *Student_head;
extern Manager *Manager_head;

St stut2;

/*����Ա��*/
void Mp::Manager_Port(void)
{
	char mp = '1';

	while (mp != '0')
	{
		show_manager();
		printf("\t\t��");
		scanf("%c", &mp);
		while (getchar() != '\n');
		switch (mp)
		{
		case '1':Manager_Login(); break;
		case '0':break;
		default:printf("\t\t�����������������\n"); Sleep(3000); break;
		}
	}
}
/*����Ա��¼*/
void Mp::Manager_Login(void)
{
	char Manager_num[20];
	char ml = '1', mp;
	Manager *t;
	printf("\n\t\t�����������˺ţ�");
	gets_s(Manager_num);
	t = Manager_check(Manager_num);
	if (!t) {
		printf("\t\t��Ǹ���˺Ų�����\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t�������������룺");
	if (Password_Text_Find(t->man_passw) == 0) {

		printf("\n\t\t���˳���¼ϵͳ������\n");
		Sleep(500);
		return;
	}
	Sleep(500);
	printf("\n\t\t��¼�С�����\n");
	Sleep(500);
	printf("\t\t��¼�ɹ�( ������)��\n");
	Sleep(500);
	printf("\t\t���ڼ��ء�����\n");
	Sleep(1000);


	while (ml != '0')
	{
		show_manager_enter();
		printf("\t\t��");
		scanf("%c", &ml);
		while (getchar() != '\n');
		switch (ml)
		{
		case '1':Manager_Add_Book(); break;
		case '2':Manager_Down_Book(); break;
		case '3':Manager_Look_Book(); break;
		case '4':Manager_Manager_Stu(); break;
		case '5':Manager_Change_Password(t); break;
		case '0':break;
		default:printf("\t\t�����������������QAQ\n"); Sleep(3000); break;
		}
	}



}
/*�˶Թ���Ա�˺�*/
Manager * Mp::Manager_check(char *Manager_num)
{

	Manager *t = Manager_head->next;
	while (t) {
		if (strcmp(Manager_num, t->man_acc) == 0)
			break;
		t = t->next;
	}
	return t;
}
/*����Ա�鿴���*/
void Mp::Manager_Look_Book(void)
{
	char ml;
	printf("\n\t\t����Ա�����ã�\n");
	printf("\t\t��ѡ������ķ�ʽ\n\n");
	printf("\t\t\t1)���������������\n");
	printf("\t\t\t2)���������������\n");

	printf("\t\t��");
	scanf("%c", &ml);
	while (getchar() != '\n');
	switch (ml)
	{
	case '1': Lookofnum(); break;
	case '2': Lookofrest(); break;
	default:printf("\t\t�������QAQ\n"); break;
	}
	printf("\t\t��������˳�");
	getch();
	return;
}
//�������鿴���
void Mp::Lookofnum(void)
{
	if (Book_head->next == NULL)
	{
		printf("\t\t�����鼮QAQ\n");
		return;
	}
	if (Book_head->next->next == NULL)
	{
		return;
	}
	Book *p1, *p2, *p3, *end, *tem;
	Book *head = Book_head;
	end = NULL;
	while (head->next != end) {
		for (p1 = head, p2 = p1->next, p3 = p2->next; p3 != end; p1 = p1->next, p2 = p2->next, p3 = p3->next) {
			if ((strcmp(p2->book_num, p3->book_num)) > 0) {
				p1->next = p2->next;
				p2->next = p3->next;
				p3->next = p2;
				tem = p2;
				p2 = p3;
				p3 = tem;
			}

		}
		end = p2;
	}
	Manager_Print_Book();
}
//�������鿴���
void Mp::Lookofrest(void)
{
	if (Book_head->next == NULL)
	{
		printf("\t\t�����鼮QAQ\n");
		return;
	}
	if (Book_head->next->next == NULL)
	{
		return;
	}
	Book *p1, *p2, *p3, *end, *tem;
	Book *head = Book_head;
	end = NULL;
	while (head->next != end) {
		for (p1 = head, p2 = p1->next, p3 = p2->next; p3 != end; p1 = p1->next, p2 = p2->next, p3 = p3->next) {
			if (p2->book_rest > p3->book_rest) {
				p1->next = p2->next;
				p2->next = p3->next;
				p3->next = p2;
				tem = p2;
				p2 = p3;
				p3 = tem;
			}

		}
		end = p2;
	}
	Manager_Print_Book();
}

//����鵥 
void Mp::Manager_Print_Book(void)
{
	int i = 0, ch, m, n;
	Book *t = Book_head->next;;
	if (t == NULL) {
		printf("\t\tû���κ��鼮��ϢQAQ\n");
		return;
	}
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-20s%-12s%-8s\n\n",
		"���", "����", "����", "���");
	while (t)
	{
		printf("\t %-8s%-20s%-12s%-8d\n\n\n\n",
			t->book_num, t->book_name, t->book_at_name, t->book_rest);
		i++;
		t = t->next;
		if (i % 5 == 0) {
			printf("\t �������ҳ\t");
			system("pause");
			system("CLS");
			printf("\n\n\t**********************************");
			printf("********************************\n\n");
			m = i / 5 + 1;
			if (t != NULL) {
				printf("\t ��%dҳ\n", m);
				printf("\t %-8s%-20s%-12s%-8s\n\n",
					"���", "����", "����", "���");
			}
		}
	}
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
}
/*����Ա�޸�����*/
void Mp::Manager_Change_Password(Manager *Man_num)
{
	char password_tem[20];
	printf("\t\t�����С�����\n");
	Sleep(500);
	printf("\t\t������ԭ���룺");
	if (Password_Text_Find(Man_num->man_passw) == 0) {
		printf("\n\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
		Sleep(1500);
		return;
	}
	printf("\n\t\t��֤�С�����\n");
	Sleep(1000);
	printf("\t\t��֤�ɹ�XD��\n");
	Sleep(500);
	printf("\t\t������������(6~10λ)��");
	Password_Input(password_tem);
	printf("\n\t\t���ٴ����������룺");
	if (Password_Text(password_tem) == 0) {
		printf("\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
		Sleep(1500);
		return;
	}
	Man_num->man_passw[0] = '\0';
	strcat(Man_num->man_passw, password_tem);
	Sleep(500);
	printf("\n\t\t���Եȣ������޸ġ�����\n");
	Sleep(1000);
	printf("\t\t������\n");
	Sleep(1000);
	printf("\t\t������\n");
	Sleep(1000);
	printf("\t\t��ϲ���޸ĳɹ���\n");
	printf("\t\t��������˳�");
	getch();
}
/*�ϼ��鼮*/
void Mp::Manager_Add_Book(void)
{


	char mab = '1';

	while (mab != '0')
	{
		system("CLS");
		printf("\n\n\n\n\t\t\t��ѡ���ϼܵ�����\n\n");
		printf("\t\t\t1)���ӿ��\n");
		printf("\t\t\t2)�ϼ�����\n");
		printf("\t\t\t0)�˳�\n");
		printf("\n\t\t\t��");
		scanf("%c", &mab);
		while (getchar() != '\n');
		switch (mab)
		{
		case '1':Manager_Add_Book1(); break;
		case '2':Manager_Add_Book2(); break;
		case '0':break;
		default:printf("\t\t�����������������\n"); Sleep(3000); break;
		}
	}
}
/*���ӿ��*/
void Mp::Manager_Add_Book1(void)
{
	Book *t;
	int n;
	char ch[20];
	Lookofnum();
	if (!Book_head->next) {
		printf("\t\t�޷����ӿ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t����������ı��:");
	gets_s(ch);
	t = Find_BookofName(ch);
	if (!t) {
		printf("\t\t��Ǹ���޴���\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t����������������");
	scanf("%d", &n);
	getchar();
	t->book_rest += n;
	Sleep(500);
	printf("\t\t�������ӡ�����\n");
	Sleep(500);
	printf("\t\t�ɹ�����%d���鼮\n", n);
	printf("\t\t��������˳�");
	getch();
}
/*�ϼ�����*/
void Mp::Manager_Add_Book2(void)
{

	printf("\t\t������������Ϣ��\n");
	Book *newbook = (Book *)malloc(sizeof(Book));
	newbook->next = NULL;
	Book *t = Book_head;
	printf("\t\t�鼮��ţ�");
	gets_s(newbook->book_num);
	if (Find_BookofName(newbook->book_num)) {
		free(newbook);
		printf("\t\t�������ϼܹ�����ѡ�����ӿ��( ������)��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t������");
	gets_s(newbook->book_name);
	printf("\t\t���ߣ�");
	gets_s(newbook->book_at_name);
	printf("\t\t��棺");
	scanf("%d", &newbook->book_rest);
	getchar();
	Sleep(500);
	printf("\t\t�����ϼܡ�����\n");
	Sleep(500);
	printf("\t\t������\n");
	Sleep(500);
	printf("\t\t������\n");
	Sleep(500);
	printf("\t\t�ϼܳɹ�XD��\n");
	while (t->next) {
		t = t->next;
	}
	t->next = newbook;
	printf("\t\t��������˳�");
	getch();
}
/*����Ա�¼��鼮*/
void Mp::Manager_Down_Book(void)
{
	char book_num[20];
	Book *t = Book_head->next;
	Lookofnum();
	if (!t) {
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t���������¼ܵ��鼮��ţ�");
	gets_s(book_num);
	t = Find_BookofName(book_num);
	if (!t) {
		printf("\t\t��Ǹ���޴��鼮\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	t->book_rest = 0;
	Sleep(500);
	printf("\t\t�����¼ܡ�����\n");
	Sleep(500);
	printf("\t\t�¼ܳɹ���\n");
	printf("\t\t��������˳�");
	getch();

}

/*����Ա����ѧ��*/
void Mp::Manager_Manager_Stu(void)
{

	char mms = '1';

	while (mms != '0')
	{
		system("CLS");
		printf("\n\n\n\n\t\t\t��ѡ��\n\n");
		printf("\t\t\t1)�鿴ѧ������\n");
		printf("\t\t\t2)ǿ��ѧ������\n");
		printf("\t\t\t3)ɾ��ѧ�����벢�黹�����鼮\n");
		printf("\t\t\t0)�˳�\n");
		printf("\n\t\t��");
		scanf("%c", &mms);
		while (getchar() != '\n');
		switch (mms)
		{
		case '1':Manager_Look_Stu(); break;
		case '2':Manager_Return_Stu(); break;
		case '3':Manager_Del_Stu();; break;
		case '0':break;
		default:printf("\t\t�����������������\n"); Sleep(3000); break;
		}
	}
}
/*����Ա�鿴ѧ������*/
void Mp::Manager_Look_Stu(void)
{
	Student *t = Student_head->next;
	printf("\t\t���ڴ�ӡѧ������������\n");
	Sleep(1000);
	if (!t) {
		printf("\n\t\t��Ǹ������ѧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\n     *************************************");
	printf("********************************\n\n");
	printf("      %-10s%-12s%-15s%-10s%-12s%-10s\n\n",
		"����", "ѧ��", "�绰", "�˺�", "����", "��������");
	while (t)
	{
		int n = 0, i;
		for (i = 0; i < 10; i++) {
			if (strcmp(t->stu_bor_book[i], "0") != 0)
				n++;
		}
		printf("      %-10s%-12s%-15s%-10s%-12s%-10d\n",
			t->stu_name, t->stu_num, t->stu_tel,
			t->stu_acc, t->stu_passw, n);
		t = t->next;
	}
	printf("\n     *****************************************");
	printf("****************************\n\n\n");
	printf("\t\t��������˳�");
	getch();

}
/*ǿ�ƻ���*/
void Mp::Manager_Return_Stu(void)
{
	char ch[20];
	Book *a;
	Student *t = Student_head->next;

	if (!t) {
		printf("\n\t\t��Ǹ������ѧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\n\t**********************");
	printf("**********************\n\n");
	printf("\t %-10s%-12s%-10s%-8s\n\n",
		"����", "ѧ��", "�˺�", "��������");
	while (t)
	{
		int n = 0, i;
		for (i = 0; i < 10; i++) {
			if (strcmp(t->stu_bor_book[i], "0") != 0)
				n++;
		}
		printf("\t %-10s%-12s%-10s%-10d\n",
			t->stu_name, t->stu_num, t->stu_acc, n);
		t = t->next;
	}
	printf("\n\t**************************");
	printf("******************\n\n\n");
	printf("\t\t����������ǿ�ƻ����ѧ�ţ�");
	gets_s(ch);
	t = stut2.Find_Stu(ch);
	if (!t) {
		printf("\t\t��Ǹ���޸�ѧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	int n = 0, i;
	for (i = 0; i < 10; i++) {
		if (strcmp(t->stu_bor_book[i], "0") != 0)
			n++;
	}
	if (!n) {
		printf("\t\t��Ǹ����ѧ����������Ϊ0���޷�ǿ�ƻ���\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	for (i = 0; i < 10; i++) {
		if (strcmp(t->stu_bor_book[i], "0") != 0) {
			a = Find_BookofName(t->stu_bor_book[i]);
			a->book_rest += 1;
			t->stu_bor_book[i][0] = '0';
			t->stu_bor_book[i][1] = '\0';
		}
	}
	printf("\t\t����ǿ�ƻ��顤����\n");
	Sleep(500);
	printf("\t\t������\n");
	Sleep(500);
	printf("\t\tǿ�ƻ���ɹ���\n");
	printf("\t\t��������˳�");
	getch();
	return;
}

/*ɾ��ѧ�����벢�黹�����鼮*/
void Mp::Manager_Del_Stu(void)
{
	int i;
	char bh[20];
	Book *a;
	Student *head = Student_head;
	Student *t = Student_head->next;
	printf("\t\t���ڴ�ӡѧ������������\n");
	Sleep(1000);
	if (!t) {
		printf("\n\t\t��Ǹ������ѧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\n     *************************************");
	printf("********************************\n\n");
	printf("      %-10s%-12s%-15s%-10s%-12s%-10s\n\n",
		"����", "ѧ��", "�绰", "�˺�", "����", "��������");
	while (t)
	{
		int n = 0, i;
		for (i = 0; i < 10; i++) {
			if (strcmp(t->stu_bor_book[i], "0") != 0)
				n++;
		}
		printf("      %-10s%-12s%-15s%-10s%-12s%-10d\n",
			t->stu_name, t->stu_num, t->stu_tel,
			t->stu_acc, t->stu_passw, n);
		t = t->next;
	}
	printf("\n     *****************************************");
	printf("****************************\n\n\n");

	printf("\t\t����������ɾ��ѧ����ѧ�ţ�");
	gets_s(bh);
	t = stut2.Find_Stu(bh);
	if (!t) {
		printf("\t\t��Ǹ���޸�ѧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	Sleep(500);
	printf("\t\t����ɾ��������\n");
	Sleep(500);
	printf("\t\tɾ���ɹ���\n");
	for (i = 0; i < 10; i++) {
		if (strcmp(t->stu_bor_book[i], "0") != 0) {
			a = Find_BookofName(t->stu_bor_book[i]);
			a->book_rest += 1;
		}
	}
	t = Student_head->next;
	while (t) {
		if (strcmp(bh, t->stu_num) == 0) {
			head->next = t->next;

			free(t);
			break;
		}
		head = t;
		t = t->next;
	}
	printf("\t\t��������˳�\n");
	getch();
	return;
}
