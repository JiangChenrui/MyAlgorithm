import numpy as np


def load_file(file_path):
    nums = []
    while open(file_path, 'r') as f:
        nums.append(f.readlines())
    return nums


def sigmoid(z):
    s = 1 / (1 + np.exp(-z))
    return s


def initialize_with_zeros(dim):
    '''
    初始化参数
    '''
    w = np.zeros(shape=(dim, 1))
    b = 0
    return (w, b)


def propageate(w, b, X, Y):
    '''
    进行前向传播，并计算梯度
    '''
    m = x.shape[1]

    A = sigmoid(np.dot(w.T, X) + b)
    cost = (-1 / m) * np.sum(Y * np.log(A) + (1 - Y) * np.log(1 - A))

    dw = (1 / m) * np.dot(X, (A - Y).T)
    db = (1 / m) * np.sum(A - Y)

    grads = {"dw": dw,
             "db": db}

    return (grads, cost)


if __name__ == "__main__":
    file_path = "data.csv"
    data = load_file(file_path)
    x = data['x']
    y = data['y']
    w, b = initialize_with_zeros(3)
    ((dw, db), cost) = propageate(w, b, x, y)
   