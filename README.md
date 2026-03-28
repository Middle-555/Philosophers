<h1 align="center">Philosophers</h1>

<p align="center">
  Dining philosophers simulation in C with POSIX threads and mutexes.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/School-42-black?style=for-the-badge" alt="42 badge" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language badge" />
  <img src="https://img.shields.io/badge/Status-Build%20verified-brightgreen?style=for-the-badge" alt="Status badge" />
</p>

<p align="center">
  <strong>threads • mutexes • synchronization • concurrency • timing</strong>
</p>

---

## Overview

`Philosophers` is a project developed as part of the 42 curriculum.

This repository contains the mandatory `philo` program, a simulation of the dining philosophers problem. Each philosopher is represented by a thread, each fork is represented by a mutex, and the main monitoring loop checks starvation and the optional meal target.

This project focuses on:
- thread creation and lifecycle management
- synchronization of shared state with mutexes
- starvation detection based on timestamps
- input validation and clean resource handling

---

## Features

- argument validation with overflow and format checks
- dedicated handling for the single philosopher case
- one thread per philosopher and one mutex per fork
- synchronized status printing to avoid mixed terminal output
- death monitoring and optional meal limit support
- current repository only contains the mandatory thread-based version, not the bonus semaphore/process version

---

## Concepts Covered

Through this project, the following concepts are exercised:

- POSIX threads (`pthread_create`, `pthread_join`)
- mutex locking and shared resource protection
- concurrent access to shared state
- time handling in milliseconds with `gettimeofday`
- parsing and validating command-line arguments
- manual cleanup of allocated memory and mutexes

---

## Build

Clone the repository and compile the project:

```bash
git clone git@github.com:Middle-555/Philosophers.git
cd Philosophers
make
```

Available Makefile rules:

```bash
make
make clean
make fclean
make re
```

The project is compiled with `cc` and the flags `-Wall -Werror -Wextra -g -pthread`.

---

## Usage

Run the program with:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments

- `number_of_philosophers`: number of philosopher threads to create
- `time_to_die`: maximum time in milliseconds a philosopher can stay without eating
- `time_to_eat`: time in milliseconds spent eating
- `time_to_sleep`: time in milliseconds spent sleeping
- `number_of_times_each_philosopher_must_eat`: optional stop condition for the simulation

### Examples

```bash
./philo 1 800 200 200
./philo 2 800 200 200 2
./philo 5 800 200 200 3
```

All time values are interpreted in milliseconds. When the optional fifth argument is provided, the simulation stops once every philosopher has reached the required meal count.

---

## Project Structure

```text
.
├── include/
│   └── philo.h
├── src/
│   ├── checking_error.c
│   ├── data.c
│   ├── handle_simulation.c
│   ├── main.c
│   ├── philo_death.c
│   ├── philo_routine.c
│   ├── utils.c
│   └── utils2.c
├── makefile
└── README.md
```

### Structure Details

- `include/`: shared structures, typedefs, and function prototypes
- `src/`: argument parsing, initialization, philosopher routine, monitoring, and utility helpers
- `src/checking_error.c`: input validation and special handling for the one philosopher case
- `src/data.c`: data initialization, mutex setup, and simulation startup
- `src/philo_routine.c`: philosopher lifecycle, eating, sleeping, thinking, and waiting logic
- `src/philo_death.c`: starvation detection and optional meal-limit completion check

---

## Project Constraints

This implementation currently targets the mandatory `philo` program:
- written in C
- built with `cc`
- synchronized with POSIX threads and mutexes
- based on millisecond timing
- organized around a single executable: `philo`

This repository does not include the bonus version based on processes and semaphores.

---

## Testing

The following checks were verified locally on this repository:
- successful compilation with `make`
- invalid argument rejection
- dedicated one philosopher behavior
- bounded simulation runs with the optional meal limit
- terminal output consistency during concurrent execution

### Manual test examples

```bash
./philo 0 800 200 200
./philo 1 800 200 200
./philo 2 800 200 200 2
./philo 5 800 200 200 3
```

### Memory checks

If `valgrind` is available on your machine, you can use:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./philo 4 410 200 200 2
```

No dedicated automated test suite is present in this repository at the moment.

---

## What This Project Helps Practice

This project is a good exercise to improve in the following areas:
- reasoning about concurrent execution
- protecting shared state with a minimal locking strategy
- debugging timing-sensitive behavior
- structuring a small multi-file C project

---

## Possible Improvements

Although the current repository provides a working mandatory version, several improvements could be considered:
- add the bonus implementation with processes and semaphores
- add automated test and sanitizer targets in the `makefile`
- refine logging and monitoring to make debugging easier
- add dedicated tooling for memory and race-condition analysis

---

## Author

Kpourcel
42 student

<p>
  <a href="https://github.com/Middle-555">GitHub</a>
</p>
