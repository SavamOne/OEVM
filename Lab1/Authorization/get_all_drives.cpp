#include "get_all_drives.h"


void get_all_drives(container<USB_Drive_struct>* drives)
{
	HDEVINFO hdev = SetupDiGetClassDevsA(NULL, NULL, NULL, DIGCF_ALLCLASSES | DIGCF_PRESENT);
	SP_DEVINFO_DATA DevInfoData;
	DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD DeviceIndex = 0;

	while (SetupDiEnumDeviceInfo(hdev, DeviceIndex, &DevInfoData))
	{
		char bufbyte[8];
		memset(bufbyte, 0, sizeof(bufbyte));
		SetupDiGetDeviceRegistryPropertyA(hdev, &DevInfoData, SPDRP_ENUMERATOR_NAME, NULL, (PBYTE)bufbyte, sizeof(bufbyte), NULL);

		if (strcmp(bufbyte, "USBSTOR") == 0 || strcmp(bufbyte, "SCSI") == 0)
		{
			USB_Drive_struct drive;

			SetupDiGetDeviceRegistryPropertyA(hdev, &DevInfoData, SPDRP_FRIENDLYNAME, NULL, (PBYTE)drive.name, sizeof(drive.name), NULL);
			SetupDiGetDeviceInstanceIdA(hdev, &DevInfoData, (PSTR)drive.data, sizeof(drive.data), NULL);

			drives->append(drive);
		}

		DeviceIndex++;
		memset(&DevInfoData, 0,
			sizeof(SP_DEVINFO_DATA));
		DevInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	}
	SetupDiDeleteDeviceInfo(hdev, &DevInfoData);
}