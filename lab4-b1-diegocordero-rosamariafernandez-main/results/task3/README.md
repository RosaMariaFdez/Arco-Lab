# Tarea 3: Paralelización con OpenMP

## Preguntas
* Una vez realizados los análisis correspondientes paraleliza el programa todo lo que puedas, fíjate en los comentarios marcados con "TODO" para ver donde tienes que incorporar código. Ten en cuenta que es posible que requiera usar modificadores de memoria o mecanismos de sincronización.

* ¿Cuántas hebras hay disponibles? ¿A qué crees que se debe este resultado?
 - Hay disponibles en el mmomento de ejecución del programa 8 hebras/hilos como nos permite ver el comando omp_get_num_procs(). Esto se debe a que en el momento no hay ningñun hilo asignado, y nuestro ordenador tiene ocho hilos por núcleo.

* Comprueba que la ejecucion paralela y secuencial es la misma. Recuerda que estás trabajando con números decimales
    * ¿Cómo lo has comprobado?
    - Hemos comprobado los tiempos de ejecución de la forma paralela y la forma secuencial y es contradictorio ver que la forma secuencial tarda menos. Lo hemos comprobado tanto desde la compilación de consola como en el survey generado por advisor al analizar ambos y los resultados coinciden. Es contradictorio con lo que esperabamos pero son los datos que hemos obtenido.
    
    Captura de comparación en consola: matmul = secuencial, mulmat = paralelizado
    
    ![image](https://user-images.githubusercontent.com/115668275/205381729-c3fe2d97-f09f-488a-9e7a-c4a84c59f76b.png)


    Captura de advisor secuencial: (0.09s)
    
    ![image](https://user-images.githubusercontent.com/115668275/205381890-bf95d0cc-1a7e-4288-b8d2-41d656732fcb.png)


    Captura de advisor paralela: (0.41s)
    
    ![image](https://user-images.githubusercontent.com/115668275/205381979-58fc434c-64a9-42d9-82ee-5acc4a926725.png)

    

* Realiza mediciones de tiempo para 2, 4, 8, 16, 32 y 64 hilos y añade los resultados de tiempo en una tabla junto a los resultados secuenciales. Además añade la ganancia obtenida por cada ejecución en comparación con la secuencial ¿Estos resultados se corresponden o se parecen a los estimados por intel advisor? Justifica tu respuesta.


![image](https://user-images.githubusercontent.com/92685068/205399949-e8eb9b0a-d88e-489c-94d7-66cebaefa1aa.png)

![imagen](https://user-images.githubusercontent.com/92685068/205252697-d3b5a868-593b-45f1-a137-92c0eff29ac8.png)

Los resultados de ganancia obtenidos se corresponden con la linearidad de la gráfica como adjuntamos en la foto, no obstante no supone ninguna ganancia, si no más bien lo contrario; es por ello que en la parte de la tabla de ganancia solo hay respuestas negativas. Suponemos que esto se debe a que el hecho de que al tener que invocar el hilo desde la función dada por openMP, consume más tiempo de lo que podría ahorrar. Esto no sería así y probablemente cumpliera con las estimaciones del advisor si fuera un programa mucho más grande.
