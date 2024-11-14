#include "Hotel_form.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace CourseWork;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CourseWork::Hotel_form form;
	Application::Run(% form);
	return 0;
}