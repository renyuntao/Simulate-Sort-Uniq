#include<iostream>
#include<vector>
#include<unistd.h>
#include<string>
#include<fstream>
using std::cout;
using std::endl;

/*
 * Show usage information.
 *
 */
void showUsage()
{
	cout<<"Usage:\n";
	cout<<"uniq [-h] [-o output_file] input_file\n";
	cout<<"Parameter:\n";
	cout<<"-o: Specify the output file.\n";
	cout<<"-h: See help.\n";
}

/*
 * Simulate linux command `uniq`.
 *
 */
void uniq(char *output_file,char *input_file)
{
	std::string tmp,prev;

	std::ofstream fout;
	fout.open(output_file);

	std::ifstream fin;
	fin.open(input_file);

	prev = "";
	while(getline(fin,tmp))
	{
		if(tmp == prev)
			continue;
		else
		{
			fout<<tmp<<"\n";
			prev = tmp;
		}
	}

	// close the file
	fout.close();
	fin.close();
}

int main(int argc,char **argv)
{
	int oflag = 0, hflag = 0;
	char *output_file;
	char default_output_file[] = "uniq.txt";
	int c;
	
	extern char *optarg;
	extern int optind;
	while((c = getopt(argc,argv,"ho:")) != -1)
	{
		switch(c)
		{
			case 'h':
				hflag = 1;
				break;
			case 'o':
				oflag = 1;
				output_file = optarg;
				break;
			case '?':
				cout<<"Syntax error.\n";
				showUsage();
				return 1;
		}
	}

	// hflag is set
	if(hflag)
	{
		cout<<"Description:\n";
		cout<<"Simulate linux command `uniq`.\n";
		showUsage();

		return 0;
	}

	// no input file
	if(optind == argc)
	{
		cout<<"Syntax error.\n";
		showUsage();

		return 1;
	}

	// oflag is set
	if(oflag)
		uniq(output_file,argv[optind]);
	else
		uniq(default_output_file,argv[optind]);

	return 0;

}
