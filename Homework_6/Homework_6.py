import numpy as np
from scipy.optimize import least_squares

def read_data(filename):
    with open(filename, 'r') as file:
        data = [list(map(float, line.split())) for line in file]
    return np.array(data)

def model(params, x):
    a1, a2, a3, a4, a5, a6 = params
    return np.column_stack((a1 * x[:, 0] + a2 * x[:, 1] + a3, a4 * x[:, 0] + a5 * x[:, 1] + a6))

def objective(params, x, y):
    return (model(params, x) - y).flatten()

def main():
    data_title = ['fitdata1.dat', 'fitdata2.dat', 'fitdata3.dat']
    for i in data_title:
        data = read_data(i)
        x = data[:, :2]
        y = data[:, 2:]

        initial_params = np.zeros(6)
        result = least_squares(objective, initial_params, args=(x, y), method='lm')

        optimized_params = result.x
        print("Optimized Parameters for " +i+ ":")
        for y, param in enumerate(optimized_params, 1):
            print("a["+str(y) + "] = " +  str(param))
        print()

if __name__ == "__main__":
    main()
