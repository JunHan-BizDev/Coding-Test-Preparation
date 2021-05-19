#m-coloring 문제

def promisingColor(i, vcolor):
    switch = True
    idx = 0
    while (idx < i) and switch:
        if(W[i][idx] and (vcolor[i] == vcolor[idx])):
            switch = False
        idx += 1

    return switch

def color(i, vcolor):
    if promisingColor(i, vcolor):
        if (i == num_color):
            print(vcolor)
        else:
            for num in range(1,num_color+1):
                vcolor[i+1] = num
                color(i+1, vcolor)



print()
num_node = 4
W = [[0, 1, 1, 1], [1, 0, 1, 0], [1, 1, 0, 1], [1, 0, 1, 0]]
vcolor = num_node * [0]
num_color = 3
color(-1, vcolor)

