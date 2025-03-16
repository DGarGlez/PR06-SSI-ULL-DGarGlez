#include "Rijndael.h"

Rijndael::Rijndael(){   // Constructor
	k=0;    // Contador de iteraciones
}


Rijndael::~Rijndael(){  // Destructor
   
}
/**
 * Devuelve el valor de la cajaS
 * @param pos - Posición de la cajaS
 * @return int - Valor de la cajaS
 */
int Rijndael::valorCajaS(int pos){
    int cajaS[256] = {  //cajaS
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, 
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, 
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, 
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, 
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, 
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, 
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, 
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, 
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, 
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, 
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, 
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, 
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, 
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, 
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, 
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 
}; 
	return cajaS[pos];
}

/**
 * Constantes para ampliar la clave
 */
int rCon[255] = {  // Constantes para ampliar la clave
    0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 
    0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 
    0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 
    0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 
    0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 
    0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 
    0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 
    0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 
    0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 
    0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 
    0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 
    0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 
    0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 
    0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 
    0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 
    0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb  
};

/**
 * Expande la clave
 * @param arrClave - Array de la clave
 * @param mClaveExp - Clave expandida
 */
void Rijndael::expandirClave(unsigned char (*arrClave)[4], unsigned char *mClaveExp){
int i,j,k;  // Variables de control
k=0;    // Inicializamos k a 0
	unsigned char copia[4],copia2;  // Variables auxiliares	   
	
	for (int i = 0; i < 4; i++){  // Pasamos la clave a los primeras posiciones de clave expandida
	    for (int j = 0; j < 4; j++){    // Recorremos la clave
            	mClaveExp[k] = arrClave[j][i];  //Metemos la clave en clave expandida
		        k++;        // Incrementamos k
            }
    	}

	for(i=4;i < 44;i++){    // 44 columnas
	
		for( j = 0; j < 4; j++){    // Recorremos las columnas
	    		copia[j] = mClaveExp[(i-1) * 4 + j];  // Metemos la ultima columna en copia
		}
		
		if (i % 4 == 0){  // Cada cuatro filas -- RotWord
	    	copia2 = copia[0];      // Guardamos el primer elemento de copia
			copia[0] = copia[1];    // Cambiamos el primer elemento por el segundo
	    	copia[1] = copia[2];    // Cambiamos el segundo elemento por el tercero
			copia[2] = copia[3];    // Cambiamos el tercero elemento por el cuarto
			copia[3] = copia2;      // Cambiamos el cuarto elemento por el primero
						
	    	//SW, se aplica la caja S a cada uno de los 4 bytes de entrada
	    	copia[0] = valorCajaS(copia[0]);    // Aplicamos la caja S al primer elemento
			copia[1] = valorCajaS(copia[1]);    // Aplicamos la caja S al segundo elemento
			copia[2] = valorCajaS(copia[2]);    // Aplicamos la caja S al tercer elemento
			copia[3] = valorCajaS(copia[3]);    // Aplicamos la caja S al cuarto elemento
				
            copia[0] =  copia[0] ^ rCon[i/4];   // XOR con rCon 
		}
		// XOR entre una cte. y el resultado anterior			
		mClaveExp[i*4+0] = mClaveExp[(i-4)*4+0] ^ copia[0];
		mClaveExp[i*4+1] = mClaveExp[(i-4)*4+1] ^ copia[1];
		mClaveExp[i*4+2] = mClaveExp[(i-4)*4+2] ^ copia[2];
		mClaveExp[i*4+3] = mClaveExp[(i-4)*4+3] ^ copia[3];
		
					
	}
    
}

/**
 * Sumamos cada byte de texto a byte de clave, columna a columna
 * @param pos - Posición
 * @param texto - Texto
 * @param mClaveExp - Clave expandida
 */
void Rijndael::addRoundKey(int pos, unsigned char (*texto)[4], unsigned char *mClaveExp){ // Sumamos cada byte de texto a byte de clave, columna a columna 
   unsigned char copia[32];         // Array auxiliar
   
    for (int i = 0; i < 4; i++){    // Recorremos la matriz
	    for (int j = 0; j < 4; j++){    // Recorremos la matriz
	       copia[i*4 + j] =  texto[j][i];  // Metemos la matriz en copia
	    }
    }
 	
    cout << "\n R" << pos <<" (SUBCLAVE = ";
    for( int i = 0; i < 16; i++){                   // Recorremos la subclave
	    // Uso printf porque cout no admite %02x, (%02x es para que muestre en hexadecimal)
	    printf("%02x",mClaveExp[pos * 16 + i]);         // Mostramos la subclave
	}
	
	for( int i = 0; i < 16; i++){
		copia[i] ^= mClaveExp[pos * 16 + i];  // XOR: byte de subclave y byte de texto
	}
		
	for (int i = 0; i < 4; i++){    // Recorremos la matriz
		for (int j = 0; j < 4; j++){    // Recorremos la matriz
		    texto[j][i]  = copia[i*4 + j];  // Se guarda en la matriz 4x4 el resultado
			iteraciones[k] = texto[j][i];	// Guardamos tambien en un array
			k++;                            
		}
	}
    
	cout << ") = " ;
	for (int i = 0; i < 4; i++){    // Recorremos la matriz
		for (int j = 0; j < 4; j++){    // Recorremos la matriz
	        	printf("%02x",texto[j][i]);     // Mostramos resultado final
		}	    
	}
	cout << endl;
}

/**
 * Sustituimos el texto por los valores de cajaS
 * @param texto - Texto
 */
void Rijndael::subBytes(unsigned char (*texto)[4]){  //Sustituimos el texto por los valores de cajaS
    for( int i = 0; i < 4; i++){    // Recorremos la matriz
		for( int j = 0; j < 4; j++){    // Recorremos la matriz
			texto[i][j] = valorCajaS(texto[i][j]);  // Sustituimos el texto por los valores de cajaS
		}
	} 
}

/**
 * Rotamos 2a fila un byte,3a fila dos bytes y 4a fila tres bytes
 * @param texto - Texto
 */
void Rijndael::shiftRows(unsigned char (*texto)[4]){ // Rotamos 2a fila un byte,3a fila dos bytes y 4a fila tres bytes
    unsigned char copia;    // Variable auxiliar
   	 
	copia = texto[1][0];	    //
	texto[1][0] = texto[1][1];  //
	texto[1][1] = texto[1][2];  // Rotamos 2a fila un byte
	texto[1][2] = texto[1][3];  //
	texto[1][3] = copia;        // 

	copia = texto[2][0];        // 
	texto[2][0] = texto[2][2];  // 
	texto[2][2] = copia;        // Rotamos 3a fila dos bytes
	copia = texto[2][1];        // 
	texto[2][1] = texto[2][3];  // 
	texto[2][3] = copia;        // 

	copia = texto[3][0];        // 
	texto[3][0] = texto[3][3];  // 
	texto[3][3] = texto[3][2];  // Rotamos 4a fila tres bytes
	texto[3][2] = texto[3][1];  // 
	texto[3][1] = copia;        // 
}

/**
 * Cada columna se multiplica por una matrix dada
 * @param r - Matriz
 */
void Rijndael::mixColumns(unsigned char (*r)[4]){ // Cada columna se multiplica por una matrix dada
    unsigned char a[4]; // Copia del array r
    unsigned char b[4]; // Cada elemento del array a multiplicado por 2
    unsigned char c,j;  // Variables de control
    unsigned char h;    // Variable auxiliar
        
    for(j = 0; j < 4; j++) {    // Recorremos la matriz
        for(c=0;c<4;c++) {  // Recorremos la matriz
            a[c] = r[c][j];         // Copiamos la matriz
            h = (unsigned char)((signed char)r[c][j] >> 7);  // Desplazamiento aritmético a la derecha
	        b[c] = r[c][j] << 1;    // Elimina implícitamente high  porque b[c] es un char de 8 bits, por lo que XOR por 0x1b y no 0x11b en la siguiente línea
	        b[c] ^= 0x1B & h;       // Si h es 1, entonces XOR con 0x1B
        }
                
    	r[0][j] = b[0] ^ a[3] ^ a[2] ^ b[1] ^ a[1]; // 2 * a0 + a3 + a2 + 3 * a1
    	r[1][j] = b[1] ^ a[0] ^ a[3] ^ b[2] ^ a[2]; // 2 * a1 + a0 + a3 + 3 * a2
    	r[2][j] = b[2] ^ a[1] ^ a[0] ^ b[3] ^ a[3]; // 2 * a2 + a1 + a0 + 3 * a3
	    r[3][j] = b[3] ^ a[2] ^ a[1] ^ b[0] ^ a[0]; // 2 * a3 + a2 + a1 + 3 * a0
	}    
}

/**
 * Ciframos el texto
 * @param texto - Texto
 * @param mClaveExp - Clave expandida
 */
void Rijndael::encriptar(unsigned char (*texto)[4],unsigned char *mClaveExp){
	addRoundKey(0,texto,mClaveExp); // Primera iteracion    	
	
	for( int i = 1; i < 10; i++){   // 8 siguientes iteraciones
		subBytes(texto);        // Sustituimos el texto por los valores de cajaS
		shiftRows(texto); 	    // Rotamos 2 fila un byte,3 fila dos bytes y 4 fila tres bytes
		mixColumns(texto);	    // Cada columna se multiplica por una matrix dada dando una nueva matriz
		addRoundKey(i, texto,mClaveExp);    // Sumamos cada byte de texto a byte clave, columna a columna
	}	
	
	// Última iteracion
	subBytes(texto);    // Sustituimos el texto por los valores de cajaS
	shiftRows(texto);   // Rotamos 2a fila un byte,3a fila dos bytes y a4 fila tres bytes
	addRoundKey(10, texto,mClaveExp);   // Sumamos cada byte de texto a byte clave, columna a columna
}
	







