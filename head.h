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
	char book_num[10];				//书号
	char book_name[20];				//书名
	char book_at_name[30];			//作者名
	int book_rest;					//库存
	struct book *next;				//下本书
}Book;

typedef struct stu {
	char stu_acc[10];				//学生账号
	char stu_passw[15];				//学生密码
	char stu_find_question[30];		//密保问题
	char stu_find_passw[15];		//密保问题密码	
	char stu_num[10];				//学生学号
	char stu_name[20];				//学生姓名
	char stu_tel[15];				//学生电话
	char stu_bor_book[10][20];		//所借书号
	struct stu *next;				//下位学生
}Student;

typedef struct manager {
	char man_name[15];				//管理员姓名
	char man_acc[10];				//管理员账号
	char man_passw[15];				//管理员密码
	struct manager *next;			//下个管理员
}Manager;


#endif
