import matplotlib.pyplot as plt
import numpy as np


def fetch_data(input_lines, start_line):
    x = np.array([int(i) for i in input_lines[start_line].split()])
    y = np.array([int(i) for i in input_lines[start_line+1].split()],
                 ndmin=2, dtype=np.int64)
    line = start_line + 2
    while input_lines[line] != "":
        y = np.concatenate(
            (y, np.array([int(i) for i in input_lines[line].split()], ndmin=2, dtype=np.int64)))
        line += 1

    return x, y, line + 1


with open('benchmark_output.txt', 'r') as file:
    input_lines = [line.strip() for line in file]


x_recursive, y_recursive, i1 = fetch_data(input_lines, 0)
x_iterative, y_iterative, i2 = fetch_data(input_lines, i1)
x_power, y_power, _ = fetch_data(input_lines, i2)

plt.plot(x_recursive, np.mean(y_recursive/1000.0, axis=0), 'b.')
plt.plot(x_recursive, np.mean(y_recursive/1000.0, axis=0), 'b-', alpha=0.5)
plt.xlabel('Input (n)')
plt.ylabel('Time (µs) (Averaged over 10 iterations)')
plt.title('Time vs Input graph for Recursive Algorithm')
plt.savefig('Recursive_Plot.png')
plt.close()

plt.plot(x_iterative, np.mean(y_iterative/1000.0, axis=0), 'b.')
plt.plot(x_iterative, np.mean(y_iterative/1000.0, axis=0), 'b-', alpha=0.5)
plt.xlabel('Input (n)')
plt.ylabel('Time (µs)  (Averaged over 10 iterations)')
plt.title('Time vs Input graph for Iterative Algorithm')
plt.savefig('Iterative_Plot.png')
plt.close()

plt.plot(x_power, np.mean(y_power/1000.0, axis=0), 'b.')
plt.plot(x_power, np.mean(y_power/1000.0, axis=0), 'b-', alpha=0.5)
plt.xscale('log')
plt.xlabel('Input (n)')
plt.ylabel('Time (µs) (Averaged over 1000 iterations)')
plt.title('Time vs Input graph for Power Algorithm')
plt.savefig('Power_Plot.png')
plt.close()
