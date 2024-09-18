# Tarea 3
Una vez completada la paralelización realiza las medidas de rendimiento para ver la mejora

## ¿Cómo mejora el código paralelo con respecto al código secuencial?
- No mejora, es peor incluso en cuanto a tiempo en nuestro caso 

## ¿Por qué la primera vez tarda más que las siguientes?
- Porque se deben asignar los espacios de memoria.

## Realiza una tabla para cada imagen y cada configuración (serie, paralelo) con los tiempos medios
| Imagen | serie | paralelo |
|---|---|---|
| homer | 0.09062 s | 0.19237 s |
| paisaje | 0.51348 s | 0.20944 s |
| puente | 0.12975 s | 0.22843 s |

## Modifica el código para poder desplegar el mismo en una GPU, utiliza devcloud para probar la ejecución en GPU

### Modifica la tabla anterior para añadir los tiempos con GPU
| Imagen | serie | paralelo | gpu|
|---|---|---|---|
| homer | 0.09062 s | 0.19237 s | 0.10452 s |
| paisaje | 0.51348 s | 0.20944 s | 0.15280 s |
| puente | 0.12975 s | 0.22843 s | 0.18920 s |

### ¿Cómo te has asegurado de ejecutar el código en una GPU?
Hemos incluido una variable gpu_selector: gpu_selector selector y la hemos metido a la cola en queue q(selector)

### Modifica el programa para obtener información sobre el nodo que ejecuta la cola
**Guarda el código resultante en results/task3/task3.cpp**

----

# Task 3
One the parallelization task is completed you'll check the performance of the solution.

## Which is the improvement of the parallel version with respect to the sequential one?
**Answer here**

## Why does the first time take more time than the next ones?
**Answer here**

## Create a table for each image and configuration (serial, parallel) with the average times for each combination
**Answer here** **Explain the results obtained***

## Modify the code to deploy it in a GPU, using devcloud for the testing

## Modify the previous table to include the timing with respect to the GPU
**Answer here**

## How did you run the code in the GPU?
**Write down the devcloud command**

## Modify the program to gather information about the node running the task in the queue
**Save the resulting code in results/task3/task3.cpp**
