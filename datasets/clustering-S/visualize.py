import os
import sys
import numpy as np
import matplotlib.pyplot as plt

def read_file(filename: str) -> np.ndarray:
    return np.genfromtxt(filename) 

def cli(argv: list) -> str:
    if len(argv) == 1:
        i = 0
        datafiles = list(filter(lambda file : file.endswith('.txt') , os.listdir(os.path.dirname(__file__))))
        for i, file in enumerate(datafiles):
                print(f'{i + 1}: {file}')
        return datafiles[int(input("select dataset: ")) - 1]
    elif len(argv) == 2:
        return sys.argv[-1]
    else:
         raise NotImplementedError('too many arguments passed')


if __name__ == '__main__':

    datafile = cli(sys.argv)
    data = read_file(datafile)
    
    fig = plt.figure()
    ax = fig.add_subplot()
    ax.scatter(data[:, 0], data[:, 1], s=1)
    plt.show()

