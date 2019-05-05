#ifndef HEAD_H_
#define HEAD_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

typedef struct book {
	char book_num[10];				//���
	char book_name[20];				//����
	char book_at_name[30];			//������
	int book_rest;					//���
	struct book *next;				//�±���
}Book;

typedef struct stu {
	char stu_acc[10];				//ѧ���˺�
	char stu_passw[15];				//ѧ������
	char stu_find_question[30];		//�ܱ�����
	char stu_find_passw[15];		//�ܱ���������	
	char stu_num[10];				//ѧ��ѧ��
	char stu_name[20];				//ѧ������
	char stu_tel[15];				//ѧ���绰
	char stu_bor_book[10][20];		//�������
	struct stu *next;				//��λѧ��
}Student;

typedef struct manager {
	char man_name[15];				//����Ա����
	char man_acc[10];				//����Ա�˺�
	char man_passw[15];				//����Ա����
	struct manager *next;			//�¸�����Ա
}Manager;


#endif
