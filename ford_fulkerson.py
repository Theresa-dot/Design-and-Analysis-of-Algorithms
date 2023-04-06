#Ford-Fulkerson Algorithm

#find path by using BFS
def dfs(C, F, s, t):
        stack = [s]
        paths={s:[]}
        if s == t:
                return paths[s]
        while(stack):
                u = stack.pop()
                for v in range(len(C)):
                        if(C[u][v]-F[u][v]>0) and v not in paths:
                                paths[v] = paths[u]+[(u,v)]
                                if v == t:
                                        return paths[v]
                                stack.append(v)
        return None

def max_flow(C, s, t):
        n = len(C) # C is the capacity matrix
        F = [[0] * n for i in range(n)]
        path = dfs(C, F, s, t)
        while path != None:
            flow = min(C[u][v] - F[u][v] for u,v in path)
            for u,v in path:
                F[u][v] += flow
                F[v][u] -= flow
            path = dfs(C,F,s,t)
        return sum(F[s][i] for i in range(n))
    
# make a capacity graph
# node s  a  b  c  d   e f   g  t
C = [[ 0, 9, 1, 0, 10, 0, 0, 0, 6 ],  # s
     [ 0, 0, 5, 3, 4, 0, 0, 7, 0 ],  # a
     [ 0, 0, 0, 10, 0, 0, 0, 0, 0 ],  # b
     [ 0, 4, 7, 0, 5, 0, 0, 0, 0 ],  # c
     [ 0, 4, 0, 10, 0, 0, 0, 0, 7 ],  # d
     [ 0, 0, 5, 0, 0, 0, 9, 1, 0 ],  # e
     [ 0, 1, 0, 4, 0, 0, 0, 5, 0 ],  # f
     [ 0, 1, 6, 1, 5, 0, 0, 0, 5 ],  # g
     [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ]]  # t

source = 0  # A
sink = 8    # F
max_flow_value = max_flow(C, source, sink)
print ("Ford-Fulkerson algorithm")
print ("max_flow_value is: ", max_flow_value)