#program that prints out a double half-pyramid
#of a specified height, per the below.

def main():
    nline = 1
    while True:
        height = int(input("Height: "))
        if height > 0 and height < 23:
            break
    for i in range (height):
        print(" " * (height - nline),
            '#' * nline,'', '#' * nline)
        nline = nline + 1

if __name__ == "__main__":
    main()