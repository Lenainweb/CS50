#program that determines whether a provided credit card number
#is valid according to Luhn’s algorithm


def main():

    cc = input("Number: ")
    ccl = list(cc)
    ccl.reverse()
    contral_sum = 0

    for i in range(0, len(ccl)):
        if  (i % 2) != 0:
            digit = int(ccl[i]) * 2
            if digit > 9:
                digit = digit % 10 + 1
                contral_sum = contral_sum + digit
            else:
                contral_sum = contral_sum + digit
        else:
            digit = int(ccl[i])
            contral_sum = contral_sum + digit
    if contral_sum % 10 != 0:
        print("INVALID")

    elif len(ccl) == 15:
        if int(ccl[14]) == 3 and int(ccl[13]) == 7:
            print("AMEX")
    elif len(ccl) == 16:
        if int(ccl[15]) == 5 and int(ccl[14]) == 1 or int(ccl[14]) == 2 or int(ccl[14]) == 3 or int(ccl[14]) == 4 or int(ccl[14]) == 5:
            print("MASTERCARD")
        if int(ccl[15]) == 4:
            print ("VISA")
    elif len(ccl) == 13:
        if int(ccl[12]) == 4:
            print("VISA")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()