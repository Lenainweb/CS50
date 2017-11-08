# calculates the minimum number of coins required to give a user change
def main():
    coin = 0
    while True:
        coins = float(input("O hai! How much change is owed?\n"))
        if coins > 0:
            break
    coins = int(coins * 100)

    if coins >= 50:
        coin = coin + coins // 50
        coins = coins % 50
    if coins >= 25:
        coin = coin + coins // 25
        coins = coins % 25
    if coins >= 10:
        coin = coin + coins // 10
        coins = coins % 10
    if coins >= 5:
        coin = coin + coins // 5
        coins = coins % 5
    if coins >= 1:
        coin = coin + coins // 1
        coins = coins % 1

    print(coin)

if __name__ == "__main__":
    main()