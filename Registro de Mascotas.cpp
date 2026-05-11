#include <iostream>
using namespace std;

struct Mascota {
    string nombre;
    string especie;
    string raza;
    int edad;
    float peso;
};

Mascota registrarMascota() {
    Mascota m;

    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, m.nombre);

    cout << "Ingrese especie: ";
    getline(cin, m.especie);

    cout << "Ingrese la raza: ";
    getline(cin, m.raza);

    cout << "Ingrese edad: ";
    cin >> m.edad;

    cout << "Ingrese peso: ";
    cin >> m.peso;
    return m;
}

void mostrarMascota(Mascota m) {
    cout << "\n==DATOS DE LA MASCOTA ==\n";
    cout << "Nombre: " << m.nombre << endl;
    cout << "Especie: " << m.especie << endl;
    cout << "Raza: " << m.raza << endl;
    cout << "Edad: " << m.edad << " anos" << endl;
    cout << "Peso: " << m.peso << " kg" << endl;
}

int calcularEdadHumana(Mascota m) {
    return m.edad * 7;
}

void clasificarPeso(Mascota m) {
    cout << "\nClasificacion: ";

    if (m.peso < 5) {
        cout << "Mascota pequena.\n" << endl;
    }
    else if (m.peso >= 5 && m.peso <= 20) {
        cout << "Mascota mediana.\n" << endl;
    }
    else {
        cout << "Mascota grande.\n" << endl;
    }
}

void modificarDatos(Mascota &m) {
    int opcion;

    cout << "\n==MODIFICAR DATOS ==\n";
    cout << "1. Nombre\n";
    cout << "2. Especie\n";
    cout << "3. Raza\n";
    cout << "4. Edad\n";
    cout << "5. Peso\n";
    cout << "\nSelecciona una opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1) {
        cout << "Ingrese nuevo nombre: ";
        getline(cin, m.nombre);
    }
    else if (opcion == 2) {
        cout << "Ingrese nueva especie: ";
        getline(cin, m.especie);
    }
    else if (opcion == 3) {
        cout << "Ingrese nueva raza: ";
        getline(cin, m.raza);
    }
    else if (opcion == 4) {
        cout << "Ingrese nueva edad: ";
        cin >> m.edad;
    }
    else if (opcion == 5) {
        cout << "Ingrese nuevo peso: ";
        cin >> m.peso;
    }
    else {
        cout << "Opcion invalida." << endl;
    }
}

int main() {
    cout << "Nombre del estudiante: Cindy Julissa Carrillo Guarcas\n";

    Mascota mascota;
    int opcion;
    bool registrada = false;

    do {
        cout << "\n==== REGISTRO DE MASCOTA ====\n";
        cout << "1. Registrar mascota\n";
        cout << "2. Mostrar mascota\n";
        cout << "3. Calcular edad equivalente\n";
        cout << "4. Clasificar por peso\n";
        cout << "5. Modificar datos\n";
        cout << "6. Salir\n";
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
            mascota = registrarMascota();
                registrada = true;
                break;

            case 2:
                if (registrada)
                    mostrarMascota(mascota);
                else
                    cout << "\nPrimero necesitas registrar una mascota.\n";
                break;

        case 3:
            if (registrada) {
                cout << "\nEdad equivalente en anos humanos: "
                     << calcularEdadHumana(mascota)
                     << " anos.\n";
            }
            else {
                cout << "\nPrimero necesitas registrar una mascota.\n";
            }
            break;

            case 4:
                if (registrada)
                    clasificarPeso(mascota);
                else
                    cout << "\nPrimero necesitas registrar una mascota.\n";
                break;

            case 5:
                if (registrada)
                    modificarDatos(mascota);
                else
                    cout << "\nPrimero necesitas registrar una mascota.\n";
                break;

            case 6:
                cout << "\nSalir del programa...\n";
                break;

            default:
                cout << "\nOpcion incorrecta.\n";
        }

    } while(opcion != 6);

    return 0;
}