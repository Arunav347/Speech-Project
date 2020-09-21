#pragma once
#include<vector>
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
	/// Summary for Test_train
	/// </summary>
	public class HMM
	{
		public:
		void durbinsAlgorithm(vector<double>& R, vector<double>& a);
		void calculatingRvalues(vector<double> v, vector<double>& ri);
		void calculatingCIs(double r0, vector<double> ai, vector<double>& ci);
		void raisedCIs(vector<double>& ci);
		void Normalization(vector<double>& v, double factor);
		int takeInput();
		void ObjSeqGeneration();
		long double solution1(vector<int> objseq1);
		int TestHMM();
		int start(string, string, string, string, string, int);

	};
}