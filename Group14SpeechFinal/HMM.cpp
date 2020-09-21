#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cmath>
#include<sstream>
#include<iomanip>
#include "HMM.h"
#define p 12
#define N 5
#define M 32	
#define samplesize 320
using namespace std;
ofstream fout;
long double testWord[300][12], codebook[M][12], A[N][N], B[N][M], PI[N], inA[N][N], inB[N][M], inPI[N];
long double alpha[300][N], beta[300][N];
int ObjSeqSize, ObjSeq[300];
long double finalA[10][N][N], finalB[10][N][M], finalPI[10][N];

double tokhuraWeight[12] = { 1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0 };
string input_file, fileA, fileB, filePI, fileCB;
int CurrLevelsize;
void  CLRproj1 :: HMM :: durbinsAlgorithm(vector<double>& R, vector<double>& a) {
	long double E[p + 1];
	long double arr[p + 1][p + 1];
	long double k[p + 1];
	E[0] = R[0];
	for (int i = 1; i <= p; i++) {
		int j = 1;
		double tmp = 0;
		while (j < i) {
			tmp += arr[j][i - 1] * R[i - j];
			j++;
		}
		k[i] = (R[i] - tmp) / E[i - 1];
		arr[i][i] = k[i];
		j = 1;
		while (j < i) {
			arr[j][i] = arr[j][i - 1] - k[i] * arr[i - j][i - 1];
			j++;
		}
		E[i] = (1 - k[i] * k[i]) * E[i - 1];
	}

	for (int i = 1; i <= p; i++) {
		a.push_back(arr[i][p]);
	}
}

void  CLRproj1 :: HMM :: calculatingRvalues(vector<double> v, vector<double>& ri) {
	for (int i = 0; i <= 12; i++) {
		double r = 0;
		for (int m = 0; m <= samplesize - 1 - i; m++) {
			r += v[m] * v[m + i];
		}
		//cout<<r<<endl;
		ri.push_back(r);
	}
}

void  CLRproj1 :: HMM :: calculatingCIs(double r0, vector<double> ai, vector<double>& ci) {
	ci.push_back(0);

	for (int i = 1; i <= 12; i++) {
		double sum = 0;
		for (int j = 1; j <= i - 1; j++) {
			//cout<<j<<endl;
			sum += (((double)j) / ((double)i)) * ci[j] * ai[i - j - 1];

		}
		//cout<<sum<<endl;
		ci.push_back(ai[i - 1] + sum);
	}
}

void  CLRproj1 :: HMM :: raisedCIs(vector<double>& ci) {
	for (int i = 1; i <= 12; i++) {
		//cout<<setprecision(6);
		double value = 1 + 6 * sin(3.141592653 * i / 12);
		ci[i] *= value;
	}

}

void  CLRproj1 :: HMM :: Normalization(vector<double>& v, double factor)
{
	for (int i = 0; i < v.size(); i++) {
		v[i] *= factor;
	}
}
int  CLRproj1 :: HMM :: takeInput()
{
	//cout << "Recording Starts now for 3 seconds: ";

	//system("Recording_Module.exe 3 input_file.wav input_file.txt");
	//cout << "Recording Ends now: ";
	ifstream fin;
	fin.open(input_file);
	if (!fin)
	{
		cout << "Unable to open the file ";
		exit(1);
	}
	int data, count = 0;
	vector<double> v;
	double max1 = -2147483647;
	while (fin >> data)
	{
		count++;
		if (count >= 7000)
		{
			v.push_back(data);
			if ((abs(data)) > max1) max1 = abs(data);
		}
	}
	//cout<<endl;
	//cout<<v.size()<<endl;
	//cout<<max1<<endl;
	double factor = 5000.0 / max1;
	//cout<<factor<<endl;
	Normalization(v, factor);
	max1 = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] > max1) max1 = v[i];
	}
	//cout<<v.size()<<endl;
	//cout<<max1<<endl;
	vector<double> ri, ai, ci, v1;
	long double STE = 0;
	int startFrameno = 0;
	int stride = 100;
	int totalframes = v.size() / stride;
	long double tenste[20];
	int limit = 20;

	while (startFrameno < totalframes)
	{
		memset(tenste, 0, sizeof(tenste));
		STE = 0;
		for (int k = 0; k < stride; k++)
		{
			STE += v[startFrameno * stride + k] * v[startFrameno * stride + k];
		}
		STE /= stride;
		//cout<<"Current STE: "<<startFrameno<<endl;
		//cout<<STE<<endl;
		//cout<<"STE of next "<< limit<<" frames \n";
		int consecframes = startFrameno + 1;
		for (int l = 0; l < limit; l++)
		{
			for (int m = 0; m < stride; m++)
			{
				tenste[l] += v[consecframes * stride + m] * v[consecframes * stride + m];
			}
			tenste[l] /= stride;
			//cout<<tenste[l]<<endl;
			consecframes++;

		}
		int conseccount = 0, high = 0;
		for (int k = 0; k < limit; k++)
		{
			if (tenste[k] > 1000000) high++;
			if (tenste[k] >= 8 * STE) conseccount++;
		}
		if (conseccount >= 10)
		{
			if (high > 2)
				break;
			else if (conseccount >= 22) break;
		}
		else {
			if (high >= 6) break;
		}
		startFrameno++;
	}
	reverse(v.begin(), v.end());
	int endFrameno = 0;
	long double tenste1[25];
	limit = 25;
	//cout<<startFrameno<<endl;
	//cout<<"For end mark"<<endl;
	while (endFrameno < totalframes)
	{
		memset(tenste1, 0, sizeof(tenste1));
		STE = 0;
		for (int k = 0; k < stride; k++)
		{
			STE += v[endFrameno * stride + k] * v[endFrameno * stride + k];
		}
		STE /= stride;
		//if(i == 3 && j==10)cout<<STE<<endl;
//cout<<"Current STE: "<<endFrameno<<endl;
//cout<<STE<<endl;
//cout<<"STE of previous "<< limit<<" frames \n";
		int consecframes = endFrameno + 1;
		for (int l = 0; l < limit; l++)
		{
			for (int m = 0; m < stride; m++)
			{
				tenste1[l] += v[consecframes * stride + m] * v[consecframes * stride + m];
			}
			tenste1[l] /= stride;
			//cout<<tenste[l]<<endl;
			consecframes++;

		}
		int conseccount = 0, high = 0;
		for (int k = 0; k < limit; k++)
		{
			if (tenste1[k] > 1000000) high++;
			if (tenste1[k] >= 8 * STE) conseccount++;
		}
		if (conseccount >= 15)
		{
			if (high >= 2)
				break;
		}
		else
		{
			if (high >= 8) break;
		}
		endFrameno++;
	}
	reverse(v.begin(), v.end());
	int endIndex = endFrameno * stride;
	endIndex = (v.size() - endIndex - 1);
	int startIndex = startFrameno * stride;
	int totalsamplesize = endIndex - startIndex + 1;
	if (totalsamplesize > 16000) return -1;
	if (startIndex > endIndex) return -1;
	cout << startIndex << " " << endIndex << endl;
	//cout<<"TotalampleSize: "<<totalsamplesize<<endl;
	//fout<<endl;
	int s = 0, t = 0, index = startIndex, flag = 0;
	while (1)
	{
		s = 0;
		ri.clear(), v1.clear(), ai.clear(), ci.clear();
		while ((s++) < samplesize)
		{
			if (index < endIndex)
			{
				v1.push_back(v[index++]);
			}
			else
			{
				flag = 1;
				break;
			}

		}
		if (flag == 1)break;
		calculatingRvalues(v1, ri);
		durbinsAlgorithm(ri, ai);
		calculatingCIs(ri[0], ai, ci);
		raisedCIs(ci);
		for (int k = 0; k < p; k++)
		{
			testWord[t][k] = ci[k + 1];
		}
		t++;
		index = index - 240;
	}
	ObjSeqSize = t;
	fin.close();
	return 0;
}

void   CLRproj1 :: HMM :: ObjSeqGeneration()
{
	ifstream fin;
	fin.open(fileCB);
	if (!fin)
	{
		cout << "Unable to open the file";
		exit(1);
	}
	string line; long double data;
	int i = 0;
	while (getline(fin, line))
	{
		stringstream ss(line);
		for (int j = 0; j < 12; j++)
		{
			ss >> data;
			codebook[i][j] = data;
		}
		i++;
	}
	fin.close();
	for (int t = 0; t < ObjSeqSize; t++)
	{
		long double min = 0;
		int index = 0;
		for (int k = 0; k < 12; k++)
		{
			min += tokhuraWeight[k] * (pow(testWord[t][k] - codebook[0][k], 2));
		}
		long double tokhuradistance;
		for (int m = 1; m < M; m++)
		{
			tokhuradistance = 0;
			for (int k = 0; k < 12; k++)
			{
				tokhuradistance += tokhuraWeight[k] * (pow(testWord[t][k] - codebook[m][k], 2));
			}
			if (tokhuradistance < min)
			{
				min = tokhuradistance;
				index = m;
			}
		}
		ObjSeq[t] = index;
		//cout<<index<<" ";
	}
	//cout<<endl<<endl;
}
long double   CLRproj1 :: HMM :: solution1(vector<int> objseq1)
{
	int T = objseq1.size();
	//for(int i=0; i<T; i++) fout<<objseq1[i]<<" ";
	//fout<<endl<<endl;
	//Working for Forward Procedure
	//Initialization of alpha matrix
	for (int i = 0; i < N; i++)
	{
		alpha[0][i] = PI[i] * B[i][objseq1[0]];
	}


	//Induction for alpha matrix
	for (int t = 1; t < T; t++)
	{
		for (int j = 0; j < N; j++)
		{
			long double sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += (alpha[t - 1][i] * A[i][j]);
			}
			sum *= B[j][objseq1[t]];
			alpha[t][j] = sum;
		}
	}

	//Termination
	long double sol1forward = 0;
	for (int i = 0; i < N; i++) sol1forward += alpha[T - 1][i];
	return sol1forward;
	//Forward Procedure ends here
}
int CLRproj1 :: HMM :: TestHMM()
{
	//Reading intial Model parameters A,B,PI;

	ifstream fin;
	string line;
	fin.open(fileA);
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	int i = 0, j = 0;
	long double data;
	cout << setprecision(9);
	while (getline(fin, line))
	{
		if (line.empty())
		{
			i++, j = 0;
			continue;
		}
		stringstream ss(line);
		for (int k = 0; k < N; k++)
		{
			ss >> data;
			finalA[i][j][k] = data;
		}
		j++;
	}
	fin.close();
	fin.open(fileB);
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	i = 0, j = 0;
	cout << scientific;
	while (getline(fin, line))
	{
		if (line.empty())
		{
			i++, j = 0;
			continue;
		}
		stringstream ss(line);
		for (int k = 0; k < M; k++)
		{
			ss >> data;
			finalB[i][j][k] = data;
		}
		j++;

	}
	fin.close();
	fin.open(filePI);
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	i = 0;
	while (getline(fin, line))
	{
		stringstream ss(line);
		for (int j = 0; j < N; j++)
		{
			ss >> data;
			finalPI[i][j] = data;
		}
		i++;
	}
	fin.close();
	int iteration;
	vector<int> objseq1;
	for (int t = 0; t < ObjSeqSize; t++)
	{
		objseq1.push_back(ObjSeq[t]);
	}
	long double* pobmodel = new long double[CurrLevelsize];
	for (int k = 0; k < CurrLevelsize; k++)
	{
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < N; m++)
			{
				A[l][m] = finalA[k][l][m];
			}
		}
		for (int l = 0; l < N; l++)
		{
			for (int m = 0; m < M; m++)
			{
				B[l][m] = finalB[k][l][m];
			}
		}
		for (int l = 0; l < N; l++)
		{
			PI[l] = finalPI[k][l];
		}
		pobmodel[k] = solution1(objseq1);
		cout << pobmodel[k]<<endl;

	}
	long double max = 0;
	int index = 0;
	for (int k = 0; k < CurrLevelsize; k++)
	{
		if (max < pobmodel[k])
		{
			max = pobmodel[k];
			index = k;
		}
	}
	return index;


}
int  CLRproj1 :: HMM:: start(string input_txt, string fa, string fb, string fpi, string fcb, int levelsize)
{
	input_file = input_txt;
	fileA = fa;
	fileB = fb;
	filePI = fpi;
	fileCB = fcb;
	CurrLevelsize = levelsize;
	int utteredindex;
	int val = takeInput();
	if (val == 0) {
		ObjSeqGeneration();
		utteredindex = TestHMM();
	}
	else utteredindex = -1;
	return utteredindex;
}