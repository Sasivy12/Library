#pragma once

namespace LibraryManagment {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
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
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ regButton;
	protected:
	private: System::Windows::Forms::Button^ loginButton;

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
			this->regButton = (gcnew System::Windows::Forms::Button());
			this->loginButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// regButton
			// 
			this->regButton->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->regButton->Location = System::Drawing::Point(162, 80);
			this->regButton->Name = L"regButton";
			this->regButton->Size = System::Drawing::Size(163, 58);
			this->regButton->TabIndex = 0;
			this->regButton->Text = L"Register";
			this->regButton->UseVisualStyleBackColor = true;
			this->regButton->Click += gcnew System::EventHandler(this, &MainWindow::regButton_Click);
			// 
			// loginButton
			// 
			this->loginButton->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->loginButton->Location = System::Drawing::Point(162, 176);
			this->loginButton->Name = L"loginButton";
			this->loginButton->Size = System::Drawing::Size(163, 56);
			this->loginButton->TabIndex = 1;
			this->loginButton->Text = L"Login";
			this->loginButton->UseVisualStyleBackColor = true;
			this->loginButton->Click += gcnew System::EventHandler(this, &MainWindow::loginButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(496, 316);
			this->Controls->Add(this->loginButton);
			this->Controls->Add(this->regButton);
			this->Name = L"MainWindow";
			this->Text = L"Library";
			this->ResumeLayout(false);

		}
#pragma endregion
	public: bool switchToReg = false;
	private: System::Void regButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->switchToReg = true;
		this->Close();
	}
	public: bool switchToLog = false;
	private: System::Void loginButton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->switchToLog = true;
		this->Close();
	}
	};
}
