void Find_Book(void);

Book *Find_BookofName(char *Book_num);

void Change_Stupassword(Student *Stu_num);

void Find_Theborrow(Student *Stu_num);

void Stu_Borrow(Student *Stu_num);

void Recom_Book();

/*打印书单*/
void Print_Book(void);

/*寻找该书是否存在*/
Book *Book_exit(char *Book_num);

/*查询学生是否借过此书*/
int Ifborrow(Student *Stu_num,char *Book_num);

/*学生还书*/
void Stu_Back(Student *Stu_num);

/*打印所借书籍*/
void Print_Borbook(Student *Stu_num);

/*还书具体操作*/
void Bake_Book(Student *Stu_num,char *Book_num);



