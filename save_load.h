Book *Book_load();

/*将学生文件中的信息加载至学生链表*/
Student *Student_load(void);

Manager *Manager_load(void);
/*保存书籍链表至文件*/
void Save_Book(void);
/*保存学生链表至文件*/
void Save_Student(void);
/*保存管理员链表至文件*/
void Save_Manger(void);
/*所有信息保存至文件*/
void Massage_Save(void);
