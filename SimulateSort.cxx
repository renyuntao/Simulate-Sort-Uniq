#include<iostream>
#include<unistd.h>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>
using std::endl;
using std::cout;


/*
 * Case sensitive Quick Sort
 *
 */
void quicksort(std::vector<std::string> &v_str,int low,int high)
{
	if(low < high)
	{
		int i = low+1;
		int j = high;
		std::string pivot = v_str[low];

		while(1)
		{
			while(i < high && v_str[i] <= pivot) ++i;
			while(j > low && v_str[j] > pivot) --j;

			if(i < j)
			{
				std::string tmp = v_str[i];
				v_str[i] = v_str[j];
				v_str[j] = tmp;
			}
			else
				break;
		}
		
		v_str[low] = v_str[j];
		v_str[j] = pivot;

		if(low < j)
			quicksort(v_str,low,j-1);
		if(i < high)
			quicksort(v_str,i,high);
	}
}

/*
 * Used for case insensitive Quick Sort
 *
 * Whether str1 <= str2 ?
 */
 
bool compare(std::string str1,std::string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();

	int minLen = len1 < len2 ? len1 : len2;

	for(int i = 0; i < minLen; ++i)
	{
		// str1[i] and str2[i] is alphabet
		if(isalpha(str1[i]) && isalpha(str2[i]))
		{
			// str1[i] and str2[i] have difference case
			if(isupper(str1[i]) ^ isupper(str2[i]))
			{
				int diff = abs(str1[i] - str2[i]);
				
				if(diff == 32)
					continue;
				else
				{
					int to_upper = str1[i] > 'a' ? str1[i]-32 : str2[i]-32;

					// str1 is upper 
					if(str1[i] <= 'Z')    
					{
						if(str1[i] < to_upper)
							return true;
						else
							return false;
					}
					// str2 is upper
					else
					{
						if(to_upper < str2[i])
							return true;
						else
							return false;
					}
				}
			}
			// str1[i] and str2[i] have same case
			else
			{
				if(str1[i] == str2[i])
					continue;
				if(str1[i] < str2[i])
					return true;
				else
					return false;
			}
		}
		// str1[i] and str2[i] is not both alphabet
		else
		{
			if(str1[i] == str2[i])
				continue;
			else if(str1[i] < str2[i])
				return true;
			else
				return false;
		}
	}

	if(len1 <= len2)
		return true;
	else
		return false;
}

/*
 * Case insensitive Quick Sort
 *
 */
void ignore_case_quicksort(std::vector<std::string> &v_str,int low,int high)
{
	if(low < high)
	{
		int i = low+1;
		int j = high;
		std::string pivot = v_str[low];

		while(1)
		{
			while(i < high && compare(v_str[i],pivot)) ++i;
			while(j > low && !compare(v_str[j],pivot)) --j;

			if(i < j)
			{
				std::string tmp = v_str[i];
				v_str[i] = v_str[j];
				v_str[j] = tmp;
			}
			else
				break;
		}
		
		v_str[low] = v_str[j];
		v_str[j] = pivot;

		if(low < j)
			ignore_case_quicksort(v_str,low,j-1);
		if(i < high)
			ignore_case_quicksort(v_str,i,high);
	}
}

int main(int argc,char **argv)
{

	extern char *optarg;
	extern int optind;
	char *output_file;
	char default_output_file[] = "sorted.txt";

	int iflag = 0, hflag = 0, oflag = 0, uflag = 0;
	int c;
	while((c=getopt(argc,argv,"iho:")) != -1)
	{
		switch(c)
		{
			case 'i':
				iflag = 1;
				break;
			case 'h':
				hflag = 1;
				break;
			case 'o':
				oflag = 1;
				output_file = optarg;
				break;
			case '?':
				cout<<"Parameter error\n";
				return 1;
		}
	}

	// Help flag is set
	if(hflag)
	{
		cout<<"Description:\n";
		cout<<"Simulate the linux command `sort`.\n";
		cout<<"Usage:\n";
		cout<<argv[0]<<" [-ih] [-o output_file] input_file\n";
		cout<<"Parameter:\n";
		cout<<"-i: Case insensitive sorting.Default is case sensitive sorting.\n";
		cout<<"-o: Specify the output file.Default is sorted.txt.\n";
		cout<<"-h: See help\n";
		return 0;
	}

	// Syntax error
	if(optind == argc)
	{
		cout<<"Syntax error\n";
		cout<<"Usage:\n";
		cout<<argv[0]<<" [-ih] [-o output_file] input_file\n";
		cout<<"Parameter:\n";
		cout<<"-i: Case insensitive sorting.Default is case sensitive sorting.\n";
		cout<<"-o: Specify the output file.Default is sorted.txt.\n";
		cout<<"-h: See help\n";
		return 0;
	}


	std::vector<std::string> v_str;
	std::string line;
	std::ifstream fin;
	fin.open(argv[optind]);
	if(fin)
	{
		while(getline(fin,line))
			v_str.push_back(line);
	}
	else
	{
		cout<<"open error.\n";
		return 1;
	}
	fin.close();

	int len = v_str.size();

	// iflag is set
	if(iflag)
	{
		ignore_case_quicksort(v_str,0,len-1);
	}
	// iflag is not set
	else
	{
		quicksort(v_str,0,len-1);
	}

	// Write to file
	std::ofstream fout;
	// oflag is set
	if(oflag)
		fout.open(output_file);
	// oflag is not set
	else
		fout.open(default_output_file);
	for(int k = 0; k < len; ++k)
		fout<<v_str[k]<<"\n";
	
	fout.close();

	return 0;

}
