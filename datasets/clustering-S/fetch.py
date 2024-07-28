import os
import requests


if __name__ == '__main__':
    n_sets = 4
    folder_path = os.path.dirname(__file__)
    for i in range(n_sets):
        content = requests.get(f'https://cs.joensuu.fi/sipu/datasets/s{i+1}.txt').text
        with open(os.path.join(folder_path, f's{i+1}.txt'), "w") as file:
            file.write(content)
