#include <iostream>
#include <cstring>

using namespace std;

int sizechar(char* palabra) {
	int cont = 0;
	for (char* p = palabra; *p != '\0'; p++) {
		cont++;
	}
	return cont;
}

void errorcont(char* word, char* letra, int* error, int size) {
	int aux = 0;
	for (char* p = word; p < word + size; p++) {
		if (*p != *letra) {
			aux++;
		}
	}
	int aux2 = aux / size;

	*error += aux2;
}

void busqueda(char *palabra, char *letra, char* palabravacia) {
	char* p1 = palabra;
	char* p2 = letra;
	char* p3 = palabravacia;
	int cont = 0;
	for (char* p = p1 ; *p != '\0' ; p++, cont++) {
		if (*p == *p2) {
			*(p3 + cont) = *p2;
		}
	}
}

void imprimir(char* ini, char* final) {
	for (char* p = ini; p != final; p++) {
		cout << *p;
	}
}

void comparar(int size, int* p, char* word1, char* word2) {
	int aux = 0;
	int i = 0;
	char* p2 = word2;
	for (char* l = word1; l < word1 + size; l++ ) {
		if (*l == *(p2 + aux)) {
			i++;
		}
		aux++;
	}
	if (i == size) {
		*p = 0;
	}

}

void imppalabra(char* palabra) {
	for (char* p = palabra; *p !='\0'; p++) {
		cout << *p;
	}
}

int main() {

	char palabra [100];
	int cont = 0;
	int error = 0;
	int continuar = 1;

	cout << "Ingrese palabra para el ahorcado: "; cin >> palabra; cout << endl;

	
	system("cls");

	int const size = sizechar(palabra);

	char* palabravacia = new char[size];
	char* letra = new char[1];


	cout << endl;
	while (continuar == 1) {

		if (error == 0) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |			" << endl;
			cout << "___________|___________" << endl;
		}
		if (error == 1) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (   )" << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |			" << endl;
			cout << "___________|___________" << endl;
		}
		if (error == 2) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (   )" << endl;
			cout << "           |            |" << endl;
			cout << "           |            |" << endl;
			cout << "           |            |" << endl;
			cout << "           |            |" << endl;
			cout << "           |            |" << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |			" << endl;
			cout << "___________|___________" << endl;
		}
		if (error == 3) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (   )" << endl;
			cout << "           |            |" << endl;
			cout << "           |          :'|" << endl;
			cout << "           |         :' |" << endl;
			cout << "           |        :'  |" << endl;
			cout << "           |            |" << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |			" << endl;
			cout << "___________|___________" << endl;
		}
		if (error == 4) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (   )" << endl;
			cout << "           |            |" << endl;
			cout << "           |          :'|':" << endl;
			cout << "           |         :' | ':" << endl;
			cout << "           |        :'  |  ':" << endl;
			cout << "           |            |" << endl;
			cout << "           |           " << endl;
			cout << "           |           " << endl;
			cout << "           |			" << endl;
			cout << "___________|___________" << endl;
		}
		if (error == 5) {
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (   )" << endl;
			cout << "           |            |" << endl;
			cout << "           |          :'|':" << endl;
			cout << "           |         :' | ':" << endl;
			cout << "           |        :'  |  ':" << endl;
			cout << "           |            |" << endl;
			cout << "           |          :'" << endl;
			cout << "           |         :' " << endl;
			cout << "           |        :'  " << endl;
			cout << "___________|___________ " << endl;
		}
		if (error == 6) {
			cout << "PERDISTE" << endl;
			cout << "La palabra era: "; imppalabra(palabra); cout << endl;
			cout << "           ______________ " << endl;
			cout << "           |            | " << endl;
			cout << "           |          (x x)" << endl;
			cout << "           |         --------" << endl;
			cout << "           |          :'|':" << endl;
			cout << "           |         :' | ':" << endl;
			cout << "           |        :'  |  ':" << endl;
			cout << "           |            |" << endl;
			cout << "           |          :' ':" << endl;
			cout << "           |         :'   ':" << endl;
			cout << "           |        :'     ':" << endl;
			cout << "___________|__________________" << endl;
			exit(1);
		}
		cout << endl;

		cout << "Ingrese letra :"; cin >> letra;


		busqueda(palabra, letra, palabravacia);
		
		comparar(size, &continuar, palabra, palabravacia);

		errorcont(palabra, letra, &error, size);

		cout << endl;
		
		system("cls");

		imprimir(palabravacia, palabravacia + size);
		cout << endl;

		
	}
	cout << "GANASTE!!";

	exit(1);

	return 0;
}