#include <iostream>
#include <Windows.h>


using namespace std;

void decodecode(DWORD code)
{
    DWORD DeviceType = (code >> 16) & 0xFFFF;
    DWORD FunctionCode = (code >> 2) & 0xFFF;
    DWORD AccessMethod = code & 0x03;
    DWORD RequiredAccess = (code >> 14) & 0x03;

    cout << "Device Type -> 0x" << hex << DeviceType << endl;
    cout << "Function Code -> 0x" << std::hex << FunctionCode << endl;
    cout << "Access Method -> ";
    


    if (AccessMethod == 0) 
    {
        cout << "METHOD_BUFFERED" << endl;
    }
    else if (AccessMethod == 1) 
    {
        cout << "METHOD_IN_DIRECT" << endl;
    }
    else if (AccessMethod == 2) 
    {
        cout << "METHOD_OUT_DIRECT" << endl;
    }
    else if (AccessMethod == 3) 
    {
        cout << "METHOD_NEITHER" << endl;
    }
    else 
    {
        cout << "Unknown" << endl;
    }

    cout << "Required Access -> ";

    if (RequiredAccess == 0) 
    {
        cout << "FILE_ANY_ACCESS" << endl;
    }
    else if (RequiredAccess == 1) 
    {
        cout << "FILE_READ_ACCESS" << endl;
    }
    else if (RequiredAccess == 2) 
    {
        cout << "FILE_WRITE_ACCESS" << endl;
    }
    else if (RequiredAccess == 3) 
    {
        cout << "FILE_READ_ACCESS | FILE_WRITE_ACCESS" << endl;
    }
    else 
    {
        cout << "Unknown" << endl;
    }

}

int main()
{
    DWORD usercode;

	SetConsoleTitle(TEXT("ioctl Code Decoder"));

start:

    system("cls");
    cout << "Enter Your ioctl Code -> ";
    cin >> hex >> usercode;

    decodecode(usercode);
    system("pause"); // ignore the bad code
    goto start;
    
}