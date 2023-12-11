#pragma once

namespace LibraryManagment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for AllBooks
	/// </summary>
	public ref class AllBooks : public System::Windows::Forms::Form
	{
	public:
		AllBooks(void)
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
		~AllBooks()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ BookGrid;
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
			this->BookGrid = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BookGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(302, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"All Books";
			// 
			// BookGrid
			// 
			this->BookGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->BookGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->BookGrid->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->BookGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->BookGrid->Location = System::Drawing::Point(1, 69);
			this->BookGrid->Name = L"BookGrid";
			this->BookGrid->ReadOnly = true;
			this->BookGrid->Size = System::Drawing::Size(721, 491);
			this->BookGrid->TabIndex = 1;
			this->BookGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AllBooks::dataGridView1_CellContentClick);
			// 
			// AllBooks
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(722, 561);
			this->Controls->Add(this->BookGrid);
			this->Controls->Add(this->label1);
			this->Name = L"AllBooks";
			this->Text = L"AllBooks";
			this->Load += gcnew System::EventHandler(this, &AllBooks::AllBooks_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BookGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void AllBooks_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{
			SqlConnection sqlConn("Data Source=DESKTOP-6QL0FP6\\MSSQLSERVER01;Initial Catalog=library;Integrated Security=True");
			sqlConn.Open();

			String^ Querry = "Select book_name, book_author from dbo.library_books Where taken_by is NULL";

			SqlCommand command(Querry, % sqlConn);

			SqlDataReader^ reader = command.ExecuteReader();

			DataTable^ table = gcnew DataTable();
			table->Load(reader);

			BookGrid->DataSource = table;

			sqlConn.Close();
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Ошибка регистрации пользователя", "Database Error", MessageBoxButtons::OK);
		}
	}
	};
}
