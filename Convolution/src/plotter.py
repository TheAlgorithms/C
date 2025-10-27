import numpy as np
import matplotlib.pyplot as plt
import sys
import os
from matplotlib.ticker import MaxNLocator

FILENAME = "data.txt"

def plot_convolution_data():
    """Reads the data file and plots the convolution results."""
    plt.style.use('dark_background')
    plt.rcParams["font.family"] = "sans-serif"

    try:
        with open(FILENAME, 'r') as f:
            lines = f.readlines()
            if len(lines) < 3:
                print(f"Python Error: '{FILENAME}' does not contain three lines.")
                sys.exit(1)

            input_signal = np.array([int(x) for x in lines[0].strip().split()])
            filter_kernel = np.array([int(x) for x in lines[1].strip().split()])
            output_signal = np.array([int(x) for x in lines[2].strip().split()])

    except FileNotFoundError:
        print(f"Python Error: Could not find '{FILENAME}'.")
        sys.exit(1)
    except Exception as e:
        print(f"Python Error: An error occurred while reading the file: {e}")
        sys.exit(1)

    fig, axs = plt.subplots(3, 1, figsize=(10, 8), tight_layout=True)
    fig.suptitle('Convolution Results', fontsize=18)

    # Plot Input Signal
    axs[0].stem(input_signal)
    axs[0].set_title(f'Input Signal (Size: {len(input_signal)})')
    axs[0].xaxis.set_major_locator(MaxNLocator(integer=True)) 

    # Plot Filter Kernel
    axs[1].stem(filter_kernel)
    axs[1].set_title(f'Filter Kernel (Size: {len(filter_kernel)})')
    axs[1].xaxis.set_major_locator(MaxNLocator(integer=True)) 

    # Plot Output (Convolved) Signal
    axs[2].stem(output_signal)
    axs[2].set_title(f'Output Signal (Size: {len(output_signal)})')
    axs[2].xaxis.set_major_locator(MaxNLocator(integer=True)) 
    os.remove('data.txt')
    plt.show()

if __name__ == "__main__":
    plot_convolution_data()
