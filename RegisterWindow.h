#pragma once
#include "User.h"

namespace LibraryManagment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for RegisterWindow
	/// </summary>
	public ref class RegisterWindow : public System::Windows::Forms::Form
	{
	public:
		RegisterWindow(void)
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
		~RegisterWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ nameBox;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ phoneBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ passwBox;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ repPasswBox;

	private: System::Windows::Forms::Button^ button1;
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
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->phoneBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->passwBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->repPasswBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(222, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registration";
			this->label1->Click += gcnew System::EventHandler(this, &RegisterWindow::label1_Click);
			// 
			// nameBox
			// 
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameBox->Location = System::Drawing::Point(196, 95);
			this->nameBox->Multiline = true;
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(352, 23);
			this->nameBox->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(117, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name:";
			// 
			// phoneBox
			// 
			this->phoneBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->phoneBox->Location = System::Drawing::Point(196, 142);
			this->phoneBox->Multiline = true;
			this->phoneBox->Name = L"phoneBox";
			this->phoneBox->Size = System::Drawing::Size(352, 23);
			this->phoneBox->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(33, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(157, 23);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Phone number:";
			// 
			// passwBox
			// 
			this->passwBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->passwBox->Location = System::Drawing::Point(196, 186);
			this->passwBox->Multiline = true;
			this->passwBox->Name = L"passwBox";
			this->passwBox->Size = System::Drawing::Size(352, 23);
			this->passwBox->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(81, 186);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 23);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Password:";
			this->label4->Click += gcnew System::EventHandler(this, &RegisterWindow::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(19, 228);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(171, 23);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Repeat Pasword:";
			// 
			// repPasswBox
			// 
			this->repPasswBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->repPasswBox->Location = System::Drawing::Point(196, 228);
			this->repPasswBox->Multiline = true;
			this->repPasswBox->Name = L"repPasswBox";
			this->repPasswBox->Size = System::Drawing::Size(352, 23);
			this->repPasswBox->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(227, 296);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(158, 46);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RegisterWindow::button1_Click);
			// 
			// RegisterWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(599, 414);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->repPasswBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->passwBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->phoneBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label1);
			this->Name = L"RegisterWindow";
			this->Text = L"Register";
			this->Load += gcnew System::EventHandler(this, &RegisterWindow::RegisterWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void RegisterWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	public: User^ user = nullptr;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ name = nameBox->Text;
		String^ phone_num = phoneBox->Text;
		String^ passw = passwBox->Text;

		if (nameBox->Text->Length == 0 || phoneBox->Text->Length == 0 || passwBox->Text->Length == 0 || repPasswBox->Text->Length == 0)
		{
			MessageBox::Show("Некорректные данные", "Ошибка ввода", MessageBoxButtons::OK);
		}

		if (passwBox->Text != repPasswBox->Text)
		{
			MessageBox::Show("Пароли не одинаковы", "Ошибка ввода", MessageBoxButtons::OK);
		}
		else
		{
			try
			{
				SqlConnection sqlConn("Data Source=DESKTOP-6QL0FP6\\MSSQLSERVER01;Initial Catalog=library;Integrated Security=True");
				sqlConn.Open();

				String^ Querry = "Insert Into library_users(name, phone_number, password) Values (@name, @phone_number, @password)";

				SqlCommand command(Querry, % sqlConn);
				command.Parameters->AddWithValue("@name", name);
				command.Parameters->AddWithValue("@phone_number", phone_num);
				command.Parameters->AddWithValue("@password", passw);

				command.ExecuteNonQuery();
				user = gcnew User;
				user->name = name;
				user->phone_number = phone_num;
				user->password = passw;

				MessageBox::Show("Пользователь успешно добавлен", "Succesfull Input", MessageBoxButtons::OK);

				sqlConn.Close();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Ошибка регистрации пользователя", "Database Error", MessageBoxButtons::OK);
			}
		}
		
	}

};
}
