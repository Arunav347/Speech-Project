#include "All-rounders.h"
#include "Bowlers.h"
#include "dirent.h"
#include "Test_train.h"
#include "Sports.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "India.h"
#include "Hardik.h"
#include "Ashwin.h"
#include "Jadeja.h"
#include "Stoinis.h"
#include "Maxwell.h"
#include "Cummins.h"
using namespace std;
int CLRproj1::Allrounders::count_files(string directory) {
	int levelsize;
	struct dirent* de;  // Pointer for directory entry 

	// opendir() returns a pointer of DIR type.
	char* cstr = new char[directory.length() + 1];
	std::strcpy(cstr, directory.c_str());
	DIR* dr = opendir(cstr);

	if (dr == NULL)  // opendir returns NULL if couldn't open directory 
	{
		printf("Could not open current directory");
		return 0;
	}

	while ((de = readdir(dr)) != NULL) {
		levelsize++;
		printf("%s\n", de->d_name);

	}

	closedir(dr);
	return levelsize;
}

void CLRproj1::Allrounders::speak(string str)
{
	if (str == "India") {
		while (1) {
			label1->Text = L"List of INDIA Allrounders";
			label2->Text = L"Hardik";
			label3->Text = L"Jadeja";
			label4->Text = L"Aswin";
			this->Hide();
			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label6->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports") - 2;
			int levelsize = 4;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			int index = hmm.start("Record_Module\\Voice\\test.txt", "India\\Allrounders\\Modelpara\\finalA.txt",
				"India\\Allrounders\\Modelpara\\finalB.txt", "India\\Allrounders\\Modelpara\\finalPI.txt",
				"India\\Allrounders\\Modelpara\\codebook.txt", levelsize);

			if (index == -1) {
				this->label6->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				//Bumrah
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Ashwin sh;
				sh.ShowDialog();


			}
			else if (index == 1) {
				//Shami
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Jadeja sh;
				sh.ShowDialog();
			}
			else if (index == 2) {
				//Umesh
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Hardik sh;
				sh.ShowDialog();
			}
			else {
				//Back
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::India in;
				in.Show();
				in.Refresh();
				in.speak("India");
			}
		}
	}
	else {
		while (1) {
			label1->Text = L"List of Australia Allrounders";
			label2->Text = L"Cummins";
			label3->Text = L"Maxwell";
			label4->Text = L"Stoinis";

			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label6->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports") - 2;
			int levelsize = 4;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			int index = hmm.start("Record_Module\\Voice\\test.txt", "Australia\\Bowlers\\Modelpara\\finalA.txt",
				"Australia\\Allrounders\\Modelpara\\finalB.txt", "Australia\\Allrounders\\Modelpara\\finalPI.txt",
				"Australia\\Allrounders\\Modelpara\\codebook.txt", levelsize);
			if (index == -1) {
				this->label6->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				//Bumrah
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Maxwell sh;
				sh.ShowDialog();


			}
			else if (index == 1) {
				//Shami
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Stoinis sh;
				sh.ShowDialog();
			}
			else if (index == 2) {
				//Umesh
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Cummins sh;
				sh.ShowDialog();
			}
			else {
				//Back
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::India in;
				in.Show();
				in.Refresh();
				in.speak("Australia");
			}
		}

	}

}