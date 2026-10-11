#include "LoginForm.h"  // include your new login form

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ZenBarApp::LoginForm loginForm;  // Launch the login form first!
    Application::Run(% loginForm);
    return 0;
}