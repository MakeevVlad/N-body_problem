import plotly.graph_objs as go
import plotly.offline as pl
import numpy as np


data = open('data_500.txt', 'r')

N = 3
X = [[] for i in range(N)]
Y = [[] for i in range(N)]
Z = [[] for i in range(N)]

i = 0
for line in data:
    if i % 100 == 0:
        for j in range(N):
            X[j].append(line.split()[j*3])
            Y[j].append(line.split()[j*3+1])
            Z[j].append(line.split()[j*3+2])
    i += 1

data.close()

fig = go.Figure()
colors = ['red', 'green', 'blue']
for i in range(N):
    fig.add_trace(go.Scatter(x = X[i], y = Y[i], mode = 'lines', line = dict(color = colors[i])))


#fig.show()
pl.plot(fig, filename="Stars1.html", auto_open=False)
