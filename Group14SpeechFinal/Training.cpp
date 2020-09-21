#include "Training.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cmath>
#include<sstream>
#include<iomanip>
#include<iomanip>
#define p 12
#define N 5
#define tot 1
#define M 32
#define samplesize 320
using namespace std;
ofstream fout1;
long double alldigits1[10][21][300][12], codebook1[32][12], a11[10][21][N][N], b11[10][21][N][M], pi11[10][21][N], A11[N][N], B11[N][M], PI11[N], inA1[N][N], inB1[N][M], inPI1[N];
long double alpha1[300][N], beta1[300][N], delta1[300][N], sol31[300][N][N], gamma1[300][N];
int ObjSeqSize1[10][21], psi1[300][N], statesequence1[300], ObjSeq1[10][21][300];
long double sol1forward1, performance1;
long double finalA1[10][N][N] = { 0 }, finalB1[10][N][M] = { 0 }, finalPI1[10][N] = { 0 };
int utt = 0;
double tokhuraWeight1[12] = { 1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0 };
string finalcb1;
void  CLRproj1::Training::durbinsAlgorithm(vector<double>& R, vector<double>& a) {
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

void  CLRproj1::Training::calculatingRvalues(vector<double> v, vector<double>& ri) {
	for (int i = 0; i <= 12; i++) {
		double r = 0;
		for (int m = 0; m <= samplesize - 1 - i; m++) {
			r += v[m] * v[m + i];
		}
		//cout<<r<<endl;
		ri.push_back(r);
	}
}

void  CLRproj1::Training::calculatingCIs(double r0, vector<double> ai, vector<double>& ci) {
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

void  CLRproj1::Training::raisedCIs(vector<double>& ci) {
	for (int i = 1; i <= 12; i++) {
		//cout<<setprecision(6);
		double value = 1 + 6 * sin(3.141592653 * i / 12);
		ci[i] *= value;
	}

}

void  CLRproj1::Training::Normalization(vector<double>& v, double factor)
{
	for (int i = 0; i < v.size(); i++) {
		v[i] *= factor;
	}
}
void  CLRproj1::Training::takeInput()
{
	string inputfile;
	ifstream fin;

	string firstlevel[1] = { "TrainingPart\\" };
	string seperator = "_";
	string extension = ".txt";
	cout << "insidefunction" << endl;
	for (int i = 0; i < tot; i++)
	{
		for (int j = 1; j < utt; j++)
		{
			inputfile = firstlevel[i] + to_string((unsigned long long)j) + extension;
			cout << inputfile << endl << endl;
			fin.open(inputfile);
			if (!fin)
			{
				cout << "Unable to open the file";
				exit(1);
			}
			int data, count = 0;
			vector<double> v;
			double max1 = -2147483647;
			while (fin >> data)
			{
				count++;
				if(count>7000)
				v.push_back(data);
				if ((abs(data)) > max1) max1 = abs(data);
			}
			double factor = 5000.0 / max1;
			Normalization(v, factor);
			vector<double> ri, ai, ci, v1; 
			long double STE = 0;
			int startFrameno = 0;
			int stride = 100;
			int totalframes = v.size() / stride;
			cout << "total frames in this recording"<<totalframes << endl;
			long double tenste[20];
			int limit = 20;

			while (startFrameno < totalframes-2)
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
			//cout << startFrameno * 100 << endl;
			reverse(v.begin(), v.end());
			int endFrameno = 0;
			long double tenste1[20];
			limit = 20;
			//cout<<startFrameno<<endl;
			//cout<<"For end mark"<<endl;
			while (endFrameno < totalframes-3)
			{
				//cout << endFrameno << endl;
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
					if (tenste1[k] >= 8* STE) conseccount++;
				}
				if (conseccount >= 15)
				{
					if (high >= 2)
						break;
					//else if (conseccount >= 20 && high == 1)break;
					
				}
				else
				{
					if (high >= 8) break;
				}
				endFrameno++;
			}
			reverse(v.begin(), v.end());
			int endIndex = endFrameno * 100;
			endIndex = (v.size() - endIndex - 1);
			int startIndex = startFrameno * 100;
			int totalsamplesize = endIndex - startIndex + 1;
			cout << startIndex << " " << endIndex << endl;
			//cout<<"TotalampleSize: "<<totalsamplesize<<endl;
			//cout<<endl;
			int s = 0, t = 0, index = startIndex, flag = 0;
			//cout<<index<<endl;
			while (1)
			{
				//cout<<index<<endl;
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
				//cout<<s<<endl<<endl;
				calculatingRvalues(v1, ri);
				durbinsAlgorithm(ri, ai);
				calculatingCIs(ri[0], ai, ci);
				raisedCIs(ci);
				for (int k = 0; k < p; k++)
				{
					alldigits1[i][j][t][k] = ci[k + 1];
					//foutci<<ci[k+1]<<"  ";
				}
				//foutci<<endl;
				//fout<<endl;
				t++;
				index = index - 240;
			}
			//fout<<endl;
			ObjSeqSize1[i][j] = t;
			cout << t << " ";

			fin.close();
		}
	}
}

void  CLRproj1::Training::ObjSeqGeneration()
{
	ifstream fin;
	fin.open(finalcb1);
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
			codebook1[i][j] = data;
		}
		i++;
	}
	for (int i = 0; i < tot; i++)
	{
		for (int j = 1; j < utt; j++)
		{
			//cout<<"Digit: "<<i<<", Recording no: "<<j<<endl;
			for (int t = 0; t < ObjSeqSize1[i][j]; t++)
			{
				long double min = 0;
				int index = 0;
				for (int k = 0; k < 12; k++)
				{
					min += tokhuraWeight1[k] * (pow(alldigits1[i][j][t][k] - codebook1[0][k], 2));
				}
				long double tokhuradistance;
				for (int m = 1; m < 32; m++)
				{
					tokhuradistance = 0;
					for (int k = 0; k < 12; k++)
					{
						tokhuradistance += tokhuraWeight1[k] * (pow(alldigits1[i][j][t][k] - codebook1[m][k], 2));
					}
					if (tokhuradistance < min)
					{
						min = tokhuradistance;
						index = m;
					}
				}
				ObjSeq1[i][j][t] = index;
				//cout<<index<<" ";
			}
			//cout<<endl<<endl;
		}
		//cout<<endl<<endl;
	}
	fin.close();

}
void  CLRproj1::Training::solution1(vector<int> objseq1)
{
	int T = objseq1.size();

	//Working for Forward Procedure
	//Initialization of alpha1 matrix
	for (int i = 0; i < N; i++)
	{
		alpha1[0][i] = PI11[i] * B11[i][objseq1[0]];
	}


	//Induction for alpha1 matrix
	for (int t = 1; t < T; t++)
	{
		for (int j = 0; j < N; j++)
		{
			long double sum = 0;
			for (int i = 0; i < N; i++)
			{
				sum += (alpha1[t - 1][i] * A11[i][j]);
			}
			sum *= B11[j][objseq1[t]];
			alpha1[t][j] = sum;
		}
	}

	//Termination
	sol1forward1 = 0;
	for (int i = 0; i < N; i++) sol1forward1 += alpha1[T - 1][i];
	//Forward Procedure ends here

	//Working for Backward Procedure
	//Initialization step
	for (int i = 0; i < N; i++)
	{
		beta1[T - 1][i] = 1;
	}

	//Induction step
	for (int t = T - 2; t >= 0; t--)
	{
		for (int i = 0; i < N; i++)
		{
			long double sum = 0;
			for (int j = 0; j < N; j++)
			{
				sum += A11[i][j] * B11[j][objseq1[t + 1]] * beta1[t + 1][j];
			}
			beta1[t][i] = sum;
		}
	}
}
void  CLRproj1::Training::solution2(vector<int> objseq1)
{
	int T = objseq1.size();
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < N; i++)
		{
			gamma1[t][i] = alpha1[t][i] * beta1[t][i] / sol1forward1;
		}

	}
	//Initialization
	for (int i = 0; i < N; i++)
	{
		delta1[0][i] = PI11[i] * B11[i][objseq1[0]];
		psi1[0][i] = 0;
	}
	//Induction part or Recursion
	for (int t = 1; t < T; t++)
	{
		for (int j = 0; j < N; j++)
		{
			long double max = delta1[t - 1][0] * A11[0][j];
			int index = 0;
			for (int i = 1; i < N; i++)
			{
				if (max < delta1[t - 1][i] * A11[i][j])
				{
					max = delta1[t - 1][i] * A11[i][j];
					index = i;
				}
			}
			delta1[t][j] = max * B11[j][objseq1[t]];
			psi1[t][j] = index;
		}
	}

	//Termination
	long double perfo = delta1[T - 1][0];
	int qt = 0;
	for (int i = 1; i < N; i++)
	{
		if (perfo < delta1[T - 1][i])
		{
			perfo = delta1[T - 1][i];
			qt = i;
		}
	}
	performance1 = perfo;

	//finding state sequence;
	statesequence1[T - 1] = qt;
	for (int t = T - 2; t >= 0; t--)
	{
		statesequence1[t] = psi1[t + 1][statesequence1[t + 1]];
	}
	//for(int t=0; t<T; t++) fout<<statesequence1[t]+1<<" ";//cout<<statesequence1[t]+1<<" ";
	//fout<<"\n  P(objseq/model) : "<<sol1forward1<<endl;
	//cout<<endl;

}
void  CLRproj1::Training::solution3(vector<int> objseq1)
{
	int T = objseq1.size();
	long double ExpTranFromItoJ[N][N], ExpTranFromI[N];
	//sol31 matrix computation
	long double val;

	for (int t = 0; t < T - 1; t++)
	{
		long double div = 0;
		for (int i = 0; i < N; i++)
		{
			long double sum = 0;
			for (int j = 0; j < N; j++)
			{
				val = (alpha1[t][i] * A11[i][j] * B11[j][objseq1[t + 1]] * beta1[t + 1][j]);
				val /= sol1forward1;
				sol31[t][i][j] = val;
				sum += val;
			}
			//gamma1[t][i] = sum;
		}
	}

	long double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += alpha1[T - 1][i];
	}
	for (int i = 0; i < N; i++)
	{
		gamma1[T - 1][i] = alpha1[T - 1][i] / sum;
	}


	//Storing Expected no. of transitions from every state i;
	for (int i = 0; i < N; i++)
	{
		int t;
		long double sum = 0;
		for (t = 0; t < T - 1; t++)
		{
			sum += gamma1[t][i];
		}
		ExpTranFromI[i] = sum;
	}
	//Storing Expected no. of transitions from any state i to any state j
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long double sum = 0;
			for (int t = 0; t < T - 1; t++)
			{
				sum += sol31[t][i][j];
			}
			ExpTranFromItoJ[i][j] = sum;
		}
	}
	//Calculating pinew
	for (int i = 0; i < N; i++)
	{
		PI11[i] = gamma1[0][i];
	}
	//cout<<"Intermediate A matrix: \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A11[i][j] = ExpTranFromItoJ[i][j] / ExpTranFromI[i];
			//cout<<A11[i][j]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl;
	//cout<<"Intermediate B Matrix: \n";
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			long double val = 0;
			for (int t = 0; t < T; t++)
			{
				if (k == objseq1[t])
					val += gamma1[t][j];
			}
			val /= ExpTranFromI[j];
			B11[j][k] = val;
			//printf("%E  ",val);
		}
		//cout<<endl;

	}

}

void  CLRproj1::Training::AverageHMM(int i)
{
	long double sum = 0;
	ofstream fout1, fout2;
	fout1.open("finalA1.txt");
	//calculating A matrix Average;
	//cout<<"Final A matrix : "<<endl;
	for (int k = 0; k < N; k++)
	{
		for (int l = 0; l < N; l++)
		{
			sum = 0;
			for (int j = 1; j < utt; j++)
			{
				sum += a11[i][j][k][l];
			}
			finalA1[i][k][l] = sum / (utt-1);
			//cout<<finalA1[i][k][l]<<" ";
		}
		//cout<<endl;
	}
	//cout<<endl<<endl<<endl<<endl;
	fout1 << setprecision(9) << fixed;
	/*for(int i=0; i<10; i++)
	{
		//fout1<<"Final A Matrix for digit "<<i<<" :"<<endl;
		for(int k=0; k<N; k++)
		{
			long double sum = 0;
			for(int l=0; l<N; l++)
			{
				sum += finalA1[i][k][l];
				fout1<<finalA1[i][k][l]<<" ";
			}
			fout1<<endl;
		}
		fout1<<endl;
	}*/
	fout1.close();
	//calculating B matrix Average;
	for (int k = 0; k < N; k++)
	{
		for (int l = 0; l < M; l++)
		{
			sum = 0;
			for (int j = 1; j < utt; j++)
			{
				sum += b11[i][j][k][l];
			}
			finalB1[i][k][l] = sum / (utt-1);
		}
	}
	fout1.open("finalB1.txt");
	fout1 << setprecision(35) << fixed;
	/*for(int i=0; i<10; i++)
	{
		//fout1<<"Final B Matrix for digit "<<i<<" :"<<endl;
		for(int k=0; k<N; k++)
		{
			long double sum = 0;
			for(int l=0; l<M; l++)
			{
				sum += finalB1[i][k][l];
				fout1<<finalB1[i][k][l]<<" ";
			}
			fout1<<endl;
		}
		fout1<<endl;
	}*/
	fout1.close();
	//calculating B matrix Average;
	for (int k = 0; k < N; k++)
	{
		sum = 0;
		for (int j = 1; j < utt; j++)
		{
			sum += pi11[i][j][k];
		}
		finalPI1[i][k] = sum / (utt-1);
	}
	fout1.open("finalPI1.txt");
	fout1 << setprecision(9) << fixed;
	/*
	for(int i=0; i<10; i++)
	{
		for(int k=0; k<N; k++)
		{
			fout1<<finalPI1[i][k]<<" ";
		}
		fout1<<endl;
	}*/
	fout1.close();
}

void  CLRproj1::Training::BuildHMM()
{
	//Reading intial Model parameters A,B,PI;
	ifstream fin;
	string line;
	fin.open("initialA.txt");
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	int i = 0;
	long double data;
	while (getline(fin, line))
	{
		stringstream ss(line);
		for (int j = 0; j < N; j++)
		{
			ss >> data;
			A11[i][j] = data;
			inA1[i][j] = data;
			//cout<<A11[i][j]<<" ";
		}
		//cout<<endl;
		i++;
	}
	fin.close();
	cout << setprecision(30);
	fin.open("initialB.txt");
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	cout << endl;
	i = 0;
	while (getline(fin, line))
	{
		stringstream ss(line);
		for (int j = 0; j < M; j++)
		{
			ss >> data;
			B11[i][j] = data;
			inB1[i][j] = data;
			//cout<<B11[i][j]<<" ";
		}
		//cout<<endl;
		i++;
	}
	//cout<<endl;
	fin.close();
	fin.open("initialPI.txt");
	if (!fin)
	{
		cout << "coudn't open the file";
		exit(1);
	}
	while (getline(fin, line))
	{
		stringstream ss(line);
		for (int j = 0; j < N; j++)
		{
			ss >> data;
			PI11[j] = data;
			inPI1[j] = data;
		}
	}
	fin.close();


	//fout<<endl<<endl;;
	int iteration;
	vector<int> objseq1;
	int total = 1;

	while (total <= 3)
	{
		for (int i = 0; i < tot; i++)
		{
			if (total != 1)
			{
				cout << setprecision(9) << fixed;
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < N; k++)
					{
						A11[j][k] = finalA1[i][j][k];
						//cout<<A11[j][k]<<" ";
						inA1[j][k] = finalA1[i][j][k];
					}
					//cout<<endl;
				}
				//cout<<endl;
				cout << setprecision(35) << fixed;
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < M; k++)
					{
						B11[j][k] = finalB1[i][j][k];
						//cout<<B11[j][k]<<" ";
						inB1[j][k] = finalB1[i][j][k];
					}
					//cout<<endl;
				}
				//cout<<endl;
				cout << setprecision(9) << fixed;
				for (int j = 0; j < N; j++)
				{
					PI11[j] = finalPI1[i][j];
					//cout<<PI11[j]<<" ";
					inPI1[j] = finalPI1[i][j];
				}
				//cout<<endl<<endl<<endl<<endl<<endl;
			}

			for (int j = 1; j < utt; j++)
			{

				objseq1.clear();
				for (int t = 0; t < ObjSeqSize1[i][j]; t++)
				{
					objseq1.push_back(ObjSeq1[i][j][t]);
				}
				iteration = 20;

				while (iteration--)
				{
					solution1(objseq1);
					solution2(objseq1);
					solution3(objseq1);
				}

				long double threshold = powf(10, -30);
				for (int k = 0; k < N; k++)
				{
					int count = 0;
					long double max = 0;
					int index = 0;
					for (int l = 0; l < M; l++)
					{
						if (B11[k][l] > max)
						{
							max = B11[k][l];
							index = l;
						}

					}
					for (int l = 0; l < M; l++)
					{
						if (B11[k][l] < threshold)
						{
							B11[k][l] += threshold;
							count++;
						}

					}
					B11[k][index] = B11[k][index] - count * threshold;
				}
				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < N; l++)
					{
						a11[i][j][k][l] = A11[k][l];
						A11[k][l] = inA1[k][l];
					}
				}

				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < M; l++)
					{
						b11[i][j][k][l] = B11[k][l];
						B11[k][l] = inB1[k][l];
					}
				}
				for (int k = 0; k < N; k++)
				{
					pi11[i][j][k] = PI11[k];
					PI11[k] = inPI1[k];
				}
			}
			AverageHMM(i);
		}


		total++;
	}

	ofstream fout1;
	fout1.open("finalA1.txt");
	fout1 << setprecision(9) << fixed;
	for (int i = 0; i < tot; i++)
	{
		//fout1<<"Final A Matrix for digit "<<i<<" :"<<endl;
		for (int k = 0; k < N; k++)
		{
			long double sum = 0;
			for (int l = 0; l < N; l++)
			{
				sum += finalA1[i][k][l];
				fout1 << finalA1[i][k][l] << " ";
			}
			//fout1<<sum;
			fout1 << endl;
		}
		fout1 << endl;
	}
	fout1.close();
	fout1.open("finalB1.txt");
	fout1 << setprecision(35) << fixed;
	for (int i = 0; i < tot; i++)
	{
		//fout1<<"Final B Matrix for digit "<<i<<" :"<<endl;
		for (int k = 0; k < N; k++)
		{
			long double sum = 0;
			for (int l = 0; l < M; l++)
			{
				sum += finalB1[i][k][l];
				fout1 << finalB1[i][k][l] << " ";
			}
			//fout1<<sum;
			fout1 << endl;
		}
		fout1 << endl;
	}
	fout1.close();
	fout1.open("finalPI1.txt");
	fout1 << setprecision(9) << fixed;
	for (int i = 0; i < tot; i++)
	{
		for (int k = 0; k < N; k++)
		{
			fout1 << finalPI1[i][k] << " ";
		}
		fout1 << endl;
	}
	fout1.close();


}


void CLRproj1::Training::start(string cb,int iteration) {
	utt = iteration + 1;
	finalcb1 = cb;
	//fout.open("Everything.txt");
	cout << "takeinputstart" << endl;
	takeInput();
	cout << "takeinputdone" << endl;
	ObjSeqGeneration();


	BuildHMM();

	//fout.close();
}


void CLRproj1::Training::updateModel(string path, int index, int count) {
	cout << "index is : " << index << " and count is : " << count << endl;
	long double finalA1[N][N], finalB1[N][M];
	long double finalA[10][N][N], finalB[10][N][M];
	ifstream fin;
	string line;
	fin.open(path + "finalA.txt");
	if (!fin) cout << "file not found" << endl;
	cout << "file opened" << endl;
	int i = 0,j=0;
	long double data;
	cout << setprecision(9);
	while (getline(fin, line))
	{
		if (line.empty())
		{
			i++, j = 0;
			//cout << endl;
			continue;
		}
		stringstream ss(line);
		for (int k = 0; k < N; k++)
		{
			ss >> data;
			//cout << data<<" ";
			finalA[i][j][k] = data;
		}
		//cout << endl;
		j++;
	}
	fin.close();
	fin.open(path + "finalB.txt");
	i = 0, j = 0;
	cout << endl << endl;
	
	while (getline(fin, line))
	{
		if (line.empty())
		{
			i++, j = 0;
			//cout << endl;
			continue;
		}
		stringstream ss(line);
		for (int k = 0; k < M; k++)
		{
			ss >> data;
			//cout << data<<" ";
			finalB[i][j][k] = data;
		}
		//cout << endl;
		j++;
	}
	fin.close();

	//cout << setprecision(9);
	fin.open("finalA1.txt");
	i = 0;
	while (getline(fin, line)) {
		if (!line.empty()) {
			stringstream ss(line);
			for (int j = 0; j < N; j++) {
				ss >> data;
				finalA1[i][j] = data;
				//cout << data << " ";
			}
			//cout << endl;
			i++;
		}
	}
	cout << endl << endl;
	fin.close();
	//cout << setprecision(35);
	fin.open("finalB1.txt");
	i = 0;
	while (getline(fin, line)) {
		if (!line.empty()) {
			stringstream ss(line);
			for (int j = 0; j < M; j++) {
				ss >> data;
				finalB1[i][j] = data;
				//cout << data << " ";

			}
			//cout << endl;
			i++;
		}
	}
	fin.close();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			finalA[index][i][j] = finalA1[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			finalB[index][i][j] = finalB1[i][j];
		}
	}
	ofstream fout;
	fout.open(path + "finalA.txt");
	fout << setprecision(9)<<fixed;

	//cout << endl << endl << endl;
	//cout << "updatedAMatrix" << endl;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				fout << finalA[i][j][k] << " ";
				//cout << finalA[i][j][k]<<" " ;
			}
			//cout << endl;
			fout << endl;
		}
		//cout << endl;
		fout << endl;
	}
	fout.close();
	fout.open(path + "finalB.txt");
	fout << setprecision(35)<<fixed;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				fout << finalB[i][j][k] << " ";
			}
			fout << endl;
		}
		fout << endl;
	}
	fout.close();

}