# Tarea 2
En esta tarea paralelizarás el código con DPC para obtener el máximo rendimiento a la vez que obtienes una gran
portabilidad.

## Preparar el código
En primer lugar, copia el código results/task1/task1_b.cpp en results/task2/base.cpp. Este será el fichero base
para las modificaciones necesarias.

## Crea la cola y un selector de dispositivo por defecto
Busca como crear la cola y pasa como parámetro a la cola el selector por defecto. Recuerda que la cola se tiene que crear
antes de cualquier tipo de computo.

## ¿Para que sirve la cola?
- Sirven como medio de comunicación entre el host los dispositivos y nos permite mandar unidades de ejecución a un único dispositivo

## Para cada array crea sus buffer correspondientes
Recuerda que uno de los modos de acceder a memoria en DPC es mediante los buffers y los accessors. Este es el método que vamos
a usar en esta práctica.
Para ello, crea los buffers una vez inicializados los espacios de memoria donde vamos a trabajar, es decir, justo antes del for.

Algunas pistas:
* Necesitas 4 buffers, dos para imágenes (entrada/salida) y dos para filtros.
* El segundo parámetro que requiere el constructor es un objeto de tipo rango. Para las imágenes los rangos son: img_width img_height y para los filtros 3 * 3 o, directamente, 9.

## Crea un rango para indicar el espacio de trabajo del kernel
El primer parámetro del paralell_for va a ser el rango de trabajo. Para definir este rango tenemos que indicar, en tiempo de compilación,
el número de dimensiones que tiene y el tamaño de cada dimensión.

Pistas:
* El número de dimensiones viene determinado por el número de dimensiones de la imagen. ¿Cuantas dimensiones tiene una imagen en **blanco y negro**? **Recuerda que está en blanco y negro no en RGB**.
* El tamaño de cada dimensión viene determinado por el alto y el ancho.

Crea esta variable **justo debajo de la definición de los buffer**.

## Manda una tarea a la cola
Ahora crearemos el trabajo dentro de la cola donde, en las siguientes tareas, iremos metiendo el código para: solicitar acceso a las variables y ejecutar el trabajo.
Busca como crear el trabajo para la cola. Comprueba que el código compila.

## Solicitar acceso a los buffer
Recuerda que hemos creado los buffer para abstraer el acceso a las diferentes variables. Tal y como se ha visto en teoría hay que solicitar el acceso a cada
buffer por medio de los accessors. **En las primeras líneas dentro de la cola** define los accessor que necesitamos.

Pistas:
* Tenemos que crear tantos accessors como buffers hemos creado anteriormente.
* Elige bien los permisos.

## Crea el parallel_for
Ahora que ya tenemos acceso a cada uno de los buffer, hay que solicitar por medio del handler el parallel_for indicando: el rango del kernel (revisa los pasos anteriores)
y el kernel. Inicialmente deja el kernel vacio y comprueba que la compilación es correcta.

Pistas:
* Los for que recorren la imagen (row, col) desaparecen ya que el for se reparte por píxeles.
* Puedes acceder al valor de row y col mediante el segundo parámetro del kernel id<2>. Row será item[0] y col item[1].

Una vez finalizado el parallel_for (recuerda añadir el código para multiplicar por el kernel), compila el código y asegurate
de no tener errores de compilación.

## Esperar al trabajo y acceder a los resultados
Finalmente solo queda esperar a la cola, busca como puedes esperar y acceder mediante un host_accessor al buffer de salida
del kernel. Únicamente creando el host_accessor al buffer el runtime se asegura que tienes acceso al mismo y ya puedes acceder como lo harías normalmente.

**Comprueba que el código produce los mismos resultados que el código secuencial**
**Guarda el código final en results/task2/dpc.cpp**

----

# Task 2
In this task you will parallelize the code con DPC to obtain the maximum performance while you don't compromise portability.

## Prepare the code
First, copy the code from results/task1/task1_b.cpp to results/task2/base.cpp. This will be starting version.

## Crete the queue using a default device selector
Find how to create the queue and call the constructor with a default device selector. Remember that the queue has to be created before 
any kind of computation. 

## What is the queue used for?
**Answer here**

## Create the corresponding buffer for each array
Remember that accessors are the preferred way to access to memory, so this is the one to be used in this lab.
Create the buffers once you have initialized the memory locations used by the algorithm (before the *for* clause).

Some clues:
* You need 4 buffers: 2 for images (input/output) and 2 for filters.
* The second parameter of the constructor is a range type. For images ranges are: img_width img_height, while it's 3 by 3 o, directly 9 for filters.

## Create a range for the kernel
The first parameter of the *paralell_for* will be the working range. For this, you need to specify the size at compile time: number of dimensions and size of each dimension.

Clues:
* The number of dimensions refers to the dimensions of the image. How many dimensions uses a  **black & white** image? **Remember it's b&W, not RGB**.
* The size of each dimension is determined by height and size of the image.

Create the range variable **justo below the definition of the buffers**.

## Send the task to the queue
You'll create a task to be submitted to the queue. The task should include the code to request access to data and do the filtering.

## Request access to buffers
Remeber that we use buffers to abstract memory access. Then, you need to use accessors for such purpose. Include the required accessors **in the first lines of the task**.

Clues:
* You need as many accessors as buffers exist.
* Choose the right permissions.

## Create the parallel_for
After having access to buffers, you need to code the *parallel_for*, telling: the range of the kernel (defined in a previous step) and the kernel itself. First write an empty kernel and test the compilation and execution of the code.

Clues:
* For clauses for going through each row and column will disappear, since the deployment will allocate as many thread processors as iterations they where in the loops. Each processor will then compute the value for a single pixel.
* You can access the corresponding row and col location of the thread using the second parameter in the kernel *id<2>*. Row will be item[0] and col item[1].

After coding the *parallel_for* compile and check the code.

## Wait for the task and get the results
Now, you have to code the waiting of the queue, and use a host_accessor to get the output buffer of the kernel.
By just creating the host_accessor to the buffer, the runtime will handle the necessary operations to provide data. 

**Run the code and checl that the results match the ones of the sequential version**
**Save the final code in results/task2/dpc.cpp**
