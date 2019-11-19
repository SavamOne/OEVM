#include "set_auth.h"


void without_auth()
{
	std::ofstream o_File;
	o_File.open("Authorization/secure.dat", std::ios::binary);
	if (!o_File.is_open())
	{
		std::cout << "Не удалось поменять тип авторизации! \n";
	}
	else
	{
		o_File.write("f", 1);
		o_File.close();
	}
}

void usb_flash_auth()
{
	container<USB_Drive_struct> drives;
	get_all_drives(&drives);

	short num = readers::choose_usb_storage(&drives);

	char password[50];
	std::cout << "Введите пароль на случай физической недоступности устройства" << std::endl;
	std::cin >> password;


	std::ofstream o_File;
	o_File.open("Authorization/secure.dat", std::ios::binary);
	if (!o_File.is_open())
	{
		std::cout << "Открыть файл не удалось! \n";
	}
	else
	{
		USB_Drive_struct test = drives[num];
		o_File.write("l", 1);
		o_File.write((char*)&test, sizeof(test));
		o_File.write(password, sizeof(password));
		o_File.close();
	}

	std::cout << "Накопитель успешно зарегистрирован" << std::endl;
}