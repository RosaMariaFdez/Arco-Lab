# Tarea 3: Vectorización

## Preguntas
* Antes de comenzar la vectorización es importante conocer cuáles son las características de tu máquina ¿Cuáles son las extensions multimedia SIMD con las que cuenta tu arquitectura?

* Observa el análisis que has realizado al programa complexmul.cpp. El propio Intel Advisor debe haber detectado que hay una infrautilización de instrucciones, esto está directamente relacionado con la vectorización, ya que lo que pretende reflejar es que tienes disponibles las extensiones SIMD y no las estás utilizando. Para vectorizar el algoritmo, el propio programa Intel Advisor te aconseja como hacerlo ¿Qué has hecho para vectorizar el bucle? Ten en cuenta que debes vectorizar lo máximo que te permita tu arquitectura.

* Una vez vectorizado el programa realiza un análisis y guárdalo con el nombre task3:
    * ¿Cual es el valor del campo Vector Length? ¿Es este el valor esperado? Tanto si la respuesta es afirmativa como negativa justifica cual es el valor que esperabas.
    * ¿Cuál ha sido la ganancia? Explica si es el resultado esperado, si no lo es, explica cuál crees que es la razón (Pista: Intel Advisor puede darte indicios de cuál es el problema).

## Respuestas

* 1: Usando el comando el lscpu, hemos encintrado que el portátil de Diego tiene algunas de las siguientes extensiones de SIMD como:  avx, avx2, see o see2

* 2: Para vectorizar el bucle hemos compilado el programa con la siguiente línea:
  icpc -fopenmp -mavx2 -O3 -g -o complexmulICPC2 complexmul.cpp
De manera que utilizamos el set de instrucciones SIMD AVX2 para que se vectorice automáticamente lo que pueda. Este comando lo hemos tenido que ejecutar desde devcloud, ya que con arquitectuara AMD resultaba imposible.

* 3: 
* 3.1: El valor del campo VL nos sale 8. Teniendo en cuenta que el vector length es el número de iteraciones que se realizan por instrucción, el valor esperado es 8 según intel advisor, y si lo comprobamos mirandoe el analisis trip count, podemos comprobar que ha habido una media de 6500 interacciones, que es justamente el resultado de dividir 50000(iteraciones que tiene el segundo bucle for) entre 8. Por tanto podemos asumirq ue se han realizado 8 iteraciones del bucle por instrucción ,ergo el valor estimado coincide con el esperado

Para decir est, nos basamos en cambios hechos a la variable SIZE que nos cambia el número de iteraciones del bucle vectorizado. Se haga el cambio que se haga, el valor del trip count siempre varía con respecto a la variable VL, a veces no es completamente exacto como es lógico porque  no se puede hacer media iteración, pero siempre queda muy aproximado.

* 3.2: Según  intel advisor el resultado esperado con la vectoruzación, sería 9.05 veces mejor que el programa sin vectorizar. También nos dice que finalmente el resultado obtenido, en cuanto a mejora, ha sido el esperado, 9,05 veces mejor.