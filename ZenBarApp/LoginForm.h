#pragma once
#include "DashboardForm.h"

namespace ZenBarApp {

    using namespace System;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;
    using namespace System::Windows::Forms;
    using namespace System::ComponentModel;

    public ref class LoginForm : public Form
    {
    public:
        LoginForm(void)
        {
            components = nullptr;
            InitializeComponent();
        }

    protected:
        ~LoginForm()
        {
            if (components != nullptr)
                delete components;
        }

    private:
        Panel^ greenFrame;
        Panel^ loginCard;
        Panel^ curvePanel;
        Panel^ usernameLine;
        Panel^ passwordLine;

        Label^ lblLogo;
        Label^ lblWelcome;
        Label^ lblHelp;
        Label^ lblHelpArrow;

        PictureBox^ picFruit;

        TextBox^ txtUsername;
        TextBox^ txtPassword;

        Button^ btnLogin;

        System::ComponentModel::Container^ components;

        GraphicsPath^ MakeRoundedRectangle(
            Rectangle r, int radius)
        {
            GraphicsPath^ path = gcnew GraphicsPath();
            int d = radius * 2;

            path->AddArc(r.X, r.Y, d, d, 180, 90);
            path->AddArc(r.Right - d, r.Y, d, d, 270, 90);
            path->AddArc(r.Right - d, r.Bottom - d,
                d, d, 0, 90);
            path->AddArc(r.X, r.Bottom - d,
                d, d, 90, 90);

            path->CloseFigure();
            return path;
        }

        void InitializeComponent(void)
        {
            this->SuspendLayout();

            // MAIN WINDOW
            this->Text = L"ZenBar login";
            this->ClientSize = System::Drawing::Size(956, 650);
            this->MinimumSize = System::Drawing::Size(972, 689);
            this->StartPosition = FormStartPosition::CenterScreen;
            this->MaximizeBox = false;
            this->BackColor = Color::FromArgb(31, 31, 31);
            this->Font = gcnew Drawing::Font(
                L"Segoe UI", 10);

            // OUTER GREEN FRAME
            greenFrame = gcnew Panel();
            greenFrame->Location = Point(30, 30);
            greenFrame->Size = Drawing::Size(853, 520);
            greenFrame->BackColor =
                Color::FromArgb(62, 96, 72);

            // WHITE LOGIN CARD
            loginCard = gcnew Panel();
            loginCard->Location = Point(45, 52);
            loginCard->Size = Drawing::Size(767, 415);
            loginCard->BackColor =
                Color::FromArgb(255, 255, 253);

            // CURVED GREEN LEFT SIDE
            curvePanel = gcnew Panel();
            curvePanel->Location = Point(0, 0);
            curvePanel->Size = Drawing::Size(400, 415);
            curvePanel->BackColor =
                Color::FromArgb(255, 255, 253);

            curvePanel->Paint +=
                gcnew PaintEventHandler(
                    this, &LoginForm::DrawCurvedPanel);

            // LOGO
            lblLogo = gcnew Label();
            lblLogo->Text = L"⚒ ZenBar";
            lblLogo->Location = Point(18, 25);
            lblLogo->AutoSize = true;
            lblLogo->Font = gcnew Drawing::Font(
                L"Georgia", 20, FontStyle::Regular);
            lblLogo->ForeColor = Color::White;
            lblLogo->BackColor = Color::Transparent;


            // SMOOTHIE BOWL IMAGE
            picFruit = gcnew PictureBox();
            picFruit->Location = Point(82, 55);
            picFruit->Size = Drawing::Size(310, 310);
            picFruit->SizeMode = PictureBoxSizeMode::Zoom;
            picFruit->BackColor = Color::FromArgb(255, 255, 253);
            picFruit->Region = gcnew System::Drawing::Region(MakeRoundedRectangle(Rectangle(0, 0, 310, 310), 155));

            String^ imagePath =
                System::IO::Path::Combine(
                    Application::StartupPath,
                    L"SmoothieBowl.png");

            if (System::IO::File::Exists(imagePath))
            {
                picFruit->Image = Image::FromFile(imagePath);
                picFruit->Visible = true;
            }
            else
            {
                MessageBox::Show(
                    L"Image not found at: " + imagePath);
            }


            // WELCOME HEADING
            lblWelcome = gcnew Label();
            lblWelcome->Text =
                L"WELCOME BACK\nTO ZENBAR";
            lblWelcome->Location = Point(435, 52);
            lblWelcome->Size = Drawing::Size(315, 82);
            lblWelcome->Font = gcnew Drawing::Font(
                L"Arial Black", 21, FontStyle::Bold);
            lblWelcome->ForeColor =
                Color::FromArgb(45, 57, 46);
            lblWelcome->BackColor =
                Color::FromArgb(255, 255, 253);
            lblWelcome->TextAlign =
                ContentAlignment::MiddleLeft;

            // USERNAME INPUT
            txtUsername = gcnew TextBox();
            txtUsername->Location = Point(435, 173);
            txtUsername->Size = Drawing::Size(295, 27);
            txtUsername->BorderStyle =
                BorderStyle::None;
            txtUsername->BackColor =
                Color::FromArgb(255, 255, 253);
            txtUsername->ForeColor =
                Color::FromArgb(53, 63, 54);
            txtUsername->Font = gcnew Drawing::Font(
                L"Segoe UI", 11);
            txtUsername->Text = L"Username";

            txtUsername->GotFocus +=
                gcnew EventHandler(
                    this, &LoginForm::Username_GotFocus);

            txtUsername->LostFocus +=
                gcnew EventHandler(
                    this, &LoginForm::Username_LostFocus);

            usernameLine = gcnew Panel();
            usernameLine->Location = Point(435, 198);
            usernameLine->Size = Drawing::Size(295, 1);
            usernameLine->BackColor =
                Color::FromArgb(205, 211, 204);

            // PASSWORD INPUT
            txtPassword = gcnew TextBox();
            txtPassword->Location = Point(435, 212);
            txtPassword->Size = Drawing::Size(295, 27);
            txtPassword->BorderStyle =
                BorderStyle::None;
            txtPassword->BackColor =
                Color::FromArgb(255, 255, 253);
            txtPassword->ForeColor =
                Color::FromArgb(53, 63, 54);
            txtPassword->Font = gcnew Drawing::Font(
                L"Segoe UI", 11);
            txtPassword->Text = L"Password";
            txtPassword->UseSystemPasswordChar = false;

            txtPassword->GotFocus +=
                gcnew EventHandler(
                    this, &LoginForm::Password_GotFocus);

            txtPassword->LostFocus +=
                gcnew EventHandler(
                    this, &LoginForm::Password_LostFocus);

            passwordLine = gcnew Panel();
            passwordLine->Location = Point(435, 237);
            passwordLine->Size = Drawing::Size(295, 1);
            passwordLine->BackColor =
                Color::FromArgb(205, 211, 204);

            // LOGIN BUTTON
            btnLogin = gcnew Button();
            btnLogin->Text = L"LOGIN TO DASHBOARD";
            btnLogin->Location = Point(435, 285);
            btnLogin->Size = Drawing::Size(213, 49);
            btnLogin->BackColor =
                Color::FromArgb(63, 97, 73);
            btnLogin->ForeColor = Color::White;
            btnLogin->FlatStyle = FlatStyle::Flat;
            btnLogin->FlatAppearance->BorderSize = 0;
            btnLogin->Font = gcnew Drawing::Font(
                L"Consolas", 9, FontStyle::Bold);
            btnLogin->Cursor = Cursors::Hand;
            btnLogin->Region =
                gcnew System::Drawing::Region(
                    MakeRoundedRectangle(
                        Rectangle(0, 0, 213, 49), 25));

            btnLogin->Click +=
                gcnew EventHandler(
                    this, &LoginForm::BtnLogin_Click);

            // HELP LINK
            lblHelp = gcnew Label();
            lblHelp->Text = L"help";
            lblHelp->Location = Point(680, 337);
            lblHelp->AutoSize = true;
            lblHelp->Font = gcnew Drawing::Font(
                L"Segoe UI", 9);
            lblHelp->ForeColor =
                Color::FromArgb(58, 66, 59);
            lblHelp->Cursor = Cursors::Hand;

            lblHelp->Click +=
                gcnew EventHandler(
                    this, &LoginForm::Help_Click);

            lblHelpArrow = gcnew Label();
            lblHelpArrow->Text = L"›";
            lblHelpArrow->Location = Point(709, 333);
            lblHelpArrow->AutoSize = true;
            lblHelpArrow->Font = gcnew Drawing::Font(
                L"Segoe UI", 17);
            lblHelpArrow->ForeColor =
                Color::FromArgb(90, 100, 91);
            lblHelpArrow->Cursor = Cursors::Hand;

            lblHelpArrow->Click +=
                gcnew EventHandler(
                    this, &LoginForm::Help_Click);


          
           // CONTROL ORDER
            loginCard->Controls->Add(curvePanel);
            curvePanel->Controls->Add(lblLogo);
            loginCard->Controls->Add(picFruit);
            picFruit->BringToFront();

           loginCard->Controls->Add(lblWelcome);
           loginCard->Controls->Add(txtUsername);
           loginCard->Controls->Add(usernameLine);
           loginCard->Controls->Add(txtPassword);
           loginCard->Controls->Add(passwordLine);
           loginCard->Controls->Add(btnLogin);
           loginCard->Controls->Add(lblHelp);
           loginCard->Controls->Add(lblHelpArrow);

           // Bring the logo above the image
           lblLogo->BringToFront();
          
            
            // Make sure the image is on top.
            
            lblLogo->BringToFront();


            greenFrame->Controls->Add(loginCard);
            this->Controls->Add(greenFrame);

            this->ResumeLayout(false);
        }

        // DRAW THE CURVED GREEN SHAPE
        void DrawCurvedPanel(
            Object^ sender, PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                SmoothingMode::AntiAlias;

            GraphicsPath^ curve =
                gcnew GraphicsPath();

            curve->StartFigure();
            curve->AddLine(0, 0, 128, 0);

            curve->AddBezier(
                128, 0,
                205, 35,
                265, 88,
                300, 150);

            curve->AddBezier(
                300, 150,
                335, 205,
                335, 270,
                285, 318);

            curve->AddBezier(
                285, 318,
                250, 355,
                190, 393,
                73, 415);

            curve->AddLine(73, 415, 0, 415);
            curve->CloseFigure();

            SolidBrush^ brush = gcnew SolidBrush(
                Color::FromArgb(62, 96, 72));

            e->Graphics->FillPath(brush, curve);

            delete brush;
            delete curve;
        }

        // USERNAME PLACEHOLDER
        void Username_GotFocus(
            Object^ sender, EventArgs^ e)
        {
            if (txtUsername->Text == L"Username")
            {
                txtUsername->Text = L"";
                txtUsername->ForeColor =
                    Color::FromArgb(53, 63, 54);
            }
        }

        void Username_LostFocus(
            Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(
                txtUsername->Text))
            {
                txtUsername->Text = L"Username";
                txtUsername->ForeColor = Color::Gray;
            }
        }

        // PASSWORD PLACEHOLDER
        void Password_GotFocus(
            Object^ sender, EventArgs^ e)
        {
            if (txtPassword->Text == L"Password")
            {
                txtPassword->Text = L"";
                txtPassword->UseSystemPasswordChar = true;
            }
        }

        void Password_LostFocus(
            Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrEmpty(txtPassword->Text))
            {
                txtPassword->UseSystemPasswordChar = false;
                txtPassword->Text = L"Password";
            }
        }

        // LOGIN NAVIGATION
        void BtnLogin_Click(
            Object^ sender, EventArgs^ e)
        {
            if (String::IsNullOrWhiteSpace(
                txtUsername->Text) ||
                txtUsername->Text == L"Username" ||
                String::IsNullOrEmpty(txtPassword->Text) ||
                txtPassword->Text == L"Password")
            {
                MessageBox::Show(
                    L"Please enter your username and password.",
                    L"ZenBar Login",
                    MessageBoxButtons::OK,
                    MessageBoxIcon::Warning);
                return;
            }

            // Connect your real authentication check here.
            DashboardForm^ dash = gcnew DashboardForm();

            this->Hide();
            dash->ShowDialog();
            this->Show();

            delete dash;
        }

        // HELP
        void Help_Click(
            Object^ sender, EventArgs^ e)
        {
            MessageBox::Show(
                L"Please contact your ZenBar administrator "
                L"if you need help accessing your account.",
                L"ZenBar Help",
                MessageBoxButtons::OK,
                MessageBoxIcon::Information);
        }
    };
}