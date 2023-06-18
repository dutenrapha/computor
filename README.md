# Computor - School 42 Programming Curriculum

This repository contains the project implementation for the Computor project, which is part of the curriculum at School 42.

## Project Description

The Computor project focuses on building a polynomial equation solver. The solver is capable of handling polynomial equations of degree 0, 1, and 2, providing both real and complex solutions. It takes an equation as input and outputs the solution(s) if any exist.

The project is implemented in the C programming language and follows the guidelines and norms specified by School 42.

## Project Structure

The project is structured as follows:

```
.
├── include/
│   └── computor.h       # Header file
├── lib/                  # Libraries (if any)
├── main.c                # Main source code file
├── Makefile              # Build automation file
├── obj/                  # Object files
├── src/
│   ├── polynomials.c     # Source file for polynomial operations
│   ├── solver.c          # Source file for equation solver
│   ├── utils.c           # Source file for utility functions
│   └── validation.c      # Source file for equation validation
├── test.sh               # Script for testing
```

## Prerequisites

To compile and run the Computor project, you need to have the following software installed on your machine:

- GCC compiler
- Make build automation tool

## Getting Started

To get started with the Computor project, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the project directory.

```shell
$ git clone git@github.com:dutenrapha/computor.git
$ cd Computor
```

3. Build the project using the Makefile.

```shell
$ make
```

4. Run the solver with an input equation. For example, to solve the equation `5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0`, use the following command:

```shell
$ ./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```

5. The solver will provide the solution(s) for the equation, if any exist.

## Usage

The Computor solver accepts equations in the following format:

- Coefficients and powers are separated by `*`.
- Terms are separated by `+` or `-`.
- The equation is represented as `left_side = right_side`.

For example, to solve the equation `5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0`, the input should be:

```
$ ./computor "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
```

## Additional Resources

For more information and detailed instructions about the Computor project, please refer to the official School 42 curriculum and project instructions.

## Contributing

Contributions to the Computor project are not accepted as this repository is intended for educational purposes and follows the guidelines of School 42.

## License

This project is licensed under the [MIT License](LICENSE).

---

**Note:** This README provides a general overview of the Computor project. For detailed instructions and specific requirements, please refer to the official project guidelines provided by School 42.
