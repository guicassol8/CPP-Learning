#include <iostream>
#define DEBUG

using namespace std;
class Contador
{
private:
	int valor;
public:
	static const int DEFAULT = 0;
	Contador (int v = 0){
		valor = v ;
		#ifdef DEBUG
		cout<<"+ Contador("<< valor <<") criado..." <<endl;
		#endif
	}
    ~Contador()
	{
		#ifdef DEBUG
		cout<<"- Contador("<< valor <<") destruído..." <<endl;
		#endif
	}
	int getValor()
	{
		return valor;
	}
	void incrementa ()
	{
		++valor;
	}
	void defineValor (int v)
	{
		valor = v;
	}  
	void zera()
	{
		valor = 0;
	}
};
Contador c7(10000);

int main ()
{
	Contador c1,c2(10);
	Contador c3();//Isso eh um prototipo apenas
	Contador *c4;//Isso eh um ponteiro para um objeto
	Contador *c5 = new Contador(100);
	cout<<"Valor c1: "<<c1.getValor()<<endl;
	cout<<"Valor c2: "<<c2.getValor()<<endl;
	cout<<"Valor c5: "<<c5->getValor()<<endl;
	cout<<"Contador::DEFAULT ="<<Contador::DEFAULT<<endl;
	delete c5;
	if (true)
	{
		Contador c6(1000);
	}
	return 0;
}