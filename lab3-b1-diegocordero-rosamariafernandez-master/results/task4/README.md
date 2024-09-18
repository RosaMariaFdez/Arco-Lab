# Tarea 4: Análisis de memoria y mejora vectorización

## Preguntas

* Compila de nuevo el programa complexmul.cpp **sin vectorizar** y genera un análisis de memoria marcando los bucles del cómputo que realizan la mutliplicación de números complejos, en concreto marca los bucles de las líneas 27 y 28 (si el análisis se demora mucho prueba a reducir el tamaño). Realiza el análisis tanto usando la interfaz gráfica de intel advisor como por línea de comandos. Además indica que comando es el que has usado para realizar el análisis por comando.

* Abre advisor y selecciona la vista "Refinement Reports".
    * ¿Qué información nos proporciona esta vista? enumera cada elemento de la tabla resumiendo el significado
    * ¿Qué comportamiento de memoria se obtiene? ¿Por qué es deseable tener un stride uniforme?
    * Mira el resultado del análisis de memoria de ambos bucles y comprueba que el stride es de 2.
        * ¿Por qué el stride tiene este valor? (Revisa los conceptos de row-order y column-order así como el orden en el que se reserva la memoria en C)
        * ¿Sobre que variables se está accediendo con un stride de 2? ¿Cómo afecta esto a la caché?
        * ¿Se te ocurre algún modo de modificar el programa, manteniendo los dos bucles y el mismo resultado, para que
        el acceso a la variable sea uniforme? Realiza la modificación y almacena el resultado en esta misma carpeta con el nombre complexmul_unit_stride.cpp.
        
* Genera un snapshot para el análisis completo (hasta los patrones de acceso a memoria) tanto para la versión con un stride de 2 como para la versión con stride unitario (ambos vectorizando el código) y llámalos respectivamente "task4a" y "task4b", añádelos a esta misma carpeta. 
    * En "task4b" ¿Cuáles son los valores de la longitud del vector y la ganancia estimada? ¿Son los resultados que se esperaban? Justifica la respuesta.
    * Comparando estas dos soluciones ¿Cuánto ha aumentado la ganancia?

* Compara los resultados del análisis task2 y task4b:
    * ¿Cuál ha sido la ganancia real del algoritmo vectorizado? ¿Ha sido menor o mayor a la estimación?

# Respuestas
 * 1: El comando proporcionado por la interfaz gráfica de advisor misma sería:
  /opt/intel/oneapi/advisor/2022.3.1/bin64/advisor -collect survey -project-dir /home/diego/intel/advixe/projects/Task4b --app-working-dir=/home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4 -- /home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4/complexmulMem
/opt/intel/oneapi/advisor/2022.3.1/bin64/advisor -collect tripcounts -flop -project-dir /home/diego/intel/advixe/projects/Task4b --app-working-dir=/home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4 -- /home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4/complexmulMem
/opt/intel/oneapi/advisor/2022.3.1/bin64/advisor -collect map -project-dir /home/diego/intel/advixe/projects/Task4b --app-working-dir=/home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4 -- /home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4/complexmulMem
 También se podría usar el siguiente comando si lo que se quiere es únicamente el análisis de memoria:
 opt/intel/oneapi/advisor/2022.3.1/bin64/advisor -collect map -mark-up-list=3 -project-dir /home/diego/intel/advixe/projects/Task4b --app-working-dir=/home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4 -- /home/diego/net-book-code/ArCo/git/lab3-b1-diegocordero-rosamariafernandez/results/task4/complexmulMem 

 * 2: 
    * 2.1: Nos proporciona, entre otras cosas, la distribución de los stride. Parte de la información proporcionada es:
        - Un 73% de instrucciones de acceso a memoria con stride 1 o 0
        - Un 27% de instrucciones de acceso a memoria con stride constante
        - Un 0% de instrucciones de acceso a memoria con stride irregular
        Se puede ver en profundidad, en nuestro análisis que subimos en esta misma carpeta
    
    * 2.2: Obtenemos un comportamiento de "Mixed Strides".
        Es deseable tener un stride constante ya que así se genera menos carga al no tener qu emodificar el tamaño del mismo.
    * 2.3: 
        * 2.3.1: Creemos que el stride tiene ese valor ya que C++ (al igual que casi todos los lenguajes que derivan de C), sigue el Row major order, es decir, las varaibles se almacenan en memoria con respecto a su fila, y en este caso estamos accediendo a elementos de filas distintas en cada interacción, por lo que estamos accediendo a posiciones de memoria que no son adyacentes.
        * 2.3.2: En intel advisor podemos observar que cuando tenemos un stride de 2 se está accediendo o bien a C[i][REAL] o bien a C[i][IMAG]. Esto no hace mucho bien en la cache, pues estamos haciendo un acceso a memoria no adyacente varias veces.
        * 2.3.3: Se podría modificar el código para que se hicieran los accesos por filas y no por columnas. Esto es fácil hacerlo, ya que en este caso solo se opera con los valores que están o en las filas o en las columnas, en este caso los valores están en las columnas y se accede a ellos por las filas (Con las variables i y j), por lo que solo tenemos que cambiar REAL e IMAG a donde antes estaban i y j. 

        Hemos hecho esto, adjuntado el código como complexmul_unit_stride y realizado un análisis con su snapshot task4b. Se demeustra no solo que ahora hay stride unitario, si no que ahora es del tipo "All uni stride" y que tarda bastante menos en ejecutarse.
    * 3.1: Comentar primero que hemos bajado el size a 5000 en estos dos últimos snapshots, pues aunque sabemos qeu va a tardar menos porque está vectorizado, nos sigue tardando mucho tiempo que podemos ahorrar simplificando esa variable.
        Vl vale 8, la ganancia estimada era 7.09. Se ha conseguido 7.98 de ganacia estiamda, por lo que se ha sobrepasado lo que se estimaba
    * 3.2 En task4a teníamos una ganancia estimada del 7.03 y hemos conseguido una ganacia del 7.93, por lo que se estimaba menos ganancia y se ha conseguido menos que con task 4b, no obstante, la diferencia entre el estimado y lo esperado ha sido mayor para bien en task4a.

    * 4.1: En terminos generales, ya que siempre que lo hemos probado ha salido así, la estimación de ganancia con la vectorización siempre ha sido menor a la conseguida finalmente. Aunque es cierto que con esta última versión, la ganancia era mayor.
    


