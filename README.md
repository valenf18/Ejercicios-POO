# Ejercicios de Programación Orientada a Objetos (POO) - C++ con Qt

Este repositorio contiene una colección de ejercicios prácticos de la materia **POO** (Programación Orientada a Objetos) desarrollados con **C++ y Qt Framework**.

Cada ejercicio tiene como objetivo aplicar conceptos fundamentales como encapsulamiento, herencia, polimorfismo, señales y slots, uso de Qt Designer, manejo de bases de datos, archivos, timers, eventos y más.

---
A
## 🧩 Lista de ejercicios

### 🔹 Ejercicio 1 – Clase Poste
Se define una clase `Poste` con atributos de altura y diámetro. Se cargan postes en un `std::vector`, se ordenan por altura y se muestran antes y después de ordenarlos.

### 🔹 Ejercicio 2 – Expresiones idiomáticas
Se carga un `std::vector<std::string>` con expresiones como “pan comido” y se ordenan alfabéticamente ignorando espacios.

### 🔹 Ejercicio 3 – Carga dinámica de objetos
Se crea una clase personalizada y se instancian objetos hasta consumir 200 MB de RAM, contando cuántos se logran almacenar.

### 🔹 Ejercicio 4 – Control de volumen
Ejemplo clásico de sincronización entre `QSlider` y `QSpinBox` usando `signals` y `slots`. El título de la ventana cambia según el valor del slider.

### 🔹 Ejercicio 5 – Mostrar imagen y cerrar automáticamente
Se muestra una imagen en un `QLabel`, maximizando sin deformarla. A los 3 segundos, la ventana se cierra automáticamente.

### 🔹 Ejercicio 6 – Login básico con GridLayout
Login con usuario/clave. Si es correcto (admin:1111), se muestra un formulario de ingreso de datos personales.

### 🔹 Ejercicio 7 – Login con validación extendida
Versión más completa con validación de campos no nulos, rango de legajo y un sistema de captcha visual.

### 🔹 Ejercicio 12 – Login con temperatura actual
Usa una API para mostrar la temperatura actual de Córdoba al iniciar sesión (usuario admin:1234).

### 🔹 Ejercicio 13 – Imagen remota en pantalla completa
Login con fondo descargado desde internet. Si es válido, se muestra una nueva ventana fullscreen con otra imagen remota (sin deformarla).

### 🔹 Ejercicio 14 – Pintura libre
Clase `Pintura` que permite dibujar a mano alzada. Se cambia color con teclas `R`, `G`, `B`, y el tamaño del pincel con la rueda del mouse. Escape borra todo.

### 🔹 Ejercicio 15 – Login con SQLite
Login validando contra una base de datos local `SQLite`. Muestra el último ingreso registrado con `QLabels`.

### 🔹 Ejercicio 16 – Login con SQLite y clave en MD5
Similar al anterior, pero la clave se almacena cifrada en MD5 y se precarga el último usuario al volver a abrir la app.

### 🔹 Ejercicio 17 – Botones personalizados con colores
Se crea una clase `Boton` heredada de `QWidget` con `paintEvent`. Se colocan 5 botones personalizados en una ventana, con señal propia `signal_clic()`.

### 🔹 Ejercicio 18 – T-Rex Extremo
Minijuego inspirado en el dinosaurio de Chrome. `TRex` debe esquivar cactus y pájaros. Se usan `QTimer`, eventos de teclado y detección de colisiones.

### 🔹 Ejercicio 20 – Herencia múltiple
Se implementa una jerarquía de instrumentos musicales (`Guitarra`, `Batería`, `Teclado`). El teclado hereda además de una clase `Electrico`.

### 🔹 Ejercicio 21 – HTML Parser
Aplicación con GUI para ingresar una URL. Descarga todas las imágenes, CSS y JS de la web y permite al usuario elegir el directorio de guardado.

### 🔹 Ejercicio 22 – Sensor inline
Se comparan métodos `inline` vs `offline` con `QElapsedTimer`, ejecutando millones de llamadas para medir rendimiento.

### 🔹 Ejercicio 23 – CuentaBancaria con función amiga
Se define una clase `CuentaBancaria` con métodos `depositar()` y `mostrar()`, y una función amiga para comparar saldos entre dos cuentas.

### 🔹 Ejercicio 24 – Uso de `static`
Se cuenta cuántas instancias de la clase `Persona` se crearon, usando atributos y métodos `static`.

---

## 💻 Requisitos

- Qt 6.6+ y Qt Creator
- Compilador compatible con C++11 o superior (MSVC / MinGW)
- MySQL (opcional en Ej. 15–16)
- Conexión a internet (Ej. 12, 13, 21)

---

## 📦 Organización del proyecto

Cada ejercicio está en su propia carpeta (`Ejercicio1/`, `Ejercicio2/`, ...), con su respectivo `.pro`, `.cpp`, `.h` y `.ui` cuando corresponde.

---

## 🙌 Autor

Valentino Frache – Estudiante de Ingeniería en Informática  
Estos ejercicios fueron desarrollados como parte del curso de Programación Orientada a Objetos.

---

## 📘 Licencia

Uso académico y libre distribución con fines educativos.
