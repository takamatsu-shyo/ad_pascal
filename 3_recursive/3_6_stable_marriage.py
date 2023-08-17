n = 8
single = [True] * n
x_list = [0] * n
y_list = [0] * n

# Men's peference
wmr = [[val-1 for val in row] for row in
  [ [7, 2, 6, 5, 1, 3, 8, 4],
    [4, 3, 2, 6, 8, 1, 7, 5],
    [3, 2, 4, 1, 8, 5, 7, 6],
    [3, 8, 4, 2, 5, 6, 7, 1],
    [8, 3, 4, 5, 6, 1, 7, 2],
    [8, 7, 5, 2, 4, 3, 1, 6],
    [2, 4, 6, 3, 1, 7, 5, 8],
    [6, 1, 4, 2, 7, 5, 3, 8]]
  ]

# Wemen's preference
mwr = [[val-1 for val in row] for row in
  [ [4, 6, 2, 5, 8, 1, 3, 7],
    [8, 5, 3, 1, 6, 7, 4, 2],
    [6, 8, 1, 2, 3, 4, 7, 5],
    [3, 2, 4, 7, 6, 8, 5, 1],
    [6, 3, 1, 4, 5, 7, 2, 8],
    [2, 1, 3, 8, 7, 4, 6, 5],
    [3, 5, 7, 2, 4, 1, 8, 6],
    [7, 2, 8, 4, 5, 6, 3, 1]]
  ]

def get_rank_table(wmr, n):
    rmw = [[0 for _ in range(n)] for _ in range(n)]

    for man in range(n):
        for rank in range(n):
            rmw[man][wmr[man][rank]] = rank

    return rmw

rmw = get_rank_table(wmr, n)
rwm = get_rank_table(mwr, n)


def show_result():
    # Test by the redundant
    for woman in x_list:
        if x_list[y_list[woman]] != woman:
            print("Sth wong at woman", woman)
            raise ValueError("Matching is inconsistent")
    
    rank_man = 0
    rank_woman = 0

    for woman in x_list:
        print(woman + 1, " ", end="")
        rank_man += rmw[woman][x_list[woman]] + 1
        rank_woman += rwm[x_list[woman]][woman] + 1

    print(rank_man, " ", rank_woman)


def stable(man, woman, rank):
    stable = True
    
    i = 0
    while i < rank and stable:
        picked_woman = wmr[man][i]
        i += 1
        if not single[picked_woman]:
           stable = rwm[picked_woman][man] > rwm[picked_woman][y_list[picked_woman]]
           #print("w ", stable)

    j = 0
    limit = rwm[woman][man]
    while j < limit and stable:
        picked_man = mwr[woman][j]
        j += 1
        if picked_man < man:
            stable = rmw[picked_man][woman] > rmw[picked_man][x_list[picked_man]]
            #print("m ", stable)


    #print("stable ", man, woman, rank, stable)
    return stable


def trial(man):
    #print("trial", man)
    for rank in range(n):
        woman = wmr[man][rank]
        if single[woman] and stable(man, woman, rank):
            # Record the marriage
            x_list[man] = woman
            y_list[woman] = man
            single[woman] = False

            if man < n - 1:
                trial(man + 1)
            else:
                show_result()

            single[woman] = True

def main():
    #print("Stable Marriage")

    trial(0)

if __name__ == '__main__':
    main()
