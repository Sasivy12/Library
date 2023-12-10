#pragma once
#include "User.h"
#include "Library.h"

namespace LibraryManagment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for LoginWindow
	/// </summary>
	public ref class LoginWindow : public System::Windows::Forms::Form
	{
	public:
		LoginWindow(void)
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
		~LoginWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::TextBox^ passwBox;

	private: System::Windows::Forms::Button^ loginButton;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->passwBox = (gcnew System::Windows::Forms::TextBox());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(253, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Login";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(85, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name:";
			this->label2->Click += gcnew System::EventHandler(this, &LoginWindow::label2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(49, 123);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 23);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Password:";
			// 
			// nameBox
			// 
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nameBox->Location = System::Drawing::Point(164, 84);
			this->nameBox->Multiline = true;
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(352, 23);
			this->nameBox->TabIndex = 9;
			// 
			// passwBox
			// 
			this->passwBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->passwBox->Location = System::Drawing::Point(164, 124);
			this->passwBox->Multiline = true;
			this->passwBox->Name = L"passwBox";
			this->passwBox->Size = System::Drawing::Size(352, 23);
			this->passwBox->TabIndex = 10;
			// 
			// loginButton
			// 
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->loginButton->Location = System::Drawing::Point(221, 190);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(158, 46);
			this->loginButton->TabIndex = 11;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &LoginWindow::loginButton_Click);
			// 
			// LoginWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(604, 281);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->passwBox);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginWindow";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	public: User^ user = nullptr;
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		String^ name = nameBox->Text;
		String^ passw = passwBox->Text;

		if (passwBox->Text->Length == 0 || nameBox->Text->Length == 0)
		{
			MessageBox::Show("Incorect input", "Input Error", MessageBoxButtons::OK);
		}

		try
		{
			SqlConnection sqlConn("Data Source=DESKTOP-6QL0FP6\\MSSQLSERVER01;Initial Catalog=library;Integrated Security=True");
			sqlConn.Open();

			String^ Querry = "Select * From library_users Where name = @name And password = @password";

			SqlCommand command(Querry, %sqlConn);
			command.Parameters->AddWithValue("@name", name);
			command.Parameters->AddWithValue("@password", passw);

			SqlDataReader^ reader = command.ExecuteReader();
			
			if (reader->Read())
			{
				user = gcnew User;
				user->id = reader->GetInt32(0);
				user->phone_number = reader->GetString(2);
				user->password = reader->GetString(3);

				MessageBox::Show("User succesfully found", "Input Succesfull", MessageBoxButtons::OK);

				LibraryManagment::Library lib;
				lib.name = name;
				lib.ShowDialog();
			}
			else
			{
				MessageBox::Show("User not found", "Input Error", MessageBoxButtons::OK);
			}

		}
		catch (Exception^ e)
		{
			MessageBox::Show("Database connection error", "Database Error", MessageBoxButtons::OK);
		}
	}
};
}
