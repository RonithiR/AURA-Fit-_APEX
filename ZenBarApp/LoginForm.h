#pragma once
#include "DashboardForm.h" // Add this line right here!

namespace ZenBarApp {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        LoginForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~LoginForm()
        {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Panel^ leftPanel;
        System::Windows::Forms::Panel^ rightPanel;
        System::Windows::Forms::Label^ lblLogo;
        System::Windows::Forms::Label^ lblSub;
        System::Windows::Forms::Label^ lblTagline;
        System::Windows::Forms::Label^ lblWelcome;
        System::Windows::Forms::Label^ lblLoginSub;
        System::Windows::Forms::TextBox^ txtUsername;
        System::Windows::Forms::TextBox^ txtPassword;
        System::Windows::Forms::Button^ btnLogin;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->SuspendLayout();

            this->ClientSize = System::Drawing::Size(920, 560);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Text = L"ZenBar | Login";
            this->MinimumSize = System::Drawing::Size(920, 560);
            this->MaximizeBox = false;
            this->BackColor = Color::FromArgb(250, 247, 239);

            leftPanel = gcnew Panel();
            leftPanel->Size = System::Drawing::Size(440, 560);
            leftPanel->Dock = DockStyle::Left;
            leftPanel->BackColor = Color::FromArgb(48, 78, 58);

            lblLogo = gcnew Label();
            lblLogo->Text = L"ZenBar";
            lblLogo->Font = gcnew Drawing::Font(L"Segoe UI", 28, FontStyle::Bold);
            lblLogo->ForeColor = Color::White;
            lblLogo->Location = Point(45, 120);
            lblLogo->AutoSize = true;

            lblSub = gcnew Label();
            lblSub->Text = L"SUPPLEMENT SHOP";
            lblSub->Font = gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
            lblSub->ForeColor = Color::FromArgb(139, 166, 139);
            lblSub->Location = Point(48, 170);
            lblSub->AutoSize = true;

            lblTagline = gcnew Label();
            lblTagline->Text = L"Better Nutrition\nBetter You";
            lblTagline->Font = gcnew Drawing::Font(L"Segoe UI", 16, FontStyle::Regular);
            lblTagline->ForeColor = Color::FromArgb(226, 236, 220);
            lblTagline->Location = Point(48, 240);
            lblTagline->AutoSize = true;

            leftPanel->Controls->Add(lblLogo);
            leftPanel->Controls->Add(lblSub);
            leftPanel->Controls->Add(lblTagline);

            rightPanel = gcnew Panel();
            rightPanel->Size = System::Drawing::Size(480, 560);
            rightPanel->Dock = DockStyle::Fill;
            rightPanel->BackColor = Color::FromArgb(255, 255, 252);

            lblWelcome = gcnew Label();
            lblWelcome->Text = L"Welcome Back!";
            lblWelcome->Font = gcnew Drawing::Font(L"Segoe UI", 22, FontStyle::Bold);
            lblWelcome->ForeColor = Color::FromArgb(47, 59, 49);
            lblWelcome->Location = Point(60, 110);
            lblWelcome->AutoSize = true;

            lblLoginSub = gcnew Label();
            lblLoginSub->Text = L"Login to access your account";
            lblLoginSub->Font = gcnew Drawing::Font(L"Segoe UI", 10);
            lblLoginSub->ForeColor = Color::FromArgb(125, 132, 119);
            lblLoginSub->Location = Point(64, 155);
            lblLoginSub->AutoSize = true;

            txtUsername = gcnew TextBox();
            txtUsername->Location = Point(64, 215);
            txtUsername->Size = System::Drawing::Size(340, 32);
            txtUsername->Font = gcnew Drawing::Font(L"Segoe UI", 11);
            txtUsername->Text = L"Username";
            txtUsername->ForeColor = Color::Gray;

            txtPassword = gcnew TextBox();
            txtPassword->Location = Point(64, 270);
            txtPassword->Size = System::Drawing::Size(340, 32);
            txtPassword->Font = gcnew Drawing::Font(L"Segoe UI", 11);
            txtPassword->Text = L"Password";
            txtPassword->UseSystemPasswordChar = true;

            btnLogin = gcnew Button();
            btnLogin->Text = L"Login  →";
            btnLogin->Location = Point(64, 335);
            btnLogin->Size = System::Drawing::Size(340, 44);
            btnLogin->BackColor = Color::FromArgb(48, 78, 58);
            btnLogin->ForeColor = Color::White;
            btnLogin->FlatStyle = FlatStyle::Flat;
            btnLogin->FlatAppearance->BorderSize = 0;
            btnLogin->Font = gcnew Drawing::Font(L"Segoe UI", 11, FontStyle::Bold);
            btnLogin->Cursor = Cursors::Hand;
            btnLogin->Click += gcnew EventHandler(this, &LoginForm::BtnLogin_Click);

            rightPanel->Controls->Add(lblWelcome);
            rightPanel->Controls->Add(lblLoginSub);
            rightPanel->Controls->Add(txtUsername);
            rightPanel->Controls->Add(txtPassword);
            rightPanel->Controls->Add(btnLogin);

            this->Controls->Add(rightPanel);
            this->Controls->Add(leftPanel);
            this->ResumeLayout(false);
        }

        void BtnLogin_Click(Object^ sender, EventArgs^ e) {
            DashboardForm^ dash = gcnew DashboardForm();
            this->Hide();
            dash->ShowDialog();
            this->Show();
        }
    };
}