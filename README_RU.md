<h1 align="center">Консольный калькулятор mclc</h1>

[![English version](https://img.shields.io/badge/English%20version-blue)](README.md)


Консольный калькулятор комплексных чисел.
Поддерживаются базовые и продвинутые функции из следующих категорий:

* Арифметические операции
* Тригонометрические функции
* Логарифмы
* Степени

Вычисления выполняются при помощи собственной библиотеки и движка функций.

<h2>Сигнатура</h2>

<h3>Операторы</h3>

* Булевые (возвращает 0/1): '<', '>', '<=', '>=', '==', '!='
* Матемаические: '+', '-', '*'. '/'. '^', '%', 'xor'
* Тернарный: '?:'

<h3>Функции</h3>

* С одним параметром: sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, sqrt, exp, ln, conj, umag, real, abs
* С двумя параметрами: pow, atan2
* Особые: log, root

<h3>Константы</h3>

* pi, e, phi, i, inf

<h2>Примеры</h2>

* `mclc a=17 "b=sin(pi/2)" "(a>b)?pi:e"` -> 3.14159
* `mclc 2+2*2` -> 6
* `mclc --prec 15 pi` -> 3.14159265358979
* `mclc --polar "0.5(1+sqrt(3)i)"` -> (1|60)
* `mclc --triganam --degree "exp(pi/2*i)"` -> 1(cos(90)+i*sin(90))

<h2>Технологии</h2>

Стандарт компиляции: **C++23**

Зависимости:
* [MathWorker](https://github.com/Igorantivirus/MathWorker) — C++ библиотека для обработки математических выражений (подключается автоматически через FetchContent)

<h2>Сборка</h2>

1. <b>Клонирование репозитория</b>
   
   ```sh
   git clone https://github.com/Igorantivirus/mclc
   cd mclc
   ```
2. <b>Генерация CMake</b>
   
   ```sh
   cmake -B build
   ```
3. <b>Сборка</b>
   
   ```sh
   cmake --build build --config Release
   ```
4. <b>Запуск</b>
   
   Запустите файл mclc из папки `build`

<h2>Лицензия</h2>

**MIT License**