# Tarea 2
El código en src/task2/buffer.cpp debería representar el siguiente flujo:
1. Inicializar el buffer A
2. Sumar al valor de cada posición de A el índice de la iteración
3. Inicializar el buffer B Del mismo modo que A
4. Calcular B como resultado del valor de B multiplicado por A

## Comprueba el resultado y muéstralo a continuación
450

## ¿Qué abstracción se está usando para los contenedores de datos?
Una cola

## ¿Cómo se está formando el DAG? ¿implicitamente? ¿explicitamente?
Implícitamente, ya que se están mostrando dependencias, como la RAW en el último submit

## Enumera todas las dependencias y el tipo de dependencias
### RAW:
* Task1 con kernel 2 y 3, pues se accede a A y a B antes de que se escriban
### WAR:
* Ninguna
### WAW:
* Kernel 2 y 1, pues se escribe en A mientras se escribe A

