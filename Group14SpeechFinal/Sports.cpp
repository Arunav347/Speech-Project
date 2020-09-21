#include "Sports.h"
#include "Cricket_country.h"
#include "Football_country.h"
#include "Badminton_country.h"
#include "dirent.h"
#include "Test_train.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int CLRproj1::Sports::count_files(string directory) {
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

void CLRproj1::Sports::speak()
{
	while (1) {
		System::Threading::Thread::Sleep(4000);
		//system("PAUSE");
		label5->Text = "Speak NOW . . .";
		this->Hide();
		this->Show();
		this->Refresh();
		//int levelsize = count_files("Sports") - 2;
		int levelsize = 3;
		cout << levelsize << endl;
		//insert recording module here 
		system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

		CLRproj1::HMM hmm;

		int index = hmm.start("Record_Module\\Voice\\test.txt", "Sports\\Modelpara\\finalA.txt",
			"Sports\\Modelpara\\finalB.txt", "Sports\\Modelpara\\finalPI.txt",
			"Sports\\Modelpara\\codebook.txt", levelsize);

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
			CLRproj1::Cricket_country cc;
			cc.Show();
			cc.Refresh();
			cc.speak();
		}
		else if (index == 1) {
			this->label5->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::Football_country fc;
			fc.Show();
			fc.Refresh();
			fc.speak();
		}
		else {
			this->label5->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::Test_train tt;

			tt.Show();
			tt.Refresh();
			tt.speak();
		}

	}
	system("PAUSE");
	
}

