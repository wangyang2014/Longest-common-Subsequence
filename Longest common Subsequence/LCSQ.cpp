#include"LCSQ.h"

bool readdata(char* filepath,string &sequence)
{
	FILE *ftp = fopen(filepath,"rb");
	
	if (NULL == ftp)
	{
		cout<<"open file failed"<<endl;
		return false;
	}
	else
	{
		//fseek(ftp,0,SEEK_SET);
		fseek(ftp,0,SEEK_END);
		int size = ftell(ftp);
		fseek(ftp,0,SEEK_SET);

		char *data = new char[size + 1];
		if(NULL == data)
		{
			return false;
			cout<<"memery full ,please close something computering software"<<endl;
		}
		else
		{
			memset(data,0,size+1);
			fread(data,1,size,ftp);
			//memcpy(data,ftp,size);
		}
		printf("%s\n",data);
		sequence = string(data);

		delete[] data;
	}
	fclose(ftp);
	ftp = NULL;
	return true;
}

sequenceCompart setinformation(string sequence)
{
	int position = sequence.find("\n");
	sequenceCompart  seqCom ;
	seqCom.SeqA = sequence.substr(0,position-1);
	seqCom.SeqB = sequence.substr(position + 1,sequence.size());
	return seqCom;
}

void printfdata(int** score,int Row,int Column)
{
	for(int i=0;i<Row;i++)
	{
		for(int j = 0;j<Column;j++)
		{
			cout<<score[i][j]<<"  ";
		}
		cout << endl;
	}
}
int** initialization(sequenceCompart information)
{
	int Row = information.SeqA.size() + 1;
	int Column = information.SeqB.size() + 1;
	int** score = new int* [Row+1];

	for(int i=0;i<Row;i++)
	{
		score[i] = new int[Column];
		memset(score[i],0,sizeof(int)*(Column));
	} 
	//printfdata(score,Row,Column);
	return score;
}

int equalstr(char a,char b)
{
	if(a == b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void getmatrix(sequenceCompart information,int ** score)
{
	int Row = information.SeqA.size() + 1;
	int Column = information.SeqB.size() + 1;

	for(int i=1;i<Row;i++)
	{
		for(int j = 1;j<Column;j++)
		{
			if(1 == equalstr(information.SeqA[i-1],information.SeqB[j-1]))
			{
				score[i][j] = score[i-1][j-1] + 1;
			}
			else
			{
				score[i][j] = max(score[i-1][j],score[i][j-1]);
			}
		}
	}
	printfdata(score,Row,Column);
	
}

void backtrack(sequenceCompart &information, int** score, int i, int j)
{
	if(0 == i || 0 == j)
	{
		return ;
	}

	if (1 == equalstr(information.SeqA[i-1],information.SeqB[j-1]))
	{
		information.SubSeq = information.SeqA[i-1] + information.SubSeq;
		cout<<i<<j<<information.SeqA[i-1]<<endl;
		backtrack(information,score,i-1,j-1);
		return ;
	}
	if(score[i-1][j] >= score[i][j-1])
	{
		backtrack(information,score,i-1,j);
		return ;
	}
	else
	{
		backtrack(information,score,i,j-1);
		return ;
	}
}

void getSubSequence(sequenceCompart information)
{
	information.SubSeq = "";
	int** score = initialization(information);
	getmatrix(information,score);
	backtrack(information,score,information.SeqA.size(),information.SeqB.size());
	cout<<information.SubSeq<<endl;
}
