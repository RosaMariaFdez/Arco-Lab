# Tarea 1: Intel Advisor

## Preguntas
* Antes de comenzar a realizar ningún análisis es interesante conocer las características de tu arquitectura, para ello contesta a las siguientes preguntas:
    * Indica tu modelo de procesador y de cuantos núcleos dispones
         - El modelo de mi procesador es i5-8300 y tiene 4 cores.
    * ¿Cuantos hilos pueden ser ejecutados por núcleo?

* A continuación procede a realizar anotaciones en todos los bucles que deben ser paralelizados (señalados con un TODO: Paralellize). En total debes indicar tres Sites para analizar. Estas anotaciones permitirán al programa de análisis considerar que esos bucles serán paralelizados y hacer las estimaciones oportunas. Guarda el nuevo programa con las anotaciones con el nombre matmul_annotated.cpp (ten en cuenta que además de añadir las anotaciones tienes que incluir un nuevo archivo de cabecera).

* Indica el comando que usarías para compilar el programa con las anotaciones (Consejos: Mirar la opción -I y buscad la ruta del archivo advisor-annotate.h dentro del directorio intel/oneapi).
## Respuestas

* 1:
   * 1.1 El procesador de Diego es un AMD Ryzen 5 3550H con 4 cores
   * 1.2 Puede ejecutar dos hilos por núcleo

* 3: icpc -o matmul_annotated -I /opt/intel/oneapi/advisor/2022.3.1/include -fopenmp matmul_annotated.cpp
