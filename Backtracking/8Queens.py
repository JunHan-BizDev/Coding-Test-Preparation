




def promising(queen_loc, row):
    idx = 0
    switch = True

    while (switch and (idx < row)):
        if (queen_loc[idx] == queen_loc[row]) | \
                (abs(queen_loc[row] - queen_loc[idx]) == row - idx):
            switch = False
            break
        idx += 1

    return switch

def queens(length, queen_row, queen_loc, ans):

    if promising(queen_loc, queen_row):
        if queen_row == length-1:
            ans[0] += 1
            if(ans[0] == 3):
                print(f"세번째 해 : {queen_loc}")
        else:
            for col in range(length):
                queen_loc[queen_row+1] = col
                queens(length, queen_row+1, queen_loc, ans)

ans = [0]
n=7
col=n*[0]
queens(n,-1,col, ans)

print('해의 총 개수 : ', str(ans[0]))