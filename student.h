class St {
public:
	/*学生端口*/
	void Student_Port(void);
	/*学生注销账号*/
	void Student_Delete(void);
	/*学生注册账号*/
	void Student_Register(void);

	void Find_Password(void);

	Student *Find_Num(char *Stu_num);

	/*按学号查找学生*/
	Student *Find_Stu(char *Stu_Stuty);

	/*学生端登录*/
	void Student_Login(void);
};


