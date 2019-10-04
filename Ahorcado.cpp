#include <iostream>
#include <cstring>

using namespace std;



void busqueda(char *palabra, char *letra, char* palabravacia) {
	char* p1 = palabra;
	char* p2 = letra;
	char* p3 = palabravacia;
	int cont = 0;
	for (char* p = p1 ; *p != '\0' ; p++, cont++) {
		if (*p == *p2) {
			*(p3+cont)=*p2;
		}
	}
}

void imprimir(char* ini, char* final) {
	for (char* p = ini; p != final; p++) {
		cout << *p;
	}
}

int sizechar( char* palabra) {
	int cont = 0;
	for (char* p = palabra; *p != '\0'; p++) {
		cont++;
	}
	return cont;
}

int main() {

	char palabra [100];
	int cont = 0;
	int i = 0;
	int continuar = 1;

	cout << "Ingrese palabra para el ahorcado: "; cin >> palabra; cout << endl;
	
	int const size = sizechar(palabra);

	char* palabra2 = new char[size];
	char* palabravacia = new char[size];

	for (char* p = palabra; *p != '\0'; p++) {
		*(palabra2+i) = *p;
		i++;
	}

	while (continuar) {

		char letra[1];

		cout << "Ingrese letra :"; cin >> letra;

		busqueda(palabra, letra, palabravacia);

		imprimir(palabravacia, palabravacia + size);
		
		if (strcmp(palabra2, palabravacia)==0) {
			continuar = 0;
		};

		cout << endl;

		

	//	for (char* p = &palabra; palabra != '\0'; p++, i++) {
	//		if(*p==*(palabravacia + i)){
	//			cont++;
	//		}
	//		if (cont == size) {
	//			continuar = 0;
	//		}
	//	}
	//	cont = 0;
	}

	return 0;
}