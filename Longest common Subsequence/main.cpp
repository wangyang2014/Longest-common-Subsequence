#include"LCSQ.h"
/*
author wangyang 
address School of computer science ,xidian university 
time 2018/10/5
email wangyang_cs2014@163.com
this project is solve the problem that about longest common subsequence (LCS) problem.
References "https://en.wikipedia.org/wiki/Longest_common_subsequence_problem".
if you have any question ,plaese write letter give me for email.
this is my github address. git@github.com:wangyang2014/Longest-common-Subsequence.git .
welcome you visit;
*/
void main()
{
	string data;
	readdata("txtdate.txt",data);
	sequenceCompart  seqCom = setinformation(data);
	getSubSequence(seqCom);
	getchar();
}