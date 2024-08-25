import networkx as nx
import random
import matplotlib.pyplot as plt
import operator

G = nx.gnp_random_graph(10, 0.5, directed = True)
nx.draw(G, with_labels=True)
plt.show()

#x is the random source node
x = random.choice([i for i in range(G.number_of_nodes)])
dict_counter = {}
for i in range (G.number_of_nodes()):
    dict_counter[i]=0
dict_counter[x] = dict_counter[x]+1

for i in range(1000000):
    list_n = list(G.neighbours(x))
    if len(list_n) == 0: #if x is a sink
        x = random.choice([i for i in range (G.number_of_nodes())])
        dict_counter[x] = dict_counter[x]+1
    else: #choose a node randomly from neighbours of x
        x = random.choice(list_n)
        dict_counter[x] = dict_counter[x]+1

p = nx.pagerank(G)

sorted_p = sorted(p.items(), key=operator.itemgetter(1))
sorted_rw = sorted(dict_counter.items(), key=operator.itemgeq(1))

print(sorted_p)
print(sorted_rw)
