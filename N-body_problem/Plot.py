import plotly.graph_objs as go


data = open('data.txt', 'r')

X1 = []
Y1 = []
X2 = []
Y2 = []
X3 = []
Y3 = []

i = 0
for line in data:
    if i % 10 == 0:
        X1.append(line.split()[0])
        Y1.append(line.split()[1])
        X2.append(line.split()[3])
        Y2.append(line.split()[4])
        X3.append(line.split()[6])
        Y3.append(line.split()[7])
    i = i+1

data.close()

fig = go.Figure()
fig.add_trace(go.Scatter(x = X1, y = Y1, mode = 'lines', line = dict(color = 'red')))
fig.add_trace(go.Scatter(x = X2, y = Y2, mode = 'lines', line = dict(color = 'blue')))
fig.add_trace(go.Scatter(x = X3, y = Y3, mode = 'lines', line = dict(color = 'green')))

fig.show()
