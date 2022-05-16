#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <vector>

using namespace std;

void Agendar();
void listas();
void eliminar();
void modificar();
void archivos();

int cita, * preciou, * cantidad, * subtotal, * total;
string* nombre, * nombret, * descripcion;
float* hora;
int main()

{
	int opc;
	cout << "\tBIENVENIDO\n";
	cout << "Seleccione una opcion" << endl;
	cout << "1.-Agendar Cita" << endl << "2.- Modificar Cita" << endl << "3.- Eliminar Cita" << endl << "4.- Lista de citas vigentes" << endl << "5.-Limpiar Pantalla" << endl << "6.-Salir" << endl;
	cin >> opc;

	switch (opc)
	{
	case 1:
		Agendar();
		return main();
		break;

	case 2:
		modificar();
		return main();
		break;

	case 3:
		eliminar();
		return main();
		break;

	case 4:
		listas();
		return main();
		break;

	case 5:
		system("cls");
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}
void Agendar()
{
	cout << "Introduce el numero de citas que desee agendar" << endl;
	cin >> cita;
	nombre = new string[cita];
	nombret = new string[cita];
	descripcion = new string[cita];
	hora = new float[cita];
	preciou = new int[cita];
	cantidad = new int[cita];
	total = new int[cita];
	subtotal = new int[cita];
	for (int i = 0; i < cita; i++)
	{
		while (getchar() != '\n');
		cout << "Ingrese nombre del paciente" << endl;
		getline(cin, nombre[i]);
		cout << "Ingrese hora del tratamiento (en formato de 24 horas)" << endl;
		cin >> hora[i];
		while (getchar() != '\n');
		cout << "Ingrese nombre del tratamiento" << endl;
		getline(cin, nombret[i]);
		cout << "Ingrese descripcion del tratamiento" << endl;
		getline(cin, descripcion[i]);
		cout << "Ingrese la cantidad del tratamiento" << endl;
		cin >> cantidad[i];
		cout << "Ingrese el precio unitario del tratamiento" << endl;
		cin >> preciou[i];

	}
}

void listas()
{
	for (int i = 0; i < cita; i++)
	{
		cout << "Cita" << i + 1 << endl;
		cout << nombre[i] << endl;
		cout << hora[i] << endl;
		cout << descripcion[i] << endl;
		cout << cantidad[i] << endl;
		cout << preciou[i] << endl;
	}
}

void archivos()
{
	ofstream archivo;
	string nombrearchivo;
	int texto;
	string texto2;
	nombrearchivo = "citasvigentes";

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	archivo << "NOMBRE" << "\t";
	archivo << "HORA" << "\t";
	archivo << "NOMBRE TRATAMIENTO" << "\t";
	archivo << "DESCRIPCION" << "\t";
	archivo << "CANTIDAD" << "\t";
	archivo << "PRECIOUNITARIO" << "\n";

	for (int i = 0; i < cita; i++)
	{
		texto2 = nombre[i];
		archivo << texto2 << "\t" << "\t";
		texto = hora[i];
		archivo << texto << "\t" << "\t";
		texto2 = nombret[i];
		archivo << texto2 << "\t " << "\t";
		texto2 = descripcion[i];
		archivo << texto2 << "\t " << "\t";
		texto = cantidad[i];
		archivo << texto << "\t " << "\t";
		texto = preciou[i];
		archivo << texto << "\t " << "\t";
		subtotal[i] = cantidad[i] * preciou[i];
		total[i] = (subtotal[i] * .16) + (subtotal[i]);
		texto = total[i];
		archivo << texto << "\t " << "\t";
	}
}
void eliminar()
{
	int j;
	cout << "ingrese la cita a eliminar";
	cin >> j;
	j = j - 1;
	for (int i = j; i == j; i++)
	{
		cout << "Eliminando Registro" << j + 1 << endl;
		nombre[i] = "";
		hora[i] = 0;
		nombret[i] = "";
		descripcion[i] = "";
		cantidad[i] = 0;
		preciou[i] = 0;
	}
}

void modificar()
{
	int j, opcion;
	cout << "ingrese el numero de cita a modificar";
	cin >> j;
	j = j - 1;
	cout << "ingrese que desea modificar 1.-Nombre,2.-Hora, 3.- Tratamiento, 4.-Descripcion, 5.-Cantidad y Precio Unitario" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese nombre" << endl;
			getline(cin, nombre[i]);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese hora" << endl;
			cin >> hora[i];
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese tratamiento" << endl;
			getline(cin, nombret[i]);
		}
		break;
	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			cout << "Ingrese descripcion" << endl;
			getline(cin, descripcion[i]);
		}
		break;
	case 5:
		for (int i = j; i == j; i++)
		{
			cout << "Ingrese cantidad" << endl;
			cin >> cantidad[i];
			cout << "Ingrese precio unitario" << endl;
			cin >> preciou[i];
		}
		break;
	}

}