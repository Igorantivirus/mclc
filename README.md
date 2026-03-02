<h1 align="center">mclc Console Calculator</h1>

[![Русская версия](https://img.shields.io/badge/Русская%20версия-blue)](README_RU.md)

mclc is a console calculator for complex numbers.
It supports basic and advanced functions from the following categories:

* Arithmetic operations
* Trigonometric functions
* Logarithms
* Powers

Calculations are performed using a custom library and function engine.

<h2>Signature</h2>

<h3>Operators</h3>

* Boolean (returns 0/1): '<', '>', '<=', '>=', '==', '!='
* Mathematical: '+', '-', '*', '/', '^', '%', 'xor'
* Ternary: '?:'

<h3>Functions</h3>

* With one parameter: sin, cos, tan, asin, acos, atan, sinh, cosh, tanh, sqrt, exp, ln, conj, umag, real, abs
* With two parameters: pow, atan2
* Special: log, root

<h3>Constants</h3>

* pi, e, phi, i, inf

<h2>Examples</h2>

* `mclc a=17 "b=sin(pi/2)" "(a>b)?pi:e"` -> 3.14159
* `mclc 2+2*2` -> 6
* `mclc --prec 15 pi` -> 3.14159265358979
* `mclc --polar "0.5(1+sqrt(3)i)"` -> (1|60)
* `mclc --triganam --degree "exp(pi/2*i)"` -> 1(cos(90)+i*sin(90))

<h2>Technologies</h2>

Compilation standard: **C++23**

Dependencies:
* [MathWorker](https://github.com/Igorantivirus/MathWorker) — a C++ library for parsing and evaluating mathematical expressions (pulled automatically via FetchContent)

<h2>Build</h2>

1. <b>Clone the repository</b>
   
   ```sh
   git clone https://github.com/Igorantivirus/mclc
   cd mclc
   ```
2. <b>Generate CMake</b>
   
   ```sh
   cmake -B build
   ```
3. <b>Build</b>
   
   ```sh
   cmake --build build --config Release
   ```
4. <b>Run</b>
   
   Run the `mclc` executable from the `build` folder.

<h2>License</h2>

**MIT License**
