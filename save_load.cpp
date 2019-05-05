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

Book *Book_load()
{
	FILE *fp;
	int b = 0;
	Book *h = NULL, *t = h, *p;
	if ((fp = fopen("Booknode.txt", "r")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	getc(fp);
	if (feof(fp)) {
		fclose(fp);
		return NULL;
	}
	rewind(fp);  //ʹ�ļ�λ��ָ�����¶�λ��fp�ļ��Ŀ�ʼλ��
	while (!feof(fp)) {
		p = (Book *)malloc(sizeof(Book));
		p->next = NULL;
		fscanf(fp, "%s", p->book_num);
		fscanf(fp, "%s", p->book_name);
		fscanf(fp, "%s", p->book_at_name);
		fscanf(fp, "%d", &p->book_rest);
		if (h == NULL)
			h = p;
		else
			t->next = p;
		t = p;
		b++;
	}
	fclose(fp);
	return h;
}
/*��ѧ���ļ��е���Ϣ������ѧ������*/
Student *Student_load(void)
{
	FILE *fp;
	Student *h = NULL, *t = h, *p;
	int i;
	if ((fp = fopen("Studentnode.txt", "r")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	getc(fp);
	if (feof(fp)) {
		fclose(fp);
		return NULL;
	}
	rewind(fp);
	while (!feof(fp)) {
		p = (Student *)malloc(sizeof(Student));
		p->next = NULL;
		fscanf(fp, "%s", p->stu_acc);
		fscanf(fp, "%s", p->stu_passw);
		fscanf(fp, "%s", p->stu_find_question);
		fscanf(fp, "%s", p->stu_find_passw);
		fscanf(fp, "%s", p->stu_num);
		fscanf(fp, "%s", p->stu_name);
		fscanf(fp, "%s", p->stu_tel);
		for (i = 0; i < 10; i++) {
			fscanf(fp, "%s", p->stu_bor_book[i]);
		}
		int len = strlen(p->stu_passw);			//�������
		for (i = 0; i < len; i++) {
			p->stu_passw[i] = p->stu_passw[i] - (i % 4 + 1);
		}
		len = strlen(p->stu_find_passw);			//�ܱ��������
		for (i = 0; i < len; i++) {
			p->stu_find_passw[i] = p->stu_find_passw[i] - (i % 4 + 1);
		}
		if (h == NULL)
			h = p;
		else
			t->next = p;
		t = p;
	}
	fclose(fp);
	return h;
}
Manager *Manager_load(void)
{
	FILE *fp;
	Manager *h = NULL, *t = h, *p;
	int i;
	if ((fp = fopen("Managernode.txt", "r")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	getc(fp);
	if (feof(fp)) {
		fclose(fp);
		return NULL;
	}
	rewind(fp);
	while (!feof(fp)) {
		p = (Manager *)malloc(sizeof(Manager));
		p->next = NULL;
		fscanf(fp, "%s", p->man_name);
		fscanf(fp, "%s", p->man_acc);
		fscanf(fp, "%s", p->man_passw);
		int len = strlen(p->man_passw);			//�������
		for (i = 0; i < len; i++) {
			p->man_passw[i] = p->man_passw[i] - (i % 4 + 1);

		}
		if (h == NULL)
			h = p;
		else
			t->next = p;
		t = p;
	}
	fclose(fp);
	return h;
}
/*�����鼮�������ļ�*/
void Save_Book(void)
{
	FILE *fp;
	Book *t = Book_head->next;
	if (!t)
		return;
	if ((fp = fopen("Booknode.txt", "w+")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	while (t->next) {
		fprintf(fp, "%s ", t->book_num);
		fprintf(fp, "%s ", t->book_name);
		fprintf(fp, "%s ", t->book_at_name);
		fprintf(fp, "%d\n", t->book_rest);
		t = t->next;
	}
	fprintf(fp, "%s ", t->book_num);
	fprintf(fp, "%s ", t->book_name);
	fprintf(fp, "%s ", t->book_at_name);
	fprintf(fp, "%d", t->book_rest);
	fclose(fp);
}
/*����ѧ���������ļ�*/
void Save_Student(void)
{
	FILE *fp;
	Student *t = Student_head->next;
	int i;
	if (!t)
		return;
	if ((fp = fopen("Studentnode.txt", "w+")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	while (t->next) {
		int len = strlen(t->stu_passw);			//�������
		for (i = 0; i < len; i++) {
			t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
		}
		len = strlen(t->stu_find_passw);			//�ܱ��������
		for (i = 0; i < len; i++) {
			t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
		}
		fprintf(fp, "%s ", t->stu_acc);
		fprintf(fp, "%s ", t->stu_passw);
		fprintf(fp, "%s ", t->stu_find_question);
		fprintf(fp, "%s ", t->stu_find_passw);
		fprintf(fp, "%s ", t->stu_num);
		fprintf(fp, "%s ", t->stu_name);
		fprintf(fp, "%s ", t->stu_tel);
		for (i = 0; i < 9; i++) {
			fprintf(fp, "%s ", t->stu_bor_book[i]);
		}
		fprintf(fp, "%s\n", t->stu_bor_book[9]);
		t = t->next;
	}

	int len = strlen(t->stu_passw);			//�������
	for (i = 0; i < len; i++) {
		t->stu_passw[i] = t->stu_passw[i] + (i % 4 + 1);
	}
	len = strlen(t->stu_find_passw);			//�ܱ��������
	for (i = 0; i < len; i++) {
		t->stu_find_passw[i] = t->stu_find_passw[i] + (i % 4 + 1);
	}
	fprintf(fp, "%s ", t->stu_acc);
	fprintf(fp, "%s ", t->stu_passw);
	fprintf(fp, "%s ", t->stu_find_question);
	fprintf(fp, "%s ", t->stu_find_passw);
	fprintf(fp, "%s ", t->stu_num);
	fprintf(fp, "%s ", t->stu_name);
	fprintf(fp, "%s ", t->stu_tel);
	for (i = 0; i < 9; i++) {
		fprintf(fp, "%s ", t->stu_bor_book[i]);
	}
	fprintf(fp, "%s", t->stu_bor_book[9]);
	fclose(fp);

}
/*�������Ա�������ļ�*/
void Save_Manger(void)
{
	FILE *fp;
	Manager *t = Manager_head->next;
	int i;
	if (!t)
		return;
	if ((fp = fopen("Managernode.txt", "w+")) == NULL) {
		printf("\t\t��ʧ��\n");
		exit(1);
	}
	while (t->next) {
		int len = strlen(t->man_passw);			//�������
		for (i = 0; i < len; i++) {
			t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
		}
		fprintf(fp, "%s ", t->man_name);
		fprintf(fp, "%s ", t->man_acc);
		fprintf(fp, "%s\n", t->man_passw);
		t = t->next;
	}
	int len = strlen(t->man_passw);			//�������
	for (i = 0; i < len; i++) {
		t->man_passw[i] = t->man_passw[i] + (i % 4 + 1);
	}
	fprintf(fp, "%s ", t->man_name);
	fprintf(fp, "%s ", t->man_acc);
	fprintf(fp, "%s", t->man_passw);
	fclose(fp);
}
/*������Ϣ�������ļ�*/
void Massage_Save(void)
{
	system("CLS");
	printf("\t\t\t\t        **           **        \n");
	printf("\t\t\t\t    *       *     *       *    \n");
	printf("\t\t\t\t  *            *            *  \n");
	printf("\t\t\t\t *                           * \n");
	printf("\t\t\t\t *                           * \n");
	printf("\t\t\t\t *          ��лʹ��         * \n");
	printf("\t\t\t\t *                           * \n");
	printf("\t\t\t\t  *        �߳�Ϊ������     *  \n");
	printf("\t\t\t\t   *                       *   \n");
	printf("\t\t\t\t    *                     *    \n");
	printf("\t\t\t\t      *                 *      \n");
	printf("\t\t\t\t        *             *        \n");
	printf("\t\t\t\t          *         *          \n");
	printf("\t\t\t\t             *   *             \n");
	printf("\t\t\t\t               *               \n");

	Save_Book();
	Save_Student();
	Save_Manger();
}
