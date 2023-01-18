#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
#define MinBD 1900
#define MaxMark 100

char range(unsigned int R){
	char tmp=0;
	if(R<41) tmp='F';
	else if(R>=41 && R<=51) tmp='f';
	else if(R>51 && R<61) tmp='D';
	else if(R>61 && R<71) tmp='E';
	else if(R>71 && R<81) tmp='C';
	else if(R>81 && R<91) tmp='B';
	else tmp='A';
	return tmp;
}

struct person{
	string fname;
	string sname;
	string fthname;
	unsigned int birth_year;
	unsigned int mark;
	person(){
		fname="John";
		sname="Doe";
		fthname="Simple";
		birth_year=MinBD;
		mark=0;
	}
	person(string FName, string SName, string FTHName, unsigned int BD, unsigned int M){
		fname=FName;
		sname=SName;
		fthname=FTHName;
		SetBD(BD);
		SetMark(M);
	}
	void SetBD(unsigned int BD){
		if(BD<MinBD) birth_year=MinBD;
		else birth_year=BD;
	}
	void SetMark(unsigned int M){
		if(M>MaxMark) mark=MaxMark;
		else mark=M;
	}
	
};
istream& operator>>(istream& inp,person &P){
	cout<<"First Name= ";inp>>P.fname;
	cout<<"Second Name= ";inp>>P.sname;
	cout<<"Father Name= ";inp>>P.fthname;
	unsigned int BD;cout<<"Birth Year= ";inp>>BD; P.SetBD(BD);
	unsigned int M;cout<<"Mark= ";inp>>M; P.SetMark(M);
	return inp;
}
ostream& operator<<(ostream& out,person &P){
	P.fname.resize(15);P.sname.resize(15);P.fthname.resize(15);
    out<<P.fname<<P.sname<<P.fthname<<" "<<P.birth_year<<" "<<P.mark;
    if(P.mark>50) out<<"  chaabareb"; 
    else out<<"  chaiwrebi";
    return out; 
}
bool operator >(person P1,person P2){
	if(P1.mark>P2.mark) return true;
	else return false;
}
bool operator <(person P1,person P2){
	if(P1.mark<P2.mark) return true;
	else return false;
}

//==================================
struct MyPersonVector{
	unsigned int N;
	person *V;
	MyPersonVector(){
		N=1;
		V=new person[N];
	}
	MyPersonVector(unsigned int n){
		N=n;
		V=new person[N];
	}
	void CIN(){
		for(int i=0;i<N;i++){
			cout<<"["<<i<<"]= ";cin>>V[i]; 
		}
	}
	void COUT(){
		for(int i=0;i<N;i++){
			cout<<"["<<i<<"]= "<<V[i]<<endl;
		}
	}
	void SortUP(){
		for(int i=0;i<N;i++){
		   for(int j=0;j<N;j++){
		   	if(V[i]>V[j]) swap(V[i],V[j]);
		    }	
		}
	}
	void SortDown(){
		for(int i=0;i<N;i++){
		   for(int j=0;j<N;j++){
		   	if(V[i]<V[j]) swap(V[i],V[j]);
		    }	
		}
	}
};

int main(int argc, char** argv) {
	MyPersonVector BSU_I_KURSI=MyPersonVector(3);
	BSU_I_KURSI.CIN();
	cout<<endl;
	BSU_I_KURSI.SortUP();
	BSU_I_KURSI.COUT();
	return 0;
}
