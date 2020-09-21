#include "Cricket_country.h"
#//include "Football_country.h"
#include "dirent.h"
#include "Test_train.h"
#include "Sports.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "India.h"
#include "Batsmen.h"
#include "Bowlers.h"
#include "All-rounders.h"
using namespace std;

int CLRproj1::India::count_files(string directory) {
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
		//printf("%s\n", de->d_name);

	}

	closedir(dr);
	return levelsize;
}


void CLRproj1::India::speak(string str)
{
	if (str == "India") {
		while (1) {
			this->label1->Text = L"India";
			this->Text = L"India";
			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			label5->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports/Cricket") - 2;
			int levelsize = 4;
			cout << levelsize << endl;
			//insert recording module here 
			//cout << "bat bowl all";
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;


			int index = hmm.start("Record_Module\\Voice\\test.txt", "India\\Modelpara\\finalA.txt",
				"India\\Modelpara\\finalB.txt", "India\\Modelpara\\finalPI.txt",
				"India\\Modelpara\\codebook.txt", levelsize);
			//int index = 1;
			if (index == -1) {
				this->label5->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh(); 
				continue;
			}
			else if (index == 0) {
				this->label5->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Batsmen bm;
				bm.speak("India");
			}
			else if (index == 1) {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Bowlers bl;
				bl.speak("India");
			}
			else if (index == 2) {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Allrounders ar;
				ar.speak("India");
			}
			else {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Cricket_country cc;
				cc.Show();
				cc.Refresh();
				cc.speak();
			}
		}
	}
	else {
		while (1) {
			this->label1->Text = L"Australia";
			this->Text = L"Australia";
			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			label5->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports/Cricket") - 2;
			int levelsize = 4;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;


			int index = hmm.start("Record_Module\\Voice\\test.txt", "India\\Modelpara\\finalA.txt",
				"India\\Modelpara\\finalB.txt", "India\\Modelpara\\finalPI.txt",
				"India\\Modelpara\\codebook.txt", levelsize);
			//int index = 0;
			if (index == -1) {
				this->label5->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				this->label5->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Batsmen bm;
				bm.speak("Australia");
			}
			else if (index == 1) {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Bowlers bl;
				bl.speak("Australia");
			}
			else if (index == 2) {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Allrounders ar;
				ar.speak("Australia");
			}
			else {
				this->label6->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				CLRproj1::Cricket_country cc;

				cc.Show();
				cc.Refresh();
				cc.speak();
			}
		}
	}
	system("PAUSE");

}