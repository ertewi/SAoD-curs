//variant 51 1 2 3 1 3
// 1B base
// 2C year and author | K (key) - year 
// 3S direct merge sort
// 1D AVL-tree
// 3E Fano code

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

struct record
{
	char author[12];
	char title[32];
	char publisher[16];
	short int year;
	short int num_of_page;	
};

void swap(int *a, int *b) 
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int j;
	int page = 1;
	int tt_index[4000];
	for(j = 0; j < 4000; j++) tt_index[j] = j;
	char ch;
	FILE *fp;
	fp=fopen("testBase1.dat", "rb");
	record tt[4000]={0};
	int i=0,sum=0;
	i=fread((record *)tt, sizeof(record), 4000, fp);
	i = 0;
	while(i < 4000) {
		cout<<"page: "<<page<<endl;
		for(i = page * 20 - 20; i < 20 * page; i++)
			cout<<i+1<<".\t"<<tt[tt_index[i]].author<<"\t"<<tt[tt_index[i]].title<<"\t"<<tt[tt_index[i]].publisher<<"\t\t"<<tt[tt_index[i]].year<<"\t"<<tt[tt_index[i]].num_of_page<<endl;
		cout<<"\n\r"<<"<"<<" prev"<<"\t"<<">"<<" next"<<"\t"<<"?"<<" own page"<<"\t"<<"@"<<" exit"<<"\t"<<endl;
		cin>>ch;
		
		switch(ch){
			case '<':
				if(page > 1) page--;
				break;
				
			case '>':
				if(page < 4000 / 20) page++;
				break;
				
			case '?':
				cin>>page;
				if(page < 1) page = 1;
				if(page > 4000 / 20) page = 4000 / 20;
				break;
		}
		
		system("cls");
		
		if(ch == '@') break;
	}
	
	return 0;
}
