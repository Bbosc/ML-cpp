import os
import requests
import numpy as np


if __name__ == '__main__':
    n_sets = 4
    folder_path = os.path.dirname(__file__)
    for i in range(n_sets):
        content = requests.get(f'https://cs.joensuu.fi/sipu/datasets/s{i+1}.txt').text
        filepath = os.path.join(folder_path, f's{i+1}.txt')
        with open(filepath, "w") as file:
            file.write(content)
        # re-conversion to handle delimiters and trailing spaces better
        data = np.genfromtxt(filepath)
        np.savetxt(filepath, data)
