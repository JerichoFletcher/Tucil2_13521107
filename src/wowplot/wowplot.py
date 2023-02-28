import matplotlib.pyplot as plot

MARK_MAX_SCALE = 128
MARK_MIN_SCALE = 24
MARK_COLOR_LO = [0, 1, 1]
MARK_COLOR_HI = [1, 1, 0]
PAIR_COLOR = [1, 0, 0]

SIZE_COL = 3
COLOR_COL = 4

P = None
Z = None

W_MIN = None
W_MAX = None
V_MIN = None
V_MAX = None

def sizeintp(t: float) -> float:
    dist = V_MAX - V_MIN
    if dist == 0:
        return (MARK_MIN_SCALE + MARK_MAX_SCALE) / 2
    return MARK_MIN_SCALE + (MARK_MAX_SCALE - MARK_MIN_SCALE) * (t - V_MIN) / dist

def colorintp(t: float) -> list[float]:
    dist = W_MAX - W_MIN
    if dist == 0:
        return MARK_COLOR_LO
    return [MARK_COLOR_LO[i] + (MARK_COLOR_HI[i] - MARK_COLOR_LO[i]) * (t - W_MIN) / dist
        for i in range(len(MARK_COLOR_LO))
    ]

def slice_col(col: int, scl: float = 1) -> list[float]:
    if len(Z[0]) <= col:
        return [0 for i in range(len(Z))]
    return [Z[i][col] * scl for i in range(len(Z))]

def sizes() -> list[float]:
    if len(Z[0]) <= SIZE_COL:
        return [(MARK_MIN_SCALE + MARK_MAX_SCALE) / 2 for _ in range(len(Z))]
    return [sizeintp(s) for s in slice_col(SIZE_COL)]

def colors() -> list[list[float]]:
    if len(Z[0]) <= COLOR_COL:
        return [MARK_COLOR_LO if not i in P else PAIR_COLOR for i in range(len(Z))]
    return [colorintp(Z[i][COLOR_COL]) if not i in P else PAIR_COLOR for i in range(len(Z))]

if __name__ == '__main__':
    Z = []
    try:
        file = open('result.txt', 'r')
        head = False
        for line in file:
            if not head:
                P = [int(d) for d in line.split(' ')]
                head = True
            else:
                Z.append([float(r) for r in line.split(' ')])
        file.close()
    except OSError:
        print("Error while trying to open file ./result.txt")
    
    l = len(Z)
    if l > 0:
        n = len(Z[0])
        print(f"Preparing plot for {l} vectors of dimension {n}")
        if n >= 4:
            print("4th component portrayed by size")
        if n >= 5:
            print("5th component portrayed by color")
        if n >= 6:
            print("Warning! Only up to 5 dimensions are shown")
        
        fig = plot.figure()
        ax = fig.add_subplot(projection='3d')

        V_MIN = min(slice_col(SIZE_COL))
        V_MAX = max(slice_col(SIZE_COL))
        W_MIN = min(slice_col(COLOR_COL))
        W_MAX = max(slice_col(COLOR_COL))

        ax.scatter(
            slice_col(0),
            slice_col(1),
            slice_col(2),
            s=sizes(),
            c=colors()
        )

        ax.set_xlabel('Component 1')
        ax.set_ylabel('Component 2')
        ax.set_zlabel('Component 3')

        plot.show()
    