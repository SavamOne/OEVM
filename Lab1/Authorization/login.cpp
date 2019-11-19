#include "login.h"

bool login()
{
	std::cout << std::endl << "---------------------------" << std::endl;

	USB_Drive_struct test;
	char password[50];

	std::ifstream i_File;
	i_File.open("Authorization/secure.dat", std::ios::binary);
	if (!i_File.is_open())
	{
		std::cout << "Ошибка авторизации!\n";
		std::cout << "---------------------------" << std::endl << std::endl;
		return false;
	}

	char state;
	i_File.read(&state, 1);
	if (state == 'f')
	{
		std::cout << "Авторизация не требуется" << std::endl;
		std::cout << "---------------------------" << std::endl << std::endl;
		return true;
	}

	i_File.read((char*)&test, sizeof(test));
	i_File.read(password, sizeof(password));
	i_File.close();


	std::cout << "Пожалуйста, вставьте необходимый накопитель" << std::endl;
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
		if (!authorized)
			Sleep(3000);
		attempts++;
	}

	attempts = 0;

	if (!authorized)
	{
		std::cout << "Время авторизации по накопителю истекло. Введите пароль" << std::endl;
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
				std::cout << "Пароль неверный. Попробуйте еще раз" << std::endl;
				attempts++;
			}
		}
	}

	if (authorized)
		std::cout << "Успешно авторизовано" << std::endl;
	else
		std::cout << "Авторизоваться не получилось" << std::endl;

	std::cout << "---------------------------" << std::endl << std::endl;
	return authorized;
}