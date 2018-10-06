# Longest-common-Subsequence
algorithm，bioinfoematics   
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
# about the Longest-common-Subsequence algorithm
##  Pseudocode
function LCSLength(X[1..m], Y[1..n])  
    C = array(0..m, 0..n)  
    for i := 0..m  
       C[i,0] = 0  
    for j := 0..n  
       C[0,j] = 0  
    for i := 1..m  
        for j := 1..n  
            if X[i] = Y[j]  
                C[i,j] := C[i-1,j-1] + 1  
            else  
                C[i,j] := max(C[i,j-1], C[i-1,j])  
    return C[m,n]  
 # get common Subsequence and source
 ##  Pseudocode
 goldenstr = ‘’  
 function backtrack(C[0..m,0..n], X[1..m], Y[1..n], i, j)  
    if i = 0 or j = 0  
        return ""  
    if  X[i] = Y[j]  
        goldenstr = X[i] + goldenstr；  
        cout<<i<<j<<X[i];  
        return backtrack(C, X, Y, i-1, j-1)  
    if C[i,j-1] > C[i-1,j]  
        return backtrack(C, X, Y, i, j-1)  
    return backtrack(C, X, Y, i-1, j)  
