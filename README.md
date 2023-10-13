# tp-algoritmos-1ro

Aclararacion: para que los comandos funcionen tal como se muestran en este documento, se deben encontrar en la carpeta raiz del repositorio

Antes que nada, crear una carpeta vacia llamada `dat` dentro del proyecto. (solucionar esto en un futuro).

#### Compilar y crear ejecutable para windows

- 1 Compilar (desde una terminal)

`g++ -o main.exe main.cpp ./entities/repartidores/repartidores-actions.cpp ./entities/repartidores/repartidores-controller.cpp ./modules/reports-actions.cpp ./modules/reports-controller.cpp ./shared/utils/file-utils.cpp ./shared/utils/general-utils.cpp`

- 2 Ejecutar

Clickear el ejecutable, o desde la terminal usando `./main.exe` o `main.exe`
#### Compilar y crear ejecutable para linux

- 1 Compilar (desde una terminal)

`g++ -o main main.cpp ./entities/repartidores/repartidores-actions.cpp ./entities/repartidores/repartidores-controller.cpp ./modules/reports-actions.cpp ./modules/reports-controller.cpp ./shared/utils/file-utils.cpp ./shared/utils/general-utils.cpp`

- 2 Ejecutar

Ejecutando el main con `./main` desde la terminal