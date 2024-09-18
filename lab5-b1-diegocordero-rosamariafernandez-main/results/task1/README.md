# Tarea 1
Familiarizarse con el uso de DPC.
En primer lugar copia el código de src/task1/query.cpp en results/task1/src y compilalo con dpcpp.

## ¿Qué salida obtienes?
Device: Intel(R) Xeon(R) Gold 6128 CPU @ 3.40GHz

## ¿Qué tipos de selectores tenemos en DPC? ¿Podemos obtener una GPU? ¿Qué pasa si no existe el dispositivo requerido?
Dentro de los device selectors, tenemos Built-in Device Selectors como el cpu_selctor, gpu_selector,accelerator_selector,host_selector o default_selector
Sí, se podría obtener una gpu con gpu_selector
Si no exisitiera el dispositivo requerido, mandará una excepción CL_DEVICE_NOT_FOUND.


Es probable que alguno de los dispositivos que te permite seleccionar DPC no los tengas disponibles en tu PC, no pasa nada, para eso tenemos
devcloud.

## Prueba a obtener una GPU desde devcloud modificando el programa query.cpp en gpu_query.cpp
**guarda el fichero en results/task1/src.**

## ¿Cómo has obtenido la GPU? ¿Cómo has solicitado a qsub que quieres un nodo con GPU?
Pidiéndole a devcloud un nodo con una gpu
qsub -I -l nodes=1:gpu:ppn=2 -d .
Como curiosidad, añadir que nos ha sorprendido que solo nos proporcione un nodo con una gpu integrada, una intel uhd graphics, no nos ha dado ningún nodo con una gpu dedicada como las serie rtx o gtx de Nvidia. Suponemos que en parte también para evitar problemas con minería.

## Modifica el programa para obtener más datos del dispositivo.
**guarda el fichero en results/task1/src/more_query.cpp**
