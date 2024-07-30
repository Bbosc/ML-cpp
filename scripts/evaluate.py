import numpy as np
import matplotlib.pyplot as plt



if __name__ == '__main__':

    data = np.genfromtxt('datasets/clustering-S/s1.txt')
    labels = np.genfromtxt('labels.txt').astype(np.int16)
    
    fig = plt.figure()
    ax = fig.add_subplot()

    for i in range(np.unique(labels).shape[0]):
        cluster = data[labels == i]
        ax.scatter(cluster[:, 0], cluster[:, 1], s=1, label=f'{i}')

    plt.legend()
    plt.show()