/*
 *
 * REPOSITORIO: https://github.com/DGarGlez/PR06-SSI-ULL-DGarGlez.git
 * 
 */
#include "Rijndael.h"

using namespace std;

int main(){  

	unsigned int* iter;             // Puntero a array de iteraciones
	unsigned char mClaveExp[176];   // Contendra la expansion de clave	
	unsigned char clave[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};    // Clave  ejemplo  
   	unsigned char arrTexto[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff}; // Texto a cifrar ejemplo   
	char resp;                  // Respuesta del usuario
	unsigned char texto[4][4];  // Matriz 4x4 con el texto a cifrar
	unsigned char mClave[4][4]; // Matriz 4x4 con la clave a cifrar
	
	system("clear");    // Limpiamos pantalla
                 	
	cout << "*************************************************************************************" << endl;
	cout << "*                                 PRÁCTICA RIJNDAEL                                 *" << endl;
	cout << "*************************************************************************************" << endl << endl;
	
	cout << "CLAVE:\t\t";   // Mostramos la clave
	for (int i = 0; i < 16; i++){   // Recorremos la clave
        // Uso printf porque cout no admite %02x, (%02x es para que muestre en hexadecimal)
		printf(" %02x ",clave[i]);
	} 
	cout << "\nTEXTO ORIGINAL: ";   // Mostramos el texto original
	for (int i = 0; i < 16; i++){       // Recorremos el texto original
        // Uso printf porque cout no admite %02x, (%02x es para que muestre en hexadecimal) 
		printf(" %02x ",arrTexto[i]);
	}
  
	cout << "\nDESEA MODIFICAR LOS DATOS:(S/N):";
	cin >> resp;    // SI: S/s NO: N/n
	cin.clear();    // Limpiamos buffer
	fflush(stdin);  // Limpiamos buffer

	if(resp == 's' || resp == 'S') {    // Si la respuesta es S/s

        cout << "CLAVE EN HEXADECIMAL: ";
        for(int i = 0; i < 16; i++){	
            // Uso scanf porque cin no admite %02x, (%02x es para que muestre en hexadecimal)
            scanf("%02x",&clave[i]);
        }
        cin.clear();    // Limpiamos buffer
        fflush(stdin);  // Limpiamos buffer
    
        cout << "TEXTO EN HEXAMECIMAL: ";
        for(int i = 0; i < 16; i++){
            // Uso scanf porque cin no admite %02x, (%02x es para que muestre en hexadecimal)
            scanf("%02x",&arrTexto[i]);
        }
        cin.clear();    // Limpiamos buffer
        fflush(stdin);  // Limpiamos buffer
    }
    else if (resp != 'n' && resp != 'N'){    // Si la respuesta no es N/n
        cerr << "\nRESPUESTA INVÁLIDA --> SI: S/s NO: N/n\n" << endl;    // Mostramos mensaje de error
        return 1;   // Salimos del programa
    }
	
	cout << "\n********************************************************************************************" << endl;
	
	for (int i = 0; i < 4; i++){    // Recorremos la matriz
	    for (int j = 0; j < 4; j++){    // Recorremos la matriz
            mClave[j][i] = clave[i*4 + j]; // Convierte clave a cifrar en una matriz 4X4
        }
    }
	
	for (int i = 0; i < 4; i++){    // Recorremos la matriz
	    for (int j = 0; j < 4; j++){    // Recorremos la matriz
            texto[j][i] = arrTexto[i*4 + j]; // Texto a cifrar en una matriz 4X4
        }
    }

    Rijndael aes; // Creamos un objeto de la clase Rijndael
	aes.expandirClave(mClave, mClaveExp);  // Expandir la clave y guardarla en un array
    	aes.encriptar(texto, mClaveExp);  // Ciframos el texto
    	cout << "\n********************************************************************************************" << endl;
    	cout << "TEXTO CIFRADO: ";
    	for (int i = 0; i < 4; i++){    // Recorremos la matriz
            for (int j = 0; j < 4; j++){    // Recorremos la matriz
                // Uso printf porque cout no admite %02x, (%02x es para que muestre en hexadecimal)
                printf(" %02x ",texto[j][i]);   // Mostramos el texto cifrado
            }
    	}
    	cout << "\n********************************************************************************************" << endl;        
}