# Tarea 2

Hemos hecho la versión paralelizada de este programa mediandte la directiva for paralell (Como en el resto) pero en este caso sí se puede usar
también la directivaatomic, que nos permite mejorar los tiempos, casi igualándolos al tiempo sin paralelizar.

Los resultados de la ejecución son:

Sin paralelizar:

Con N=50:

El programa ha tardado 0.0004882812 segundos de media

Con N=1000000:

El programa ha tardado 0.0341796875 segundos en los casos de peor rendimiento
Pero también se dan casos de valores mínimos como 0.0175781250 segundos 

Paralelizado:

Con N=50 y 4 hilos:

El programa ha tardado 0.0026855469 segundos de media

Con N=1000000 y 8 hilos:

El programa ha tardado 0.0336914062 segundos de media

Lo que podemos comprobar con esto es que a más hilos y valores más grandes, la paralelización más importancia cobra. En este
caso hemos conseguido que el tiempo de ejecución, o la distancia entre tiempos de ejecución en este caso, sea mucho menor. No 
obstante sigue sin venirnos a cuenta paralelizar este tipo de programa tan pequeño.