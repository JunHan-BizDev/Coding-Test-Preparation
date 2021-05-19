def promising(i, weight, total):
    return (((weight + total) >= W) and ((weight == W) or ((weight + w[i+1]) <= W )))

def sumSubset(i, weight, total, include):
    if promising(i, weight,total):
        if weight == W:
            print(f'sol{include}')
        else:
            include[i+1] = 1
            sumSubset(i+1, weight + w[i+1], total-w[i+1], include)
            include[i+1] = 0
            sumSubset(i+1, weight, total-w[i+1], include)



n = 6
w = [1,2,3,4,5,6]
w.sort()
W = 9
print("items =", w, "W =", W)
include = n * [0]
total = 0
for k in w:
    total += k
sumSubset(-1, 0, total, include)

