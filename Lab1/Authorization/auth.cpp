#include "auth.h"

bool authorization()
{
	std::cout << std::endl << "---------------------------" << std::endl;

	USB_Drive_struct test;
	char password[50];

	std::ifstream i_File;
	i_File.open("Authorization/secure.dat", std::ios::binary);
	if (!i_File.is_open())
	{
		std::cout << "������ �����������!\n";
		std::cout << "---------------------------" << std::endl << std::endl;
		return false;
	}

	char state;
	i_File.read(&state, 1);
	if (state == 'f')
	{
		std::cout << "����������� �� ���������" << std::endl;
		std::cout << "---------------------------" << std::endl << std::endl;
		return true;
	}

	i_File.read((char*)&test, sizeof(test));
	i_File.read(password, sizeof(password));
	i_File.close();


	std::cout << "����������, �������� ����������� ����������" << std::endl;
	bool authorized = false;
	short attempts = 0;
	while (!authorized && attempts <= 5)
	{
		container<USB_Drive_struct> d;

		get_all_drives(&d);
		for (int i = 0; i < d.size; i++)
		{
			if (strcmp(d[i].data, test.data) == 0 && strcmp(d[i].name, test.name) == 0)
			{
				authorized = true;
				break;
			}
		}
		if(!authorized)
			Sleep(3000);
		attempts++;
	}

	attempts = 0;

	if (!authorized)
	{
		std::cout << "����� ����������� �� ���������� �������. ������� ������" << std::endl;
		while (attempts < 5)
		{
			char p[50];
			std::cin >> p;
			if (strcmp(p, password) == 0)
			{
				authorized = true;
				break;
			}
			else
			{
				std::cout << "������ ��������. ���������� ��� ���" << std::endl;
				attempts++;
			}
		}
	}

	if (authorized)
		std::cout << "������� ������������" << std::endl;
	else
		std::cout << "�������������� �� ����������" << std::endl;

	std::cout << "---------------------------" << std::endl << std::endl;
	return authorized;
}

void change_authorization_method()
{
	container<USB_Drive_struct> drives;
	get_all_drives(&drives);

	short res = choose_auth_method();

	if (res == 0)
	{
		std::ofstream o_File;
		o_File.open("Authorization/secure.dat", std::ios::binary);
		if (!o_File.is_open())
		{
			std::cout << "������� ���� �� �������! \n";
		}
		else
		{
			o_File.write("f34276478263401238", 19);
			o_File.close();
		}

		return;
	}

	short num = choose_usb_storage(&drives);

	char password[50];
	std::cout << "������� ������ �� ������ ���������� ������������� ����������" << std::endl;
	std::cin >> password;


	std::ofstream o_File;
	o_File.open("Authorization/secure.dat", std::ios::binary);
	if (!o_File.is_open())
	{
		std::cout << "������� ���� �� �������! \n";
	}
	else
	{
		USB_Drive_struct test = drives[num];
		o_File.write("l", 1);
		o_File.write((char*)&test, sizeof(test));
		o_File.write(password, sizeof(password));
		o_File.close();
	}

	std::cout << "���������� ������� ���������������" << std::endl;
}