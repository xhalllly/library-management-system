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

void Find_Book(void)
{
	Book *t = Book_head->next;
	char book_n[20];
	if (t == NULL) {
		printf("\t\t��Ǹ�������鼮\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t����������Ҫ���ҵ�������");
	gets_s(book_n);
	while (t) {
		if (strcmp(book_n, t->book_name) == 0)
			break;
		t = t->next;
	}
	if (t == NULL) {
		printf("\t\t��Ǹ���޴��鼮QAQ\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	t = Book_head->next;
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-20s%-12s%-8s\n\n",
		"���", "����", "����", "���");
	while (t) {
		if (strcmp(book_n, t->book_name) == 0)
			printf("\t %-8s%-20s%-12s%-8d\n",
				t->book_num, t->book_name, t->book_at_name, t->book_rest);
		t = t->next;
	}
	printf("\n\t**************************************");
	printf("****************************\n\n\n");
	printf("\n\t\t��������˳�");
	getch();

}

Book *Find_BookofName(char *Book_num)
{
	Book *t = Book_head->next;
	while (t) {
		if (strcmp(Book_num, t->book_num) == 0)
			return t;
		t = t->next;
	}
}
void Change_Stupassword(Student *Stu_num)
{
	char password_tem[20];
	printf("\t\t�����С�����\n");
	Sleep(500);
	printf("\t\t������ԭ���룺");
	if (Password_Text_Find(Stu_num->stu_passw) == 0) {
		printf("\n\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
		Sleep(1500);
		return;
	}
	printf("\n\t\t��֤�С�����\n");
	Sleep(1000);
	printf("\t\t��֤�ɹ���\n");
	Sleep(500);
	printf("\t\t������������(6~10λ)��");
	Password_Input(password_tem);
	printf("\n\t\t���ٴ����������룺");
	if (Password_Text(password_tem) == 0) {
		printf("\t\t�Ѿ����������������Σ����˳��޸�����ϵͳ������\n");
		Sleep(3000);
		return;
	}
	Stu_num->stu_passw[0] = '\0';
	strcat(Stu_num->stu_passw, password_tem);
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
void Find_Theborrow(Student *Stu_num)
{
	int tem = 0, i;
	Book *t;
	printf("\t\t�����С�����\n");
	Sleep(1000);
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
			tem = 1;
			break;
		}
	}
	if (tem == 0) {
		printf("\t\t���޽����¼\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\n\n\t*************************");
	printf("********************************\n\n");
	printf("\t %-8s%-20s%-12s\n\n",
		"���", "����", "����");
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
			t = Find_BookofName(Stu_num->stu_bor_book[i]);
			printf("\t %-8s%-20s%-12s%\n",
				t->book_num, t->book_name, t->book_at_name);
		}
	}
	printf("\n\t*****************************");
	printf("****************************\n\n\n");
	printf("\n\t\t��������˳�");
	getch();
}

void Stu_Borrow(Student *Stu_num)
{
	int n = 0, i;
	Book *t = Book_head;
	char numb[10], str;
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") != 0)
			n++;
	}
	printf("\n\t\t��ӭ�������ϵͳ\n");
	printf("\n\t\t�����С�����\n");
	Sleep(1000);
	if (n == 10) {
		printf("\t\t���ã����ѽ���10�����ѵ��������޶");
		printf("\t\t���ȹ黹�ѽ��鼮\n\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	printf("\t\t���ѽ��鼮%d�������ɽ�%d��\n", n, 10 - n);
	printf("\t\t�鵥����\n");
	Print_Book();
	printf("\n\t\t��ѡ���������ı�ţ�");
	gets_s(numb);
	t = Book_exit(numb);

	printf("\t\t���ڰ�������\n");
	Sleep(1000);
	if (!t) {
		printf("\t\t��Ǹ���޴��飬����ʧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	if (t->book_rest == 0) {
		printf("\t\t��Ǹ����治�㣬����ʧ��\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	if (Ifborrow(Stu_num, numb)) {
		printf("\t\t��Ǹ�����ѽ�����飬�����ظ�����\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") == 0) {
			Stu_num->stu_bor_book[i][0] = '\0';
			strcat(Stu_num->stu_bor_book[i], numb);
			t->book_rest--;
			break;
		}
	}
	printf("\t\t������\n");
	printf("\t\t��ϲ������ɹ���\n");
	printf("\t\t��������˳�");
	getch();
	return;
}
void Recom_Book()
{
	int i, count = 0;// , c = 0;
	char password[20];
	Book *p;
	
	srand((unsigned)time(NULL));
	i = rand() % 15 + 1;
	p = Book_head->next;
	while (p != NULL && count < i)
	{
		p = p->next;
		count++;
	};
	printf("\t\t********************************\n\n");
	printf("\t\tΪ���Ƽ������鼮��\n\n");
	printf("\t\t%s\t %s\n\n", p->book_num, p->book_name);
	printf("\t\t********************************\n\n");
	system("pause");
	return;
}

/*��ӡ�鵥*/
void Print_Book(void)
{
	int i = 0, ch, m, n;
	Book *t = Book_head->next;;
	if (t == NULL) {
		printf("\t\t��Ǹ�������ϼ��鼮\n");
		return;
	}
	printf("\n\n\t**********************************");
	printf("********************************\n\n");
	printf("\t %-8s%-20s%-12s%-8s\n\n",
		"���", "����", "����", "���");
	while (t)
	{
		printf("\t %-8s%-20s%-12s%-8d\n",
			t->book_num, t->book_name, t->book_at_name, t->book_rest);
		i++;
		t = t->next;
		if (i % 5 == 0) {
			printf("�������ҳ(���ȼ�ס���)\t");
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
/*Ѱ�Ҹ����Ƿ����*/
Book *Book_exit(char *Book_num)
{

	Book *t = Book_head->next;
	while (t) {
		if (strcmp(t->book_num, Book_num) == 0)
			break;
		t = t->next;
	}
	return t;
}
/*��ѯѧ���Ƿ�������*/
int Ifborrow(Student *Stu_num, char *Book_num)
{
	int tem = 0, i;
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], Book_num) == 0) {
			tem = 1;
			break;
		}
	}
	return tem;
}
/*ѧ������*/
void Stu_Back(Student *Stu_num)
{
	char book_num[15];
	int tem = 0, i;

	printf("\n\t\t��ӭ���뻹��ϵͳ\n");
	printf("\n\t\t�����С�����\n");
	Sleep(500);
	printf("\n\t\t���ڲ����ѽ��鼮������\n");
	Sleep(500);
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
			tem = 1;
			break;
		}
	}
	if (tem == 0) {
		printf("\n\t\t���޽����¼\n");
		printf("\n\t\t��������˳�");
		getch();
		return;
	}
	Print_Borbook(Stu_num);
	printf("\n\t\t��������ı�Ž��й黹��\n");
	gets_s(book_num);
	tem = 0;
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], book_num) == 0) {
			tem = 1;
			break;
		}
	}
	if (!tem) {
		printf("\t\t���������δ�������\n");
		printf("\t\t��������˳�");
		getch();
		return;
	}

	Sleep(500);
	printf("\t\t���ڹ黹������\n");
	Sleep(500);
	Bake_Book(Stu_num, book_num);
	printf("\t\t�黹�ɹ���\n");
	printf("\t\t��������˳�");
	getch();
}
/*��ӡ�����鼮*/
void Print_Borbook(Student *Stu_num)
{

	int tem = 0, i;
	Book *t;
	printf("\n\n\t*************************");
	printf("********************************\n\n");
	printf("\t %-8s%-20s%-12s\n\n", "���", "����", "����");
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], "0") != 0) {
			t = Find_BookofName(Stu_num->stu_bor_book[i]);
			printf("\t %-8s%-20s%-12s\n",
				t->book_num, t->book_name, t->book_at_name);
		}
	}
	printf("\n\t*****************************");
	printf("****************************\n\n\n");
}
/*����������*/
void Bake_Book(Student *Stu_num, char *Book_num)
{
	int i;
	Book *t;
	for (i = 0; i < 10; i++) {
		if (strcmp(Stu_num->stu_bor_book[i], Book_num) == 0) {
			Stu_num->stu_bor_book[i][0] = '0';
			Stu_num->stu_bor_book[i][1] = '\0';
			break;
		}
	}
	t = Find_BookofName(Book_num);
	t->book_rest++;
}
