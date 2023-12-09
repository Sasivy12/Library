#include "RegisterWindow.h"
#include "MainWindow.h"
#include "LoginWindow.h"
#include "User.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;

	while (true)
	{
		LibraryManagment::MainWindow mainWindow;
		mainWindow.ShowDialog();

		if (mainWindow.switchToReg)
		{
			LibraryManagment::RegisterWindow reg_window;
			reg_window.ShowDialog();
		}
		else if (mainWindow.switchToLog)
		{
			LibraryManagment::LoginWindow login_window;
			login_window.ShowDialog();
		}
		else
		{
			break;
		}
	}
	
}