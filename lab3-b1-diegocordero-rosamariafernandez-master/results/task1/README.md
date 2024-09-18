# Tarea 1: Intel Advisor

## Preguntas
* 1 En la vista de "Survey & Roofline" se hace referencia a Total time y self-time. ¿Qué diferencia hay entre ambas?
* 2 Realiza un análisis de tipo Survey, accede a  la pestaña "Survey & Roofline" y haz una captura de la información (se usará
más tarde).
* 3 Pulsa sobre roofline (dentro de Survey & Roofline) y comprueba que no aparece ningún gráfico. ¿A qué se debe?
* 4 Haz un análisis de trip-counts y flop. ¿Qué información nueva aparece en la vista de survey? Haz una captura y comenta
los datos nuevos más relevantes.

* Pregunta 1:

        La diferencia entre self-time y total-time reside en que, en self-time, se tiene en cuenta el tiempo que ha llevadoa a cabo ejecutar 
        todas las líneas de código dentro de un método excluyendo el resto de métodos llámados desde dentro de éste último.Mientras que el tiempo total, tiene en cuenta el tiempo que ha llevado a cabo ejecutar todas las líneas de código dentro de un método, incluyendo el resto de métodos que se han llamado desde dentro del mismo.

* Pregunta 3:
        No aparece gráfica debido a que ésta depende de las operaciones de entero y de punto flotante; y estas no están disponibles. Para que apareciera tendríamos que realizar el análisis de trip counts y flops.
* Pregunta 4:
        Ahora aparece la gráfica que antes no aparecía en roofline, y además en code analytics podemos consultar los trip counts. De manera que contamos con mucha más información que antes
