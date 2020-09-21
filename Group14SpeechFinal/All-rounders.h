#pragma once
#include<iostream>
namespace CLRproj1 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Allrounders
	/// </summary>
	public ref class Allrounders : public System::Windows::Forms::Form
	{
	public:
		Allrounders(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void speak(string);
		int count_files(string);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Allrounders()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(831, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 67);
			this->label1->TabIndex = 0;
			this->label1->Text = L"List of INDIA All-Rounders";
			this->label1->Click += gcnew System::EventHandler(this, &Allrounders::label1_Click);
			// 
			// label2
			// 
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(850, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 67);
			this->label2->TabIndex = 1;
			this->label2->Text = L"1.  Hardik";
			this->label2->Click += gcnew System::EventHandler(this, &Allrounders::label2_Click);
			// 
			// label3
			// 
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(850, 263);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(164, 67);
			this->label3->TabIndex = 2;
			this->label3->Text = L"2.  Jadeja";
			this->label3->Click += gcnew System::EventHandler(this, &Allrounders::label3_Click);
			// 
			// label4
			// 
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(850, 375);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(167, 67);
			this->label4->TabIndex = 3;
			this->label4->Text = L"3.  Ashwin";
			this->label4->Click += gcnew System::EventHandler(this, &Allrounders::label4_Click);
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(1111, 376);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(176, 57);
			this->label5->TabIndex = 4;
			this->label5->Text = L"4.  Previous";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(844, 558);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(221, 36);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Please Wait . . .";
			this->label6->Click += gcnew System::EventHandler(this, &Allrounders::label6_Click);
			// 
			// Allrounders
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Allrounders";
			this->Text = L"Allrounders";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
