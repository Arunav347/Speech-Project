#include "dirent.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "Football_country.h"
#include "FootballPlayers.h"
#include "Sports.h"
using namespace std;

int CLRproj1::Football_country ::count_files(string directory) {
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


void CLRproj1::Football_country::speak()
{
	while (1) {
		System::Threading::Thread::Sleep(4000);
		//system("PAUSE");
		label6->Text = "Speak NOW . . .";
		this->Hide();
		this->Show();
		this->Refresh();
		//int levelsize = count_files("Sports/Cricket") - 2;
		//cout << levelsize << endl;
		int levelsize = 4;
		//insert recording module here 
		system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

		CLRproj1::HMM hmm;


		/*int index = hmm.start("Record_Module\\Voice\\test.txt", "Sports\\Cricket\\Modelpara\\finalA.txt",
			"Sports\\Cricket\\Modelpara\\finalB.txt", "Sports\\Cricket\\Modelpara\\finalPI.txt",
			"Sports\\Cricket\\Modelpara\\codebook.txt", levelsize);*/
		int index = 0;
		if (index == -1) {
			this->label6->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
			this->Hide();
			this->Show();
			this->Refresh();
			continue;
		}
		else if (index == 0) {
			this->label6->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::FootballPlayers fb;
			fb.speak("Argentina");
		}
		else if (index == 1) {
			this->label6->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::FootballPlayers fb;
			fb.Show();
			fb.Refresh();
			fb.speak("France");
		}
		else if (index == 3) {
			this->label6->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::FootballPlayers fb;
			fb.Show();
			fb.Refresh();
			fb.speak("Spain");
		}
		else {
			this->label6->Text = L"Please Wait . . .";
			this->Refresh();
			this->Close();
			CLRproj1::Sports sp;

			sp.Show();
			sp.Refresh();
			sp.speak();
		}
	}
	//system("PAUSE");

}