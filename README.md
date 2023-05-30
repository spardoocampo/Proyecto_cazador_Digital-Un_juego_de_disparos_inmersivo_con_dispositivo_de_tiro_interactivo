## 1. Nombre del proyecto:
Cazador digital, un juego de disparos inmersivo con dispositivo de tiro interactivo.

## 2. Proposito del juego:
El propósito del juego "Cazador Digital: Un juego de disparos inmersivo con dispositivo de tiro interactivo" es brindar a los jugadores una experiencia divertida y envolvente en la caza de patos utilizando electrónica y juegos en 3D.

El objetivo principal del juego es recrear la emoción y la destreza requerida en la caza de patos en un entorno virtual. Mediante la combinación de un entorno 3D realista creado con Babylon.js y un dispositivo de tiro interactivo basado en la placa ESP32, se busca proporcionar una experiencia de juego única y más inmersiva que simplemente utilizar un teclado y un ratón.

El jugador asume el papel de un cazador digital y utiliza el dispositivo de tiro interactivo para apuntar y disparar a los patos que vuelan en la pantalla. El objetivo es acertar en la mayor cantidad de patos posibles y obtener la puntuación más alta. La precisión, la rapidez de reacción y la habilidad del jugador para apuntar con precisión son factores clave para tener éxito en el juego.

## 3. Instrucciones del juego:
El objetivo del juego es cazar la mayor cantidad de patos posible y obtener la puntuación más alta.
Utiliza el dispositivo de tiro interactivo conectado a la placa ESP32 para apuntar y disparar a los patos en la pantalla.
Asegúrate de tener el dispositivo de tiro correctamente conectado mediante bluetooth al dispositivo el cual se va a ejecutar el juego(computador, celular, tablet, etc.).
Enciende el juego y asegúrate de que tanto la pantalla como el dispositivo de tiro estén funcionando correctamente.
Se debe emparejar el dispositivo bluetooth al dispositivo en el que se piensa jugar, luego al iniciar el juego deberá clicar al botón ubicado en la parte superior izquierda para buscar el dispositivo bluetooth que es el dispositivo de captura, cuando el dispositivo de captura se encienda el led interno significa que se inicializó de manera correcta el módulo MPU6050.
Interacción con el juego:
Observa la pantalla, donde los patos se moverán y volarán en el entorno 3D.
Mueve el dispositivo de tiro en la dirección deseada para apuntar a los patos en la pantalla.
Utiliza el botón del dispositivo de tiro, para activar el disparo y acertar a los patos.
Puntuación y efectos:
Cada vez que aciertes a un pato, se sumará un punto a tu puntuación total.
Si fallas un disparo o no aciertas a un pato, no se sumará ni se restará ningún punto.
Disfruta de efectos visuales y de sonido que realzan la experiencia de caza.
El juego está diseñando para tener una duración infinita, así que si quieres batirte a duelo con un compañero se recomienda tener un temporizador y el que obtenga más puntos será el más habilidoso.
Finalización del juego:
Una vez que se haya alcanzado el límite de tiempo autoimpuesto o hayas decidido terminar el juego, se mostrará tu puntuación final.
Puedes comparar tu puntuación con las puntuaciones más altas previas o desafiar a otros jugadores a superar tu récord.

## 4. Descripción del dispositivo de captura
Se realiza el diseño del dispositivo de captura teniendo en cuenta el juego original de duck hunter, asi que se planteó las caracteristicas principales que son un microcontrolador con conectividad wifi, un accionador para el disparo y un sensor para el movimiento, ademas de un indicador de funcionamiento, tiendo esto en mente el grupo de trabajo realizo un metodo de diseño que es la tabla morfologica para asi al final concluir con la lista de dispositivos a usar que son:

Esp32

MPU6050 

LED

Pulsador.

Para el diseño de la carcasa se planeo un arma no letal fisicamente, para no incentivar el uso de armas en la sociedad, asi que con una ardua investigacion se obtuvo un modelo 3D de la pistola portal de Rick and Morty de accceso publico y con licencia libre.

Se realizo un diseño en wokwi que se observa en la siguiente imagen.
![Diagrama](https://github.com/spardoocampo/Proyecto_cazador_Digital-Un_juego_de_disparos_inmersivo_con_dispositivo_de_tiro_interactivo/blob/a23afaf25911fb1466389772fc16c3bf43451953/wireless_device/Diagrama%20final.png)
Al final la realizacion se obtuvieron los resultados que se observan en las siguientes imagenes:
![Foto1](https://github.com/spardoocampo/Proyecto_cazador_Digital-Un_juego_de_disparos_inmersivo_con_dispositivo_de_tiro_interactivo/blob/a31c467857ad6181f4238c57ae0dff7b9c6b3d0e/wireless_device/photo_5168195514225765008_y.png)
![Foto2](https://github.com/spardoocampo/Proyecto_cazador_Digital-Un_juego_de_disparos_inmersivo_con_dispositivo_de_tiro_interactivo/blob/a31c467857ad6181f4238c57ae0dff7b9c6b3d0e/wireless_device/photo_5168195514225765007_y.png)

## Conclusion del dispositivo de captura
El mando inalámbrico utilizado en el proyecto está diseñado para interactuar con el juego Cazador digital(cazapatos) y permitir al jugador apuntar y disparar a los patos en la pantalla. Está construido alrededor de una placa ESP32, que actúa como el microcontrolador principal y se encarga de la comunicación inalámbrica con el juego.

El diseño del mando incluye los siguientes componentes y características:

Placa ESP32: Se utiliza como el cerebro del mando inalámbrico. Proporciona capacidad de procesamiento, conectividad Bluetooth para la comunicación con el juego y una variedad de pines de E/S para la conexión de componentes como el MPU6050, un pulsador y un LED.

Sensores de movimiento: Se utilizó un sensor con medicion de aceleracion, giróscopio y temperatura, dicho sensor es el MPU6050 y su coneccion es mediante el protocolo I2C . Este sensor capturan los cambios en la orientación y movimiento del dispositivo de captura, lo que permite al jugador apuntar en el juego.

Boton pulsador (Disparo): El dispositivo de captura tiene un pulsador que se utiliza para activar el disparo dentro del juego. Este pulsador se conectan al pin 2 de E/S de la placa ESP32 y se programan para enviar un dato al juego como bandera cuando se presiona.

Alimentación: El mando puede ser alimentado por una batería recargable interna o utilizar una fuente de alimentación externa.



**En este repositorio se encuentran 2 carpetas; en la carpeta patos se encuentra el codigo html que es donde el juego esta elaborado en babylon.js, en la carpeta wireless_devices se encuentra el codigo de arduino.**
## Integrantes del proyecto:
***Sebastian Pardo Ocampo***

***Alexander Cadena***

***Vanesa Cuasapaz***
