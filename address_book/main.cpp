#include<iostream>
#include<string>
#include <cstdlib>
#define MAX 1000
using namespace std;
struct person
{
	string name;
	int sex;
	int age;
	string phone;
	string addr;
};
struct addressbooks
{
	struct person personarray[MAX];
	int size;
};
void showmenu()
{
	cout <<"*****1.添加联系人*****"<< endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出*****" << endl;
};
//1.添加联系人
void addperson(addressbooks* abs)
{//通讯录是否满
	if(abs->size>=MAX)
	{		cout << "通讯录已满" << endl;
		return;	}
	else
	{
		int index = abs->size;
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;cin.ignore();
		abs->personarray[index].name = name;
		cout << "请输入姓别" << endl;
		cout << "1.男" << "2.女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;cin.ignore();
			if (sex == 1 || sex == 2)
			{
				abs->personarray[index].sex = sex;
				break;
			}
			cout << "重新输入" << endl;
		};
		cout << "请输入年龄" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;cin.ignore();
			if (age > 0)
			{
				abs->personarray[index].age = age;
				break;
			}
			cout << "重新输入" << endl;
		};
		cout << "请输入电话" << endl;
		string phone ;
		cin >> phone;		cin.ignore();
		abs->personarray[index].phone = phone;
		cout << "请输入地址" << endl;
		string addr;
		cin >> addr;cin.ignore();
		abs->personarray[index].addr = addr;
		//更新人数
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
};
//2.显示联系人
void showperson(addressbooks* abs)
{
	//判断人数是否为0
	if (abs->size == 0)
	{	cout << "通讯录为空" << endl;	}
	else
	{
		for (int i = 0;i < abs->size;i++)
		{
			cout << "姓名" << abs->personarray[i].name << "\t";
			cout << "性别" <<( abs->personarray[i].sex==1? "男":"女" )<< "\t";
			cout << "年龄" << abs->personarray[i].age << "\t";
			cout << "电话号" << abs->personarray[i].phone << "\t";
			cout << "地址" << abs->personarray[i].addr << endl;;
		}
	}
	system("pause");
	system("cls");
};
//3.删除联系人
int isexist(addressbooks* abs, string name0)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personarray[i].name ==name0)
		{
			return i;
		}
	}
	return -1;
}
void deleteperson(addressbooks* abs)
{
	cout << "请输入名字" << endl;
	string name1;
	cin >> name1;
	int ret = isexist(abs, name1);
	if (ret == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		for (int i = ret;i < abs->size;i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//4.查找联系人
void findperson(addressbooks* abs)
{
	cout << "请输入名字" << endl;
	string name1;
	cin >> name1;
	int ret = isexist(abs, name1);
	if (ret ==-1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "名字" << abs->personarray[ret].name << endl;
		cout << "性别" << abs->personarray[ret].sex << endl;
		cout << "年龄" << abs->personarray[ret].age << endl;
		cout << "电话号" << abs->personarray[ret].phone << endl;
		cout << "地址" << abs->personarray[ret].addr << endl;
	}
	system("pause");
	system("cls");

}
//5.修改联系人
void modifperson(addressbooks* abs)
{
	cout << "请输入名字" << endl;
	string name1;
	cin >> name1;
	int ret = isexist(abs, name1);
	if(ret==-1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "请输入名字" << endl;
		string name1;
		cin >> name1;
		abs->personarray[ret].name = name1;
		cout << "请输入年龄" << endl;
		int age1;
		cin >> age1;
		abs->personarray[ret].age = age1;
		cout << "请输入性别" << endl;
		int sex1;
		cin >> sex1;
		abs->personarray[ret].sex = sex1;
		cout << "请输入电话号" << endl;
		string phone1;
		cin >> phone1;
		abs->personarray[ret].phone = phone1;
		cout << "请输入地址" << endl;
		string addr1;
		cin >> addr1;
		abs->personarray[ret].addr = addr1;
	}
	system("pause");
	system("cls");
}
//6.清空联系人
void shanperson(addressbooks* abs)
{
	cout << "确定要清空联系人吗" << endl;
	cout << "输入1确定,其它取消" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		abs->size = 0;
		cout << "已完成" << endl;
	}
	else
	{
		cout << "已取消" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	addressbooks abs;
	//初始化
	abs.size = 0;
	while (true)
	{
	showmenu();
	int select = 0;// 创建用户输入
	
		cin >> select;
		switch (select)
		{
		case 1://添加
			addperson(&abs);
			break;
		case 2://显示
			showperson(&abs);
			break;
		case 3://删除
			deleteperson(&abs);
		break;
		case 4://查找
			findperson(&abs);
			break;
		case 5://修改
			modifperson(&abs);
			break;
		case 6://清空
			shanperson(&abs);
			break;
		case 0://退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	//菜单调用
	
	system("pause");
	return 0;
}