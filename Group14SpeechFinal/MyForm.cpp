#include "MyForm.h"
#include<thread>
#include <chrono>   
#include "Test_train.h"
using namespace System;
using namespace System::Windows::Forms;




[STAThread]
int main(array<String^ >^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CLRproj1::MyForm form;
	//form.Hide();
	//form.ShowDialog();
	form.Show();
	form.Refresh();
	System::Threading::Thread::Sleep(4000);
	CLRproj1::Test_train tt;
	form.Close();
	tt.Show();
	tt.Refresh();
	tt.speak();
	
	return 0;
}
