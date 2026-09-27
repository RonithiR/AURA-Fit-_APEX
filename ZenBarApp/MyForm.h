#pragma once

#include "CustomElixir.h"

namespace ZenBarApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnOrders;

	private: System::Windows::Forms::Button^ btnBookings;
	private: System::Windows::Forms::Button^ btnExit;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnOrders = (gcnew System::Windows::Forms::Button());
			this->btnBookings = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 9);
			this->label1->Margin = System::Windows::Forms::Padding(8, 0, 8, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(255, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Zen Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// btnOrders
			// 
			this->btnOrders->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btnOrders->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnOrders->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOrders->ForeColor = System::Drawing::Color::White;
			this->btnOrders->Location = System::Drawing::Point(25, 68);
			this->btnOrders->Name = L"btnOrders";
			this->btnOrders->Size = System::Drawing::Size(150, 45);
			this->btnOrders->TabIndex = 1;
			this->btnOrders->Text = L"Orders";
			this->btnOrders->UseVisualStyleBackColor = false;
			this->btnOrders->Click += gcnew System::EventHandler(this, &MyForm::btnOrders_Click);
			// 
			// btnBookings
			// 
			this->btnBookings->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(88)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(87)));
			this->btnBookings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBookings->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBookings->ForeColor = System::Drawing::Color::White;
			this->btnBookings->Location = System::Drawing::Point(25, 134);
			this->btnBookings->Name = L"btnBookings";
			this->btnBookings->Size = System::Drawing::Size(150, 45);
			this->btnBookings->TabIndex = 3;
			this->btnBookings->Text = L"Bookings";
			this->btnBookings->UseVisualStyleBackColor = false;
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::Color::White;
			this->btnExit->Location = System::Drawing::Point(25, 200);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(150, 45);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(20, 45);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(253)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->ClientSize = System::Drawing::Size(1924, 1055);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnBookings);
			this->Controls->Add(this->btnOrders);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(8);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnOrders_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
