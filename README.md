# Simulation Code Readme

This C program simulates a simple queuing system and generates a tabular output detailing various aspects of the system over a series of iterations.

## Table of Contents
- [Overview](#overview)
- [Usage](#usage)
- [Output Explanation](#output-explanation)

## Overview

The program uses random number generation to simulate customer arrivals and service times in a queuing system. It then computes and outputs various metrics related to the queuing system, such as arrival time, service time, time service begins, time customer waits in the queue, time service ends, time customer spends in the system, and idle time of the server.

## Usage

1. **Compile the Code:**
   ```bash
   gcc queuing_simulation.c -o queuing_simulation
   ```

2. **Run the Executable:**
   ```bash
   ./queuing_simulation
   ```

3. **Output:**
   The program generates an output file named `output.txt` that contains the simulation results.

## Output Explanation

The output file presents the simulation results in a tabular format. Each row corresponds to a simulation iteration, and the columns represent different metrics.

- **A - Customer:** Customer number.
- **B - Time Since Last Arrival (Minutes):** Time elapsed since the last customer arrival.
- **C - Arrival Time:** Time at which the customer arrives.
- **D - Service Time (Minutes):** Time required for service.
- **E - Time Service Begins:** Time at which the service begins.
- **F - Time Customer Waits in Queue (Minutes):** Duration the customer spends waiting in the queue.
- **G - Time Service Ends:** Time at which the service ends.
- **H - Time Customer Spends in System (Minutes):** Total time the customer spends in the system.
- **I - Idle Time of Server:** Duration of server idle time.

The program runs the simulation for 20 iterations, and the output provides insights into the dynamics of the queuing system.

Feel free to modify the code or parameters in the code to suit your specific queuing system requirements.
