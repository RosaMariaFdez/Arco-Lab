# Tarea 3

Hemos paralelizado con la directiva omp critical, ya que teníamos que modificar dos posiciones en la memoria a la vez, 
esto hará que esté más tiempo bloqeuado qeu con la directiva omp atomic, pero con esta última, el resultado nunca daba exacto.

Ejecuciones de ejemplo con un intervalo 5:

Programa sin paralelizar:
El programa ha tardado 0.0000152990 segundos de media

Programa paralelizado:
El programa ha tardado 0.0003455260 segundos de media

Como podemos comprobar, el tiempo en el programa paralelizado es mayor, pero esto es debido a que se tarda de un programa 
poco exigente, solo hay 5 intervalos, por lo que el overhead de las operaciones de paralelizaciñon (En este caso el hecho de crear
los hilos por openMP), es decir, la "penalización" de cada directiva openmp es mayor que el propio beneficio que nos ofrece.



