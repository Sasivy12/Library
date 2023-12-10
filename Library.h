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
	/// Summary for Library
	/// </summary>
	public ref class Library : public System::Windows::Forms::Form
	{
	public:
		Library(void)
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
		~Library()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ IDLabel;
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
			this->IDLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(469, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Your ID:";
			// 
			// IDLabel
			// 
			this->IDLabel->AutoSize = true;
			this->IDLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IDLabel->Location = System::Drawing::Point(567, 9);
			this->IDLabel->Name = L"IDLabel";
			this->IDLabel->Size = System::Drawing::Size(49, 24);
			this->IDLabel->TabIndex = 1;
			this->IDLabel->Text = L"~ID~";
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 459);
			this->Controls->Add(this->IDLabel);
			this->Controls->Add(this->label1);
			this->Name = L"Library";
			this->Text = L"Library";
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: String^ name = nullptr;
	public: User^ user = nullptr;
	private: System::Void Library_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			SqlConnection sqlConn("Data Source=DESKTOP-6QL0FP6\\MSSQLSERVER01;Initial Catalog=library;Integrated Security=True");
			sqlConn.Open();

			String^ Querry = "Select ID from dbo.library_users Where name = @name";

			SqlCommand command(Querry, % sqlConn);
			command.Parameters->AddWithValue("@name", name);
			
			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read())
			{
				user = gcnew User;
				user->id = reader->GetInt32(0);

				IDLabel->Text = user->id.ToString();
			}
			
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Database connection error", "Database Error", MessageBoxButtons::OK);
		}
	}
	};
}
