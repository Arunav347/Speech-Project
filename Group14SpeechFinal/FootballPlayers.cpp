#include "FootballPlayers.h"

#include "Batsmen.h"
#include "Football_country.h"
#include "dirent.h"
#include "HMM.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include "Messi.h"
#include "Aguero.h"
#include "DyBala.h"
#include "DeMaria.h"
#include "Mbappe.h"
#include "Pogba.h"
#include "Kante.h"
#include "Griezmann.h"
#include "Ramos.h"
#include "Morata.h"
#include "Isco.h"
#include "Asensio.h"
using namespace std;

int CLRproj1::FootballPlayers::count_files(string directory) {
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

void CLRproj1::FootballPlayers::speak(string str)
{
		while (1) {
			if (str == "Argentina") {
				label1->Text = L"List of Argentina Footballers";
				label2->Text = L"Messi";
				label3->Text = L"Aguero";
				label4->Text = L"DyBala";
				label5->Text = L"DeMaria";
			}
			else if (str == "France") {
				label1->Text = L"List of France Footballers";
				label2->Text = L"Mbappe";
				label3->Text = L"Pogba";
				label4->Text = L"Kante";
				label5->Text = L"Griezmann";
			}
			else {
				label1->Text = L"List of Spain Footballers";
				label2->Text = L"Ramos";
				label3->Text = L"Morata";
				label4->Text = L"Isco";
				label5->Text = L"Asensio";
			}

			this->Show();
			this->Refresh();
			System::Threading::Thread::Sleep(4000);
			//system("PAUSE");
			label7->Text = "Speak NOW . . .";
			this->Hide();
			this->Show();
			this->Refresh();
			//int levelsize = count_files("Sports") - 2;
			int levelsize = 5;
			cout << levelsize << endl;
			//insert recording module here 
			system("Record_Module\\Recording_Module.exe 4 Record_Module\\Voice\\test.wav Record_Module\\Voice\\test.txt");

			CLRproj1::HMM hmm;

			/*int index = hmm.start("Record_Module\\Voice\\test.txt", "Sports\\Cricket\\India\\Batsmen\\Modelpara\\finalA.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\finalB.txt", "Sports\\Cricket\\India\\Batsmen\Modelpara\\finalPI.txt",
				"Sports\\Cricket\\India\\Batsmen\Modelpara\\codebook.txt", levelsize);*/
			int index = 0;
			if (index == -1) {
				this->label7->Text = L"We didn't recognize what you said. Wait for 4 seconds to speak again";
				this->Hide();
				this->Show();
				this->Refresh();
				continue;
			}
			else if (index == 0) {
				
				this->label7->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				if (str == "Argentina") {
					CLRproj1::Messi obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else if (str == "France") {
					CLRproj1::Mbappe obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else {
					CLRproj1::Ramos obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				//system("PAUSE");

			}
			else if (index == 1) {
				this->label7->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				if (str == "Argentina") {
					CLRproj1::Aguero obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else if (str == "France") {
					CLRproj1::Pogba obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else {
					CLRproj1::Morata obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				
			}
			else if (index == 2) {
				this->label7->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				if (str == "Argentina") {
					CLRproj1::DyBala obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else if (str == "France") {
					CLRproj1::Kante obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else {
					CLRproj1::Isco obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}

			}
			else if (index == 3) {
				this->label7->Text = L"Please Wait . . .";
				this->Refresh();
				this->Close();
				if (str == "Argentina") {
					CLRproj1::DeMaria obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else if (str == "France") {
					CLRproj1::Griezmann obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
				else {
					CLRproj1::Asensio obj;
					obj.Show();
					obj.Refresh();
					//obj.speak();
				}
			}
			else {
				//Back


			}
		}
	system("PAUSE");

}