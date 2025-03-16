# Documentación de funciones de la clase Rijndael

## Constructor y Destructor

### `Rijndael::Rijndael()`
Constructor de la clase Rijndael. Inicializa el contador de iteraciones `k` a 0.

### `Rijndael::~Rijndael()`
Destructor de la clase Rijndael. No realiza ninguna acción específica.

## Funciones de la clase Rijndael

### `int Rijndael::valorCajaS(int pos)`
Devuelve el valor de la caja S (Substitution Box) en la posición especificada por `pos`.
- **Parámetros**: 
  - `int pos`: La posición en la caja S.
- **Retorno**: 
  - `int`: El valor en la caja S correspondiente a la posición dada.

### `void Rijndael::expandirClave(unsigned char (*arrClave)[4], unsigned char *mClaveExp)`
Expande la clave original para generar una clave extendida que se utilizará en el proceso de cifrado.
- **Parámetros**: 
  - `unsigned char (*arrClave)[4]`: La clave original en forma de matriz 4x4.
  - `unsigned char *mClaveExp`: Un array donde se almacenará la clave expandida.
- **Retorno**: 
  - Ninguno.

### `void Rijndael::addRoundKey(int pos, unsigned char (*texto)[4], unsigned char *mClaveExp)`
Suma cada byte del texto a un byte de la clave expandida, columna por columna, para una ronda específica.
- **Parámetros**: 
  - `int pos`: La posición de la ronda.
  - `unsigned char (*texto)[4]`: El texto en forma de matriz 4x4.
  - `unsigned char *mClaveExp`: La clave expandida.
- **Retorno**: 
  - Ninguno.

### `void Rijndael::subBytes(unsigned char (*texto)[4])`
Sustituye cada byte del texto por el valor correspondiente en la caja S.
- **Parámetros**: 
  - `unsigned char (*texto)[4]`: El texto en forma de matriz 4x4.
- **Retorno**: 
  - Ninguno.

### `void Rijndael::shiftRows(unsigned char (*texto)[4])`
Realiza una rotación de filas en la matriz de texto: la segunda fila se rota un byte, la tercera fila dos bytes y la cuarta fila tres bytes.
- **Parámetros**: 
  - `unsigned char (*texto)[4]`: El texto en forma de matriz 4x4.
- **Retorno**: 
  - Ninguno.

### `void Rijndael::mixColumns(unsigned char (*r)[4])`
Multiplica cada columna de la matriz de texto por una matriz fija para mezclar los bytes de cada columna.
- **Parámetros**: 
  - `unsigned char (*r)[4]`: La matriz de texto en forma de matriz 4x4.
- **Retorno**: 
  - Ninguno.

### `void Rijndael::encriptar(unsigned char (*texto)[4], unsigned char *mClaveExp)`
Cifra el texto utilizando la clave expandida. Realiza varias rondas de operaciones de sustitución, permutación y mezcla.
- **Parámetros**: 
  - `unsigned char (*texto)[4]`: El texto en forma de matriz 4x4.
  - `unsigned char *mClaveExp`: La clave expandida.
- **Retorno**: 
  - Ninguno.