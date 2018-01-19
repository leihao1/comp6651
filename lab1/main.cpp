#include <iostream>
#include<fstream>

using namespace std;

int main(int arg,char* argv[]){
	cout<<"Number of arguments: "<<arg<<endl;
	for(int i=0;i<arg;++i){
		cout<<"Argument "<<i<<" is "<<argv[i]<<endl;
	}

	ifstream inf(argv[1]);
	if (!inf){
		cout<<"Input File Missing: please enter an input file\n";
		return -1;
	}

	ofstream outf(argv[2]);
	if (!outf){
		cout<<"Output File Missing: please enter an output file\n";
		return -1;
	}

	int N=0;//number of dataset
	inf>>N;
	if(N==0){//empty input file
		outf<<"Empty Input File: please check your input file\n";
		return -1;
		}

	for (int i=0;i<N;++i){
		int M=0;//number of elements in each dataset
		inf>>M;

		if(M==0){
			outf<<"EMPTY\n";
		}else{
			int max;
			inf>>max;//assume the first elements is the maximum element
			int count=1;//how many times the maximum element appears
			int next;//next element

			for(int i=0;i<M-1;i++){
				inf>>next;
				if(next==max){
					++count;
				}
				if(next>max){
					max=next;
					count=1;//reset count to 1
				}
			}
			outf<<max<<" "<<count<<endl;
		}
	}
	cout<<"Finished: please check your output file to see the results\n";
	return 0;
}
