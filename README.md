# tp-algoritmos-1ro

Para que funcione la modularizacion de archivos, hay que compilar todos los .cpp, ademas de que tienen que estar bien importados

### Ejemplos 
Aclararacion: para que el comando funcione correctamente, se deben encontrar en la carpeta raiz del repo

#### Compilar y crear ejecutable para windows
g++ -o main.exe main.cpp ./shared/utils/file-utils.cpp

#### Compilar y crear ejecutable para linux
g++ -o main main.cpp ./shared/utils/file-utils.cpp
