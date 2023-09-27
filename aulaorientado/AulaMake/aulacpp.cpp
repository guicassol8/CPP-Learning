#include <iostream>

using namespace std;

class Base {
private:
	int info;
public:
	Base (int i = 0) { 
		info = i;
		cout<<"Base("<<info<<") criado..."<<endl; 
	}
	~Base () { cout<<"Base destruído..."<<endl; }
	int obtemInfo() {return info;}
	void defineInfo(int i) {info = i;}
};

void funcao(Base &obj){
	cout<<"funcao>obj.obtemInfo() = "<<obj.obtemInfo()<<endl;
	int i = obj.obtemInfo();
	++i;
	obj.defineInfo(i);
	cout<<"funcao>obj.obtemInfo() = "<<obj.obtemInfo()<<endl;
}

int main (){
	Base o(10);
	cout<<"main>o.obtemInfo() = "<<o.obtemInfo()<<endl;
	funcao(o);
	cout<<"main>o.obtemInfo() = "<<o.obtemInfo()<<endl;
	return 0;
}