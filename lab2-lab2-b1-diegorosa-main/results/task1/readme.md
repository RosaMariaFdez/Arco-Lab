# Tarea 1

Hemos creado el programa con dos funciones, una para encontrar el máximo del vector y otora para encontrar el mínimo. Tenemso dos versiones,
una paralelizada y otra sin paralelizar. La versión sin paralelizar está con la directiva de openMP critical, ya que necesita proteger varios 
espacios de memoria.

Ejemplos ejecución:

No paralelo:

El programa ha tardado 0.0002441406 segundos de media

Paralelo:

El programa ha tardado 0.0029296875 segundos de media

Como podemos comprobar, el programa tarda más paralelizoado, porque ya de por si el hecho dec rear los hilos tarda más de lo que se 
tarda en realizar toda la tarea que supone el código.