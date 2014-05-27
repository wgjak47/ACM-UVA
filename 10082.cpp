#include<cstdio>
#include<cstring>
main()
{
	char input[100];
	char output[1000];
	output['W']='Q';
	output['S']='A';
	output['X']='Z';
	output['E']='W';
	output['D']='S';
	output['C']='X';
	output['R']='E';
	output['F']='D';
	output['V']='C';
	output['T']='R';
	output['G']='F';
	output['B']='V';
	output['Y']='T';
	output['H']='G';
	output['N']='B';
	output['U']='Y';
	output['J']='H';
	output['M']='N';
	output['I']='U';
	output['K']='J';
	output[',']='M';
	output['O']='I';
	output['L']='K';
	output['.']=',';
	output['P']='O';
	output[';']='L';
	output['/']='.';
	output['[']='P';
	output[' ']=' ';
	output['1']='`';
	output['2']='1';
	output['3']='2';
	output['4']='3';
	output['5']='4';
	output['6']='5';
	output['7']='6';
	output['8']='7';
	output['9']='8';
	output['0']='9';
	output['-']='0';
	output['=']='-';
	output['/']='.';
	output[']']='[';
	output['\'']=';';
	output['\\']=']';
	while (gets(input)!=NULL)
	{
		int l=strlen(input);
		for (int i=0;i<l;i++)
			putchar(output[input[i]]);
		putchar('\n');
	}
	return 0;	
}
