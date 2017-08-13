#include<iostream>

int PerimetroRectangulo(int base, int altura);
float AreaTriangulo(float base, float altura);
int Mayor(int numero1, int numero2, int numero3);
int Menor(int numero1, int numero2, int numero3);
void FilaEstrellas(int n);
void MatrizEstrellas(int n);
void PiramideEstrellas(int n);
void FlechaEstrellas(int n);
void Fibonacci(int n);
bool EsPrimo(int numero);

int main() {
	int p = PerimetroRectangulo(5, 3);
	std::cout << p << "\n";

	float a = AreaTriangulo(5.0f, 3.0f);
	std::cout << a << "\n";

	int mayor = Mayor(5, 9, 1);
	std::cout << mayor << "\n";

	int menor = Menor(5, 9, 1);
	std::cout << menor << "\n";

	FilaEstrellas(5);
	std::cout << "\n";

	MatrizEstrellas(4);
	std::cout << "\n";

	PiramideEstrellas(6);
	std::cout << "\n";

	FlechaEstrellas(3);
	std::cout << "\n";

	Fibonacci(9);
	std::cout << "\n";

	std::cout << EsPrimo(79) << " " << EsPrimo(52);
	std::cin.get();
	return 0;
}

int PerimetroRectangulo(int base, int altura) {
	return (base*2)+(altura*2);
}

float AreaTriangulo(float base, float altura) {
	return (base*altura) / 2;
}

int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 >= numero2 && numero1 >= numero3){
		return numero1;
	}else if (numero2 >= numero1 && numero2 >= numero3){
		return numero2;
	}
	else {
		return numero3;
	}
}

int Menor(int numero1, int numero2, int numero3) {
	if (numero1 <= numero2 && numero1 <= numero3) {
		return numero1;
	}
	else if (numero2 <= numero1 && numero2 <= numero3) {
		return numero2;
	}
	else {
		return numero3;
	}
}

void FilaEstrellas(int n) {
	for (int i = 0; i < n; i++)
	{
		std::cout << "*";
	}
	std::cout << "\n";
}

void MatrizEstrellas(int n) {
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void PiramideEstrellas(int n) {
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < j+1; i++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void FlechaEstrellas(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			std::cout << "*";
			
		}
		std::cout << "\n";
	}
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++) {
			std::cout << "*";
			
		}
		std::cout << "\n";
	}

}

void Fibonacci(int n) {
	int a = 1;
	int b = 1;
	int c = 0;
	for (int i = 0; i < n; i++) {
		std::cout << a << " ";
		c = a + b;
		a = b;
		b = c;
	}
}

bool EsPrimo(int numero) { 
	for (int i = 2; i < numero; i++) {
		if (numero%i==0) {
			return false;
		}
	}
	return true;
}