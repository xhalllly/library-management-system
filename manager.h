class Mp {
public:
	//����Ա��
	void Manager_Port(void);
	/*����Ա��¼*/
	void Manager_Login(void);
	/*�˶Թ���Ա�˺�*/
	Manager *Manager_check(char *Manager_num);
	/*����Ա�鿴���*/
	void Manager_Look_Book(void);
	//�������鿴���
	void Lookofnum(void);
	//�������鿴���
	void Lookofrest(void);
	//����鵥 
	void Manager_Print_Book(void);
	/*����Ա�޸�����*/
	void Manager_Change_Password(Manager *Man_num);
	/*�ϼ��鼮*/
	void Manager_Add_Book(void);
	/*���ӿ��*/
	void Manager_Add_Book1(void);
	/*�ϼ�����*/
	void Manager_Add_Book2(void);
	/*����Ա�¼��鼮*/
	void Manager_Down_Book(void);
	/*����Ա����ѧ��*/
	void Manager_Manager_Stu(void);
	/*����Ա�鿴ѧ������*/
	void Manager_Look_Stu(void);
	/*ǿ�ƻ���*/
	void Manager_Return_Stu(void);
	
	/*ɾ��ѧ�����벢�黹�����鼮*/
	void Manager_Del_Stu(void);

};

