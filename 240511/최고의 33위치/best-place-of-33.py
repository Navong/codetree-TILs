n = int(input())

grid =[
    list(map(int, input().split()))
    for _ in range(n)
]


def all_gold(row_s, col_s, row_e, col_e):
    num_of_gold = 0

    for row in range(row_s, row_e + 1): # by adding 1 to the row and col to make sure that the last cell of subgrid is included
        for col in range(col_s, col_e + 1):
            num_of_gold += grid[row][col]

    return num_of_gold

#explore all cases in left corner of the grid 
max_gold = 0

for row in range(n):
    for col in range(n):
        #if the 1 3 grid goes beyond the n n grid
        if row + 2 >= n or col + 2 >= n:
            continue

        num_of_gold = all_gold(row, col, row + 2, col + 2)

        max_gold = max(max_gold, num_of_gold)



print(max_gold)