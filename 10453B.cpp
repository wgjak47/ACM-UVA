1 #include <stdio.h> 
2 #include <string.h> 
3 int p[1001][1001]; 
4 int main() 
5 { 
6 char str[3001]; 
7 int i,j,len; 
8 while(gets(str)!=0) 
9 { 
10 memset(p,0,sizeof(p)); 
11 len = strlen(str); 
12 for(i = 1; i <= len; i ++) 
13 { 
14 for(j = 1; j <= len; j ++) 
15 { 
16 if(str[i-1] == str[len-j]) 
17 p[i][j] = p[i-1][j-1]+1; 
18 else if(str[i-1] != str[len-j]) 
19 { 
20 if(p[i-1][j] < p[i][j-1]) 
21 p[i][j] = p[i][j-1]; 
22 else 
23 p[i][j] = p[i-1][j]; 
24 } 
25 } 
26 } 
27 printf("%d ",len-p[len][len]); 
28 for(i = len,j = len;;) 
29 { 
30 if(str[i-1] == str[len-j]&&i >= 1&&j >=1) 
31 { 
32 printf("%c",str[i-1]); 
33 i --;j --; 
34 } 
35 else if(p[i][j] == p[i][j-1]&&j >= 1) 
36 { 
37 printf("%c",str[len-j]); 
38 j --; 
39 } 
40 else if(p[i][j] == p[i-1][j]&&i >= 1) 
41 { 
42 printf("%c",str[i-1]); 
43 i --; 
44 } 
45 else if(i == 0&&j == 0) 
46 break; 
47 } 
48 printf("\n"); 
49 } 
50 return 0; 
51 }