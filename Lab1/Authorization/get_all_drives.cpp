#include "get_all_drives.h"


void get_all_drives(container<USB_Drive_struct>* drives)
{
	drives->~container();
	HDEVINFO hdev = SetupDiGetClassDevsA(nullptr, nullptr, nullptr, DIGCF_ALLCLASSES | DIGCF_PRESENT );
	SP_DEVINFO_DATA DevInfoData;
	DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD DeviceIndex = 0;

	while (SetupDiEnumDeviceInfo(hdev, DeviceIndex, &DevInfoData))
	{
		char bufbyte[8];
		memset(bufbyte, 0, sizeof(bufbyte));
		SetupDiGetDeviceRegistryPropertyA(hdev, &DevInfoData, SPDRP_ENUMERATOR_NAME, nullptr, reinterpret_cast<PBYTE>(bufbyte), sizeof(bufbyte), nullptr);

		if (strcmp(bufbyte, "USBSTOR") == 0 || strcmp(bufbyte, "SCSI") == 0)
		{
			USB_Drive_struct drive;

			SetupDiGetDeviceRegistryPropertyA(hdev, &DevInfoData, SPDRP_FRIENDLYNAME, nullptr, reinterpret_cast<PBYTE>(drive.name), sizeof(drive.name), nullptr);
			SetupDiGetDeviceInstanceIdA(hdev, &DevInfoData, static_cast<PSTR>(drive.data), sizeof(drive.data), nullptr);

			if(strcmp(drive.name, "") != 0)
				drives->append(drive);
		}

		DeviceIndex++;
		memset(&DevInfoData, 0,
			sizeof(SP_DEVINFO_DATA));
		DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	}
	SetupDiDeleteDeviceInfo(hdev, &DevInfoData);
}