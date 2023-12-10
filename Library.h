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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ BookBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ BookGrid;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::Button^ AllBooksButton;


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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->BookBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->BookGrid = (gcnew System::Windows::Forms::DataGridView());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->AllBooksButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BookGrid))->BeginInit();
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(413, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter which books you would like to take from library:";
			// 
			// BookBox
			// 
			this->BookBox->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BookBox->Location = System::Drawing::Point(15, 88);
			this->BookBox->Name = L"BookBox";
			this->BookBox->Size = System::Drawing::Size(410, 23);
			this->BookBox->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 149);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 18);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Your books:";
			// 
			// BookGrid
			// 
			this->BookGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->BookGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->BookGrid->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->BookGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->BookGrid->Location = System::Drawing::Point(14, 196);
			this->BookGrid->Name = L"BookGrid";
			this->BookGrid->ReadOnly = true;
			this->BookGrid->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->BookGrid->Size = System::Drawing::Size(590, 237);
			this->BookGrid->TabIndex = 5;
			// 
			// SearchButton
			// 
			this->SearchButton->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SearchButton->Location = System::Drawing::Point(431, 77);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(91, 45);
			this->SearchButton->TabIndex = 6;
			this->SearchButton->Text = L"Search";
			this->SearchButton->UseVisualStyleBackColor = true;
			this->SearchButton->Click += gcnew System::EventHandler(this, &Library::SearchButton_Click);
			// 
			// AllBooksButton
			// 
			this->AllBooksButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AllBooksButton->Location = System::Drawing::Point(528, 77);
			this->AllBooksButton->Name = L"AllBooksButton";
			this->AllBooksButton->Size = System::Drawing::Size(88, 45);
			this->AllBooksButton->TabIndex = 7;
			this->AllBooksButton->Text = L"View All Books";
			this->AllBooksButton->UseVisualStyleBackColor = true;
			// 
			// Library
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 459);
			this->Controls->Add(this->AllBooksButton);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->BookGrid);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->BookBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->IDLabel);
			this->Controls->Add(this->label1);
			this->Name = L"Library";
			this->Text = L"Library";
			this->Load += gcnew System::EventHandler(this, &Library::Library_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BookGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: String^ name = nullptr;
	public: User^ user = nullptr;
	public: int^ id = 1; 

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

				id = user->id;
				IDLabel->Text = user->id.ToString();
			}
			sqlConn.Close();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Database connection error", "Database Error", MessageBoxButtons::OK);
		}

		try
		{
			SqlConnection sqlConn("Data Source=DESKTOP-6QL0FP6\\MSSQLSERVER01;Initial Catalog=library;Integrated Security=True");
			sqlConn.Open();

			String^ Querry = "Select * from dbo.library_books Where taken_by = @ID";

			SqlCommand command(Querry, % sqlConn);
			command.Parameters->AddWithValue("@ID", 1);

			SqlDataReader^ reader = command.ExecuteReader();

			DataTable^ table = gcnew DataTable();
			table->Load(reader);

			BookGrid->DataSource = table;

			sqlConn.Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Database connection error", "Database Error", MessageBoxButtons::OK);
		}
	}
	//public: User^	user = nullptr;
	private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Database connection error", "Database Error", MessageBoxButtons::OK);
		}
	}

};
}
