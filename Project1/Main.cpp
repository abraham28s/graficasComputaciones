/*********************************************************
Materia: Graficas computacionales
Fecha: 20/08/2017
Autor: Abraham Soto A01370699
*********************************************************/
#include <iostream>
#include "InputFile.h"
int main(int argc, char* argv[]) {
	std::string filename = "Prueba.txt"; InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();
	return 0;
}







/*********************************************************
Materia: Graficas computacionales
Fecha: 13/08/2017
Autor: Abraham Soto A01370699
*********************************************************/
/*
#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//OpenGL viejo, no se puede usar despues.
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f,-1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);


	glEnd();

	glutSwapBuffers();
}

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

int main(int argc, char* argv[]) {

	//Inicializar freeglut
	//SE encarga de crear una ventanta en donde podemos dibujar.

	glutInit(&argc, argv);

	//Iniciar el contexto de OpenGL. El contexto se refiere a las capacidades que va a tener nuestra app grafica.
	//En este caso estamos trabajando con el pipelineclasico
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	//Freeglut nos permite configurar eventos que ocurren en la ventana. un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso, simplemente dejamos de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//Configuramos el frame buffer. En este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad y un segundo buffer para renderear
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//iniciar las dimensiones de la ventana en pixeles
	glutInitWindowSize(400, 400);
	//Se crea como tal la ventana con un titulo dado.
	glutCreateWindow("Hello World GL");
	//Asociamos una funcion de render, esta funcion se mandara a llamara para dibujar un frame.
	glutDisplayFunc(GameLoop);

	//Inicializamos GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra tarjeta de video. 
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color del frame buffer.
	glClearColor(1.0f, 1.0f, 0.5F, 1.0f);

	//iniciar la aplicacion. El main se pausara en esta linea hasta que se cierre la ventana.
	glutMainLoop();

	/*
	//Employee 
	Employee Javi(1, "Javier", "Esponda", 10);
	std::cout << Javi.Print() << "\n";


	////////Circle
	Circle circulo(2.0, "green");
	std::cout << circulo.GetRadius() << std::endl;
	///////

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
}*/