# Tarea 2: Análisis de Threading
## Preguntas

* Procede a realizar el análisis de threading hasta el análisis **Suitability**

* Antes de comenzar a interpretar los resultados es importante saber la información representada. Ve a la pestaña Suitability Report y responde a las siguientes preguntas:
    * ¿Qué representa el gráfico Scalability of Maximum Site Gain? ¿Para que sirven las opciones Avg. Number of Iterations y Avg. Iteration Duration?
    
         - El Scalability of Maximum Site Gain nos indicala ganancia aproximada para un único sitio paralelo en la función. Las opciones Avg. Number of Iterations y Avg. Interation Duration indican como su nombre indica el promedio de iteraciones realizadas y el tiempo medio de ellas.

    * Explica que significa cada campo de las columnas **Combined Site Metrics, All Instances** y **Site Instance Metrics, Parallel Time**
    
      - La columna "Combined Site Metrics, All Instances" contiene tres subcolumnas, una del tiempo total de ejecución en serie, otra con paralelización, y la última la ganancia total conseguida a partir de las otras dos columnas. 
La columna "Site Instance Metrics, Parallel Time" refleja las métricas de tiempo en paralelo, que coincide con el tiempo paralelo de la columna anterior. Añado una captura de otro ejemplo que no es nuestro ejercicio: 

![image](https://user-images.githubusercontent.com/115668275/205145414-d9cfd61d-a321-441a-a55a-3a7836e2eac3.png)

* Analiza la escalabilidad de la ganancia por cada Site que has declarado:
    * En primer lugar configura el reporte acorde a tu sistema y al modelo de paralelización con hilos que vayas a utilizar.
    * Realiza una captura y almacenala con el nombre task2 en la carpeta [task2](/results/task2)
    * Indica para cada uno de los sites definidos, a partir de qué número de CPUs la ganancia deja de mejorar o incluso empeora, y justifica la razón por la cual ocurre.
       - Para el primer site, la ganancia comienza a empeorar a partir de los 32 núcleos
       - Para el segundo site, la ganancia comienza a empeorar a partir de los 16 núcleos
       - Para el tercer site, la ganancia comienza a empeorar a partir de los 8 núcleos
       - Esto puede deberse a que nuestros ordenadores en concreto solo tienen 8 núcleos, el hecho de poner más de 8 núcleos, sería hacer que fueran lógicos, con lo que al final lo que se consigue es estirar el rendimiento de los núcleos reales al máximo. Este máximo en este caso sería cuando empieza a empeorar, pues se usan núcleos lógicos con mucho menos rendimiento cada uno que los que usabamos originalmente en los ocho reales. Desde ese punto los núcleos usados son lógicos y rinden menos que los ocho originales, el punto en el que empieza a caer rendimiento dependerá de cuanto rendimiento se necesite por núcleo, como en el caso del último bucle cuya ejecución es más compleja por núcleo que en los otros dos, por eso empieza a disminuir su rendimeinto a partir directamente de los 8 originales.
    * ¿Cuál de los bucles definidos en el código se beneficia más del incremento de CPUs? ¿Cómo afectaría a la ganancia de este Site si, usando el máximo número de CPUs de la simulación, en vez de usar arrays de tamaño 300 lo aumentamos a 37500? Indica cómo has obtenido este nueva ganancia.
   
     
      - El primer bucle es el que más se beneficia a más núcleos haya.  Habría un 14.3% menos de "Load imbalance", casi 3% menos de "Runtime overhead" y en general            la ganancia se acercaría mucho más de media al x8. Adjuntamos una captura llamada x125 con los resultados, para obtener estos solo hemos tenido que usar la             opción de multiplicar el número medio de tareas por 125, ya que 300 por 125 casualmente da 37500.



