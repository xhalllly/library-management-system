class Mp {
public:
	//管理员端
	void Manager_Port(void);
	/*管理员登录*/
	void Manager_Login(void);
	/*核对管理员账号*/
	Manager *Manager_check(char *Manager_num);
	/*管理员查看书架*/
	void Manager_Look_Book(void);
	//编号升序查看书架
	void Lookofnum(void);
	//库存升序查看书架
	void Lookofrest(void);
	//浏览书单 
	void Manager_Print_Book(void);
	/*管理员修改密码*/
	void Manager_Change_Password(Manager *Man_num);
	/*上架书籍*/
	void Manager_Add_Book(void);
	/*增加库存*/
	void Manager_Add_Book1(void);
	/*上架新书*/
	void Manager_Add_Book2(void);
	/*管理员下架书籍*/
	void Manager_Down_Book(void);
	/*管理员管理学生*/
	void Manager_Manager_Stu(void);
	/*管理员查看学生名单*/
	void Manager_Look_Stu(void);
	/*强制还书*/
	void Manager_Return_Stu(void);
	
	/*删除学生号码并归还所有书籍*/
	void Manager_Del_Stu(void);

};

