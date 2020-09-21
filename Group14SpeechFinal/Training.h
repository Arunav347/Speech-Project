#pragma once
#include "Test_train.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <Thread>
#include <algorithm>
namespace CLRproj1 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Training
	/// </summary>
	public ref class Training : public System::Windows::Forms::Form
	{
	public:
		Training(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		void durbinsAlgorithm(vector<double>& R, vector<double>& a);
		void calculatingRvalues(vector<double> v, vector<double>& ri);
		void calculatingCIs(double r0, vector<double> ai, vector<double>& ci);
		void raisedCIs(vector<double>& ci);
		void Normalization(vector<double>& v, double factor);
		void takeInput();
		void ObjSeqGeneration();
		void solution1(vector<int> objseq1);
		void solution2(vector<int> objseq1);
		void solution3(vector<int> objseq1);
		void AverageHMM(int i);
		void BuildHMM();
		void start(string,int);
		void updateModel(string, int,int);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Training()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;

	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::TextBox^ textBox2;









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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Location = System::Drawing::Point(744, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(396, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Below are the trained Sports in the respective category";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(532, 154);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cricket";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1236, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Football";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1577, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Back";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(642, 239);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(71, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Australia";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(421, 239);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"India";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(1430, 239);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(50, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Spain";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1243, 239);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 20);
			this->label8->TabIndex = 7;
			this->label8->Text = L"France";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(1033, 239);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(78, 20);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Argentina";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(421, 313);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 20);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Virat";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(421, 410);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(51, 20);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Dhoni";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(421, 459);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(63, 20);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Shikhar";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(421, 513);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(55, 20);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Hardik";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(421, 567);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(56, 20);
			this->label15->TabIndex = 14;
			this->label15->Text = L"Jadeja";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(421, 620);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(60, 20);
			this->label16->TabIndex = 15;
			this->label16->Text = L"Ashwin";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(421, 677);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(54, 20);
			this->label17->TabIndex = 16;
			this->label17->Text = L"Shami";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(421, 729);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(60, 20);
			this->label18->TabIndex = 17;
			this->label18->Text = L"Umesh";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(421, 782);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(65, 20);
			this->label20->TabIndex = 19;
			this->label20->Text = L"Bumrah";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(642, 826);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 20);
			this->label19->TabIndex = 29;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(642, 729);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(47, 20);
			this->label21->TabIndex = 28;
			this->label21->Text = L"Starc";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(642, 677);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(53, 20);
			this->label22->TabIndex = 27;
			this->label22->Text = L"Siddle";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(642, 620);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(75, 20);
			this->label23->TabIndex = 26;
			this->label23->Text = L"Cummins";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(642, 567);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(57, 20);
			this->label24->TabIndex = 25;
			this->label24->Text = L"Stoinis";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(642, 513);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(64, 20);
			this->label25->TabIndex = 24;
			this->label25->Text = L"Maxwell";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(642, 410);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(50, 20);
			this->label27->TabIndex = 22;
			this->label27->Text = L"Smith";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(642, 360);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(61, 20);
			this->label28->TabIndex = 21;
			this->label28->Text = L"Warner";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(642, 313);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(48, 20);
			this->label29->TabIndex = 20;
			this->label29->Text = L"Finch";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(642, 782);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(59, 20);
			this->label30->TabIndex = 30;
			this->label30->Text = L"Zampa";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(1033, 459);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(50, 20);
			this->label31->TabIndex = 34;
			this->label31->Text = L"Messi";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(1033, 410);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(60, 20);
			this->label32->TabIndex = 33;
			this->label32->Text = L"DyBala";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(1033, 360);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(69, 20);
			this->label33->TabIndex = 32;
			this->label33->Text = L"DeMaria";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(1033, 313);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(61, 20);
			this->label34->TabIndex = 31;
			this->label34->Text = L"Aguero";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(1243, 459);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(55, 20);
			this->label35->TabIndex = 38;
			this->label35->Text = L"Pogba";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(1243, 410);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(67, 20);
			this->label36->TabIndex = 37;
			this->label36->Text = L"Mbappe";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(1243, 360);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(51, 20);
			this->label37->TabIndex = 36;
			this->label37->Text = L"Kante";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(1243, 313);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(87, 20);
			this->label38->TabIndex = 35;
			this->label38->Text = L"Greizmann";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(1430, 459);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(60, 20);
			this->label39->TabIndex = 42;
			this->label39->Text = L"Ramos";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(1430, 410);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(59, 20);
			this->label40->TabIndex = 41;
			this->label40->Text = L"Morata";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(1430, 360);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(39, 20);
			this->label41->TabIndex = 40;
			this->label41->Text = L"Isco";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(1430, 313);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(66, 20);
			this->label42->TabIndex = 39;
			this->label42->Text = L"Asensio";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(421, 881);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(242, 20);
			this->label43->TabIndex = 43;
			this->label43->Text = L"Type a word you want to Train. . . ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(784, 878);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(230, 26);
			this->textBox1->TabIndex = 44;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Training::textBox1_TextChanged);
			this->textBox1->Leave += gcnew System::EventHandler(this, &Training::textBox1_Leave);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1122, 871);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 40);
			this->button1->TabIndex = 45;
			this->button1->Text = L"Train";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Training::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1259, 871);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 40);
			this->button2->TabIndex = 46;
			this->button2->Text = L"Previous";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Training::button2_Click);
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(425, 933);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(115, 20);
			this->label44->TabIndex = 47;
			this->label44->Text = L"Iteration Count";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(784, 933);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 48;
			// 
			// Training
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label43);
			this->Controls->Add(this->label39);
			this->Controls->Add(this->label40);
			this->Controls->Add(this->label41);
			this->Controls->Add(this->label42);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label37);
			this->Controls->Add(this->label38);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Training";
			this->Text = L"Training";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Training::Training_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void Training_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		


}
private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	CLRproj1::Test_train tt;
	tt.Show();
	tt.Refresh();
	tt.speak();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int iteration = Convert::ToInt32(textBox2->Text);
	int val = iteration,count;

	msclr::interop::marshal_context context;
	string str = context.marshal_as<string>(textBox1->Text);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	cout << iteration << " " << str;
	//ofstream fout;
	string module;
	while (iteration--) {
		module = "Record_Module\\Recording_Module.exe 3 ";
		module = module + "TrainingPart\\"+to_string(iteration+1) + ".wav " + "TrainingPart\\" + to_string(iteration+1) + ".txt";
		cout << module << endl;
		const char* c = module.c_str();
		system(c);
		module = "TrainingPart\\" + to_string(iteration+1) + ".wav ";
		const char* c1 = module.c_str();

		remove(c1);
		//fout.open(str1 + to_string(iteration) + ".txt");



		System::Threading::Thread::Sleep(1000);
	}
	string codebooklocation,finalloc;
	int index;
	if(str == "india" || str == "australia"){
		finalloc = "Cricket\\Modelpara\\";
		if (str == "india") index = 0;
		else index = 1;

		count = 3;

	}
	else if (str == "virat" || str == "dhoni" || str == "shikhar") {
		finalloc = "India\\Batsmen\\Modelpara\\";
		if (str == "shikhar") index = 0;
		else if (str == "virat") index = 1;
 		else index = 2;
		count = 4;
	}
	else if (str == "hardik" || str == "jadeja" || str == "ashwin") {
		finalloc = "India\\Allrounders\\Modelpara\\";
		if (str == "ashwin") index = 0;
		else if (str == "jadeja") index = 1;
		else index = 2;
		count = 4;
	}
	else if (str == "shami" || str == "bumrah" || str == "umesh") {
		finalloc = "India\\Bowlers\\Modelpara\\";
		if (str == "bumrah") index = 0;
		else if (str == "shami") index = 1;
		else index = 2;
		count = 4;
	}
	else if (str == "finch" || str == "warner" || str == "smith") {
		finalloc = "Australia\\Batsmen\\Modelpara\\";
		if (str == "finch") index = 0;
		else if (str == "warner") index = 1;
		else index = 2;
		count = 4;
	}
	else if (str == "starc" || str == "siddle" || str == "zampa") {
		finalloc = "Australia\\Bowlers\\Modelpara\\";
		if (str == "siddle") index = 0;
		else if (str == "starc") index = 1;
		else index = 2;
		count = 4;
	}
	else if (str == "cummins" || str == "stoinis" || str == "maxwell") {
		finalloc = "Australia\\Allrounders\\Modelpara\\";
		if (str == "cummins") index = 0;
		else if (str == "stoinis") index = 1;
		else index = 2;
		count = 4;
	}
	else if (str == "batsmen" || str == "bowlers" || "allrounders"){
		finalloc = "India\\Modelpara\\";
		if (str == "batsmen") index = 0;
		else if (str == "bowlers") index = 1;
		else index = 2;
		count = 4;
	}
	else {

	}
	cout << finalloc + "codebook.txt" << endl;
	start(finalloc + "codebook.txt",val);
	updateModel(finalloc, index,count);
	system("PAUSE");

}
};
}
